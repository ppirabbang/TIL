// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StaticTypes {
  // 모두 컴파일 시점에 크기 결정
  bool public flag;       //1byte -> slot 0
  uint256 public number;  // 32byte -> slot1
  address public owner;   // 20byte -> slot2
  bytes32 public hash;    // 32byte -> slot3
  uint256[3] public fix;  // 96byte -> slot 4,5,6

  // 장점 : 가스 효율적, 예측 가능한 스토리지 레이아웃
}

contract DynamicTypes {
  string public name;  // slot0(길이/참조)
  bytes public data;   // slot1(길이/참조)
  uint256[] public numbers;  //slot2(길이), 데이터는 keccak256(slot)
  mapping(address => uint256) public balances; //slot3 기반 해시

  function addNumber(uint256 n) external{
    numbers.push(n); // 배열 크기 증가
  }

  function setName(string calldata _name) external {
    name = _name; 
  }
}

contract GasCost {
  uint256 public staticVar;      // SSTORE: 20,000 gas
  uint256[] public dynamicArray; // push: 20,000 + a

  // 정적 : 단순 저장
  function setStatic(uint256 v) external {
    staticVar = v; // ~20,000 gas
  }

  // 동적 : 길이 업데이트 + 데이터 저장
  function pushDynamic(uint256 v) external {
    dynamicArray.push(v); // ~22,000 + gas (length + data)
  }

  bytes32 txHash = keccak256("hello");
  
}

// 일반 주소
// address user;
// 이더 전송 가능한 주소
// address payable recipient = payable(주소주소);

/* 바이트 용도 예시
// bytes32 txHash = keccak256("hello");
// bytes4 selector - bytes4(keccak256("transfer(address,uint256)"));
*/

contract EnumDetails {
  enum OrderStatus {Created, Paid, Shipped, Delivered, Cancelled}

  OrderStatus public status = OrderStatus.Created;

  // enum -> uint8 변환
  function getStatusAsUint() public view returns (uint8) {
    return uint8(status); // 0,1,2,3,4
  }

  // uint8 -> enum 변환
  function setStatusFromUint(uint8 _status) public {
    require(_status <= uint8(type(OrderStatus).max), "Invalid status");
    status = OrderStatus(_status);
  }

  // 첫번째값 / 마지막 값 얻기
  function getMinMax() public pure returns (OrderStatus, OrderStatus) {
    return (type(OrderStatus).min, type(OrderStatus).max);
  }

  // enum 제약 사항 : 최대 256개, 빈 enum 선언 불가, 선언 시 값 지정 불가, 음수 불가
}

contract EnumDelete {
  enum Status {Pending, Active, Completed}

  Status public status = Status.Active;
  function resetStatus() public {
    delete status; // Status.Pending 으로 초기화
  }

  // 0번 값을 None/Invalid로 만드는패턴
  enum BetterStatus {None, Pending, Active, Completed}

  BetterStatus public betterStatus; // 기본값: None
  function isInitialized() public view returns (bool) {
    return betterStatus != BetterStatus.None;
  }
}

contract OrderStateMachine {
  enum State {Created,Confirmed,Shipped,Delivered,Cancelled}

  State public state;
  mapping(State => State[]) public allowedTransitions;

  constructor() {
    allowedTransitions[State.Created].push(State.Confirmed);
    allowedTransitions[State.Created].push(State.Cancelled);
    allowedTransitions[State.Confirmed].push(State.Shipped);
    allowedTransitions[State.Confirmed].push(State.Cancelled);
    allowedTransitions[State.Shipped].push(State.Delivered);
  }

  error InvalidTransition(State from, State to);

  function transition(State newState) external {
    State[] memory allowed = allowedTransitions[state];
    bool valid = false;

    for (uint256 i=0; i<allowed.length; i++) {
      if(allowed[i] == newState) {
        valid = true;
        break;
      }
    }

    if(!valid) revert InvalidTransition(state, newState);
    state = newState;
  }
}

contract EnumABI {
  enum Status {A,B,C}

  // 외부에서 호출 시 uint8로 전달
  function getStatus(Status s) external pure returns (uint8) {
    return uint8(s);
  }
}

contract Array {
  uint256[5] fixedArray;
  uint256[] dynamicArray;
  uint256 len = dynamicArray.length;

  constructor() {
    fixedArray[0] = 100;
    dynamicArray.push(100);
    dynamicArray.pop();
  }

  function example() public pure returns (uint256[] memory) {
    uint256[] memory tempArray = new uint256[](3);
    tempArray[0] = 1;
    tempArray[1] = 2;
    tempArray[2] = 3;
    return tempArray;
  }
}

contract mappings {
  mapping(address => uint256) public balances;
  uint256  myBalnce = balances[msg.sender];

  mapping(address => mapping(address => uint256)) public allowances;

  constructor() {
    balances[msg.sender] = 100;
    // allowances[owner][spender] = 50;
    // Solidity에서는 컨트랙트 본문(함수 밖)에 실행문을 쓸 수 없어서 그래요. 함수 밖에서는 변수 선언과 =로 초기값 주기만 할 수 있어요.
  }
 // 특징: 매핑은 모든 가능한 키에 대해 기본값(0)이 존재합니다. 키가 "없다"는 개념이 없습니다.
}

struct User{
  address wallet;
  uint256 balance;
  bool isActive;
  string name;
}

contract structs {
  User public alice;

  function createUser() public {
    alice = User({
      wallet: msg.sender,
      balance: 100,
      isActive: true,
      name: "Alice"
    });
  }
  
  // 혹은 이렇게 alice = User(msg.sender,100,true,"Alice");

  mapping(address => User) public users;

  function getUser(address _addr) public view returns (User memory) {
    return users[_addr];
  }
}

contract Strings {
  string public name = "MyToken";

  function getGreeting() public view returns (string memory){
    string memory greeting = string.concat("Hello, ", name);
    return greeting;
  }
}

contract DataLocation {
  //storage: 블록체인에 영구 저장
  uint256[] public storageArray;
  mapping(address => uint256) public balances;

  //memory : 함수 실행중에만 존재
  // 상태를 읽기만 함 : view
  // 상태를 읽지도 않고 매개변수를 활용 : pure
  // 상태 변경 : 아무것도 안붙임
  function processArray(uint256[] memory inputArray) public pure returns (uint256) {
    uint256 sum = 0;
    for(uint i=0; i< inputArray.length; i++) {
      sum += inputArray[i];
    }
    return sum;
  }

  // calldata : 수정불가
  // 함수 내의 지역변수는 상관 없음
  function processCalldata(uint256[] calldata inputArray) external pure returns (uint256) {
    uint256 sum = 0;
    for (uint i = 0; i<inputArray.length; i++) {
      sum += inputArray[i];
    }
    return sum;
  }

  function modifyStorage() public {
    uint256[] storage arr = storageArray;
    arr.push(100);
  }
}

contract constants {
  //컴파일 시점에 값이 결정
  //가스 비용 없음, 코드에 직접 삽입
  uint256 public constant MAX_SUPPLY = 100000;
  address public constant BURN_ADDRESS = address(0);

  //배포 시점에 한 번만 설정
  //이후 변경 불가
  address public immutable owner;
  uint256 public immutable deployTime;

  constructor() {
    owner = msg.sender;
    deployTime = block.timestamp;
  }
}

contract SimpleToken {
  // 상태 변수 storage
  string public constant name = "SimpleToken";
  uint8 public constant decimals = 18;
  uint256 public totalSupply;

  // 매핑: 주소 -> 잔액
  mapping(address => uint256) public balanceOf;

  // 중첩 매핑 : owner -> spender -> 허용량
  mapping(address => mapping(address => uint256)) public allowances;

  constructor(uint256 _initialSupply) {
    totalSupply = _initialSupply * 10 ** decimals;
    balanceOf[msg.sender] = totalSupply;
  }

  function transfer(address _to, uint256 _amount) public returns (bool) {
    require(balanceOf[msg.sender] >= _amount, "Insufficient balance");

    balanceOf[msg.sender] -= _amount;
    balanceOf[_to] += _amount;

    return true;
  }
}