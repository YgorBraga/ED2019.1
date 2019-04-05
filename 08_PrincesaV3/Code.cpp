#include "iostream"

using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
    bool chosen;

    Node(int value = 0, bool chosen = false){
        this->value = value;
        this->next = this;
        this->prev = this;
        this->chosen = chosen;
    }

    void new_Person(int value, bool chosen, int fase){
        Node *node = new Node(value * fase, chosen);
        node->prev = this;
        node->next = this->next;
        this->next = node;
        node->next->prev = node;
    }

    int kill(){
        if(this->value < 0){
            this->prev = this->prev->prev;
            this->prev->next = this;
        }else{
            this->next = this->next->next;
            this->next->prev = this;
        }
        return abs_value(this->value);
    }

    void set_sword(int steps){
        this->chosen = false;
        Node *aux = this;
        for(int i = 0; i < steps; i++){
            if(this->value < 0){
                aux = aux->prev;
            }else{
                aux = aux->next;
            }
        }
        aux->chosen = true;
    }

    void show(){
        Node *aux = this->ord();
        cout << "[ ";
        do{
            if(aux->chosen){
                if(aux->value < 0){
                    cout << "<";
                }
            }
            cout << aux->value;
            if(aux->chosen){
                if(aux->value > 0){
                    cout << ">";
                }
            }
            cout << " ";
            aux = aux->next;
        }while(aux != this->ord());
        cout << "]" << endl;
    }

    int abs_value(int value){
        if(value < 0){
            value *= -1;
        }
        return value;
    }

    Node * ord(){
        Node *aux = this;
        Node *smaller = this;
        do{
            if(abs_value(aux->value) < abs_value(smaller->value)){
                smaller = aux;
            }
            aux = aux->next;
        }while(aux != this);
        return smaller;
    }

};

int main(){    
    int Num_ppl = 0;
    int sword = 0;
    int fase = 0;

    cin >> Num_ppl >> sword >> fase;

    Node * list = new Node(1*fase);
    if(sword == 1){
        list->chosen = true;
    }

    for(int i = 2; i <= Num_ppl; i++){
        fase = fase * -1;
        if(i == sword){
            list->new_Person(i, true, fase);
        }else{
            list->new_Person(i, false, fase);
        }
        list = list->next;
    }

    list->show();
    while(list->next != list){
        if(list->chosen){
            list->set_sword(list->kill());
            list->show();
        }
        list = list->next;
    }
    return 0;
}