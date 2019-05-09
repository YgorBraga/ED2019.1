#include <set> //tree
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

pair<bool, vector<int>::iterator> busca_binaria(vector<int>& vet, int value){
    int linf = 0;
    int lsup = vet.size() - 1;
    while(linf <= lsup){
        int meio = (linf + lsup) / 2;
        if(vet[meio] == value){
            return make_pair(true, vet.begin() + meio);
        }
        if(value > vet[meio]){
            linf = meio + 1;
        }else{
            lsup = meio - 1;
        }
    }
    return make_pair(false, vet.begin() + linf);
}


int main(){
    vector<int> data;
    int sucessos = 0;
    char op;
    while(cin >> op){
        if(op == 'e'){
            break;
        }
        int value;
        cin >> value;
        if(op == 'i'){
            auto resp = busca_binaria(data, value);
            if(!resp.first){
                data.insert(resp.second, value);
                sucessos++;
            }
        }
        if(op == 's'){
            if(busca_binaria(data, value).first)
                sucessos++;
        }
        if(op == 'r'){
            auto resp = busca_binaria(data, value);
            if(resp.second != data.end()){
                if(resp.first){
                    data.erase(resp.second);
                    sucessos++;
                }
            }
        }
    }
    cout << sucessos << endl;
    cout << "[ ";
    for(auto elem : data){
        cout << elem << " "; 
    }
    cout << "]";
}