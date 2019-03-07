#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const char TREE = '#';
const char EMPTY = '.';
const char BURNING = 'o';
const char BURNED = 'x';

int deltaL[] = {1, -1, 0, 0};
int deltaC[] = {0, 0, 1, -1};
int moves = (sizeof(deltaL) / sizeof(int));

void fill_mat(int lines, int columns, char forest[lines][columns], int taxa){
    srand(time(NULL));
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            if((rand() % 101) <= taxa){
                forest[i][j] = TREE;
            }else{
                forest[i][j] = EMPTY;
            }
        }
    }
}

void write_mat(int lines, int columns, char forest[lines][columns]){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            printf("%c", forest[i][j]);
        }
        printf("\n");
    }
    getchar();
}

void shuffle(int vet[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        int random = rand() % size;
        int temp = vet[i];
        vet[i] = vet[random];
        vet[random] = temp;
    }
}

int burn_mat(int lines, int columns, char forest[lines][columns], int startl, int startc){
    if(startl < 0 || startl >= lines || startc < 0 || startc >= columns){
        return 0;
    }
    if(forest[startl][startc] != TREE){
        return 0;
    }
    forest[startl][startc] = BURNING;
    write_mat(lines, columns, forest);
    int cont = 1;
    int neigh[] = {0, 1, 2, 3};
    shuffle(neigh, moves);
    for(int i = 0; i < moves; i++){
        cont += burn_mat(lines, columns, forest, startl + deltaL[neigh[i]], startc + deltaC[neigh[i]]);
    }
    forest[startl][startc] = BURNED;
    write_mat(lines, columns, forest);
    return cont;
    
}

int main(){
    srand(time(NULL));
    
    int nl = 0;
    int nc = 0;
    scanf("%d %d", &nl, &nc);

    int taxa = 0;
    scanf("%d", &taxa);

    char forest[nl][nc];
    fill_mat(nl, nc, forest, taxa);
    
    int l = 0;
    int c = 0;
    scanf("%d %d", &l, &c);

    int damage = 0;
    damage = burn_mat(nl, nc, forest, l, c);
    printf("Total do dano foi: %d", damage);

    return 0;
}