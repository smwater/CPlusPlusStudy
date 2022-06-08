#include "COTEVector.h"

#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	MyVector v(10);

	assert(v.GetCapacity() == 10);
	assert(v.GetSize() == 0);

	v.Add(1);
	v.Add(2);
	v.Add(3);
	v.Add(4);
	assert(v.GetSize() == 4);

	v.TrimToSize();
	assert(v.GetSize() == v.GetCapacity());

	assert(nullptr == v.FindById(5));
	assert(nullptr != v.FindById(3));

	v.Add(1); v.Add(1); v.Add(1);
	v.RemoveAll(1);
	assert(nullptr == v.FindById(1));
	assert(v.GetSize() == 3);
}