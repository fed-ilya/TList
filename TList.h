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