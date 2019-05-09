#include <set> //tree
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

pair<bool, list<int>::iterator> busca_sequencial(list<int>& lista, int value){
    auto it = lista.begin();
    while(it != lista.end()){
        if(*it == value){
            return make_pair(true, it);
        }
        if(*it < value){
            it++;
        }else{
            return make_pair(false, it);
        }
    }
}

int main(){
    list<int> data;
    bool sorted = true;
    int sucessos = 0;
    char op;
    while(cin >> op){
        if(op == 'e'){
            break;
        }
        int value;
        cin >> value;
        if(op == 'i'){
            auto resp = busca_sequencial(data, value);
            if(!resp.first){
                data.insert(resp.second, value);
                sucessos++;
            }
        }
        if(op == 's'){
            if(busca_sequencial(data, value).first){
                sucessos++;
            }
        }
        if(op == 'r'){
            auto resp = busca_sequencial(data, value);
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