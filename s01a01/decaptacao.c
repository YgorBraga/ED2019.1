#include "stdio.h"

void fill_vect(int vector[], int size){
    for(int i = 0; i < size; i++){
        vector[i] = i + 1;
    }
}

void write_vect(int vector[], int size, int chosen){
    printf("[");
    for(int i = 0; i < size; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", vector[i]);
        if(chosen == i){
            printf(">");
        }
    }
    printf("]\n");
}

void move_dead(int vector[], int size, int dead){
    for(int i = dead; i < size - 1; i++){
        vector[i] = vector[i + 1];
    }
}

int main(){

    int N = 0;
    int E = 0;

    scanf("%d %d", &N, &E);

    int vector[N];
    int chosen = E - 1;
    int dead = chosen; 

    fill_vect(vector, N);

    while(N){
        chosen = (dead) % N;
        write_vect(vector, N, chosen);
        dead = (chosen + 1) % N;
        move_dead(vector, N, dead);
        N--;
    }

    return 0;
}