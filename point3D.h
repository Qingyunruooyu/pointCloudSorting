#pragma once
class point3D
{
public:
	static double tol;
	point3D();
	point3D(double x, double y, double z);
	double x(){ return X; }
	double y(){ return Y; }
	double z(){ return Z; }
	double t(){ return theta; }//角度
	double r(){ return R; }//半径
	//double p(){ return phi; }

	bool operator <(point3D &a);//比较纵坐标
	bool operator >(point3D &a);
	bool operator ==(point3D &a);
	bool operator <=(point3D &a);
	bool operator >=(point3D &a);
	~point3D();
private:
	double X, Y, Z, theta, R/*,phi*/;//柱坐标和直角坐标
};

