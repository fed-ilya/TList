#pragma once
#include <iostream>

template<class T>
struct TNode {
	T val;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};

template<class T>
class TList {
protected:
	TNode<T> * pFirst, * pLast, * pCurr, * pStop, * pPr;
	int pos, len;
public:
	TList();
	TList(const TList<T>& List);
	~TList();
	inline virtual void Reset();  //Установка pCurr на начало
	virtual void GoNext(); //Перейти к следующему элементу
	virtual bool IsEnd();  //Находится ли pCurr в конце
	virtual void InsFirst(T _val); //Добавить элемент в начало
	virtual void InsCurr(T _val); //Добавить после последнего
	virtual void InsLast(T _val); //Добавить перед текущим
	virtual void DelFirst();
	virtual void DelCurr();
	virtual void DelLast();
	virtual void DelList();
	virtual T GetPosValue(int ind);
	void SetPos(int _pos);
	void Set_val(T item);
	T Get_First();
	virtual T GetCurrentItem();
	T Get_Last();
	T Get_pos();
	T Get_length();
	inline TList<T>& operator=(const TList<T>& List);
	friend std::ostream& operator <<(std::ostream& out, const TList<T>& list);
	friend std::ostream& operator >>(std::ostream& out, const TList<T> List);
};