#include "ForwardList.h"
#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> flist;	// �⺻
	ForwardList mylist;				// ����

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
		std::cout << "mylist�� flist�� ��� ���Ҵ� ����.\n";
	}
	else
	{
		std::cout << "mylist�� flist�� ��� ���Ҵ� ���� �ʴ�.\n";
	}

	if (mylist2.compareForward_list(flist2))
	{
		std::cout << "mylist2�� flist2�� ��� ���Ҵ� ����.\n";
	}
	else
	{
		std::cout << "mylist2�� flist2�� ��� ���Ҵ� ���� �ʴ�.\n";
	}

	while (!(flist.empty() && mylist.empty()))
	{
		if (flist.front() == mylist.front())
		{
			std::cout << "����\n";
		}
		else
		{
			std::cout << "�ٸ�\n";
		}

		flist.pop_front();
		mylist.pop_front();
	}
}