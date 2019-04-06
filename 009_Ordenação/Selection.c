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

int find_smaller(int vector[], int size, int start){
    int ismaller = start;
    xs_pivot(vector[ismaller]);
    for(int i = start; i < size; i++){
        xs_partition(start, i);
        xd_vet(vector, size, "yr", i, ismaller);
        if(vector[i] < vector[ismaller]){
            ismaller = i;
            xs_pivot(vector[ismaller]);
            xd_vet(vector, size, "r", ismaller);
        }
    }
    return ismaller;
}

void Selection(int vector[], int size){
    int smaller = 0;
    for(int i = 0; i < size; i++){
        smaller = find_smaller(vector, size, i);
        xd_vet(vector, size, "rr", i, smaller);
        SWAP(&vector[i], &vector[smaller]);
        xd_vet(vector, size, "rr", i, smaller);
        xd_vet(vector, size, "g", i);
    }
}

int main(){
    x_open(800, 500);
    xs_log("Selection/");
    int size = 50;
    int vector[size];
    fill_vector(vector, size);
    //show(vector, size);
    xd_vet(vector, size, NULL);
    Selection(vector, size);
    xs_pivot(0);
    xd_vet(vector, size, "");
    //show(vector, size);
    xd_vet(vector, size, "");
    x_close();

    return 0;
}