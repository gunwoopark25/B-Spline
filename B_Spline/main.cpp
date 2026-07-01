#include <iostream>
#include <string>
#include <fstream>

#include "B_Spline.h"

using namespace std;

int main()
{
    B_Spline B;

    B.saveData();
    B.define_d();
    B.define_u();

    return 0;
}
