#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>
using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'g';
const char ABATIDO = 'm';


void showMat(matchar& mat, Par inicio, Par fim, Par atual){
    mat_draw(mat);
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
    mat_focus(atual, 'y');
    ed_show();
}

vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par)){
		if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
        	cont++;
	}
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
	std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

void furar(matchar& mat, Par par){

    stack<Par> pilha;

    Par aux;

    mat.get(par) = ABERTO;

    for(Par vizinho : shuffle(getNeib(par))){
            pilha.push(vizinho);
    }
    while(pilha.size() != 1){

        if(mat.equals(pilha.top(), PAREDE) && countOpen(mat, pilha.top()) < 2){
            mat.get(pilha.top()) = ABERTO;
            aux = pilha.top();
            pilha.pop();

            for(Par vizinho : shuffle(getNeib(aux))){
                pilha.push(vizinho);
            }
        } 
        else
            pilha.pop();
    }
}

void findPath(matchar& mat, Par inicio, Par fim){

   stack<Par> pilha;
   Par aux;

   if(inicio == fim){
      mat.get(fim) = CAMINHO;
   }

   mat.get(inicio) = CAMINHO;
   for(Par vizinho : shuffle(getNeib(inicio))){
       pilha.push(vizinho);
   }
   while(pilha.size() != 0){
       if(pilha.top() == fim){
          mat.get(pilha.top()) = CAMINHO;
          return;
       }
       else if(mat.equals(pilha.top(), ABERTO)){
           aux = pilha.top();
           mat.get(pilha.top()) = CAMINHO;
           mat_draw(mat);
           mat_focus(pilha.top(), 'y');
           ed_show();

           pilha.pop();

           for(Par vizinho : shuffle(getNeib(aux))){
               pilha.push(vizinho);
           }
       }
       else
          pilha.pop();
   }

}

int main(){
    srand(time(NULL));

    matchar mat(15, 20, PAREDE);

    furar(mat, Par(1,1));
     mat_draw(mat);
     ed_show();

    Par inicio = mat_get_click(mat, "digite o local de inicio");
    if(!mat.equals(inicio, ABERTO))
        return 0;
    Par fim = mat_get_click(mat, "digite o local de fim");
    if(!mat.equals(fim, ABERTO))
        return 0;

    findPath(mat, inicio, fim);
    mat_draw(mat);
    ed_show();

    ed_lock();
    return 0;
}

