# Pre-rendering

Next.js에서는 모든 페이지를 'Pre-rendering'한다.

이는, Client의 JavaScript에서 모든 작업을 수행하는 대신, 각 페이지에 대해 미리 HTML을 생성한다.

그렇기 때문에 SEO가 가능하다.

**SEO(Search engine optimization; 검색엔진 최적화)**

- Hydration 과정?

각 HTML 페이지는 최소한의 JavaScript 코드와 연결 한다.

즉, 브라우저에서 페이지를 로드하면, 해당 JavaScript코드가 실행되고 완전히 interactive 하게 됩니다.

인터랙티브한 [웹페이지 예시](https://tympanus.net/Development/DraggableDualViewSlideshow/)

Next.js에서 Pre-rendering은 HTML를 생성할 때 차이로 두 가지 방법이 있다.

렌더링 방식을 선택할 수 있는데, 두 방법을 혼용해서 사용할 수도 있다.

## Static Generation

첫 번째로, Static Generation방법은 공식문서에서도 권장하는 방법이다.

HTML은 Build할때, 생성되고 요청할때는 재요청이 없는 방법이다.

## Server-side Rendering

두 번째로, Server-side Rendering방법은 HTML이 생성될 때 마다 요청이 되는 방법이다.
