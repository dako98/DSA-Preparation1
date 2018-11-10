#ifndef _FORWARD_LIST_
#define _FORWARD_LIST_


class ForwardList
{
public:

	ForwardList();
	ForwardList(const ForwardList& other);
	ForwardList& operator=(const ForwardList& other);
	~ForwardList();


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

	void Copy(const ForwardList& other);
	void Clear();

	Box* head;
	Box* tail;
}
#endif // !_FORWARD_LIST_
