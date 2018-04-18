#include "point3D.h"
#include "linkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream edgefile("D:\\Documents\\graduate2\\mesh\\Cylinder\\edge.txt",ios::in);
	if (!edgefile) return 0;
	double x, y, z;
	linkedList list;
	while (!edgefile.eof()){
		edgefile >> x >> y >> z;
		if (edgefile.fail())break;
		list.insByTheta(point3D(x, y, z));
	}
	//list.prt();
	cout << endl << endl << endl;
	list.sortByZ();
	//list.prt4FMT();
	//cout << endl << endl << endl;
	//list.prtR();
	list.prt();
	system("pause");
	return 0;
} 