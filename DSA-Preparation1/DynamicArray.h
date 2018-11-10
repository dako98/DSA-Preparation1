#ifndef _DYNAMIC_ARRAY_
#define _DYNAMIC_ARRAY_


template <class T>
class DynamicArray
{
public:

	DynamicArray();
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();


	T& operator[](int index);
	const T& operator[](int index) const;

	void PushBack(const T& element);
	void PopBack();
	void InsertAfter(const T& element, int index);
	void RemoveAt(int index);

	size_t GetSize() const;
		
private:

	void Copy(const DynamicArray& other);
	void Clear();
	
	void Resize();

	T** elements;

	size_t size;
	size_t capacity;

};


template <class T>
DynamicArray<T>::DynamicArray()
	:size(0)
	, capacity(2)
{
	elements = new T*[capacity];

	for (size_t i = 0; i < capacity; i++)
		elements[i] = nullptr;
}

template<class T>
inline DynamicArray<T>::DynamicArray(const DynamicArray & other)
{
	Copy(other);
}

template<class T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray & other)
{
	if (this!=&other)
	{
		Clear();
		Copy(other);
	}
	return *this;
}

template<class T>
inline DynamicArray<T>::~DynamicArray()
{
	Clear();
}

template<class T>
inline T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index > size)
	{
		throw std::out_of_range("Out of range.");
	}

	return *elements[index];
}

template<class T>
inline const T& DynamicArray<T>::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Out of range.")
	}
	return *elements[index];
}

template<class T>
inline void DynamicArray<T>::PushBack(const T & element)
{
	if (size == capacity)
		Resize();

	elements[size] = new T(element);
	++size;
}

template<class T>
inline void DynamicArray<T>::PopBack()
{
	delete elements[size];
	elements[size] = nullptr;
	--size;
}

template<class T>
inline void DynamicArray<T>::InsertAfter(const T& element, int index)
{
	if (size == capacity)
		Resize();

	for (size_t i = size; i > index; i--)
	{
		elements[i] = elements[i - 1];
	}
	elements[index] = new T(element);

	size++;
}

template<class T>
inline void DynamicArray<T>::RemoveAt(int index)
{
	delete elements[index];

	for (size_t i = index; i < size-1; i++)
	{
		elements[i] = elements[i + 1];
	}
	size--;
}

template<class T>
inline size_t DynamicArray<T>::GetSize() const
{
	return size;
}

template<class T>
inline void DynamicArray<T>::Copy(const DynamicArray & other)
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->elements = new T*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		this->elements[i] = new T(*other.elements[i]);
	}
}

template<class T>
inline void DynamicArray<T>::Clear()
{
	for (size_t i = 0; i < size; i++)
	{
		delete elements[i];
	}
	delete[] elements;
}

template<class T>
inline void DynamicArray<T>::Resize()
{
	T** temp = new T*[capacity *= 2];

	for (size_t i = 0; i < size; i++)
		temp[i] = elements[i];

	for (size_t i = size; i < capacity; i++)
		temp[i] = nullptr;

	delete[] elements;

	elements = temp;
	temp = nullptr;
}


#endif // !_DYNAMIC_ARRAY_
