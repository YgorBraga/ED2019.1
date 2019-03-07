#include "stdio.h"

void fill_vect(int vector[], int size, int phase){
    for(int i = 0; i < size; i++){
        vector[i] = (i + 1) * phase;
        phase = phase * (-1);
    }
}

void write_vect(int vector[], int size, int chosen){
    printf("[");
    for(int i = 0; i < size; i++){
        if(i != 0){
            printf(" ");
        }
        if(chosen == i && vector[i] < 0){
            printf("<");
        }
        printf("%d", vector[i]);
        if(chosen == i && vector[i] > 0){
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

int new_chosen(int vector[], int size, int jumps, int chosen){
    if(vector[chosen] > 0){
        while(jumps > 0){
            chosen = (chosen + 1) % size;
            jumps--;
        }
    }else{
        while(jumps > 0){
            chosen = (chosen + size - 1) % size;
            jumps--;
        }
    }
    return chosen;
}

int main(){

    int N = 0;
    int fase = 0;
    int E = 0;

    scanf("%d %d %d", &N, &E, &fase);

    int vector[N];
    int chosen = E - 1;
    int dead = -1;

    fill_vect(vector, N, fase);
    write_vect(vector, N, chosen);
    
    int jumps = 0;
    while(N > 1){
        jumps = vector[chosen] > 0 ? vector[chosen] : -vector[chosen];
        
        if(vector[chosen] < 0){
            dead = (chosen + N - 1) % N;
            if(chosen != 0){
                chosen--;
            }
        }else{
            dead = (chosen + 1) % N;
            if(chosen == N - 1){
                chosen--;
            }
        }
        move_dead(vector, N, dead);
        N--;

        chosen = new_chosen(vector, N, jumps, chosen);
        write_vect(vector, N, chosen);

    }

    return 0;
}