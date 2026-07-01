#pragma once
#include <fstream>
#include "Point2D.h"

using namespace std;

class B_Spline
{
private:
   ifstream readFile;
   ofstream psFile;

public:
    /*--- constructor ---*/
    B_Spline();
    /*--- destructor ---*/
    ~B_Spline();

    /*--- Variable ---*/
    int Degree = 0;
    int Number_of_CP = 0;
	int Number_of_Knots = 0;

    double *CP = nullptr;
	double* Knots = nullptr;

    /*--- Function ---*/
    void saveData();
};
