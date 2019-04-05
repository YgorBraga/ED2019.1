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

void Insertion(int vector[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i; j > 0; j--){
            if(vector[j] < vector[j - 1]){
                SWAP(&vector[j], &vector[j-1]);
            }else{
                break;
            }
        }

    }
}

int main(){
    int vector[] = {10, 8, 9, 15, 36, 27, 44, 13, 69, 81, 75, 24};
    int size = sizeof(vector) / sizeof(int);
    show(vector, size);
    Insertion(vector, size);
    show(vector, size);
    return 0;
}