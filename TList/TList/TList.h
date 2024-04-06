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
	//������� ��������(�� �����������) ����� ������� ������������
	inline virtual void Reset();  //��������� pCurr �� ������
	virtual void GoNext(); //������� � ���������� ��������
	virtual bool IsEnd();  //��������� �� pCurr � �����
	virtual void InsFirst(T _val); //�������� ������� � ������
	virtual void InsCurr(T _val); //�������� ����� ����������
	virtual void InsLast(T _val); //�������� ����� �������
	virtual void DelFirst();
	virtual void DelCurr();
	virtual void DelLast();
	virtual void DelList();
	void SetPos(int _pos);
};