## 주요 개념

1. Observable State (관찰 받고 있는 상태)     
Mobx를 사용하는 앱은 관찰 할 수 있는 상태.      
따라서, 특정부분이 바뀌면 Mobx에서는 **정확히 어떤 부분이 바뀌었는지** 알 수 있다.

2. Computed Value (연산된 값)    
'연산된 값' ⇒ 기존 값과 다른 연산된 값에 기반해 만들어 질 수 있는 값.

3. Reactions (반응)   
값이 바뀜에 따라 해야 할 일을 정하는 것   

4. Actions (액션-행동)   
상태에 변화를 일으키는 것   
BUt! 리덕스의 액션과 달리 객체형태로 만들지 않음

## 리액트 없이 Mobx사용

import { observable, reaction, computed, autorun } from 'mobx'

- observable

Observable State 만듦.

즉, 관찰받고 있는 **상태**로 **변화**가 일어나면 **감지.**

- reaction

특정 값이 바뀔때 감지해서 **어떤 일을 하고 싶어요**!

- computed

연산된 값을 사용하고 싶어요

BUT! 변화가 일어날 때마다 특정 작업을 처리하는 것이 아니다

의존하는 값이 바뀔 때 미리 계산해 놓고 조회할때는 캐싱 된 데이터를 사용한다.

```javascript
import { observable, reaction, computed, autorun } from "mobx";

const calculator = observable({
  a: 1,
  b: 2
}); //관찰 받고 있는 상태

//특정값 바뀌면 특정 작업허가
reaction(
  () => calculator.a,
  (value, reaction) => {
    console.log(`a값이 ${value}값으로 바뀌었다`);
  }
);

reaction(
  () => calculator.b,
  (value, reaction) => {
    console.log(`b값이 ${value}로 바뀌었네요`);
  }
);

const sum = computed(() => { // 특정 값 캐싱
  console.log("계산중이다");
  return calculator.a + calculator.b; //처음에는 3
});

sum.observe(() => calculator.a); //a 변화를 보고 있다.
sum.observe(() => calculator.b); //b 변화를 보고 있다.

//computed 이후에 값의 변화를 주어야 변화를 볼 수 있음
calculator.a = 30; // sum은 32
calculator.b = 40; //sum은 70

//여러번 조회해도 값은 일정 
console.log(sum.value); // 70
console.log(sum.value); // 70

calculator.a = 50; //a변화 감지해서 
// reaction이 반응, 
// sum.observe로 a의 변화를 보고 있기 때문에, 
// computed된 sum이 console.log를 출력하고,
console.log(sum.value); // sum은 90

=>
계산중이다 
a값이 30값으로 바뀌었다 
계산중이다 
b값이 40로 바뀌었네요 
계산중이다 
2
70 
70
a값이 50값으로 바뀌었다 
계산중이다 
90
```

- autorun

reaction과 computed의 observe대신 사용 할 수 있다

computed로 만든 값의 .get()함수를 호출해주면, 값 하나하나를 observe하지 않아도 된다.

즉, 변화를 보고있다고 일일이 지정해주지 않아도 된다

```javascript
import { observable, reaction, computed, autorun } from "mobx";

const calculator = observable({
  a: 1,
  b: 2
});

const sum = computed(() => {
  console.log("계산중이다");
  return calculator.a + calculator.b;
});

autorun(() => console.log(`a값이 ${calculator.a}값으로 바뀌었다`));
autorun(() => console.log(`a값이 ${calculator.b}값으로 바뀌었다`));
autorun(() => sum.get()); 
//sum에서 a,b를 보고 있으니까, get()으로 보고 있다. _ ${calculator.a}, ${calculator.b}
//따라서, observe를 사용하지 않아도 된다. 
//    + reaction의 일을 지정해주면 reaction도 사용하지 않아도 된다. _ console.log

calculator.a = 30;
calculator.b = 40;

console.log(sum.value);

=>
a값이 1값으로 바뀌었다 
a값이 2값으로 바뀌었다 
계산중이다 
a값이 30값으로 바뀌었다 
계산중이다 
a값이 40값으로 바뀌었다 
계산중이다 
70
```
