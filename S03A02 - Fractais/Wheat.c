#include "xpaint.h"

void write_Wheat(int x, int y, float ang, float length){
    if(length < 2){
        return;
    }
    for(int i = 0; i < 4; i++){
        int xf = x + length * xm_cos(ang) / 4;
        int yf = y - length * xm_sin(ang) / 4;
        xd_line(x, y, xf, yf);
        write_Wheat(xf, yf, ang - 35, length / 3);
        write_Wheat(xf, yf, ang + 35, length / 3);
        x = xf;
        y = yf;
    }
}

int main(){
    int width = 400;
    int height = 600;

    x_open(width, height);
    write_Wheat(width / 2, height - 10, 90, height - 200);
    x_save("Wheat");
    x_close();

    return 0;
}