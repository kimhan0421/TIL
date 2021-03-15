- _document.tsx

```jsx
import Document, { Html, Head, Main, NextScript } from 'next/document';

class MyDocument extends Document {
  static async getInitialProps(ctx) {
    const initialProps = await Document.getInitialProps(ctx);
    return { ...initialProps };
  }

  render() {
    return (
      <Html>
        <Head />
        <body>
          <Main />
          <div id='modal' /> //추가
          <NextScript />
        </body>
      </Html>
    );
  }
}

export default MyDocument;
```

- CreateModal.tsx

```jsx
import { useRef, useEffect, useState } from 'react';
import { createPortal } from 'react-dom';

export default function ClientOnlyPortal({ children, selector }) {
  const ref = useRef();
  const [mounted, setMounted] = useState(false);

  useEffect(() => {
    ref.current = document.querySelector(selector);
    setMounted(true);
  }, [selector]);

  return mounted ? createPortal(children, ref.current) : null;
}
```