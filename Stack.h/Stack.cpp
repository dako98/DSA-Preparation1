#include "Stack.h"

Stack::Stack()
	:size(0)
	, capacity(2)
	, elements(nullptr)
{
	elements = new int[capacity];
}

Stack::Stack(const Stack & other)
{
	Copy(other);
}

Stack & Stack::operator=(const Stack & other)
{
	if (this!=&other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

Stack::~Stack()
{
	Clear();
}

void Stack::Push(int newElement)
{
	if (size == capacity)
		Resize();

	elements[size] = newElement;
	++size;
}

void Stack::Pop()
{
	--size;
}

int Stack::Peek() const
{
	if (size > 0)
	{
		return elements[size - 1];
	}
	throw std::logic_error("Stack is empty.");
}

void Stack::Resize()
{
	int* tmp = new int[capacity *= 2];

	for (size_t i = 0; i < size; i++)
		tmp[i] = elements[i];
	
	delete[] elements;

	elements = tmp;
}

void Stack::Copy(const Stack & other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	for (size_t i = 0; i < other.size; i++)
		this->elements[i] = other.elements[i];
}

void Stack::Clear()
{
	delete[] elements;
	size = 0;
	capacity = 0;
}
