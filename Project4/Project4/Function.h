#include "Constants.h"
class Function {
private:
    float x, y, r;
    metodo f1;
    float c1[2], c2[2];
    int dx, dy;
    float m;
    float steps;
    float pn;
    float Xinc, Yinc;
    float pk;
public:
    GLvoid graphing_circle() {

        r = sqrt(pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2));
        for (float i = c1[0]; i < c1[0] + r; i += 0.05) {

            y = sqrt(pow(r, 2) - pow(i - c1[0], 2)) + c1[1];
            f1.Pinta_Pixel(i, y, 0, 0, 255);
        }
        for (float i = c1[0]; i < c1[0] + r; i += 0.05) {

            y = -sqrt(pow(r, 2) - pow(i - c1[0], 2)) + c1[1];
            f1.Pinta_Pixel(i, y, 71, 178, 227);
        }
        for (float i = c1[0]; i < c1[0] + r; i += 0.05) {

            y = sqrt(pow(r, 2) - pow(i - c1[0], 2)) + c1[1];
            f1.Pinta_Pixel(-(i-2*c1[0]), y, 71, 178, 227);
        }
        for (float i = c1[0]; i < c1[0] + r; i += 0.05) {

            y = -sqrt(pow(r, 2) - pow(i - c1[0], 2)) + c1[1];
            f1.Pinta_Pixel(-(i - 2 * c1[0]), y, 71, 178, 227);
        }
    }

    GLvoid circle_bresenham() {

        r = sqrt(pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2));
        x = 0;
        y = r;
        pk = 1.25 - r;
        pn = pk;
        while (x < y) { 
            x++;
            if (pn < 0)
                pk = pn + 2 * x + 1;
            else
                pk = pn + 2 * x + 1 - 2 * y - 2;
            if (pk > 0)
                y--; 
            pn = pk;
            f1.Pinta_Pixel(x+c1[0], y+c1[1], 101, 193, 236);
            f1.Pinta_Pixel(x + c1[0], -(y - c1[1]), 101, 193, 236);
            f1.Pinta_Pixel(-(x - c1[0]), y + c1[1], 101, 193, 236);
            f1.Pinta_Pixel(-(x - c1[0]), -(y - c1[1]), 101, 193, 236);
            //
            f1.Pinta_Pixel(y + c1[0], x + c1[1], 101, 193, 236);
            f1.Pinta_Pixel(-(y - c1[0]), x + c1[1], 101, 193, 236);
            f1.Pinta_Pixel(y + c1[0], -(x - c1[1]), 101, 193, 236);
            f1.Pinta_Pixel(-(y - c1[0]), -(x - c1[1]), 101, 193, 236);
            
        }
        
    }

    GLvoid elipse_bresenham() {

        float r1 = sqrt(pow(c1[0], 2) + pow(c1[1], 2));
        float r2 = sqrt(pow(c2[0], 2) + pow(c2[1], 2));
        y = r2;
        x = 0;
        int rx2 = r1 * r1, ry2 = r2 * r2;
        int DosRx2 = 2 * rx2, Dosry2 = 2 * ry2;
        float p1 = ry2 - (rx2 * r2) + ((1 / 4) * rx2);
        float p2 = (ry2 * (x + 0.5) * (x + 0.5)) + (rx2 * (y - 1) * (y - 1)) - rx2 * ry2;
        int px = 0, py = DosRx2 * y;
        while (2 * ry2 * x <= 2 * rx2 * y)
        {
            x++;
            if (p1 < 0)
            {
                p1 += (2 * x * ry2) + ry2;
            }
            else
            {
                y--;
                p1 += (2 * ry2 * x) - (2 * rx2 * y) + ry2;

            }
            f1.Pinta_Pixel(x, y, 1, 1, 1);
            f1.Pinta_Pixel(x, -y, 1, 1, 1);
            f1.Pinta_Pixel(-x, y, 1, 1, 1);
            f1.Pinta_Pixel(-x, -y, 1, 1, 1);
         

        }
        while (y > 0)
        {

            y--;
            if (p2 > 0)
            {
                p2 += rx2 - (2 * rx2 * y);
            }
            else
            {
                x++;
                p2 += (2 * ry2 * x) - (2 * rx2 * y) + rx2;
            }
            f1.Pinta_Pixel(x, y, 1, 1, 1);
            f1.Pinta_Pixel(x, -y, 1, 1, 1);
            f1.Pinta_Pixel(-x, y, 1, 1, 1);
            f1.Pinta_Pixel(-x, -y, 1, 1, 1);

        }

        glFlush();

    }

    GLvoid graphing_elipse() {

        float r1 = sqrt(pow(c1[0], 2) + pow(c1[1], 2));
        float r2 = sqrt(pow(c2[0], 2) + pow(c2[1], 2));

        for (float i = 0; i < r1; i += 0.05) {

            y = sqrt(pow(r2, 2) * (1 - (pow(i, 2) / pow(r1, 2))));
            f1.Pinta_Pixel(i, y, 1, 1, 1);
            f1.Pinta_Pixel(-i, y, 1, 1, 1);
            f1.Pinta_Pixel(i,-y, 1, 1, 1);
            f1.Pinta_Pixel(-i, -y, 1, 1, 1);
        }
        



    }
    GLvoid drawing_stuff() {


        m = (c2[1] - c1[1]) / (c2[0] - c1[0]);
        for (float i = c1[0]; i <= c2[0]; i += 0.05) {
            y = m * (i + -c1[0]) + c1[1];
            f1.Pinta_Pixel(i, y, 1, 1, 1);
        }



    }
    GLvoid DDA() {

        dx = c2[0] - c1[0];
        dy = c2[1] - c1[1];
        if (abs(dx) >= abs(dy))
            steps = abs(dx);
        else
            steps = abs(dy);

        Xinc = (dx / steps);
        Yinc = (dy / steps);
        for (float i = 0; i < steps; i += 0.1) {

            x = c1[0] + Xinc * i;
            y = c1[1] + Yinc * i;
            f1.Pinta_Pixel(x, y, 128, 0, 128);
        }
    }
    GLvoid bresenham() {

        y = c1[1];
        x = c1[0];
        dx = c2[0] - c1[0];
        dy = c2[1] - c1[1];
        float pk = 2 * dy - dx;
        float p1 = 2 * dx - dy;
        int i = 0;

        if (abs(dx) >= abs(dy)) {
            steps = abs(dx);
        }
        else {
            steps = abs(dy);
        }
        Xinc = (dx / steps);
        Yinc = (dy / steps);
        if (abs(dx) >= abs(dy)) {
            while (i <= steps) {

                if (pn < 0) {
                    x = x + Xinc;
                    y = y + Yinc;
                    pn = pk + 2 * dy - 2 * dx;
                }
                else {

                    x += Xinc;
                    pn = pk + 2 * dy;

                }
                f1.Pinta_Pixel(x, y, 128, 0, 128);
                i++;
            }
        }
        if (abs(dx) < abs(dy)) {
            while (i <= steps) {

                if (pn > 0) {
                    x = x + Xinc;
                    y = y + Yinc;
                    pn = p1 + 2 * dx - 2 * dy;
                }
                else {

                    y += Yinc;
                    pn = p1 + 2 * dx;

                }
                f1.Pinta_Pixel(x, y, 128, 0, 128);
                i++;
            }
        }



    }
    GLvoid setc(int x1, int y1)
    {
        c1[0] = x1;
        c1[1] = y1;
    }
    GLvoid setc2(int x2, int y2)
    {
        c2[0] = x2;
        c2[1] = y2;
    }
};