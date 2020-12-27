<h1 align="center">
Problems solved
</h1>

목표: GraphQL로 해결할 수 있는 2가지 문제

1. Over-fetching
   => 요청한 영역의 정보보다, 많은 정보를 서버에서 받아옴<br>
   => 비효율적<br>
   => 개발자들이 뭘 받았는지 모르게 된다<br>
   => example<br>
   모든 유저들 이름을 웹사이트에 보여주고 싶어요(Get)

   > 유저 정보 : 사용자 명,프로필사진, 이름, 성별, 이메일<br>
   > 처음 리스트에서 GET요청을 user에 보내면, 프로필사진, 이름, 성별, 이메일 영역을 사용하지 않을 것.<br>
   > 필요한 건 오직 사용자 명 뿐!<br>
   > 따라서, Database가 쓸데없는 영역을 보게 만들고, 고객들이 사용하는 어플 또한 필요 없는 정보를 받게될 것<br>
   > => GraphQL의 경우 Over fetching없이 사용가능.<br>
   > Frontend가 Database에 오직 사용자명만 요청 가능

2. Under-fetching
   => 어떤 하나를 완성하기 위해 다른 요청들을 해야할 때 발생<br>
   => 즉, REST에서 하나를 완성하려고 많은 소스를 요청함<br>
   => ex) 인스타그램 어플을 처음 시작할때,

   > 페이지의 피드, 알림, 사용자 프로필<br>
   > 3가지 요청을 하게됨<br>

   즉, 3가지 요청이 3번 오고가야 어플이 시작됨

BUT! GraphQL의 경우 Under fetching을 겪을 필요 없음<br>

- GraphQL은 어떻게 하나구요?
  한 query에 정확하게 원하는 정보만 받을 수 있어요

- 생각의 뽀인트를 바꾸자!
  첫번째, 다른 요청들을 하나의 URL로 보내기
  BUT! GraphQL에는 URL이 존재하지 않아요.

  > Query?
  > Database에서 무언가를 요청하고 GraphQL언어로 내가 원하는 정보를 알려줄 수 있어요
  > EX) 피드를 원하는데,
  > 모든 사진 피드 중에 (댓글, 좋아요 수), 알림(알림을 확인했는지), 유저프로필(사용자명과 프로필 사진)에 대한 정보를 원해요

- 자바스크립트에서 보내요

```javascript
query {
    feed {
        comments
        likeNumber
    }
    notifications{
        isRead
    }
    user{
        username
        profilePic
    }
}
```

- GraphQL에서 보내요
  => 원하는 정보만 제공가능

```GraphQL
{
    feed:[
        {
        comments:1,
        likeNumber:20
        }
    ],
    notifications: [
        {
            isRead: true
        },
         {
            isRead: false
        },
    ],
    user: {
        username: "Lily"
        profile: "http:"
    }
}

```
