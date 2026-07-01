#include "B_Spline.h"
#include "Point2D.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

B_Spline::B_Spline()
{
    /*--- 입력 Data ---*/
    Degree = 3;
    Number_of_CP = Degree + 2;
    CP = nullptr;
	Knots = nullptr;
}

B_Spline::~B_Spline()
{

}

void B_Spline::saveData()
{
	/*--- CP.txt 파일 열기 ---*/
    readFile.open("CP.txt");
    if (!readFile)
    {
        cout << "This CP.txt file can't Open" << endl;
    }
    /*--- CP 넣어줄 공간 동적 할당 ---*/
    CP = new double[Number_of_CP];
    /*--- CP Data 저장 ---*/
    cout << "===== CP =====" << endl;
    for (int i = 0; i < Number_of_CP; i++)
    {
        readFile >> CP[i];
        cout << CP[i] << endl;
    }
    readFile.close();

	/*--- Knots.txt 파일 열기 ---*/
    readFile.open("Knots.txt");
    if (!readFile)
    {
        cout << "This Knots.txt file can't Open" << endl;
    }
	/*--- Knot의 개수 저장 ---*/
	readFile >> Number_of_Knots;
	cout << "===== Number of Knots =====" << endl;
	cout << Number_of_Knots << endl;
	/*--- Knots 넣어줄 공간 동적 할당 ---*/
	Knots = new double[Number_of_Knots];
	cout << "===== Knots =====" << endl;
	for (int i = 0; i < Number_of_Knots; i++)
	{
		readFile >> Knots[i];
		cout << Knots[i] << endl;
	}
    readFile.close();
}

