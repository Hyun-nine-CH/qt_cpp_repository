#include "geo.h"
#include <iostream>
using namespace std;

GeometricFigure::GeometricFigure() {
    color="white";
}
/*
GeometricFigure::GeometricFigure(const string color) {
    this->color=color;
}
*/
void GeometricFigure::SetColor(const string color) {
    this->color=color;
}

bool GeometricFigure::IsPaint() {
    return (color=="whilte")?false:true;
}
string GeometricFigure::GetColor() {
    return color;
}

int main()
{
    GeometricFigure obj1;

    cout<<"obj1의 색 : "<<obj1.GetColor()<<endl;
    obj1.SetColor("green");
    cout<<"obj1의 색 : "<<obj1.GetColor()<<endl;
    return 0;
}
