#ifndef _STACK_
#define _STACK_

#include <stdexcept>

class Stack
{
public:

	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	void Push(int newElement);
	void Pop();
	int Peek() const;


private:

	int* elements;

	int size;
	int capacity;

	void Resize();

	void Copy(const Stack& other);
	void Clear();


};

#endif // !_STACK_
