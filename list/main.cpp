#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    void deletarTudo(Node * node){

    }

    //5 4 7 8 9 3 1
    //cortarRabo(8)
    //5 4 7
    //procura o valor, remove desse no em diante

    Node * arrancaRabo(Node * node, int value){
                if(node == nullptr)
                    return nullptr;

        node->next = arrancaRabo(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
       }

    Node * cortarRabo(Node * node, int value){
    if(node == nullptr)
        return nullptr;

    node->next = cortarRabo(node->next, value);

    if(node->value == value){
      delete node;
      return nullptr;
         }
    return node;
    }

    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    Node * _push_back(Node * node, int value){
        //todo
    if(node == nullptr)
        node = new Node(value,nullptr);
else
        node->next = _push_back(node->next,value);
        return node;
    }

    void rpush_back(int value){
        this->head = _push_back(head,value);
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }
public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    void iremove(int value){
        Node *node = head;
        Node *anterior = nullptr;

        while(node != nullptr && node->value == value)
                anterior = node;
                node = node->next;

         if(node == nullptr)
             return;
         if(anterior == nullptr)
             head = node->next;
         else
             anterior->next = node->next;

        //todo
    }
    /*
    head = 900;
    900:{1 500};
    500:{2 700};
node700:{4 250};
    300:{6 0};
    250:{5 300};
    */

    //5
    //2 >4 X 6
    void inserir_ordenado(int value){
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while(node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    Node * _rinserir_ordenado(Node * node, int value){
        if(node == nullptr || node->value <= value){
            node = new Node(value,node);
            return node;
    }
        else
        node->next = _rinserir_ordenado(node->next, value);

    //todo
    }

    void rinserir_ordenado(int value){
        //todo
        this->head = _rinserir_ordenado(head,value);
    }

    //todo
    int size(Node *node){
    int cont = 0;

    while(node != nullptr){
    cont++;

    node = node->next;
    }
    return cont;
    }

    int sizeR(Node * node){
    int cont = 0;
    if(node == nullptr)
        return 0;

    cont += sizeR(node->next);
    return cont + 1;
    }

    int rsomar(Node * node){
        //todo
    if(node == nullptr)
        return 0;

    return node->value + rsomar(node->next);
    }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

};

int main(){
    SList listen;
    listen.rpush_back(5);
    listen.rpush_back(12);
    int aux = 0;
    aux = listen.rsomar(listen.head);
    cout<<aux<<"\n";

    //lista.rpush_back(30);
    //lista.ishow();
    return 0;
}
