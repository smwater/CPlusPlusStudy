#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include "Heap.h"

using namespace std;

int main()
{
	Heap myheap = Heap();

	for (int num : {1, 2, 3, 4})
	{
		myheap.push(num);
	}

	while (false == myheap.empty())
	{
		cout << myheap.top() << " ";
		myheap.pop();
	}

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
}