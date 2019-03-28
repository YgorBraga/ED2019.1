#include "xpaint.h"
#include "stdlib.h"
#include "time.h"

void write_Tree(int x, int y, float ang, float thickness, int length, int branchs){    
    if(length < 5){
        xs_color(RED);
        xd_filled_circle(x, y, 2);
        return;
    }else if(length < 10){
        xs_color(GREEN);
    }else{
        xs_color((XColor){105,52,52});
    }
    //xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)}); CORES DIFERENTES NOS GALHOS
    float decrease = 0.74 + xm_rand(-20, 20)/100.0;
    float xf = x + length * xm_cos(ang);
    float yf = y - length * xm_sin(ang);
    xd_thick_line(x, y, xf, yf, thickness);

    float delta[] = {-35 + xm_rand(-3, 3), 35 + xm_rand(-3, 3), 0 + xm_rand(-3, 3)};
    for(int i = 0; i < branchs; i++){
        write_Tree(xf, yf, ang - delta[i], thickness - xm_rand(0, 1), length * decrease, xm_rand(2, 3));
    }
    return;
}


int main(){
    int width = 800;
    int height = 600;

    x_open(width, height);
    write_Tree(400, 599, 90, 3, 90, xm_rand(2, 3));
    x_save("Tree");
    x_close();

    return 0;
}