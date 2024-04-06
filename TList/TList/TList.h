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