#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	: Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::~Set()
{
	clear();

	delete _head;
	_head = nullptr;
}

int Set::height() const
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	int height = -1;
	while (false == q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node* node = q.front();
			q.pop();

			if (node->Left)
			{
				q.push(node->Left);
			}

			if (node->Right)
			{
				q.push(node->Right);
			}
		}

		++height;
	}

	return height;
}

int Set::height2() const
{
	if (_head->Parent == nullptr)
	{
		return -1;
	}

	return heightHelper(_head->Parent);
}

int Set::heightHelper(Node* node) const
{
	int height = 0;

	if (node->Left)
	{
		height = 1 + heightHelper(node->Left);
	}

	if (node->Right)
	{
		height = std::max(height, 1 + heightHelper(node->Right));
	}

	return height;
}

bool Set::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Set::size() const
{
	return _size;
}

void Set::clear()
{
	while (false == empty())
	{
		erase(_head->Parent);
	}
}

bool Set::insert(int value)
{
	// 1. �� ��� ����
	Node* newNode = new Node(value);

	// 2. ��Ʈ ��尡 ���� ��� ��Ʈ ��� ����
	if (_head->Parent == nullptr)
	{
		_head->Parent = newNode;
		newNode->Parent = _head;

		++_size;

		return true;
	}

	// 3. ���Ե� ��ġ�� �θ� ��� ã��.
	Node* parent = nullptr;
	Node* p = _head->Parent;

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}

	// 4. ���ο� ��� ����
	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}
	newNode->Parent = parent;

	++_size;

	return true;
}

void Set::erase(int value)
{
	// 1. value�� ��ġ�� ��带 ã��
	Node* removedNode = find(value);
	if (removedNode == nullptr)
	{
		return;
	}

	// 2. �ش� ��带 �����.
	erase(removedNode);
}

void Set::erase(Node* pos)
{
	// 1. �ڽ��� �� �� ���� ��
	if (pos->Left && pos->Right)
	{
		// 1-1. �ļ� ��带 �����ؾ���.
		Node* successor = pos->Right;

		while (successor->Left)
		{
			successor = successor->Left;
		}

		// 1-2. �ļ� ����� �����Ϳ� �����Ѵ�.
		pos->Data = successor->Data;

		// 1-3. �ļ� ��带 �����.
		erase(successor);

		return;
	}

	// 2. �ڽ��� �� �ʸ� ���� �� or �� �� ���ٸ�
	// 2-1. ���� ���� �θ��� ���ʿ� ��ġ�ϴ���, �����ʿ� ��ġ�ϴ��� �ľ��Ѵ�.	
	Node** child = nullptr;
	// 2-1-1. ������� �ϴ� ��尡 ��Ʈ ����� ���
	if (pos == _head->Parent)
	{
		child = &_head->Parent;
	}
	// 2-1-2. ���� ������ ���
	else if (pos->Data < pos->Parent->Data)
	{
		child = &pos->Parent->Left;
	}
	// 2-1-3. ���� �������� ���
	else
	{
		child = &pos->Parent->Right;
	}

	// 2-2. �θ�� �ڽ��� �����Ѵ�.
	*child = nullptr;
	if (pos->Left)
	{
		*child = pos->Left;
		pos->Left->Parent = pos->Parent;
	}
	else if (pos->Right)
	{
		*child = pos->Right;
		pos->Right->Parent = pos->Parent;
	}
	
	delete pos;
	pos = nullptr;

	--_size;

	// 4. pos�� ��Ʈ ����� ��
	// 4-1. ���� �ڽĸ� ���� ��
	// 4-2. ������ �ڽĸ� ���� ��
	// 4-3. �� �� ���� ��
}

Set::Node* Set::find(int value) const
{
	Node* result = _head->Parent;

	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if (result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}

	return result;
}

void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

void Set::traverseByLevelorder() const
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	while (q.empty() == false)
	{
		Node* node = q.front();
		q.pop();

		std::cout << node->Data << "->";

		if (node->Left)
		{
			q.push(node->Left);
		}
		if (node->Right)
		{
			q.push(node->Right);
		}
	}
}

void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}

void Set::traverseByInorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}

void Set::traverseByPostorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}

	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}
