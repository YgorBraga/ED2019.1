#include "xpaint.h"

void write_Sankaku(int x, int y, float ang, float length){
    if(length < 10){
        return;
    }
    for(int i = 0; i < 3; i++){
        write_Sankaku(x, y, ang, length / 2);
        float xf = x + length * xm_cos(ang);
        float yf = y - length * xm_sin(ang);
        xd_line(x, y, xf, yf);
        x = xf;
        y = yf;
        ang += 120;
    }
}

int main(){
    int width = 900;
    int height = 900;

    x_open(width, height);
    write_Sankaku(450, 800, 60, 800);
    x_save("Sankaku");
    x_close();

    return 0;
}