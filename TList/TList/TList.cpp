#include "TList.h"

template<class T>
TList<T>::TList() {
	pFirst = nullptr; pLast = nullptr; pStop = nullptr; pCurr = nullptr; pPr = nullptr;
	pos = -1;
	len = 0;
}

template<class T>
inline void TList<T>::Reset() {
	pCurr = pFirst; pPr = pStop; pos = 0;
}

template<class T>
void TList<T>::GoNext() {
	if (pCurr != pStop) {
		pPr = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	else {
		throw "This List is empty or current is not detected!"
	}
}

template<class T>
bool TList<T>::IsEnd() {
	return (pCurr == pStop);
}

template<class T>
void TList<T>::InsFirst(T _val) {
	if (pFirst == pStop)
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->value = _val;
		tmp->pNext = pFirst;//////
		pFirst = tmp;
		pLast = tmp;
		len++;
	}
	else {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = pFirst;
		if (pFirst == pCurr) pPr = tmp;
		pFirst = tmp;
		len++
	}
}

template<class T>
inline void TList<T>::InsCurr(T _val) {
	if (pCurr == pFirst) InsFirst(_val);
	else if (pCurr == pLast) InsLast(_val);
	else {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pPr->pNext = tmp;
		tmp->pNext = pCurr;
		pPr = tmp;
		++len;
		++pos;
	}
}

template<class T>
void TList<T>::InsLast(T _val) {
	if (pFirst == pStop)
	{
		InsFirst(_val);
	}
	else
	{
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		tmp->pNext = PStop;
		pLast.pNext = tmp;
		PLast = tmp;
	}
}

template<class T>
void TList<T>::DelFirst() { //?
	if (pFirst != pStop)
	{
		TNode<T>* tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
		len--;
	}
	else
	{
		throw "This List is empty!";

	}
}

template<class T>
void TList<T>::DelLast() { //?
	if (!IsEnd) {
		delete pLast;
		pLast = pStop;
	}
}

template<class T>
void TList<T>::DelCurr() {
	if (pCurr != pStop) {
		if (pCurr == pFirst) DelFirst();
		else if (pCurr == pLast) DelLast;
		else {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			--len;
		}
	}
}

template<class T>
void TList<T>::DelList() {
	TNode<T>* tmp = pFirst;
	while (pFirst != pStop) {
		tmp = pFirst;
		pFirst = pFirst->pNext;
		delete tmp;
	}
}

template<class T>
void TList<T>::SetPos(int _pos) {
	pos = _pos;
	pPr = pCurr;
	pCurr = pCurr->pNext;
}