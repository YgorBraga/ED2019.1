#include "stdio.h"
#include "stdlib.h"
#include "time.h"

const char WALL = '#';
const char HALL = ' ';
//New Code for V2
const char STEP = '.';
//END

int deltaL[] = {1, -1, 0, 0};
int deltaC[] = {0, 0, 1, -1};

void fill_maze(int lines, int columns, char maze[lines][columns]){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            maze[i][j] = WALL;
        }
    }
}

void write_maze(int lines, int columns, char maze[lines][columns]){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            printf("%c", maze[i][j]);
        }
        puts("");
    }
    getchar();
}

int search_hall(int lines, int columns, char maze[lines][columns], int line, int column){
    int sides = (sizeof(deltaL)) / (sizeof(int));
    int cont = 0;
    for(int i = 0; i < sides; i++){
        if(maze[line + deltaL[i]][column + deltaC[i]] == HALL){
            cont++;
        }
    }
    if(cont <= 1){
        return 1;
    }else{
        return 0;
    }
}

void shuffle(int values[], int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        int random = rand() % size;
        int temp = values[i];
        values[i] = values[random];
        values[random] = temp;
    }
}

void create_maze(int lines, int columns, char maze[lines][columns], int line, int column){
    if(line < 1 || line >= lines - 1 || column < 1 || column >= columns - 1){
        return;
    }
    if(maze[line][column] != WALL){
        return;
    }
    if(!search_hall(lines, columns, maze, line, column)){
        return;
    }
    maze[line][column] = HALL;
    write_maze(lines, columns, maze);
    int sides = (sizeof(deltaL)) / (sizeof(int));
    int neigh[] = {0, 1, 2, 3};
    shuffle(neigh, sides);
    for(int i = 0; i < sides; i++){
        create_maze(lines, columns, maze, line + deltaL[neigh[i]], column + deltaC[neigh[i]]);
    }
}

//New Code for V2
void fill_visited(int lines, int columns, int visited[lines][columns]){
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < columns; j++){
            visited[i][j] = 0;
        }
    }
}

int search_out(int start[], int out[], int lines, int columns, char maze[lines][columns], int visited[lines][columns]){
    if(maze[start[0]][start[1]] != HALL){
        return 0;
    }
    if(visited[start[0]][start[1]] == 1){
        return 0;
    }

    maze[start[0]][start[1]] = STEP;
    visited[start[0]][start[1]] = 1;
    write_maze(lines, columns, maze);

    if(start[0] == out[0] && start[1] == out[1]){
        return 1;
    }

    int sides = (sizeof(deltaL)) / (sizeof(int));
    int new_step[] = {-1, -1};
    for(int i = 0; i < sides; i++){
        new_step[0] = start[0] + deltaL[i];
        new_step[1] = start[1] + deltaC[i];
        if(search_out(new_step, out, lines, columns, maze, visited)){
            return 1;
        }
    }

    maze[start[0]][start[1]] = HALL;
    write_maze(lines, columns, maze);
    return 0;


}
//END

int main(){
    srand(time(NULL));

    int lines = 0;
    int columns = 0;
    scanf("%d %d", &lines, &columns);
    setbuf(stdin, NULL);

    char maze[lines][columns];
    fill_maze(lines, columns, maze);

    write_maze(lines, columns, maze);
    
    int line = 0;    
    int column = 0;
    do{
        line = rand() % lines;
    }while(line < 1 || line == lines - 1);
    do{
        column = rand() % columns;
    }while(column < 1 || column == columns - 1);

    create_maze(lines, columns, maze, line, column);

    //New Code for V2
    int visited[lines][columns];
    fill_visited(lines, columns, visited);

    int start[] = {-1, -1};
    int out[] = {-1, -1};

    do{
        printf("Escolha o local de inicio: ");
        scanf("%d %d", &start[0], &start[1]);
        setbuf(stdin, NULL);
    }while(maze[start[0]][start[1]] != HALL);
    do{
        printf("Escolha o local da saida: ");
        scanf("%d %d", &out[0], &out[1]);
        setbuf(stdin, NULL);
    }while(maze[out[0]][out[1]] != HALL);

    search_out(start, out, lines, columns, maze, visited);

    //END    

    return 0;
}