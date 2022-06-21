#include "ForwardList.h"
#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> flist;	// 기본
	ForwardList mylist;				// 구현

	flist.push_front(1);	// [1]
	flist.push_front(2);	// [2] [1]
	std::forward_list<int>::iterator iter = flist.begin();
	++iter;
	flist.insert_after(iter, 3);	// [2] [1] [3]

	mylist.push_front(1);	// [1]
	ForwardList::iterator myiter = mylist.insert_after(mylist.begin(), 2);	// [1] [2] 
	mylist.insert_after(myiter, 3);	// [1] [2] [3]

	std::forward_list<int> flist2;
	ForwardList mylist2;

	flist2.push_front(1);		// [1]
	mylist2.push_front(1);		// [1]
	
	if (mylist.compareForward_list(flist))
	{
		std::cout << "mylist와 flist의 모든 원소는 같다.\n";
	}
	else
	{
		std::cout << "mylist와 flist의 모든 원소는 같지 않다.\n";
	}

	if (mylist2.compareForward_list(flist2))
	{
		std::cout << "mylist2와 flist2의 모든 원소는 같다.\n";
	}
	else
	{
		std::cout << "mylist2와 flist2의 모든 원소는 같지 않다.\n";
	}

	while (!(flist.empty() && mylist.empty()))
	{
		if (flist.front() == mylist.front())
		{
			std::cout << "같음\n";
		}
		else
		{
			std::cout << "다름\n";
		}

		flist.pop_front();
		mylist.pop_front();
	}
}