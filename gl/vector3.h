#include <iostream>
using namespace std;
//#include 
class Vector3
{
public:
	double x, y, z;
	Vector3(double xx = 0, double yy = 0  ,double zz = 0){
		x = xx;
		y = yy;
		z = zz;
	}
	void sett(double xx, double yy, double zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}

	Vector3 operator+(Vector3 b)
	{
		Vector3 c;
		c.x = x + b.x;
		c.y = y + b.y;
		c.z = z + b.z;
		return c;
	}

	Vector3 operator*(Vector3 b)
	{
		Vector3 c;
		c.x = x * b.x;
		c.y = y * b.y;
		c.z = z * b.z;
		return c;
	}
	Vector3 operator/(Vector3 b)
	{
		Vector3 c;
		c.x = x / b.x;
		c.y = y / b.y;
		c.z = z / b.z;
		return c;
	}

	Vector3 operator*(double b)
	{
		Vector3 c;
		c.x = x * b;
		c.y = y * b;
		c.z = z * b;
		return c;
	}

	Vector3 operator/(double b)
	{
		Vector3 c;
		c.x = x / b;
		c.y = y / b;
		c.z = z / b;
		return c;
	}

	Vector3 operator+(double b)
	{
		Vector3 c;
		c.x = x + b;
		c.y = y + b;
		c.z = z + b;
		return c;
	}

};

