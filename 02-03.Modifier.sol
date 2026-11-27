// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

// modifier : 함수 실행 전후에 조건을 검사하는 재사용 가능한 코드 블록
contract Example{
  
  address public owner;

  modifier onlyOwner() {
    require(msg.sender == owner, "Not owner");
    _; // 원래 함수가 여기서 실행됨
  }

  function withdraw() public onlyOwner {
    // onlyOwner 조건을 통과해야 실행됨
    // withdraw() 라는 함수에 onlyOwner 라는 modifier가 붙었으므로 modifier 먼저 실행되고 그 다음에 _ 자리가 원래 함수가 실행되는 자리
  }

  // 기본구조
  // modifier 이름(파라미터) {
    // 전처리 코드 (함수 실행 전)
    // _; 원래 함수 실행 지점
    // 후처리 코드(함수 실행 후)
  //}

}

// onlyOwner - 소유자 제한
contract Ownable {
  address public owner;

  constructor() {
    owner = msg.sender;
  }

  modifier onlyOwner() {
    require(msg.sender == owner, "Caller is not owner");
    _;
  }

  function changeOwner(address newOwner) public onlyOwner {
    owner = newOwner;
  }

  function withdraw() public onlyOwner {
    payable(owner).transfer(address(this).balance);
  }
}

// nonReentrant - 재진입 방지
contract ReentrancyGuard {
  bool private locked;
  mapping(address => uint256) public balances;
  modifier nonReentrant() {
    require(!locked, "Reentrant call");
    locked = true;
    _;
    locked = false;
  }

  function withdraw(uint256 amount) public nonReentrant {
    // 이 함수 실행중에는 다시 호출할 수 없음
    require(balances[msg.sender] >= amount);
    balances[msg.sender] -= amount;
    (bool success,) = msg.sender.call{value: amount}("");
    require(success);
  }
}

// whenNotPaused - 긴급 정지
contract Pausable {
  bool public paused;
  address public admin;

  modifier whenNotPaused() {
    require(!paused, "contract is paused");
    _;
  }

  modifier whenPaused() {
    require(paused, "contract is not paused");
    _;
  }

  function pause() public {
    require(msg.sender == admin);
    paused = true;
  }

  function unpause() public {
    require(msg.sender == admin);
    paused = false;
  }

  function transfer(address to, uint256 amount) public whenNotPaused {
    // paused가 false 일 때만 실행
  }
}

// 파라미터가 있는 modifier
contract eExample {
  mapping(address => uint256) public balances;

  //최소 금액 검증
  modifier minAmount(uint256 _min) {
    require(msg.value >= _min, "Below minimum");
    _;
  }

  //잔액 검증
  modifier hasBalance(uint256 _amount) {
    require(balances[msg.sender] >= _amount, "Insufficient balance");
    _;
  }

  function deposit() public payable minAmount(0.1 ether) {
    balances[msg.sender] += msg.value;
  }

  function withdraw(uint256 amount) public hasBalance(amount) {
    balances[msg.sender] -= amount;
    payable(msg.sender).transfer(amount);
  }
}

contract MultiModifier {
  address public owner;
  bool public paused;

  modifier onlyOwner() {
    require(msg.sender == owner, "Not owner");
    _;
  }

  modifier whenNotPaused() {
    require(!paused, "Paused");
    _;
  }

  modifier validAddress(address _addr) {
    require(_addr != address(0), "Invalid address");
    // address 초기화가 0으로 되니까 주소의 타당성 확인
    _;
  }

  // 여러 modifier 적용
  function transfer(address to, uint256 amount) public whenNotPaused onlyOwner validAddress(to) {
    // 모든 modifier를 통과해야 실행
    // 왼쪽부터 차례대로 검증
  }

  // 실행 순서:
  // 1. modifier1 전처리
  //    2. modifier2 전처리
  //       3. modifier3 전처리
  //          4. 함수 본문 실행
  //       5. modifier3 후처리
  //    6. modifier2 후처리
  // 7. modifier1 후처리
}

contract threer {
  address public condition;
  mapping(address => uint256) public balances;

  // require : 조건이 false 면 revert 하고 남은 가스 환불
  require(condition, "Error message");
  function withdraw(uint256 amount) public {
    require(amount > 0, "Amount must be positive");
    require(balances[msg.sender] >= amount, "Insufficient balance");

    // 불변 조건 검증: totalSupply는 절대 변하면 안됨
    assert(totalSupply == balanceBefore);
  }
}

// 에러 정의
// 커스텀 에러 사용 (가스 절약)
error Unauthorized();

contract Example{
  mapping(address => uint256) public balances;
  address public owner;

  function withdraw(uint256 amount) public {
    if(msg.sender != owner) {
      revert Unauthorized();
    }
  }
}


//예시
contract TokenSale {
  address public owner;
  bool public saleActive;
  uint256 public tokenPrice;
  uint256 public tokenSold;
  uint256 public maxTokens;

  mapping(address => uint256) public purchasedTokens;

  //에러 정의
  error SaleNotActive();
  error SaleEnded();
  error InsufficientPayment(uint256 sent, uint256 required);
  error ExceedsLimit(uint256 requested, uint256 available);

  //Modifier 정의
  modifier onlyOwner() {
    require(msg.sender == owner, "Not Owner");
    _;
  }

  modifier saleIsActive() {
    if(!saleActive) revert SaleNotActive();
    if(tokenSold >= maxTokens) revert SaleEnded();
    _;
  }

  modifier validPurchase(uint256 amount) {
    uint256 cost = amount * tokenPrice;
    if (msg.value < cost) {
      revert InsufficientPayment(msg.value, cost);
    }
    if (tokenSold + amount > maxTokens) {
      revert ExceedsLimit(amount, maxTokens - tokenSold);
    }
    _;
  }

  constructor(uint256 _price, uint256 _maxTokens) {
    owner = msg.sender;
    tokenPrice = _price;
    maxTokens = _maxTokens;
    saleActive = false;
  }

  function startSale() public onlyOwner {
    saleActive = true;
  }

  function endSale() public onlyOwner {
    saleActive = false;
  }

  function buyTokens(uint256 amount) public payable saleIsActive validPurchase(amount) {
    purchasedTokens[msg.sender] += amount;
    tokenSold += amount;

    //잔돈 반환
    uint256 cost = amount * tokenPrice;
    if (msg.value > cost) {
      payable(msg.sender).transfer(msg.value - cost);
    }
  }

  function withdrawFunds() public onlyOnwer {
    payable(owner).transfer(address(this).balance);
  }
}
