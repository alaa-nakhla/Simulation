#include <math.h>
#include "vector3.h"
class Plant
{

public:
	Vector3 a , v , position ,f_gra, f_total , f1 ,  f2;
	Vector3 delta_v , d;
	double  v0 , vx , vy, q;
	double m ,  r_planet , x1 , x2;
	double dx , f_g ;
	
	 void planet (double r_plant, double m_plant,Vector3 position_p,double v0)

	{
          dx = x2-x1; 
		  

		this->position.x = r;
		this->position.y = r;
		this->position.z = 0;
		this->q = 0;
		this->m = m_plant;
		this->v.x = cos(90)*v0;
		this->v.y = sin(90)*v0;
		this->position = position_p   ;
	}

	double En  ( Vector3 pos1 ,Vector3 pos2 , double m1 , double m2)
	{
		double d = sqrt(pow((pos2.x - pos1.x), 2) + pow((pos2.y - pos1.y), 2));
		double g = pow(10, -11.0);
		double G = (6.67428 + 0.00067) * (g);
		f_g = G*m1*m2 / pow(d , 2);
		return f_g;
	}

	Vector3 f_22 (Vector3 pos1 ,Vector3 pos2 , double m1 , double m2) {
		 f1.x = pos2.x - pos1.x ;
		 f1.y =  pos2.y - pos1.y ;
		 f1.z =  pos2.z - pos1.z ;
		 double f1_= sqrt(pow((pos2.x - pos1.x), 2) + pow((pos2.y - pos1.y), 2)+ pow((pos2.z - pos1.z), 2));
	double k = En(pos1, pos2 , m1 ,m2) / f1_;
	if (k >=1){
		 f2.x = f1.x /k ;
		 f2.y =  f1.y /k ;
		 f2.z =  f1.z /k ;}

	return f2;
	}


		/*double teta = atan((pos1.y - pos2.y) / (pos1.x - pos2.x));
		f_gra.x = f_g * cos(teta);
		f_gra.y =  f_g * sin(teta);
		f_gra.z= 0;
		return f_gra ;}
		
			double mm = (pos1.y - pos2.y) / (pos1.x - pos2.x);
		 Vector3 f1  ;
		*/

	Vector3 update_pos(){
		double d_t = 0.0000001;
		a.x = f_gra.x / m;
		a.y = f_gra.y / m;
		
	}
}