#pragma once
#include <iostream>
#include "point3D.h"
struct node{
	point3D d;
	node * next;
	node * prev;
};

class linkedList{
public:
	linkedList(){ head = NULL; }
	void insByTheta(point3D x);//˳����루��thetaֵ��
	void append(point3D x);//�ڱ��ĩβ�����x
	void prt();
	void prtR();//�������
	void prt4FMT();//��FMT��Ҫ�ĵ㼯��ʽ���
	void prtR4FMT();
	void sortByZ();
private:
	node * head;	
};