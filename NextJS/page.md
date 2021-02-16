# Pre-rendering

Next.js에서는 모든 페이지를 'Pre-rendering'한다.

이는, Client의 JavaScript에서 모든 작업을 수행하는 대신, 각 페이지에 대해 미리 HTML을 생성한다.

그렇기 때문에 SEO가 가능하다.

**SEO(Search engine optimization; 검색엔진 최적화)**

- Hydration 과정?

각 HTML 페이지는 최소한의 JavaScript 코드와 연결 한다.

즉, 브라우저에서 페이지를 로드하면, 해당 JavaScript코드가 실행되고 완전히 interactive 하게 됩니다.

인터랙티브한 [웹페이지 예시](https://tympanus.net/Development/DraggableDualViewSlideshow/)
