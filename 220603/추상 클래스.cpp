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
	void Foo() { std::cout << "¹ÙºÎ\n"; }
};

Abstract a;
Base b;
Derived d;