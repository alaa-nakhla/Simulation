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
using namespace std;
#define WinMain
 int img1,img2,img3,img4,img5;
 double me,re,vx,vy,xo,yo,xv=0;
//model:
Model_3DS s1;
GLUquadric* quadric=gluNewQuadric();
Camera MyCamera;
void AddCamera(){
	MyCamera.Render();}
class Vector3
{
public:
	double x,y,z;
	Vector3(double xx=0,double yy=0,double zz=0){
		x=xx;
		y=yy;
		z=zz;
	}
	void sett(double xx,double yy,double zz)
	{
		x=xx;
		y=yy;
		z=zz;
	}
	//ÌãÚ ÔÚÇÚíä
	Vector3 operator+(Vector3 b)
	{
		Vector3 c;
		c.x=x+b.x;
		c.y=y+b.y;
		c.z=z+b.z;
		return c;
	}
	//ÖÑÈ ÔÚÇÚíä
	Vector3 operator*(Vector3 b)
	{
		Vector3 c;
		c.x=x*b.x;
		c.y=y*b.y;
		c.z=z*b.z;
		return c;
	}
	//ÞÓãÉ ÔÚÇÚíä
	Vector3 operator/(Vector3 b)
	{
		Vector3 c;
		c.x=x/b.x;
		c.y=y/b.y;
		c.z=z/b.z;
		return c;
	}
	//ÖÑÈ ÔÚÇÚ ÈÞíãÉ 
	Vector3 operator*(double b)
	{
		Vector3 c;
		c.x=x*b;
		c.y=y*b;
		c.z=z*b;
		return c;
	}
	//ÞÓãÉ ÔÚÇÚ Úáì ÞíãÉ
	Vector3 operator/(double b)
	{
		Vector3 c;
		c.x=x/b;
		c.y=y/b;
		c.z=z/b;
		return c;
	}
	//ÌãÚ ÔÚÇÚ ãÚ ÞíãÉ
	Vector3 operator+(double b)
	{
		Vector3 c;
		c.x=x+b;
		c.y=y+b;
		c.z=z+b;
		return c;
	}
};
class Planet
{
public:
	Vector3 a,v,position;
	double mass,r_planet,force_scaler;
	int img;
	Planet()
	{
		a.x=0; a.y=0; a.z=0; v.x=0; v.y=0; v.z=0;
		position.x=0; position.y=0; position.z=0;
		mass=10;
		r_planet=0.5;
		this->img=img4;
	}
	Planet(double r,double m1,Vector3 position0,Vector3 v0,int im)
	{
		a.x=0; a.y=0; a.z=0;
		v=v0;
		position=position0;
		mass=m1;
		r_planet=r;
		this->img=im;
	}
	//(åÐÇ ÇáÊÇÈÚ íÍÓÈ ÔÏÉ ÇáÞæÉ ÞíÇÓíÇ(ØæíáÉ 
	double force_scaler_calc(Vector3 pos1,Vector3 pos2, double m1,double m2)
	{
		double d=sqrt(pow((pos2.x-pos1.x),2)+pow((pos2.y-pos1.y),2));
		double G=6.67428*10e0-10;
		force_scaler=G*m1*m2/pow(d,2);
		return force_scaler;
	}
	//åÐÇ ÇáÊÇÈÚ íÍÓÈ ÔÏÉ ÇáÞæÉ ÔÚÇÚíÇ
	Vector3 force_vector(Vector3 pos1,Vector3 pos2,double m1,double m2) {
		 Vector3 ftotalv,fv;
		 //áÍÓÇÈ ãÑßÈÇÊ ÔÚÇÚ ÇáÍÇãá
		 ftotalv.x=pos2.x-pos1.x;
		 ftotalv.y=pos2.y-pos1.y;
		 ftotalv.z=pos2.z-pos1.z;
		 //áÍÓÇÈ ØæíáÉ ÔÚÇÚ ÇáÍÇãá
		 double ftotol=sqrt(pow((pos2.x-pos1.x),2)+pow((pos2.y-pos1.y),2)+pow((pos2.z-pos1.z),2));
		 //to calculat k where ftotal=Kforce_scaler
	     double k = ftotol/force_scaler_calc(pos1,pos2,m1,m2) ;
	     //to calculat fv where fv=ftotal/k
	     fv.x=ftotalv.x/k ;
		 fv.y=ftotalv.y/k ;
		 fv.z=ftotalv.z/k ;
	return fv;
	}
	//åÐÇ ÇáÊÇÈÚ íÑÓã ÇáßæßÈ Ýí ÇÍÏÇËíÇÊ ãÚíäÉ
	void drawplanet(){
		glPushMatrix();
		int im=this->img;
		glTranslated(position.x,position.y,position.z);
		glRotated(xv,0,1,0);
		xv+=0.02;
		glBindTexture(GL_TEXTURE_2D,im);
		gluSphere(quadric,r_planet,100,100);
		glPopMatrix();
	}
	    //UFO
		void drawUFO(float m){
		glRotated(xv,0,1,0);
		glPushMatrix();
		glRotated(30,0,0,1);
		s1.scale=0.5;
		s1.pos.x=position.x;
		s1.pos.y=position.y;
		s1.pos.z=position.z;
		 s1.rot.y=xv;
		 mass=m;
		 s1.Draw();
		 glPopMatrix();
		glPopMatrix();
}
};
//controled
void keyboard (unsigned char k, int x, int y);
void mouse(int button,int state,int mousex,int mousey);
void processSpecialKeys(int key, int x, int y);
void initGL(){
glClearColor(0,0,0,1);
glClearDepth(1);
glDepthFunc(GL_LEQUAL);
glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
glEnable(GL_DEPTH_TEST);
glEnable(GL_TEXTURE_2D);

gluQuadricTexture(quadric, GL_TRUE);
img1=LoadTexture("sun.bmp");
img2=LoadTexture("mercury.bmp");
img3=LoadTexture("venus.bmp");
img4=LoadTexture("earth.bmp");
img5=LoadTexture("moon.bmp");

   ////models:
  s1=Model_3DS();
  s1.Load("UFO.3ds");
  s1.Materials[0].tex.Load("nd.bmp");
  s1.Materials[2].tex.Load("download.bmp");
  s1.Materials[1].tex.Load("d.bmp");
  s1.Materials[3].tex.Load("sa4.bmp");
}
void reshape(int w,int h){
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(double)w/(double)h,2,50);
	glMatrixMode(GL_MODELVIEW);
	
}
double t0=0.00000001;
Planet *p;
int n=0,q=0;
//********DRAW*****************
void display (void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslated(0,0,-20);
AddCamera();
if(q==0){
	p = new Planet[100];
	p[0].position.x=5;
	p[0].mass=20000;
	p[0].r_planet=1;
	p[0].img=img1;
	p[1].position.x=-5;
	p[1].mass=20000;
	p[1].r_planet=1;
	p[1].img=img5;
	n=2;
}
q++;
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++){
		if(i!=j)
		{
			//(vector)a=a0+f/m 
			p[i].a=p[i].a+p[i].force_vector(p[i].position,p[j].position,p[i].mass,p[j].mass)/p[i].mass;
			//(vector)v=a*t0+v0
			p[i].v=p[i].a*t0 + p[i].v;
			//(vector)x=v*t0+x0
			p[i].position=p[i].v*t0+p[i].position;
		}
	}
}
 for(int i=0;i<n;i++){
	  p[i].drawplanet();
}
glutPostRedisplay();
glutSwapBuffers();
}
int main(int argc,char** argv,HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
glutInit (&argc,argv);
glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowSize(800,800);
glutInitWindowPosition(0,0);
glutCreateWindow("alaa nakhla");
initGL();
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutSpecialFunc(processSpecialKeys);
glutMouseFunc(mouse);
glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
cout<<"enter me,re,vx,vy,xo,yo:"<<endl;
cout<<"me=";
cin>>me;
cout<<"\n re=";
cin>>re;
cout<<"\n vx=";
cin>>vx;
cout<<"\n vy=";
cin>>vy;
cout<<"\n x0=";
cin>>xo;
cout<<"\n y0=";
cin>>yo;
glutMainLoop();
return WinMain(hInstance,hPrevInstance,lpCmdLine,nCmdShow);
}
void keyboard(unsigned char key,int x,int y) {
	switch(key){
	case 's':
		MyCamera.RotateX(-2);
		break;
	case 'w':
		MyCamera.RotateX(2);
		break;
	case 'd':
	    MyCamera.RotateY(-2);
		break;
	case 'a':
	    MyCamera.RotateY(2);
		break;
	case 'u':
		p[n].drawUFO(100);
		n++;
		break;
	}
}
void processSpecialKeys(int key,int x,int y) {
	switch(key) {
	case GLUT_KEY_DOWN :
		MyCamera.MoveUpward(0.3);
				 break;
	case GLUT_KEY_UP :
		MyCamera.MoveUpward(-0.3);
				 break;
	case GLUT_KEY_RIGHT :
		MyCamera.MoveRight(-0.3);
				 break;
	case GLUT_KEY_LEFT :
		MyCamera.MoveRight(0.3);
				 break;
	case GLUT_KEY_F1:
		MyCamera.MoveForward(0.3);
		break;
	case GLUT_KEY_F2:
		MyCamera.MoveForward(-0.3);
		break;
	}
}
void mouse(int button,int state,int mousex,int mousey){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ){
		p[n].position.x=xo;
		p[n].position.y=yo;
		p[n].v.x=vx;
		p[n].v.y=vy;
		p[n].mass=me;
		p[n].img=img4;
		p[n].r_planet=re;
		n++;
	}
	else if(button == GLUT_RIGHT_BUTTON && state ==GLUT_DOWN){
		    p[n].position.x=0;
			p[n].position.y=0;
			p[n].v.x=0;
			p[n].v.y=0;
			p[n].mass=10000;
			p[n].img=img5;
		n++;
	}
	else{
		glClearColor(0,0,0,1);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
}