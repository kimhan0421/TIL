next.js에서는 css-in-js방식으로 스타일 코드를 작성 할 수 있는 styled.jsx 패키지를 내장하고 있다.

styled-component같은 다른 패키지를 이용해서 css-in-js 방식을 사용하려면 설정을 해야 한다.

css-in-js방식을 사용하려면 서버사이드 렌더링 시 스타일 코드를 추출해서 HTML에 삽입하는 과정이 필요하다.

pages 하단에 \_document.js파일에 styled-jsx문법으로 작성한 스타일 코드를 추출하는 코드를 작성해야 한다.
