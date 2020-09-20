#include "Constants.h"

using namespace std;
Plane my_plane;
xd my_xd;
int c1[2];
int c2[2];
int cx, cy;
int aux = 1;

void mouse(int button, int state, int x, int y) {
    cx = x - my_xd.gx;
    cy = y - my_xd.gy;


    if (aux == 1) {
        if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN) {

            my_plane.f1.Pinta_Pixel(cx, cy, 1, 1, 1);
            my_plane.my_function.setc(cx, cy);
            aux = 0;
        }

    }
    else {
        if (button == GLUT_LEFT_BUTTON and state == GLUT_DOWN) {

            my_plane.my_function.setc2(cx, cy);
            my_plane.f1.Pinta_Pixel(cx, cy, 1, 1, 1);
            aux = 1;
        }
    }

    glFlush();
}


GLvoid display() {

    my_plane.doing_stuff();

}

GLvoid menu_linea(int sub) {

    switch (sub) {
    case 1:
        my_plane.my_function.DDA();
        break;
    case 2:
        my_plane.my_function.bresenham();
        break;
    case 3:
        my_plane.my_function.drawing_stuff();
        break;
    case 4:
        my_plane.my_function.graphing_circle();
        break;
    case 5:
        my_plane.my_function.graphing_elipse();
        break;
    case 6:
        my_plane.my_function.circle_bresenham();
        break;
    case 7:
        my_plane.my_function.elipse_bresenham();
        break;

    case 8:
        exit(0);
        break;
    }

}



int main(int argc, char** argv) {
    int szs;

    glutInit(&argc, argv);// inicializamos glutInit
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//buffers   
    glutInitWindowSize(500, 500);//Tamaño de la ventana
    glutInitWindowPosition(100, 100);//Posicion de la ventan
    glutCreateWindow("szs");//Titulo de la ventana
    glutMouseFunc(mouse);
    gluOrtho2D(-my_xd.gx, my_xd.gx, my_xd.gy, -my_xd.gy);//Punto exacto en la ventana
    glutDisplayFunc(display);

    glutCreateMenu(menu_linea);
    glutAddMenuEntry("1.Algoritmo DDA", 1);
    glutAddMenuEntry("2.Algoritmo Bresenham", 2);
    glutAddMenuEntry("3.Algoritmo Propio", 3);
    glutAddMenuEntry("4.Circulo", 4);
    glutAddMenuEntry("5.Elipse", 5);
    glutAddMenuEntry("6.Circulo-Bresenham", 6);
    glutAddMenuEntry("7.Elipse-Bresenham", 7);
    glutAddMenuEntry("8.Exit", 8);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();//Loop para no salir


     
    return 0;
}