#include "iostream"
#include "sstream"
#include "string"
#include "vector"
#include "list"
#include "queue"

using namespace std;

struct Client{
    string id;
    int docs;
    int patience;

    Client(string id, int docs, int patience){
        this->id = id;
        this->docs = docs;
        this->patience = patience;
    }
};

struct Bank{
    vector<Client*> boxes;
    list<Client*> input_queue;
    queue<Client*> output_queue;

    void start_boxes(int qtd_boxes){ //Liga os caixa -> [][]...[]
        for(int i = 0; i < qtd_boxes; i++){
            this->boxes.push_back(nullptr);
        }
    }

    void show(){ //Mostra a visualização dos caixas e das filas: | [][]...[] | in :{} | out :{}
        //Visualização dos caixas        
        for(int i = 0; i < this->boxes.size(); i++){
            if(this->boxes[i] == nullptr){
                cout << "[]";
            }else{
                cout << "[" << this->boxes[i]->id << ":" << this->boxes[i]->docs << ":" << this->boxes[i]->patience << "]";
            }
        }
        cout << endl;

        //Visualização da fila de entrada in :{ }
        cout << "in :{ ";
        for(auto client : this->input_queue){
            cout << client->id << ":" << client->docs << ":" << client->patience << " ";
        }
        cout << "}" << endl;

        //Visualização da fila de saida
        cout << "out:{ ";
        queue<Client*> copy = this->output_queue;
        while(!copy.empty()){
            cout << copy.front()->id << ":" << copy.front()->docs << ":" << copy.front()->patience << " ";
            copy.pop();
        }
        cout << "}" << endl;
    }

    void insert(string id, int docs, int patience){
        Client* client = new Client(id, docs, patience);
        this->input_queue.push_back(client);
    }

    void tic_tac(int* docs_rec, int* docs_lost){
        while(this->output_queue.empty() != true){
            *docs_lost += this->output_queue.front()->docs;
            this->output_queue.pop();
        }

        for(int i = 0; i < this->boxes.size(); i++){
            if(this->boxes[i] != nullptr){
                if(this->boxes[i]->docs > 0){
                    this->boxes[i]->docs--;
                    *docs_rec += 1;
                }else{
                    this->output_queue.push(this->boxes[i]);
                    this->boxes[i] = nullptr;
                }
            }else{
                if(!this->input_queue.empty()){
                    this->boxes[i] = this->input_queue.front();
                    this->input_queue.pop_front();
                }
            }
        }

        auto client = this->input_queue.begin();
        while(client != this->input_queue.end()){
            if((*client)->patience > 0){
                (*client)->patience--;
                client++;
            }else{
                this->output_queue.push(*client);
                client = this->input_queue.erase(client);
            }
        }
        /*for(auto client = this->input_queue.begin(); client != this->input_queue.end(); client++){
        }*/
    }

};

int main(){
    Bank bank;
    string commands, cmd;
    int docs_rec = 0, docs_lost = 0, t_bank = 0;
    bool init_boxes = false, rec_ppl = true;

    while(true){

        getline(cin, commands);
        stringstream ui(commands);
        
        ui >> cmd;

        if(cmd == "end"){
            break;
        }        
        if(cmd == "init"){
            int qtd_boxes;
            ui >> qtd_boxes;
            if(!init_boxes){
                bank.start_boxes(qtd_boxes);
                init_boxes = true;                
            }
        }
        if(cmd == "tic"){
            bank.tic_tac(&docs_rec, &docs_lost);
            t_bank++;
        }
        if(cmd == "show"){
            bank.show();
        }
        if((cmd == "in") && (rec_ppl)){
            string id;
            int docs, patience;
            ui >> id >> docs >> patience;
            bank.insert(id, docs, patience);
        }
        if(cmd == "fim"){
            rec_ppl = false;
            cout << "turnos passados: " << t_bank << endl;
            cout << "docs recebidos: " << docs_rec << endl;
            cout << "docs perdidos: " << docs_lost << endl;
        }

    }
}