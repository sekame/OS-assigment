# 운영체제 프로젝트 (2)
## 동기화
### 1.Producer/Consumer 프로그램 설명
#### [기타 매장]
기타 매장에서는 직접 구매자의 취향에 따라 기타를 주문 제작하는 시스템이 존재한다. 
해당 매장은 기타를 직접 주문제작을 즉 Producer이고  주문제작한 기타를 고객번호에 맞게 배송을 해주어야 한다. 그리고
구매자가 Consumer이므로 배송을 받아야된다. 이러한 시스템을 멀티쓰레드를 이용하여서 구현을 하였다. 
  여기서 주문제작을 먼저 하지않고 배송을 받으면 race condition이 일어나는 지점이다. 이 프로그램에서는 고객의 번호를 radom
값을 받아서 item에 저장을 해준다.

### 파일 설명
#### PandC.c -> 동기화 기능이 없는 Producer/Consumer 프로그램이다.
#### PandCsys.c -> 동기화 기능을 추가한 Producer/Consumer 프로그램이다.

### 실행 방법
#### - 실행 환경 : MAC OS
#### PandC.c
1. gcc -o compile1 PandC.c -> 컴파일후에 exe파일을 생성해준다.
2. ./compile1 -> compile1.exe 실행
#### PandCsys.c
1. gcc -o compile2 PandCsys.c -> 컴파일후에 exe파일을 생성해준다.
2. ./compile2 -> compile2.exe 실행

### 2.Reader/Writer 프로그램 설명
#### [로또 번호 받아적기 프로그램]
어느 미국의 작은 마을에 할아버지 한분이 사는데 일주일에 한번씩 로또를 사는 로또광이다. 이 할아버지는 특이한 취미가 있는데 TV에 로또 번호가 나올때마다 기록하는 취미를 가지고 있다. TV에서 로또 번호가 나왔을 때, 로또 번호 순서대로 읽어와야되는데 먼저 읽기도전에 써버리면 race condition이 발생한다. 

### 파일 설명
#### WandR.c -> 동기화 기능이 없는 Reader/Write프로그램이다.
#### WandRsys.c -> 동기화 기능을 추가한 Reader/Write 프로그램이다.

### 실행 방법
#### - 실행 환경 : MAC OS
#### WandR.c
1. gcc -o compile3 WandR.c -> 컴파일후에 exe파일을 생성해준다.
2. ./compile3 -> compile3.exe 실행
#### WandRsys.c
1. gcc -o compile4 WandRsys.c -> 컴파일후에 exe파일을 생성해준다.
2. ./compile4 -> compile4.exe 실행
