#include "Queue.h"

Queue::Queue()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

Queue::Queue(const Queue & other)
{
	Copy(other);
}

Queue & Queue::operator=(const Queue & other)
{
	if (this!=&other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

Queue::~Queue()
{
	Clear();
}

void Queue::Push(int element)
{
	if (size==0)
	{
		first = new Box(element);
		last = first;
	}
}

void Queue::Pop()
{
	Box* tmp = first;
	first = first->next;
	delete first;
}

int Queue::Peek() const
{
	if (size > 0)
		return first->data;
	else
		throw std::logic_error("Queue is empty.");
}

void Queue::Copy(const Queue & other)
{
	if (size > 0)
	{
		first = new Box(other.first->data);

		Box* read = other.first;
		Box* write = this->first;

		while (read->next != nullptr)
		{
			read = read->next;
			write->next = new Box(read->data);
			write = write->next;
		}
	}
}

void Queue::Clear()
{
	if (size > 0)
	{
		Box* nextPtr = first;

		while (first != nullptr)
		{
			nextPtr = nextPtr->next;
			delete first;
			first = nextPtr;
		}
		first = nullptr;
		last = nullptr;
		size = 0;
	}
}
