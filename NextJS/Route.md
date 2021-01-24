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
