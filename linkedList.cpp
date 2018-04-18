#include "linkedList.h"
using namespace std;
double point3D::tol = 1.3e-4;

//��z������������
void linkedList::sortByZ(){
	if (head == NULL || head->next == NULL)return;
	node*first = head;
	node*last = head->next;
	//	int i = 0;
	bool exchanged = false;
	while (last->next != NULL){
//		prt();
		//cout << endl;
		node*p = last->next;//first��last��һ���ź��˵����䣬p����������һ���ڵ�
				//int j = 0;

		//��������Ķ���˵���Ѿ���������ˣ����������С����ǰ�滹�п����б�pС��
		if (p->d >= last->d){
			last = last->next;
			continue;
		}

		//itr��Ϊ�����ӣ����������һ���ڵ㵽��һ���ڵ��������p�Ƚϣ����ֱ�pС�Ľڵ㣬�Ͱ�p����������
		for (node *itr = last; itr != first; itr = itr->prev){
						//++j;
			if (p->d >= itr->d ){//�ҵ���һ��p->d ���ڵ��� itr->d������p->d �ȵ�һ���ڵ㶼С������p��itr�ڵ�
				cout << "�ڵ�" << p->d.z()<<"�ú���" << itr->d.z()<<endl;

				last->next = p->next;//ɾ��ԭλ���ϵ�p
				if (p->next){ p->next->prev = last; }
				p->next = itr->next;
				itr->next->prev = p;
				itr->next = p;
				p->prev = itr;
				exchanged = true;
				break;
			}
			else if (itr->prev == first && p->d < itr->d){
				cout << "�ڵ�" << p->d.z() << "�ö�" << endl;
				last->next = p->next;//ɾ��ԭλ���ϵ�p
				if (p->next){ p->next->prev = last; }
				p->next = itr;//��p���뵽��һ������С�Ľڵ��ǰ��
				p->prev = itr->prev;
				itr->prev->next = p;
				itr->prev = p;
				exchanged = true;
				break;

			}
		}
				//cout << "�Ƚ���" << j << "��\n";
		//		++i;
		if (exchanged){//������������ݵĻ���last����һ���ڵ�����½ڵ㣬����Ҫ�ƶ�last
			exchanged = false;
			continue;
		}
		last = last->next;//�ƶ�last
	}
	//cout << "ѭ����" << i << "��\n";
	/*prt();
	prtR();*/
}
/***********��ע��д���������ʱ��̫ë���ˣ��������˷��˲���ʱ��************
************һ���������ʱ�򣬱����һ�����˿϶���ǰ�����еĴ�**************
************�ǶԵģ����Ǳ����һ��С�ˣ����п��ܱ�ǰ���С����**************
************if (p->d > itr->d) һ��ʼ ���Ⱥ�д���ˣ�������**************
************С���������ܵ���ǰ��ȥ����һ���ǵ��Ե�ʱ��ʵ����*************
************��Ƚϲ��ÿ���Ϊʲôһ��ʼ�������Լ���һ��ֱ��һ��*************
************�ġ���һ��������������أ�*********************************
************�ջ��ǶԾ�̬��Ա�����������ء�˫�������Ϥ********************/


void linkedList::prt(){
	node*p = head;
	//int i = 0;
	while (p->next != NULL){
		cout << "(" << p->next->d.r() << "," << p->next->d.t() << "," << p->next->d.z() << ") (" <<
			p->next->d.x() << "," << p->next->d.y() << "," << p->next->d.z() << ")" << endl;
		p = p->next;
//		++i;
	}
	//cout << "ѭ����" << i << "��\n";
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
	cout << "\n\t\tSavePartMatch('������','����');//���������Ϊ�û�Ԥ��Ĳ��ϣ����򲿼���ɫ����Ĭ��"
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



//��������ǲ��ȶ���
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
	while (q->next != NULL && q->next->d.t() < x.t()){//�Ƚϵ�ǰ�ڵ�q�ĺ���һ���ڵ��theta���������theta��С��ϵ
		q = q->next;
	}
	if (q->next == NULL){//�Ƶ���ĩβ��
		q->next = p;
		p->next = NULL;
		p->prev = q;
		return;
	}
	//���м�
	p->next = q->next;//��p�����q���棬Ҳ���ǲ��ڵ�һ������p���theta��ֵ��ǰ��
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
