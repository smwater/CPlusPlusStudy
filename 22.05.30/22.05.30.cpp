#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base 생성\n"; }
	~Base() { std::cout << "Base 소멸\n"; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived 생성\n"; }
	~Derived() { std::cout << "Derived 소멸\n"; }
};

int main()
{
	Derived d;
}