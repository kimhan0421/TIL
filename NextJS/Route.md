<h2 align="center">
  <strong>Next.js _ Route</strong><br>
</h2>

### Index Routes

- index.js가 root

⇒ pages/index.js 인 경우 route는 '/'

⇒ pages/blog/index.js 인 경우 route는 'blog'

### Nested Routes

- index.js가 아닌 파일인 경우

⇒ pages/blog/first-port.js 인 경우 route는 'blog/first-port.js'

⇒ pages/dashboard/settings/username.js 인 경우 route는 '/dashboard/settings/username'

### Dynamic Route Segments

- parameters를 사용한 경우

⇒ pages/blog/[slug].js인 경우 route는 'blog/:slug'

⇒ pages/[username]/settings.js인 경우 route는 '/:username/settings'

⇒ pages/post/[...all].js인 경우 route는 '/post/\*'

즉, '/post/2020/id/title'

## Linking Between Pages

- client-side route와 같은 방식을 따름
- single-page application과 비슷한 방식

`import Link from 'next/link'` 후 `<Link href='/' />`

이때, pages는 자동적으로 인식

### Linking to Dynamic Paths

예시상황:

Post 컴퍼넌트에서 posts를 부모로부터 받아오고, map으로 post를 접근해서, {post.title}로 표시한 후 link를 걸고 싶어요

```javascript
import Link from "next/link";

function Post({ posts }) {
  return (
    <>
      {posts.map((post) => (
        <li key={post.id}>
          <Link
            href={{
              pathname: "/blog/[slug]",
              query: { slug: post.slug },
            }}
          >
            <a>{post.title}</a>
          </Link>
        </li>
      ))}
    </>
  );
}
```

### Injecting the Router(Router 객체를 이용해 페이지 이동하기)

```jsx
import Router from "next/router";

export default function Page2() {
  return (
    <div>
      <button onClick={() => Router.push("/")}>home으로 이동</button>
    </div>
  );
}
```

⇒ `import Router from 'next/router';` 사용

⇒ Router객체를 이용하는 것과 Link컴포넌트를 사용하는 것의 기능적 차이는 없다.

BUT! Router 객체가 동적인 코드에 적합하다.
