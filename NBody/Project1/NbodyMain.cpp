/* Gerald Blake
 * CS 3513
 * N BODY Simulator
 *
 */
#include<fstream>
#include<iostream>
//#include <string>
#include "Point.h"
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;
void readFile(ifstream &file, vector<Point> &p);
void openFile(ifstream &file, ofstream& out);

void PrintSystem(vector<Point> p, ofstream& out,string baseName, int frame);
void EulerMethod(vector<Point> &p, int frame, int timeStep, double epsilon);
void openFile(ifstream &inputFile, char *fileName);
int main(int argc,char *argv[])
{
	//0 prog
	//1 file

	ifstream file;
	ofstream out;
	vector<Point> p;
	char *inputFile = argv[1];
	int timeStep = atoi(argv[2]);
	double epsilon = atof(argv[3]);
	int frame = atoi(argv[4]);
	char* fileName = argv[5];
	

	
	
				openFile(file,inputFile);
				readFile(file,p);
			
	
				
			
				for(int i = 0; i < frame; i++)
				{
					
					EulerMethod(p,frame,timeStep, epsilon);
					PrintSystem(p,out,fileName,i);
					
				}



	return 0;
}



void openFile(ifstream &file, ofstream& outFile)
{
    string name;
	file.close();
	outFile.close();
	int fileType = 0;
	cout << "Which type of file would you like to open" << endl;
	cout << "0 for input 1 for output" << endl;
	cin >> fileType;
	cout << "Enter file name: ";
	cin >> name;


	switch(fileType)
	{
		case 0:
			file.open(name.c_str());
			break;
		case 1:
			outFile.open(name.c_str());
			break;
	}
	
}


void openFile(ifstream &inputFile, char *fileName)
{
	
	inputFile.open(fileName);

}


//reads system in

void readFile(ifstream &file, vector<Point> &p)
{
	string type;
	double G;
	int numberMasses;
	file >> type >> G >> numberMasses;
	double mass,x,y,vx,vy;


	//p->setSize(numberMasses);
	for(int i = 0; i < numberMasses;i++)
	{
		file >> mass >> x >> y >> vx >> vy;

		p.push_back(Point(x,y,vx,vy,mass));
		p[i].setType(type);
		p[i].setG(G);
		p[i].setSize(numberMasses);
		
		
	}
	file.close();
	
}

//prints system
void PrintSystem(vector<Point> p, ofstream& out,string baseName, int frame)
{
	ostringstream stm;
    stm << frame;

	baseName+=stm.str()+".txt";
	out.open(baseName.c_str());
	out << p[0].getType() << endl;
	out << p[0].getG() << endl;
	out << p[0].getSize() << endl;

	for(unsigned int i = 0; i < p.size(); i++)
	{
		out << p[i].getMass() <<  " " << p[i].getX()<< " " << p[i].getY()<<" " << p[i].getDX() << " " << p[i].getDY() << endl;
		
	
	}
	out.close();
}


//Performs Euler's Method
void EulerMethod(vector<Point> &p, int frame, int timeStep, double epsilon)
{
	
//
	for (unsigned int i = 0; i < p.size(); i++)

               {

				   p[i].setFX(0);

				   p[i].setFY(0);
				 
				   for (unsigned int j = 0; j < p.size(); j++)

                  {

                     if(i == j)

                        continue;

                     


					 double theNumerator = p[0].getG() *p[i].getMass()*p[j].getMass();

                     


					 p[j].setDX ( (p[j].getX() - p[i].getX()));

					 p[j].setDY((p[j].getY() - p[i].getY()));

                     double dist = sqrt(p[j].getDX()*p[j].getDX() + p[j].getDY()*p[j].getDY());

                     double theDenominator = dist + epsilon;

                     


                     double cubeProduct = theDenominator*theDenominator*theDenominator;

					 p[i].setFX(p[i].getFX() + (theNumerator*(p[j].getX()-p[i].getX()))/(cubeProduct));

                


					 p[i].setFY( p[i].getFY() + (theNumerator*(p[j].getY()-p[i].getY()))/(cubeProduct));

                  }
				   

				  
               }


	for(unsigned int i = 0; i < p.size();i++)
	{
		
				 p[i].setVX(p[i].getVX() + (((timeStep)/p[i].getMass())*p[i].getFX()));
				 
				  p[i].setX( p[i].getX() + timeStep * p[i].getVX());

				

				  p[i].setVY( p[i].getVY() + (((timeStep)/p[i].getMass())*p[i].getFY()));

				  p[i].setY( p[i].getY() + timeStep * p[i].getVY());

	}





}