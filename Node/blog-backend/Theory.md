## Node.js

js엔진을 기반으로 웹 브라우저 뿐만 아니라 서버에서도 js사용할 수 있는 런타임 개발 ⇒ Node.js

- koa

웹 서버 구축 시, 웹 프레임 워크  
미들웨어 기능만. 나머지는 다른 라이브러리 적용하여 사용 ⇒ Express보다 가벼움

- node version확인
- 마지막 프로젝트이 블로그 서비스와 연동할 서버이기 때문에 blog디렉터리 만들고,
  내부에 blog-backend디렉터리 생성.
- yarn init -y로 패키지 정보를 생성
  ⇒ package.json파일 생성

- koa웹 프레임워크 설치
  ⇒ yarn add koa
  ⇒ yarn run eslint —init

```
  ✔ How would you like to use ESLint? · problems
  ✔ What type of modules does your project use? · commonjs
  ✔ Which framework does your project use? · none
  ✔ Does your project use TypeScript? · No / Yes
  ✔ Where does your code run? · browser, node

  ✔ What format do you want your config file to be in? · JSON
  The config that you've selected requires the following dependencies:
```

⇒ .eslintrc.json 파일 생성됨

### .prettierc파일 생성

```javascript
  {
  "singleQuote": true,
  "semi": true,
  "useTabs": false,
  "tabWidth": 2,
  "trailingComma": "all",
  "printWidth": 80
  }
```

prettier적용

```javascript
yarn add eslint-config-prettier

```

설치 후, .exlintrc.json 생성

- src 파일 임의로 생성
  => index.js
  서버 포트 4000번으로 열기

```javascript
const Koa = require('koa');
const app = new Koa();

app.use((ctx) => (ctx.body = 'hello world'));
app.listen(4000, () => {
  console.log('Listening to port 4000');
});
```
-> node src 

koa => 미들웨어의 배열로 구성.
app.use => 미들웨어 함수를 애플리케이션에 등록

- 쿼리 이용
```javascript
app.use((ctx, next) => {
  console.log(ctx.url);
  console.log(1);
  if (ctx.query.authorized !== '1') {
    ctx.status = 401;
    return; //authorized=1이라는 쿼리 파라미터가 포함되어 있으면 이후 미들웨어 처리
  }
  next();
});
```

- async/await 사용
koa ) 정식으로 지원함

## 21.4 nodemon

서버 코드 변경시 서버 재시작 번거로워요.
```
yarn add --dev nodemon
```
=> nodemon도구를 사용해서,   
코드 변경할 때마다 서버 자동 재시작

package.json
```javascript
"scripts":{
  "start": "node src", //서버 시작
  "start:dev": "nodemon --watch src/ src/index.js"//nodemone을 통해 서버를 실행해주는 명령어
}
```
nodemon은 src디렉터리 주시. 
내부의 어떤 파일이 변경되면 이를 감지하여 src/index.js 파일 재시작!
재시작 필요 없다면,
> yarn start
재시작 필요하면
> yarn start:dev

## 21.5 koa-router사용
koa에서도 다른 주소로 요청이 들어올 경우 다른 작업을 처리할 수 있도록 라우터를 사용해야 함.
koa-router모듈 설치
```
yarn add koa-router
```

- 라우터 설정
```javascript
router.get('/', (ctx) => {
  ctx.body = '홈';
});
router.get('/about/:name?', (ctx) => {
  const {name}=ctx.params;
  ctx.body = name ?`${name}의 소개`:'소개';
});
```
첫번째 파라메타 => 라우트 경로
두번째 파라메타 => 해당 라우트에 적용할 미들웨어 함수

get => 해당 라우트에서 사용할 HTTP메서드 의미
ex)post, put, delete

- 라우트 파라미터, 쿼리
> ctx.params 객체에서 조회
파라미터 사용시, 콜론(:)사용
쿼리, 물음표(?)사용

파라미터 => 처리할 작업의 카테고리 받아오거나 고유ID 혹은 이름으로 <strong>특정 데이터</strong>를 조회할 때 사용
쿼리 => <strong>옵션</strong>에 관련된 정보 받아옴

- Reat Api
클라이언트: 서버에 자신이 데이터를 조회, 생성, 삭제, 업데이트 하겠다!
서버: 필요한 로직에 따라 데이터베이스에 접근해 작업 처리
> get : 데이터 조회 
> post : 데이터 등록, 인증작업 거칠때
> delete: : 데이터 지울때
> put: 새 정보로 통째로 교체 할때
> patch: 특정 필드 수정

## 21.5.5 posts라우트 생성
api/posts/index.js
=> 여러종류의 라우트 설정 후 printInfo함수 호출
문자열이 아닌 JSON객체를 반환하도록 설정, 
> 현재 요청의 메서드, 경로, 파라미터

api라우트에 posts라우트 연결


- koa-bodyparser미들웨어 적용
```
yarn add koa-bodyparser
```

함수 이렇게 내보냈다!
> exprots.이름 =
이렇게 받는다!
> const 모듈이름 = require('파일이름')
> 모듈이름.이름();
