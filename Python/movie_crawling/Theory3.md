<h1 align="center">
Movie crawling
</h1> 
<p align="center">
  <strong>4. Server Construction</strong><br>
</p>

aws
+ python을 설치했으니 우분투 18.04버전 사용
+ general purpose
+ key 이름 지정

.pem 파일 저장한 곳에서 실행
+ ssh -i <key이름>.pem ubuntu@<IPv4 퍼블릭 IP>
+ pip3가 없기 때문에 
> sudo apt-get update \
> sudo apt-get install python3-pip
+ pip3가 설치된 후 그동안 설치한 것 알려주기
> pip3 install requests bs4 python-telegram-bot apscheduler

서버에 올리기
+ git 으로 올려서 내려받기
+ 파일 직접 ) 파일이 하나니, 이 방법 사용.

<p align="center">
  EC2 서버에 알리미 파일 전송하기
</p>

filezila 이용 ) all platforms 다운
+ 프로토콜 - SFTP
+ 호스트 - id입력
+ 사용자 - ubuntu
+ 키 파일 - 파일 위치

<p align="center">
  EC2 서버에 알리미 실행시키기
</p>

nohup
+ 터미널을 끄게 되도 항상 돌아가게 함
+ 백그라운드에서 실행되도록 함
>  nohup python3 crawling_imax.py &
+ 프로세스 종류
> ps -ef 에서 확인 후\
> kill -9 8219

파일 수정 후
+ filezila 에서 파일 덮어쓰기

