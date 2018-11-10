#ifndef _QUEUE_
#define _QUEUE_

#include <stdexcept>

class Queue
{
public:


	Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	~Queue();

	void Push(int element);
	void Pop();
	int Peek() const;


private:

	struct Box
	{
		int data;
		Box* next;

		Box(int data, Box* next = nullptr)
			:data(data)
			, next(next)
		{}
	};

	int size;

	Box* first;
	Box* last;

	void Copy(const Queue& other);
	void Clear();

};


#endif // !_QUEUE_
