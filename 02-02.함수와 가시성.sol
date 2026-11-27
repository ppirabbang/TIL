// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract iExample {
  // public 함수: 어디서든 호출 가능
  function publicFunction() public pure returns (uint256) {
    return 100;
  }

  // public 상태변수: 자동으로 getter 함수 생성
  // balance() 라는 getter 함수가 자동 생성됨
  uint256 public balance = 1000;

  function internalCall() internal pure {
    publicFunction(); // 내부에서도 호출 가능
  }
}

contract Caller {
  iExample example;

  function call() public view {
    example.publicFunction(); // 외부에서 public 호출 가능
    example.balance(); // getter 호출 가능
  }
}

contract eExample {
  // external 함수 : 외부에서만 호출 가능
  function externalFunction() external pure returns (uint256) {
    return 100;
  }

  function internalCall() internal view {
    // externalFunction(); 내부에서 직접 호출 불가로 에러 발생
    this.externalFunction(); // this를 통해 우회 가능, 비효율적
  }
}

contract Parent {
  // internal 함수 : 컨트랙트 내부 + 상속받은 컨트랙트에서만 호출 가능
  function internalFunction() internal pure returns (uint256) {
    return 100;
  }

  function callInternal() public pure {
    internalFunction();
  }
}

contract Child is Parent {
  function useParent() public pure {
    internalFunction(); // 상속 받았으므로 호출 가능
  }
}

contract External {
  Parent parent;

  function tryCall() public pure {
    //parent.internalFunction(); // 외부에서 호출 불가
  }
}

contract pParent {
  // private 함수 : 오직 이 컨트랙트 내부에서만
  function privateFunction() private pure returns (uint256) {
    return 100;
  }

  function callPrivate() public pure {
    privateFunction();
  }
}

contract pChild is pParent {
  function useParent() public {
    // privateFunction(); 상속 받아도 호출 불가능
  }
}

contract vExample {
  uint256 public balance = 100;

  // view : 상태를 읽기만 하는 함수
  function getBalance() public view returns (uint256) {
    return balance; // 읽기 가능
    // balance = 200; 변경은 불가능
  }

  // view 함수는 외부 호출 시 가스 비용 없음
}

contract pExample {
  uint256 public balance = 100;

  //pure : 상태를 읽지도 쓰지도 않음
  function add(uint256 a, uint256 b) public pure returns (uint256) {
    return a+b; // 매개변수를 활용한 계산만 수행
    // return balance; 상태 읽기 불가능
  }

  // 연산, 인코딩 등에 사용
}

contract payalbeExample {
  // payable : 이더를 받을 수 있음
  function deposit() public payable {
    require(msg.value > 0, "Must send ETH");
  }

  // payable 없으면 이더 전송 시 revert
  function notPayable() public {
    // 이더를 받을 수 없음
  }

  function getBalance() public view returns (uint256) {
    return address(this).balance;
  }

  // 가스 비용 발생
}

contract Example {
  uint256 public counter;

  // 상태를 변경하는 일반 함수
  function increment() public {
    counter += 1; // 상태 변경
  }
  // 가스 비용 발생
}

contract constructorExample {
  address public owner;
  uint256 public initialSupply;

  constructor(uint256 _supply) {
    owner = msg.sender;
    initialSupply = _supply;
  }
}

contract receiveExample {
  // calldata 없이 이더만 받을 때 실행되는 함수
  receive() external payable {
    // 단순하게 이더만 전송 시 실행
  }
}

contract fallbackExample {
  // 매칭 되는 함수가 없을 때 실행되는 함수
  fallback() external payable {
    // 호출된 함수가 없거나 calldata가 있는 이더 전송
  }
  // payable 없이 선언 시 이더 없이 알 수 없는 함수 호출 
}

contract SimpleVault {
  mapping(address => uint256) private balances;

  //payable : 이더를 받을 수 있음
  function deposit() public payable {
    require(msg.value > 0, "Must deposit something");
    balances[msg.sender] += msg.value;
  }

  //view : 상태만 읽음
  function getBalance() public view returns (uint256) {
    return balances[msg.sender];
  }

  //일반 함수 : 상태 변경
  function withdraw(uint256 amount) public {
    require(balances[msg.sender] >= amount, "Insufficient balance");

    balances[msg.sender] -= amount;

    //이더 전송
    (bool success,) = msg.sender.call{value:amount}("");
    require(success, "Transfer failed");
  }

  function calculateFee(uint256 amount) public pure returns (uint256) {
    return amount * 1 / 100;
  }

  // external + calldata : 가스 효율적
  function batchDeposit(address[] calldata recipients, uint256[] calldata amounts) external payable {
    require(recipients.length == amounts.length, "Length mismatch");

    for(uint256 i=0; i<recipients.length; i++){
      balances[recipients[i]] += amounts[i];
    }
  }
}