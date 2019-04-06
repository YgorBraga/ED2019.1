#include <stdio.h>
#include <stdlib.h>
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

void Bubble(int vector[], int size){
    int saux = size;
    for(int i = 0; i < size; size--){
        for(int j = 0; j < (size - 1); j++){
            xs_partition(i, j + 1);
            if(vector[j] < vector[j + 1]){
                xs_pivot(vector[j + 1]);
                xd_vet(vector, saux, "rr", j, j + 1);
            }
            if(vector[j] > vector[j + 1]){
                xs_pivot(vector[j]);
                xd_vet(vector, saux, "rr", j, j + 1);
                SWAP(&vector[j], &vector[j + 1]);
                xd_vet(vector, saux, "rr", j, j + 1);
            }
        }
        if(size == 1){
            xs_pivot(vector[i]);
            xs_partition(i, i);
        }
        xd_vet(vector, saux, "g", size -1);
    }
    xs_pivot(0);
    xs_partition(0, saux - 1);
    xd_vet(vector, saux, "");
}

int main(){
    srand(1);
    x_open(800, 500);
    xs_log("Bubble/");
    int size = 50;
    int vector[size];
    fill_vector(vector, size);
    //show(vector, size);
    Bubble(vector, size);
    //show(vector, size);
    x_close();
    return 0;
}