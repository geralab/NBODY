#ifndef  POINT_H
#define  POINT_H
#include <string>
using namespace std;

class Point
{
	private:
		double x,y,dx,dy,mass,G,fx,fy,vx,vy;
		int size;
	    string type;

	public:
		Point(double x,double y,double dx,double dy,double mass);
		Point();
		double getFX();
		double getFY();
		double getG();
		double getX();
		double getY();
		double getDX();
		double getDY();
		double getMass();
		double getVX();
		double getVY();
		int getSize();
		string getType();
		void setMass(double mass);
		void setX(double x);
		void setY(double y);
		void setDX(double dx);
		void setDY(double dy);
		void setSize(int size);
		void setG(double G);
		void setType(string type);
		void setFX(double fx);
		void setFY(double fy);
		void setVX(double vx);
		void setVY(double vy);




};





#endif // ! POINT_H
void Point::setFX(double fx)
{
	this->fx=fx;

}
void Point::setFY(double fy)
{
	this->fy=fy;

}

double Point::getVX()
{

	return vx;
}
double Point::getVY()
{

	return vy;
}


void Point::setVX(double vx)
{
	this->vx = vx;
}

void Point::setVY(double vy)
{

	this->vy = vy;
}
void Point::setType(string type)
{
	this->type =type;

}

string Point::getType()
{

	return type;
}
void Point::setG(double G)
{
	this->G = G;
}

double Point::getG()
{
	return G;
}
int Point::getSize()
{
	return size;
}



void Point::setSize(int size)
{

	this->size = size;
}

Point::Point(){}
Point::Point(double x,double y,double vx,double vy,double mass)

{
	this->x=x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->mass = mass;

}

double Point::getFX(){
	return fx;
}

double Point::getFY()
{
	return fy;
}
void Point::setMass(double mass)
{
	this->mass = mass;
}

void Point::setX(double x)
{
	this->x = x;
}


void Point::setY(double y)
{
	this->y = y;
}

void Point::setDX(double dx)
{
	this->dx = dx;
}


void Point::setDY(double dy)
{
	this->dy = dy;
}

double Point::getMass()

{
	return mass;
}

double Point::getX()
{

	return x;
}


double Point::getY()
{
	return y;

}

double Point::getDX()
{
	return dx;

}
 


double Point::getDY()
{
	return dy;
}