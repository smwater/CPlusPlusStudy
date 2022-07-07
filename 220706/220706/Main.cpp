#include "Set.h"
#include <initializer_list>
#include <iostream>

using namespace std;

int main()
{
	/*auto initList = { 10, 5, 1, 6, 17, 14, 21 };

	Set s;
	for (int elem : initList)
		s.insert(elem);

	cout << "레벨 순회\n";
	s.traverseByLevelorder();

	cout << "\n전위 순회\n";
	s.traverseByPreorder();

	cout << "\n중위 순회\n";
	s.traverseByInorder();

	cout << "\n후위 순회\n";
	s.traverseByPostorder();*/

	Set s;

	s.insert(10);
	s.insert(14);
	s.insert(2);
	s.insert(4);
	s.insert(17);

	s.erase(17);
	s.traverseByInorder();
}