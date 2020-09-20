#pragma once
#include "Constants.h"
class xd {
public:
    int heigth = 500;
    int length = 500;
    int gx = length / 2;
    int gy = heigth / 2;
};
class Plane {
private:

    xd my_xd;

    int gx = my_xd.gx;
    int gy = my_xd.gy;
public:
    metodo f1;
    Function my_function;
    GLvoid doing_stuff() {

        for (float i = -gx; i < gx; i += 0.1) {

            f1.Pinta_Pixel(i, 0, 1, 1, 1);
        }
        for (float i = -gy; i < gy; i += 0.1) {

            f1.Pinta_Pixel(0, i, 1, 1, 1);
        }


    }
};
