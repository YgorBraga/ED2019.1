#include "xpaint.h"

void write_Spiral(int x, int y, float ang, float length, float side){
    if(length > 400){
        return;
    }
    float xf = x + length * xm_cos(ang);
    float yf = y - length * xm_sin(ang);
    
    xd_filled_rect((xf-(side/2)),(yf-(side/2)),(xf+(side/2)),(yf+(side/2)));
    write_Spiral(xf, yf, ang + 35 + 1, length * 1.1 + 0.1, side * 1.1);
    //xd_line(x, y, xf, yf);
}

int main(){
    int width = 800;
    int height = 800;

    x_open(width, height);
    write_Spiral(width / 2, height / 2, 90, 2, 1);
    x_save("Spiral");
    x_close();

    return 0;
}