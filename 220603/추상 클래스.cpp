#include <iostream>

class Abstract
{
	virtual void Foo() = 0;
};

class Base : Abstract
{

};

class Derived : Base
{
	void Foo() { std::cout << "�ٺ�\n"; }
};

Abstract a;
Base b;
Derived d;