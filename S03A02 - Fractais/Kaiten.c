#include "xpaint.h"

void write_Kaiten(int x, int y, float ang, float length){
    if(length < 2){
        return;
    }
    xs_color((XColor){xm_rand(0, 255),xm_rand(0, 255),xm_rand(0, 255)});
    float xf = x + length * xm_cos(ang);
    float yf = y - length * xm_sin(ang);
    xd_line(x, y, xf, yf);
    write_Kaiten(xf, yf, ang - 90, length - 5);
}

int main(){
    int width = 800;
    int height = width;

    x_open(width, height);
    write_Kaiten(20, 20, 0, width - 40);
    x_save("Kaiten");
    x_close();

    return 0;
}