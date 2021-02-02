next.js에서는 css-in-js방식으로 스타일 코드를 작성 할 수 있는 styled.jsx 패키지를 내장하고 있다.

styled-component같은 다른 패키지를 이용해서 css-in-js 방식을 사용하려면 설정을 해야 한다.

css-in-js방식을 사용하려면 서버사이드 렌더링 시 스타일 코드를 추출해서 HTML에 삽입하는 과정이 필요하다.

pages 하단에 \_document.js파일에 styled-jsx문법으로 작성한 스타일 코드를 추출하는 코드를 작성해야 한다.

### _그런데, \_document.js를 작성하지 않고도 .babelrc에서 `ssr:true`를 해주어 해결했다._

파일을 작성하는 이유는, 서버와 클라이언트가 생성하는 해시 값이 서로 달라서 문제가 된다.

styled-components에서 제공하는 바벨 플러그인을 이용해서 서버와 클라이언트의 결과값을 일치시킬 수 있다.

따라서, `npm install styled-components babel-plugin-styled-components`를 설치하고 바벨을 설정해본다.

여기서 말하는 바벨 설정이란, .babelrc파일을 만들어 코드를 작성하는 것이다.

바벨과 웹팩 설정을 변경할 수 없게 하는 create-react-app과 비교되는 부분이다.
