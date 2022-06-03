#include <iostream>

class A
{
public:
	A() { std::cout << "Constructor"; }
	~A() { std::cout << "Destructor"; }
};

int main()
{
	int* p = new int;
	delete p;

	p = new int[3];
	delete[] p;

	A* a = new A();
	delete a;

	return 0;
}