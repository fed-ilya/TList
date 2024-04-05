#pragma once

#include <iostream>
using namespace std;

template<class T>
struct TNode {
	T val;
	TNode<T>* pNext;
};

template<class T>
class TList {
protected:
	TNode<T>* pPr, * pFirst, * pCurr, * pLast, * pStop;
	int pos, len;
public:
	//Функции удаления(мб добалвления) нужно сделать виртуальными
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
	void SetPos(int _pos);
};