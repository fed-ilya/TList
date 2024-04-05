#include "TList.h"

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
}

template<class T>
bool TList<T>::IsEnd() {
	return (pCurr == pStop);
}

template<class T>
void TList<T>::InsFirst(T _val) {
	TNode<T>* tmp = new TNode<T>;
	tmp->val = _val;
	tmp->pNext = pFirst;
	if (pFirst == pCurr) pPr = tmp;
	pFirst = tmp;
}

template<class T>
inline void TList<T>::InsCurr(T _val) {
	if (pCurr == pFirst) InsFirst(_val);
	else if (pCurr == pLast) InsLast(_val);
	else {
		TNode<T>* tmp = new TNode<T>;
		tmp->val = _val;
		pPr.pNext = tmp;
		tmp->pNext = pCurr;
		pPr = tmp;
		++len;
		++pos;
	}
}

template<class T>
void TList<T>::InsLast(T _val) {
	TNode<T>* tmp = new TNode<T>;
	tmp->val = _val;
	tmp->pNext = PStop;
	pLast.pNext = tmp;
	PLast = tmp;
}

template<class T>
void TList<T>::DelFirst() { //?
	TNode<T>* tmp;
	tmp = pFirst->pNext;
	delete pFirst;
	pFirst = tmp;
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