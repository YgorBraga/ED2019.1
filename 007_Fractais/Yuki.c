#include "xpaint.h"

void write_Yuki(int x, int y, float ang, float length){
    if(length < 1){
        return;
    }
    for(int i = 0; i < 5; i++){
        int xf = x + length * xm_cos(ang);
        int yf = y - length * xm_sin(ang);
        xd_line(x, y, xf, yf);
        write_Yuki(xf, yf, ang, length / 3);
        ang += 72;
    }
}

int main(){
    int width = 500;
    int height = 500;
    
    x_open(width, height);
    write_Yuki(width / 2, height / 2, 270, 120);
    x_save("Yuki");
    x_close();

    return 0;
}