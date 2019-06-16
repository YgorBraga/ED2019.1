#include "xpaint.h"
#include "xmat.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Pos{
    int l, c;
    Pos(int _l, int _c){
        this->l = _l;
        this->c = _c;
    }
};

vector<char> colors = {'B','g','r','b','y','c','m','o','w','v'};
vector<Pos> neigh = {Pos(1, 0), Pos(-1, 0), Pos(0, -1), Pos(0, 1)};

bool has_value(vector<string>& mat, int l, int c, char cor){
    if(l < 0 || l >= mat.size()){
        return false;
    }
    if(c < 0 || c >= mat[0].size()){
        return false;
    }
    return mat[l][c] == cor;
}

void putnumbers(vector<vector<int>>& mat_int,int nl, int nc){
    for(int il = 0; il < nl; il++){
        for(int ic = 0; ic < nc; ic++){
            if(mat_int[il][ic] != -1){
                xmat_put_number(il, ic, BLACK, mat_int[il][ic]);
            }
        }
    }
}

void pathfinding(vector<string>& mat, vector<vector<int>>& mat_int, int l, int c){
    if(l < 0 || l >= mat_int.size()){
        return;
    }
    if(c < 0 || c >= mat_int[0].size()){
        return;
    }
    if(mat_int[l][c] < 0){
        return;
    }
    char cor = mat[l][c];
    queue<Pos> path;
    path.push(Pos(l, c));
    while(mat_int[path.back().l][path.back().c] != 0){
        for(int i = 0; i < neigh.size(); i++){
            Pos viz = Pos(path.back().l + neigh[i].l, path.back().c + neigh[i].c);
            if(has_value(mat, viz.l, viz.c, cor)){
                if(mat_int[viz.l][viz.c] < mat_int[path.back().l][path.back().c]){
                    path.push(viz);
                    break;
                }
            }
        }
    }
    xmat_draw(mat);
    while(!path.empty()){
        xmat_put_circle(path.front().l, path.front().c, WHITE);
        path.pop();
        putnumbers(mat_int, mat_int.size(), mat_int[0].size());
        x_step("mat");
    }
}

void floodfill(vector<string>& mat, vector<vector<int>>& mat_int, int l, int c, char cor_base, char cor_final, int nl, int nc){
    queue<Pos> fila;
    fila.push(Pos(l, c));
    mat[l][c] = cor_final;
    mat_int[l][c] = 0;
    xmat_draw(mat);
    xmat_put_number(l, c, BLACK, mat_int[l][c]);
    x_step("mat");
    while(!fila.empty()){
        Pos ref = fila.front();
        fila.pop();
        for(int i = 0; i < neigh.size(); i++){
            if(has_value(mat, ref.l + neigh[i].l, ref.c + neigh[i].c, cor_base)){
                mat[ref.l + neigh[i].l][ref.c + neigh[i].c] = cor_final;
                mat_int[ref.l + neigh[i].l][ref.c + neigh[i].c] = mat_int[ref.l][ref.c] + 1;
                fila.push(Pos(ref.l + neigh[i].l, ref.c + neigh[i].c));
                xmat_draw(mat);
                putnumbers(mat_int, nl, nc);
                x_step("mat");
            }
        }
    }
}

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    xmat_init(nl, nc);
    vector<string> mat(nl, string(nc, 'B'));
    vector<vector<int>> mat_int(nl, vector<int>(nc, -1));
    for(int l = 0; l < nc; l++){
        for(int c = 0; c < nc; c++){
            mat[l][c] = colors[xm_rand(0, 1)];
        }
    }
    xmat_draw(mat);
    x_save("mat");
    int l = 0, c = 0;
    cin >> l >> c;
    string clear;
    getline(cin, clear);
    floodfill(mat, mat_int, l, c, mat[l][c], 'b', nl, nc);
    cin >> l >> c;
    getline(cin, clear);
    pathfinding(mat, mat_int, l, c);
    x_save("mat");
    x_close();
}