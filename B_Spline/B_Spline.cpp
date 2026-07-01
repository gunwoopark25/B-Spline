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

