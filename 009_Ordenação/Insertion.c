#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

void fill_vector(int vector[], int size){
    for(int i = 0; i < size; i++){
        vector[i] = rand() % 181 + 10;
    }
}

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

void Insertion(int vector[], int size){
    for(int i = 0; i < size; i++){
        xs_partition(0, i);
        xs_pivot(vector[i]);
        xd_vet(vector, size, "r", i);
        for(int j = i; j > 0; j--){
            if(vector[j] < vector[j - 1]){
                xd_vet(vector, size, "ry", j, j - 1);
                SWAP(&vector[j], &vector[j-1]);
                xd_vet(vector, size, "yr", j, j - 1);
            }else{
                xd_vet(vector, size, "g", j);
                break;
            }
        }
        if(i < 2){
            xd_vet(vector, size, "g", i);
        }
    }
}

int main(){
    x_open(800, 500);
    xs_log("Insertion/");
    int size = 50;
    int vector[size];
    fill_vector(vector, size);
    //show(vector, size);
    Insertion(vector, size);
    xs_pivot(0);
    xd_vet(vector, size, "");
    //show(vector, size);
    x_close();
    return 0;
}