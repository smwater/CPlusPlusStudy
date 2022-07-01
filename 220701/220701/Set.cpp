#include "Set.h"

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::Node::~Node()
{
	Parent	= nullptr;
	Left	= nullptr;
	Right	= nullptr;
}

bool Set::Node::IsLeaf() const
{
	if (Left == nullptr && Right == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
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

std::pair<Set::Node*, bool> Set::insert(int value)
{
	if (empty())
	{
		_root = new Node(value);
		++_size;

		return std::make_pair(_root, true);
	}

	// ���� �˻� Ʈ�� : ���� ���� Ʈ���� �ڱ⺸�� ���� ��, ������ ���� Ʈ���� �ڱ⺸�� ū ��.
	Node* currentNode = _root;
	Node* prevNode = nullptr;

	while (currentNode)
	{
		prevNode = currentNode;
		
		// ���� �˻� ����.
		if (currentNode->Data == value)
		{
			return std::make_pair(currentNode, false);
		}
		else if (currentNode->Data < value)
		{
			currentNode = currentNode->Right;
		}
		else
		{
			currentNode = currentNode->Left;
		}
	}

	currentNode = new Node(value, prevNode);

	// currentNode�� prevNode�� ���� �ڽ����� ������ ���� ������ �ڽ����� ������ ����?
	if (prevNode->Data < value)
	{
		prevNode->Right = currentNode;
	}
	else
	{
		prevNode->Left = currentNode;
	}

	++_size;

	return std::make_pair(currentNode, true);
}

void Set::erase(Node* pos)
{
	// 1. pos�� _head���?
	if (pos->Parent == nullptr)
	{
		// 1. �ڽ��� ���ٸ�?
		if (pos->IsLeaf())
		{
			_root = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 2. ���� �ڽĸ� �ִٸ�?
		if (pos->Right == nullptr)
		{
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;
			
			--_size;

			return;
		}

		// 3. ������ �ڽĸ� �ִٸ�?
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 4. �� �� �ִٸ�?
		if (pos->Left != nullptr && pos->Right != nullptr)
		{

		}
	}

	// 2. pos�� ���� �����?

	// 3. pos�� ���� �ڽĸ� �ִٸ�?

	// 4. pos�� ������ �ڽĸ� �ִٸ�?

	// 5. pos�� �ڽ��� �� �� ������ �ִٸ�?
}