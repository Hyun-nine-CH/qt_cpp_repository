#ifndef GEO_H
#define GEO_H

#include <iostream>
#include <string>

using namespace std;

class GeometricFigure {
public:
    GeometricFigure();
    void SetColor(const string color);
    bool IsPaint();
    string GetColor();
protected:
    string color;
};

#else
#endif // GEO_H
