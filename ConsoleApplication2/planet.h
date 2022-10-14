#include<Windows.h>
#include<stdlib.h>
#include<gl\glut.h>
#include<gl\GL.H>
#include<math.h>
#include<gl\texture.h>
#include<gl\3DTexture.h>
#include<gl\camera.h>
#include<iostream>
#include<Model_3DS.h>
#include<gl\3DTexture.h>

class Vec
{
public:
  double x, y, z;

  Vec(double xx = 0, double yy = 0  ,double zz = 0){
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

  Vec operator+(Vec b)
  {
    Vec c;
    c.x = x + b.x;
    c.y = y + b.y;
    c.z = z + b.z;
    return c;
  }

  Vec operator*(Vec b)
  {
    Vec c;
    c.x = x * b.x;
    c.y = y * b.y;
    c.z = z * b.z;
    return c;
  }
  Vec operator/(Vec b)
  {
    Vec c;
    c.x = x / b.x;
    c.y = y / b.y;
    c.z = z / b.z;
    return c;
  }

  Vec operator*(double b)
  {
    Vec c;
    c.x = x * b;
    c.y = y * b;
    c.z = z * b;
    return c;
  }

  Vec operator/(double b)
  {
    Vec c;
    c.x = x / b;
    c.y = y / b;
    c.z = z / b;
    return c;
  }

  Vec operator+(double b)
  {
    Vec c;
    c.x = x + b;
    c.y = y + b;
    c.z = z + b;
    return c;
  }

};

GLUquadric* quadric = gluNewQuadric();
class planet{

public:
	float mass1;
	float mass2;
	float radios;
	float distans;
    float gravitational;
	float  x,y,z,vx,vy,vz,ax,ay,az;
Vec F1;
Vec F2;
Vec v1;
Vec v2;
Vec a1;
Vec a2;
	
	planet(){
		gravitational=6.67428*pow(10,-11);
	}
void drawplanet(float x,float y,float z,float r,int img){
glPushMatrix();
//glRotated(xv,0,1,0);
//xv+=0.02;
glTranslated(x,y,z);
glBindTexture(GL_TEXTURE_2D,img);
gluSphere(quadric,r,100,100);
glPopMatrix();
}

	/*calculat scalars of force*/
	double forcesc(float m1,float m2,float d){
		this->mass1=m1;
		this->mass2=m2;
		this->distans=d;
	double Fo=(gravitational*mass1*mass2)/pow(distans,2);
	return Fo;
	}
	void drawplanet(float x,float y,float z,float r,int img){
glPushMatrix();
//glRotated(xv,0,1,0);
//xv+=0.02;
glTranslated(x,y,z);
glBindTexture(GL_TEXTURE_2D,img);
gluSphere(quadric,r,100,100);
glPopMatrix();
}
};

