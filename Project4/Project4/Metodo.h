#pragma once
#include"Constants.h"
class metodo
{
    int heigth;
    int lenght;
    int gx;
    int gy;
public:

    void Pinta_Pixel(float CX, float CY, float RED, float GREEN, float BLUE) {

        glPointSize(5);//tamaño del pixel
        glBegin(GL_POINTS);// vertices o puntos
        glColor3f(RED, GREEN, BLUE);//colores 
        glVertex2d(CX, CY);//coordenadas
        glEnd();//funcion que finaliza
        glFlush();
    }
};
