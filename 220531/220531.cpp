#include <iostream>

class A
{
public:
	A(int data) // 1번 생성자
		: _data(data) { }

	A(int data, double d) // 2번 생성자
		: _data(data), d(d) { }

private:
	int _data;
	double d;
};

void Foo(A a);

class Num1
{
public:
	Num1() { std::cout << "Num1 생성\n"; }
	~Num1() { std::cout << "Num1 소멸\n"; }
};

class Num2 : public Num1
{
public:
	Num2() { std::cout << "Num2 생성\n"; }
	~Num2() { std::cout << "Num2 소멸\n"; }
};

class Num3 : public Num2
{
public:
	Num3() { std::cout << "Num3 생성\n"; }
	~Num3() { std::cout << "Num3 소멸\n"; }
};

class Base1
{
public:
	void Foo() {}

};

int main()
{
	//Foo(A(10));
	//// == Foo(10);
	//
	//A b(10); // 1번 생성자

	//A b(10, 0.1); // 2번 생성자

	//Num3 test;
}

void Foo(A a)
{
	std::cout << "Foo";
}


// 클래스의 필드를 private으로 사용하는 이유
// 1. 데이터 은닉에 위반 => 객체지향적 설계에 맞지 않음.
//    - 데이터 은닉(Data Hiding) : 구현 세부 사항에 사용되는 데이터를 외부에 노출하지 않는 것
// 2. 디버깅이 어려워짐.
// 3. 확장성이 떨어짐.