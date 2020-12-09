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