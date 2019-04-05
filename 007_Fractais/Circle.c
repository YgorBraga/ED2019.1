#include "xpaint.h"

void write_Circle(int x, int y, float ang, float radius ){
    if(radius < 1){
        return;
    }
    xd_circle(x, y, radius);
    for(int i = 0; i < 6; i++){
        float xf = x + radius * xm_cos(ang);
        float yf = y + radius * xm_sin(ang);
        write_Circle(xf, yf, ang, radius / 3);
        //xd_line(x, y, xf, yf);
        ang+= 60;
    }
}

int main(){
    int width = 600;
    int height = 600;

    x_open(width, height);
    write_Circle(width / 2, height / 2, 0, 200);
    x_save("Circle");
    x_close();

    return 0;
}