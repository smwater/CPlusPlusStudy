#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	set<int> tree;
	tree.insert(1);

	int N;
	scanf("%d", &N);

	N--;
	while (N--)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		if (tree.contains(node1))
		{
			set<int>::iterator iter = tree.find(node1);
			tree.insert(iter, node2);
		}
		else if (tree.contains(node2))
		{
			set<int>::iterator iter = tree.find(node2);
			tree.insert(iter, node1);
		}
	}

	int size = tree.size() - 1;
	while (size--)
	{

	}
}