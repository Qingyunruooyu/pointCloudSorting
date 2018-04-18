#include "linkedList.h"
using namespace std;
double point3D::tol = 1.3e-4;

//按z坐标升序排序
void linkedList::sortByZ(){
	if (head == NULL || head->next == NULL)return;
	node*first = head;
	node*last = head->next;
	//	int i = 0;
	bool exchanged = false;
	while (last->next != NULL){
//		prt();
		//cout << endl;
		node*p = last->next;//first到last是一个排好了的区间，p是区间后面第一个节点
				//int j = 0;

		//如果比最大的都大，说明已经是有序的了，如果比最大的小，则前面还有可能有比p小的
		if (p->d >= last->d){
			last = last->next;
			continue;
		}

		//itr作为迭代子，从区间最后一个节点到第一个节点遍历，与p比较，发现比p小的节点，就把p插在它后面
		for (node *itr = last; itr != first; itr = itr->prev){
						//++j;
			if (p->d >= itr->d ){//找到第一个p->d 大于等于 itr->d，或者p->d 比第一个节点都小，交换p、itr节点
				cout << "节点" << p->d.z()<<"置后于" << itr->d.z()<<endl;

				last->next = p->next;//删除原位置上的p
				if (p->next){ p->next->prev = last; }
				p->next = itr->next;
				itr->next->prev = p;
				itr->next = p;
				p->prev = itr;
				exchanged = true;
				break;
			}
			else if (itr->prev == first && p->d < itr->d){
				cout << "节点" << p->d.z() << "置顶" << endl;
				last->next = p->next;//删除原位置上的p
				if (p->next){ p->next->prev = last; }
				p->next = itr;//将p插入到第一个比它小的节点的前面
				p->prev = itr->prev;
				itr->prev->next = p;
				itr->prev = p;
				exchanged = true;
				break;

			}
		}
				//cout << "比较了" << j << "次\n";
		//		++i;
		if (exchanged){//如果交换过数据的话，last的下一个节点就是新节点，不需要移动last
			exchanged = false;
			continue;
		}
		last = last->next;//移动last
	}
	//cout << "循环了" << i << "次\n";
	/*prt();
	prtR();*/
}
/***********备注：写这个函数的时候太毛躁了，以至于浪费了不少时间************
************一个是排序的时候，比最后一个大了肯定比前面所有的大**************
************是对的，但是比最后一个小了，还有可能比前面的小啊，**************
************if (p->d > itr->d) 一开始 不等号写反了，导致最**************
************小的数不能跑到最前面去，另一个是调试的时候，实验数*************
************剧比较不好看，为什么一开始不考虑自己编一组直观一点*************
************的、少一点的数据来测试呢？*********************************
************收获是对静态成员、操作符重载、双链表的熟悉********************/


void linkedList::prt(){
	node*p = head;
	//int i = 0;
	while (p->next != NULL){
		cout << "(" << p->next->d.r() << "," << p->next->d.t() << "," << p->next->d.z() << ") (" <<
			p->next->d.x() << "," << p->next->d.y() << "," << p->next->d.z() << ")" << endl;
		p = p->next;
//		++i;
	}
	//cout << "循环了" << i << "次\n";
}

void linkedList::prt4FMT(){
	node *p = head;
	if (!p) return;
	cout << "PROGRAM mainfunction(); \n"
		"\tUSES ORDERS;\n\tTYPE\n\t\tFEATURE = INTEGER;\nBEGIN\n\t\tNewPart('pointcloud.sat'); \n";
	cout << "Points('points: 159 ";
	while (p->next != NULL){
		cout << p->next->d.x() << " " << p->next->d.y() << " " << p->next->d.z() << " ";
		p = p->next;
	}
	cout /*<< head->next->d.x() << " " << head->next->d.y() << " " << head->next->d.z() */<< "');\n \t\tlines('line 0 0 159');";
	cout << "\n\t\tSavePartMatch('部件名','材料');//这个材料须为用户预设的材料，否则部件颜色会是默认"
		"\n\t\tEND.";
}

void linkedList::prtR(){
	node * p = head;
	if (!p) return;
	while (p->next != NULL){
		p = p->next;
	}
	while (p->prev != NULL){
		cout << "(" << p->d.r() << "," << p->d.t() << "," << p->d.z() << ") (" <<
			p->d.x() << "," << p->d.y() << "," << p->d.z() << ")" << endl;
		p = p->prev;
	}
}



//这个排序是不稳定的
void linkedList::insByTheta(point3D x){
	node *p = new node;
	p->d = x;
	if (head == NULL){
		head = new node;
		head->next = p;
		head->prev = NULL;
		p->prev = head;
		p->next = NULL;
		return;
	}
	node *q = head;
	while (q->next != NULL && q->next->d.t() < x.t()){//比较当前节点q的后面一个节点的theta与待插入点的theta大小关系
		q = q->next;
	}
	if (q->next == NULL){//移到了末尾了
		q->next = p;
		p->next = NULL;
		p->prev = q;
		return;
	}
	//在中间
	p->next = q->next;//将p点插在q后面，也就是插在第一个大于p点的theta的值的前面
	q->next->prev = p;
	q->next = p;
	p->prev = q;
}



void linkedList::append(point3D x){
	node *p = new node;
	p->d = x;
	p->next = NULL;
	if (head == NULL){
		head = new node;
		head->next = p;
		head->prev = NULL;
		p->prev = head;
		return;
	}
	node*q = head;
	while (q->next != NULL){
		q = q->next;
	}
	q->next = p;
	p->prev = q;
}
