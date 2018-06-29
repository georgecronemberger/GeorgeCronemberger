#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int linhas= 20;
const int colunas=70;

struct Par{
    int l, c;
};

void mostrar(char mat[linhas][colunas]);
void limpar();
void esperar();
int queimar(int l, int c,char mat[linhas][colunas], int nivel);
vector<Par> vizinhos(int lin, int col);
vector<Par> embaralhar(vector<Par> vet);

int main(){

    char mat[linhas][colunas];
    int qtd= 1000,lin, col, total=0;

    for(int l = 0; l < linhas; l++){
       for(int c = 0; c < colunas; c++){
           mat[l][c] = '.';
    	}
	}

    for(int i = 0; i < qtd; i++){
        mat[rand() % linhas][rand() % colunas] = '#';
     }

    limpar();
    mostrar(mat);

    cout << endl;

    cout << "Digite a linha e coluna para pegar fogo" << endl;

    cin >> lin >> col;

    total = queimar(lin, col, mat, 0);

    cout << "O numero de arvores queimadas foi: " << total << endl;

    return 0;
}


void mostrar(char mat[linhas][colunas]){

    for(int l = 0; l < linhas; l++){
        for(int c = 0; c < colunas; c++){
            cout << mat[l][c];
		}
		cout << endl;
    }
}

void limpar(){
    for(int i= 0; i < 20; i++){
		cout << endl;
    }
}

void esperar(){
    char c;
    cin >> std::noskipws >> c;
}

int queimar(int l, int c, char mat[linhas][colunas], int nivel){ 
    int cont = 0;

	if( l < 0 or l >= linhas)
       return 0;
	if( c < 0 or c >= colunas)
       return 0;
	if( nivel >= 10)
       nivel = 0;
	if( mat[l][c] == '#'){
       cont = 1;
       mat[l][c] = '0' + nivel;
       limpar();
       mostrar(mat);
	   esperar();
	   for(auto par : embaralhar(vizinhos(l,c))){
	      cont += queimar(par.l, par.c, mat, nivel + 1);
 	   }

    	mat[l][c] = 'o';
    	limpar();
    	mostrar(mat);
    	esperar();
	}
   
   return cont;

}

vector<Par> vizinhos(int lin, int col){

    vector<Par> viz;

    viz.push_back(Par{lin, col - 1});
    viz.push_back(Par{lin, col + 1});
    viz.push_back(Par{lin - 1, col});
    viz.push_back(Par{lin + 1, col});

    return viz;
}

vector<Par> embaralhar(vector<Par> vet){

    for(int i = 0; i < (int)vet.size(); i++){
        int aleat = rand() % vet.size();
        Par aux = vet[i];
        vet[i] = vet[aleat];
        vet[aleat] = aux;
    }
    return vet;
}