#pragma once
#include <iostream>
#include <cstdlib>
template <class T>
/*class Stack
{
	int size, MaxSize;
	T* mas;
public:
	Stack(int _MaxSize = 10)//констуктор
	{
		if (_MaxSize <= 0)
		{
			throw _MaxSize;
		}
		MaxSize = _MaxSize;
		mas = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++)
		{
			mas[i] = 0;
		}
		size = 0;
	}

	~Stack() //деструктор
	{
		size = 0;
		delete[] mas;
	}

	Stack(const Stack <T>& m)// конструктор копирования
	{
		MaxSize = m.MaxSize;
		mas = new T[MaxSize];
		size = m.size;
		for (int i = 0; i < size; i++)
		{
			mas[i] = m.mas[i];
		}
	}

	Stack& operator=(const Stack <T>& m)//присваивание
	{
		if (MaxSize != m.MaxSize)
		{
			delete[] mas;
			MaxSize = m.MaxSize;
			mas = new T[MaxSize];
		}
		size = m.size;
		for (int i = 0; i < size; i++)
		{
			mas[i] = m.mas[i];
		}
		return (*this);
	}

	bool Empty() //пустой стек
	{
		if (size == 0)
		{
		return true;
		}
		else return false;
	}

	bool Full() //полный стек
	{
		if (size == MaxSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(T a) //добавить в стек
	{
		if (Full())
		{
			throw 1;
		}
		mas[size] = a;
		size++;
	}

	T Pop() //удалить из стека
	{
		if (Empty())
		{
			throw 0;
		}
		size--;
		return mas[size];
	}

	T Top() //вершина
	{
		if (Empty())
		{
			throw 0;
		}
		return mas[size - 1];
	}

	void Clear()//очистка стека
	{
		size = 0;
	}
};

*/
struct TLink
{
	T val;
	TLink* pNext;
};
template <class T>
class TList
{
	TLink<T>* pFirst;
public:
	//конструктор
	TList()
	{
		pFirst = NULL;
	}
	
	int GetSize()//подсчет количества элементов в списке
	{
		TLink<T>* pCurrent=pFirst;
		int k = 0;
		while (pCurrent != NULL)
		{
			pCurrent = pCurrent->pNext;
			k++;
		}
		return k;
	}
	void InsFirst(T elem)//добавить новый элемент в начало списка
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	void InsLast(T elem)//последний элемент
	{
		TLink<T>* pCurr = pFirst;
		while (pCurr->pNext != NULL)
		{
			pCurr = pCurr->pNext;
		}
		TLink<T>* tmp = new TLink<T>;
		tmp->val = elem;
		tmp->pNext = NULL;
		pCurr->pNext = tmp;
	}
	void InsK(T elem, int k)//добавление в середину
	{
		TLink <T>* pCurr = pFirst;
		TLink<T>* tmp = new TLink<T>;
		for (int i = 0; i < k; i++)
		{
			pCurr = pCurr->pNext;
		}
		TLink<T>* _tmp = pCurr->pNext;
		pCurr->pNext = tmp;
		tmp->pNext = _tmp;
	}
};
template <class T>
class Stack
{
	TLink<T>* pFirst;
public:
	Stack()
	{

		pFirst = NULL;

	}
	void Push(T elem)
	{
		TLink<T>* tmp = new TLink<T>;
		tmp->val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
	T Pop()
	{
		if (pFirst == NULL)
		{
			throw NULL;
		}
		T tmp = pFirst->val;
		TLink<T>* t = pFirst;
		pFirst = pFirst->pNext;
		delete t;
		return tmp;
	}
	T Top()
	{

		if (pFirst == NULL)
		{
			throw NULL;
		}
	    return pFirst->val;

	}
	bool Empty()
	{
		return pFirst == 0;
	}
	bool Full()
	{
		if (Empty())
		{
			return false;
		}
		else return true;
	}
	~Stack()
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
	}
	Stack(const Stack<T>& s)
	{
		if (s.pFirst != NULL)
		{
			TLink<T>* prev = new TLink<T>;
			TLink<T>* tmp = s.pFirst;
			prev->val = s.pFirst->val;
			pFirst = prev;
			tmp = tmp->pNext;
			while (tmp != NULL)
			{
				TLink<T>* p = new TLink<T>;
				p->val = tmp->val;
				prev->pNext = p;
				prev = p;
				tmp = tmp->pNext;
			}
			prev->pNext = NULL;
		}
		else
			pFirst = NULL;
	}
	void Clear()
	{
		while (pFirst != NULL)
		{
			TLink<T>* tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
	}
	Stack& operator = (const Stack<T>& s)
	{
		if (s.pFirst != NULL)
		{
			while (pFirst != NULL)
			{
				TLink<T>* tmp = pFirst->pNext;
				delete pFirst;
				pFirst = tmp;
			}
			TLink<T>* prev = new TLink<T>;
			TLink<T>* tmp = s.pFirst;
			pFirst = prev;
			prev->val = s.pFirst->val;
			tmp = tmp->pNext;
			while (tmp != NULL)
			{
				TLink<T>* p = new TLink<T>;
				p->val = tmp->val;
				prev->pNext = p;
				prev = p;
				tmp = tmp->pNext;
			}
			prev->pNext = NULL;
		}
		else
			pFirst = NULL;
		return (*this);
	}

};