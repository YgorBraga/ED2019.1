#include "xpaint.h"

void write_Square(int x, int y, float ang, float length){
    if(length < 2){
        return;
    }
    for(int i = 0; i < 4; i++){
        int xf = x + length * xm_cos(ang);
        int yf = y - length * xm_sin(ang);
        xd_line(x, y, xf, yf);
        ang += 90;
        x = xf;
        y = yf;
    }
    write_Square(x - length / 5, y + length / 5, ang, length * 2 / 5);
    write_Square(x - length / 5, y - length * 4 / 5, ang, length * 2 / 5);
    write_Square(x + length * 4 / 5, y + length / 5, ang, length * 2 / 5);
    write_Square(x + length * 4 / 5, y - length * 4 / 5, ang, length * 2 / 5);

}

int main(){
    int width = 1000;
    int height = 1000;

    x_open(width, height);
    write_Square(width / 4, height * 3 / 4, 0, width / 2);
    x_save("Square");
    x_close();

    return 0;
}