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
