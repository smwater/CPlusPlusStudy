#include "Set.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main()
{
	auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
		s.insert(elem);

	cout << "���� ��ȸ\n";
	s.traverseByLevelorder();

	cout << "\n���� ��ȸ\n";
	s.traverseByPreorder();

	cout << "\n���� ��ȸ\n";
	s.traverseByInorder();

	cout << "\n���� ��ȸ\n";
	s.traverseByPostorder();
}