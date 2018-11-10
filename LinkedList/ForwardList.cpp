#include "List.h"

List::List()
	:head(nullptr)
	,tail(nullptr)
{ }

List::List(const List & other)
{
	Copy(other);
}

List & List::operator=(const List & other)
{
	if (this!=&other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

List::~List()
{
	Clear();
}

void List::PushFront(int element)
{
	Box* newElement = new Box(element, head);

	if (head==nullptr)
		tail = newElement;

	head = newElement;
}

void List::PushBack(int element)
{
	if (tail != nullptr)
	{
		tail->next = new Box(element);
		tail = tail->next;
	}
	else
	{
		PushFront(element);
	}
}

void List::PopFront()
{
	if (head != nullptr)
	{
		if (head->next==nullptr)
		{
			delete head;

			head = nullptr;
			tail = nullptr;
			return;
		}
		Box* tmp = head;

		head = head->next;

		delete tmp;

	}
}

void List::PopBack()
{
	if (head != nullptr)
	{
		if (head->next == nullptr)
		{
			delete head;

			head = nullptr;
			tail = nullptr;
			return;
		}
		Box* current = head;

		while (current->next!=tail)
		{
			current = current->next;
		}
		delete tail;
		tail = current;
	}
}

bool List::Exists(int data)
{
	Box* current = head;
	while (current!=tail)
	{
		if (current->data==data)
		{
			return true;
		}
	}
	return false;
}

void List::RemoveAfter(int data)
{
	if (head!=nullptr)
	{
		if (head->next==nullptr)
		{
			PopFront();
		}
		else
		{
			Box* current= head;

			while (current->next !=nullptr)
			{
				if (current->data==data)
				{
					Box* tmp = current->next;

					current->next = tmp->next;

					delete tmp;
				}
			}
		}
	}
}

void List::Copy(const List & other)
{
	this->head = new Box(other.head->data);

	Box* write = other.head;
	Box* read = this->head;

	while (read->next != nullptr)
	{
		write->next = new Box(write->data);
		read = read->next;
		write = write->next;
	}

	this->tail = write;
}

void List::Clear()
{
	Box* current = head;
	
	while (head!=nullptr)
	{
		head = head->next;
		delete current;
		current = head;
	}
	head = nullptr;
	tail = nullptr;
}
