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
	double t(){ return theta; }//�Ƕ�
	double r(){ return R; }//�뾶
	//double p(){ return phi; }

	bool operator <(point3D &a);//�Ƚ�������
	bool operator >(point3D &a);
	bool operator ==(point3D &a);
	bool operator <=(point3D &a);
	bool operator >=(point3D &a);
	~point3D();
private:
	double X, Y, Z, theta, R/*,phi*/;//�������ֱ������
};

