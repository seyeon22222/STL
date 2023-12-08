# STL 프로젝트
사용언어 :  &nbsp;&nbsp; <img src="https://img.shields.io/badge/C++-3178C6?style=flat"/> &nbsp;<img src="https://img.shields.io/badge/Makefile-3178C6?style=flat"/>
<br>
<br>

STL(standard Template Library)를 구현하기

1. [STL이란?](#STL이란?)

2. [Vector](#벡터-구현)

3. [Map](#Map-구현)

4. [Stack](#Stack-구현)



# STL이란?
- 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리

- 구성요소 : 컨테이너, 반복자, 알고리즘, 함수 객체, 어댑터, 할당기

## 컨테이너
- 표준 시퀸스 컨테이너 : 벡터, 덱 ,리스트
- 표준 연관 컨테이너 : set, map, multiset, multimap
- 배열 기반 컨테이너 : 데이터 여러 개를 하나의 메모리 단위에 저장(벡터, 덱)
- 노드 기반 컨테이너 : 데이터를 하나를 하나의 메모리 단위에 저장(리스트, 맵)

# 벡터 구현
- 시퀸스 컨테이너로 임의 지정 반복자(random_access_iterator)를 기반으로 구성됨

## [벡터 구현 순서](https://en.cppreference.com/w/cpp/container/vector)

1. Random_access_iterator의 기능 구현
2. 멤버 타입 선언
3. 멤버 함수 구현
4. 비 멤버 함수 구현

- 벡터 구현 시, 주의할점
	
	SFINAE(Substitution failure is not an error)
	- cpp에서 템플릿 매개변수에 자료형이나 값을 넣을 수 없어도 오류가 발생하지 않는 상황, 즉 템플릿의 일부분을 조건문으로 사용하는 상황
	- Vector의 생성자 및 멤버함수에서 매개변수로 iterator를 받는 상황과 값을 직접 받는 상황에서 어느쪽으로 함수가 호출될지를 결정해주는 상황에서 사용
	
	벡터의 사이즈 관련 내용
	- 벡터를 복사하거나 Capacity가 커져야하는 상황이면, 기존의 메모리보다 큰 메모리를 할당한 후, 원소들을 복사하고 기존의 메모리를 삭제하고 큰 메모리의 포인터를 넘겨줘야함
	- 벡터를 삭제하는 경우, 메모리를 이동시키는것이 새로 할당, 복사, 제거하는 경우보다 효율적으로 작동


# Map 구현

# Stack 구현