#include "TList.h"

template<class T>
TList<T>::TList() {
	pFirst = nullptr; pLast = nullptr; pStop = nullptr; pCurr = nullptr; pPr = nullptr;
	pos = -1;
	len = 0;
}

template<class T>
TList<T>::TList(const TList<T>& List) {
	TNode<T>* tmp = List.pFirst, * Curr;
	while (tmp != List.pStop) {
		Curr = new TNode<T>;
		Curr->val = tmp->val;
		if (pFirst == pStop) {
			pFirst = Curr;
			pLast = Curr;
		}
		else {
			pLast->pNext = Curr;
			pLast = Curr;
		}
		tmp = tmp->pNext;
	}
	len = List.len;
	Reset();
}

template<class T>
TList<T>::~TList() { DelList(); };

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
		throw "This List is empty or current is not detected!";
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
		tmp->pNext = pFirst;
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
		len++;
	}
}

template<class T>
inline void TList<T>::InsCurr(T _val) {
	if (len == 0) {
		InsFirst(_val);
	}
	else {
		if (pCurr == pFirst) { 
			InsFirst(_val);
			pPr = pFirst;
		}
		else if (pCurr == pStop && pPr == pLast) {
			InsLast(_val);
			pPr = pLast;
		}
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
		tmp->pNext = pStop;
		pLast.pNext = tmp;
		pLast = tmp;
		len++;
	}
}

template<class T>
void TList<T>::DelFirst() {
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
	if (!IsEnd()) {
		delete pLast;
		pLast = pStop;
	}
}

template<class T>
void TList<T>::DelCurr() {
	if (pCurr != pStop) {
		if (pCurr == pFirst) DelFirst();
		else if (pCurr == pLast) DelLast();
		else {
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			--len;
		}
	}
	else {
		TNode<T>* tmp = pCurr;
		pCurr = pCurr->pNext;
		pPr->pNext = pCurr;
		delete tmp;
		len--;
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
	len = 0;
	pos = -1;
}

template<class T>
T TList<T>::GetPosValue(int ind)
{
	if (ind >= len && ind < 0)
	{
		throw "Incorrect index";
	}
	Reset();

	while (ind != pos)
	{
		GoNext();

	}
	return (pCurr->value);
}

template<class T>
void TList<T>::SetPos(int _pos) {
	if (_pos < 0 || _pos >= len) {
		throw "Incorrect Pos";
	}
	Reset();
	else {
		for (int i = 0; i < _pos; ++i) {
			GoNext();
		}
	}
}

template<class T>
void TList<T>::Set_val(T item)
{
	pCurr->value = item;
}

template<class T>
T TList<T>::Get_First()
{
	return pFirst->value;
}

template<class T>
T TList<T>::GetCurrentItem()
{
	if (pCurr == pStop)
	{
		throw "Error";

	}
	return pCurr->value;
}

template<class T>
T TList<T>::Get_Last()
{
	return pLast->value;
}

template<class T>
T TList<T>::Get_pos()
{
	return pos;
}

template<class T>
T TList<T>::Get_length()
{
	return len;
}

template<class T>
bool Is_Empty()
{
	return (pFirst == pStop);
}

template<class T>
inline TList<T>& TList<T>::operator=(const TList<T>& list_object)
{
	if (list_object.pFirst == nullptr)
	{
		DelList();
	}
	else
	{
		DelList();
		TNode<T>* tmp = list_object.pFirst, * curr;
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
		len = list_object.len;

		Reset();
	}
	return *this;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const TList<T>& list) {
	TList<T> copyList = list;
	copyList.Reset();

	while (!copyList.IsEnd())
	{
		T value = copyList.GetPosValue(copyList.GetPos());
		out << value << " ";
		copyList.GoNext();
	}

	return out;

}

template<class T>
std::ostream& operator >>(std::ostream& in, const TList<T> List) {
	T value;
	in >> value;
	List.InsCurr(value);
	return in;
}