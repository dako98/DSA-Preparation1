#ifndef _LIST_
#define _LIST_




class List
{
public:

	List();
	List(const List& other);
	List& operator=(const List& other);
	~List();


	void PushFront(int element);
	void PushBack(int element);

	void PopFront();
	void PopBack();

	bool Exists(int data);
	void RemoveAfter(int data);


private:

	struct Box
	{
		Box(int data, Box* next = nullptr)
			:data(data)
			, next(next)
		{ }

		int data;
		Box* next;
	};

	void Copy(const List& other);
	void Clear();

	Box* head;
	Box* tail;
};

#endif // !__List__