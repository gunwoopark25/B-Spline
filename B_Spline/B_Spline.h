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
    /*--- 생성자 ---*/
    B_Spline();
    /*--- 소멸자 ---*/
    ~B_Spline();

    /*--- 1차원 변수 ---*/
    int Degree;
    int Number_of_CP;
	int Number_of_Knots;

    double *CP;
	double* Knots;

    /*--- 함수 ---*/
    void saveData(); //파일 열기 및 InputData 저장
};
