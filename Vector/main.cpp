#include <iostream>

using namespace std;

struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];//retorno zerado
    }
    void push_back(int value){
        if(this->_size == this->_capacidade){
            reserve(2*this->_capacidade);
            return;
}
        this->_data[this->_size] = value;
        this->_size += 1;

    }
    void pop_back(){
        if(this->_size == 0)
            return;
        this->_data[_size] = 0;
        this->_size -= 1;
    }

    //retornar a refencia à variavel dessa posicao
    int& at(int indice){
        return this->_data[indice];
    }
    int& front(){
        return this->_data[0];
    }
    int& back(){
        return this->_data[this->_size - 1];
    }
    int * begin(){
        return &this->_data[0];
    }
    int * end(){
        return &this->_data[this->_size];
    }
    int size(){
        return this->_size;
    }
    int capacity(){
        return this->_capacidade;
    }

    void reserve(int capacity){
        int salvar[this->_capacidade]; // capacidade pode ta cheia

        for(int i = 0; i < this->_size; i++)
        salvar[i] = this->_data[i];


        if(capacity >= this->_size)
            this->_capacidade = capacity;

        else if(capacity < this->_size){
            this->_capacidade = capacity;
            this->_size = capacity;
        }

        for(int j = 0; j < this->_size;j++)
            this->_data[j] = salvar[j];
    }


};


#include <vector>
int main()
{

    Vetor pt(2);
    pt.push_back(10);
    pt.push_back(12);
    pt.push_back(32);
    pt.push_back(3);
    pt.reserve(2);

    cout << pt.at(0)<<"\n";
    cout<<pt.at(2)<<"\n";
    cout<<pt.size()<<"\n";
    cout<<pt.capacity()<<"\n";

    return 0;
}
