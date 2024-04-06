#pragma once
#include "TList.h"

template <class T>
class THeadList : public TList<T> {
protected:
	TNode<T>* pHead;
public:
	THeadList() {
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pFirst = pPr = pCurr = pLast = pHead;
		pos = -1;
		len = 0;
	}

	THeadList(const THeadList<T>& List)//Конструктор копирования
	{
		TNode<T>* tmp = List.pFirst, * curr;

		while (tmp != List.pStop)
		{
			curr = new TNode<T>;
			curr->value = tmp->value;
			if (pFirst == pStop)
			{
				pFirst = curr;
				pLast = curr;
			}
			else
			{
				pLast->pNext = curr;
				pLast = curr;
			}

			tmp = tmp->pNext;
		}
		pHead = new TNode<T>;
		pHead->pNext = pFirst;
		len = List.len;
		TList<T>::Reset();
	}

	inline THeadList<T>& operator=(const THeadList<T>& List)
	{
		if (List.pFirst == nullptr)
		{
			TList<T>::DelList();
		}
		else
		{
			TList<T>::DelList();
			TNode<T>* tmp = List.pFirst, * curr;
			while (tmp != nullptr)
			{
				curr = new TNode<T>;
				curr->value = tmp->value;
				if (pFirst == nullptr)
				{
					pFirst = curr;
					pLast = curr;
				}
				else
				{
					pLast->pNext = curr;
					pLast = curr;
				}
				tmp = tmp->pNext;
			}
			len = List.len;
			pHead->pNext = pFirst;
			TList<T>::Reset();
		}
		return *this;
	}
	void InsFirst(const T& _val) override{
		TList<T>::InsFirst(_val);
		pHead->pNext = pFirst;
	}

	void DelFirst() override {
		TList<T>::DelFirst();
		pHead->pNext = pFirst;
	}

	~THeadList() {
		TList<T>::DelList();
		delete pHead;
	}
};