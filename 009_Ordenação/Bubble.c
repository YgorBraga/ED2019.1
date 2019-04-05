#include <stdio.h>

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
    for(int i = 0; i < size; size--){
        for(int j = 0; j < (size - 1); j++){
            if(vector[j] > vector[j + 1]){
                SWAP(&vector[j], &vector[j + 1]);
            }
        }
    }
}

int main(){
    int vector[] = {10, 8, 9, 15, 36, 27, 44, 13, 69, 81, 75, 24};
    int size = sizeof(vector) / sizeof(int);
    show(vector, size);
    Bubble(vector, size);
    show(vector, size);
    return 0;
}