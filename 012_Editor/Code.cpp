#include <iostream>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

struct Ambient{
    list<char> texto;
    list<char>::iterator cursor;

    Ambient(){
        this->cursor = this->texto.begin();
    }

    void show(){
        if(this->texto.begin() != this->texto.end()){
            for(auto it = this->texto.begin(); it != this->texto.end(); it++){
                if(it == this->cursor){
                    cout << "|";
                }
                cout << *it;
            }
            if(this->cursor == this->texto.end()){
                cout << "|";
            }
        }else{
            cout << "|";
        }
        cout << "\n";
    }

    void write(char value){
        this->texto.insert(this->cursor, value);
        this->cursor = this->cursor++;
    }

    void ret(){
        write('\n');
    }

    void back(){
        if(this->cursor != this->texto.begin()){
            auto elem = this->cursor;
            elem--;
            this->texto.erase(elem);
        }
    }

    void del(){
        if(this->cursor != texto.end()){
            auto elem = this->cursor;
            this->cursor++;
            this->texto.erase(elem);
        }
    }

    void right(){
        if(this->cursor != this->texto.end()){
            this->cursor++;
        }
    }

    void left(){
        if(this->cursor != this->texto.begin()){
            this->cursor--;
        }
    }

    void undo(){

    }

    void redo(){

    }

    int count_char(){
        auto it = this->cursor;
        int count = 0;
        if(*it == '\n'){
            it--;
            count++;
        }
        while(*it != '\n' && it != this->texto.begin()){
            it--;
            count++;
        }
        if(it == this->texto.begin()){
            count++;
        }
        return (count-1);
    }

    //fase = true (up); fase = false (down)
    void move_cursor(list<char>::iterator& cursor, bool fase){
        if(fase){
            if(*cursor == '\n'){
                cursor--;
            }
            while(*cursor != '\n' && cursor != this->texto.begin()){
                cursor--;
            }
        }else{
            if(*cursor == '\n'){
                cursor++;
            }else{
                while(*cursor != '\n' && cursor != this->texto.end()){
                    cursor++;
                }
                if(*cursor == '\n'){
                    cursor++;
                }
            }
        }
    }

    void up(){
        int nchar = count_char();
        auto cursor = this->cursor;
        cout << nchar << endl;
        move_cursor(cursor, true);
        if(cursor == this->texto.begin()){
            return;
        }
        cursor--;
        move_cursor(cursor, true);
        if(*cursor == '\n'){
            cursor++;
        }
        while(*cursor != '\n' && cursor != this->texto.end() && nchar > 0){
            nchar--;
            cursor++;
        }
        this->cursor = cursor;
    }

    void down(){
        int nchar = count_char();
        auto cursor = this->cursor;
        cout << nchar << endl;
        move_cursor(cursor, false);
        if(cursor == this->texto.end()){
            return;
        }
        while(*cursor != '\n' && cursor != this->texto.end() && nchar > 0){
            nchar--;
            cursor++;
        }
        this->cursor = cursor;
    }
};

int main(){
    string user_input;
    Ambient* editor = new Ambient();
    while(true){
        getline(cin, user_input);
        stringstream ui(user_input);
        char cmd;
        while(ui >> cmd){
            if(cmd == 'R'){
                editor->ret();
            }else if(cmd == 'B'){
                editor->back();
            }else if(cmd == 'D'){
                editor->del();
            }else if(cmd == '>'){
                editor->right();
            }else if(cmd == '<'){
                editor->left();
            }else if(cmd == 'Z'){
                
            }else if(cmd == 'Y'){
                
            }else if(cmd == 'A'){
                editor->up();
            }else if(cmd == 'V'){
                editor->down();
            }else{
                editor->write(cmd);
            }
        }
        editor->show();
    }
}