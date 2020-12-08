#pragma once
#include "Stack.h"
template<class A>
class TQueue : public TStack<A>
{
protected:
	int head, count;

public:
	TQueue() :TStack<A>() { head = 0; count = 0; }
	TQueue(TQueue& _q) :TStack<A>(_q) { head = _q.head; count = _q.count; }
	TQueue(int _size) :TStack<A>(_size) { head = 0; count = 0; }
	TQueue(const std::initializer_list<A>& list) :TStack<A>(list) { head = 0; this->tail = 0; count = this->size; }
	~TQueue() { head = 0; count = 0; }

	void push(A elem)
	{
		if (this->IsFull())
			throw logic_error("queue full");
		count++;
		this->arr[this->tail] = elem;
		this->tail = (this->tail + 1) % this->size;
	}

	A pop()
	{
		if (this->IsEmpty())
			throw logic_error("queue empty");
		count--;
		A temp = this->arr[head];
		head = (head + 1) % this->size;
		return temp;
	}

	bool IsFull()
	{
		if (count == size)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& ostr, const TQueue<A>& lhs)
	{
		if (lhs.tail == lhs.head)
			for (int i = lhs.head; i < lhs.size; i++)
				ostr << lhs.arr[i] << ' ';
		else
			if (lhs.tail > lhs.head)
				for (int i = lhs.head; i < lhs.tail; i++)
					ostr << lhs.arr[i] << ' ';
			else
			{
				int t = lhs.tail + lhs.head + lhs.head + 1;
				for (int i = lhs.head; i < t; i++)
					ostr << lhs.arr[i % lhs.size] << ' ';
			}
		return ostr;
	}

	//extra

	A find_max_odd()
	{
		TQueue<A> t(*this);
		A max = -1;
		for (int i = 0; i < count; i++)
		{
			A temp = t.pop();
			if ((temp > max) && (temp % 2 == 0))
				max = temp;
		}

		return max;
	}

	void cleanse(A value)
	{
		TQueue<A> t(count);
		int old_head = head;
		int old_count = count;

		for (int i = 0; i < old_count; i++)
		{
			A temp = pop();
			if (temp % value != 0)
				t.push(temp);
		}

		head = old_head;
		tail = head;
		old_count = t.count;

		for (int i = 0; i < old_count; i++)
		{
			A temp = t.pop();
			push(temp);
		}
	}

	TStack<A> transform()
	{
		TQueue<A> t(*this);
		TStack<A> result(this->size);
		
		for (int i = 0; i < this->count; i++)
			result.push(t.pop());

		return result;
	}
};
