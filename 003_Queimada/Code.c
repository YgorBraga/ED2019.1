#include "stdio.h"

const char TREE = '#';
const char EMPTY = '.';
const char BURNING = 'o';

void fill_mat(int lines, int columns, char forest[lines][columns]){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            scanf(" %c", &forest[i][j]);
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
}

void burn_mat(int lines, int columns, char forest[lines][columns], int startl, int startc){
    if(startl < 0 || startl >= lines || startc < 0 || startc >= columns){
        return;
    }
    if(forest[startl][startc] != TREE){
        return;
    }
    getchar();
    forest[startl][startc] = BURNING;
    puts("");
    write_mat(lines, columns, forest);
    burn_mat(lines, columns, forest, startl + 1, startc);
    burn_mat(lines, columns, forest, startl - 1, startc);
    burn_mat(lines, columns, forest, startl, startc + 1);
    burn_mat(lines, columns, forest, startl, startc - 1);
}

int main(){

    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;

    scanf("%d %d %d %d", &nl, &nc, &l, &c);
    char forest[nl][nc];

    fill_mat(nl, nc, forest);
    burn_mat(nl, nc, forest, l, c);

    return 0;
}