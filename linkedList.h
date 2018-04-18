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
	void insByTheta(point3D x);//顺序插入（按theta值）
	void append(point3D x);//在表的末尾插入点x
	void prt();
	void prtR();//逆序输出
	void prt4FMT();//以FMT需要的点集形式输出
	void prtR4FMT();
	void sortByZ();
private:
	node * head;	
};