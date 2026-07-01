#include "B_Spline.h"
#include "Point2D.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

B_Spline::B_Spline()
{
    /*--- Input Data ---*/
    Degree = 3;
    Number_of_CP = Degree + 2;
}

B_Spline::~B_Spline()
{

}

void B_Spline::saveData()
{
	/*--- CP.txt File Open ---*/
    readFile.open("CP.txt");
    if (!readFile)
    {
        cout << "This CP.txt file can't Open" << endl;
    }
    /*--- Dynamic allocation CP ---*/
    CP = new double[Number_of_CP];
    /*--- Save CP Data ---*/
    cout << "===== CP =====" << endl;
    for (int i = 0; i < Number_of_CP; i++)
    {
        readFile >> CP[i];
        cout << CP[i] << endl;
    }
    readFile.close();

	/*--- Knots.txt File Open ---*/
    readFile.open("Knots.txt");
    if (!readFile)
    {
        cout << "This Knots.txt file can't Open" << endl;
    }
	/*--- Save Number of Knots ---*/
	readFile >> Number_of_Knots;
	cout << "===== Number of Knots =====" << endl;
	cout << Number_of_Knots << endl;
	/*--- Dynamic allocation Knots ---*/
	Knots = new double[Number_of_Knots];
	cout << "===== Knots =====" << endl;
	for (int i = 0; i < Number_of_Knots; i++)
	{
		readFile >> Knots[i];
		cout << Knots[i] << endl;
	}
    readFile.close();
}

void B_Spline::define_d()
{
    /*--- Dynamic allocation Matrix d ---*/
    d = new double*[Degree + 1];
    for (int k = 0; k <= Degree; k++)
    {
        d[k] = new double[Degree + Number_of_CP];
    }
    /*--- Save CP Data to Matrix d ---*/
    cout << "==== Matrix d at k = 0 ====" << endl;
    for (int i = 0; i < Number_of_CP; i++)
    {
        d[0][i] = CP[i];
        cout << d[0][i] << endl;
    }
}

void B_Spline::define_u()
{
    /*--- Dynamic allocation Matrix u ---*/
    u = new double* [Degree + 1];
    for (int k = 0; k <= Degree; k++)
    {
        u[k] = new double[Degree + Number_of_Knots];
    }
    /*--- Save CP Data to Matrix u ---*/
    cout << "==== Matrix u at k = 0 ====" << endl;
    for (int i = 0; i < Number_of_Knots; i++)
    {
        u[0][i] = Knots[i];
        cout << u[0][i] << endl;
    }
}