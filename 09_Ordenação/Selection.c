#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

void SWAP(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux; 
}

void show(int vector[], int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf(" %d", vector[i]);
    }
    printf(" ]\n");
}

int find_smaller(int vector[], int size, int start){
    int ismaller = start;
    for(int i = start; i < size; i++){
        if(vector[i] < vector[ismaller]){
            ismaller = i;
        }
    }
    return ismaller;
}

void Selection(int vector[], int size){
    int smaller = 0;
    for(int i = 0; i < size; i++){
        smaller = find_smaller(vector, size, i);
        SWAP(&vector[i], &vector[smaller]);
    }
}

int main(){
    
    x_open(800, 600);
    int vector[] = {10, 8, 9, 15, 36, 27, 44, 13, 69, 81, 75, 24};
    int size = sizeof(vector) / sizeof(int);
    //show(vector, size);
    xd_vet(vector, size, NULL);
    //Selection(vector, size);
    //show(vector, size);
    //xd_vet(vector, size, "");*/
    x_close();

    return 0;
}