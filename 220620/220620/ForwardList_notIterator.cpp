#include "ForwardList_notIterator.h"
#include <utility>

ForwardList::ForwardList()
{
	// _head -> []
	// _end -> []

	// [] -> []
	_head->Next = _end;
}

ForwardList::ForwardList(size_t count)
	: ForwardList()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

ForwardList::ForwardList(const ForwardList& other)
	:ForwardList()
{
	Node* inserted = before_begin();
	for (const Node* iter = other.before_begin(); iter != other.end(); iter->Next)
	{
		inserted = insert_after(inserted, iter->Data);
	}
}

ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}

	return *this;
}

ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;

	delete _end;
}

int& ForwardList::front()
{
	return begin()->Data;
}

const int& ForwardList::front() const
{
	return begin()->Data;
}

ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}

const ForwardList::Node* ForwardList::before_begin() const
{
	return _head;
}

ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}

const ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::Node* ForwardList::end()
{
	return _end;
}

const ForwardList::Node* ForwardList::end() const
{
	return _end;
}

ForwardList::Node* ForwardList::insert_after(const Node* pos, int value)
{
	// [] -> [] -> [] -> []
	//       pos
	//         value
	pos->Data;
	Node* newNode = new Node(value);
	Node* where = pos->Next;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::Node* ForwardList::erase_after(const Node* pos)
{
	if (empty())
	{
		return end();
	}

	// [] -> [] -> [] -> []
	//       pos
	Node* where = pos->Next;
	Node* removed = where->Next;

	where->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
}

void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	if (_head->Next == _end)	// if (begin() == end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ForwardList::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (const Node* iter = begin(); iter != end(); iter->Next)
	{
		if (iter->Data == value)
		{
			return true;
		}
	}

	return false;
}