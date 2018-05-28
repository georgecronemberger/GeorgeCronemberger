#include <random>
#include "Libs/pintor.h"

#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>//funcao time
#include <stdlib.h> //funcao srand

using namespace std;

//Cada dia possui 6 horas de trabalho
//60 minutos x 6 horas = 360 minutos
//cada minuto eh um turno.
const int TURNOS_DIA = 360;

//A quantidade máxima de caixas não pode ser alterada.
const int MAX_CAIXAS = 10;

//Esse valor determina o quanto o banco por caixa por dia de trabalho
const int CUSTO_CAIXA_DIA = 100;

//numero de simulacoes de teste para cada caixa
const int N_EXEC_TESTE = 100;

//gera um numero entre min e max, [min, max]
int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}
int simulacao2(){
    Pintor pintor;
    //Determinar mínimo e maximo de "paciencia" e "documentos"
    int min_doc = 1, max_doc = 10;
    int min_pac = 1, max_pac = 5;
    int min_cli = 1, max_cli = 30;
    //Tempo da simulação
    const unsigned int tempo = TURNOS_DIA;
    const unsigned int numCaixas = MAX_CAIXAS;//5 caixas no banco

    //Vector para caixas e clientes nos caixas
    // Estruturas para representar os clientes
    // no caixa e na fila
    std::vector<Cliente*> caixa(numCaixas);
    std::list<Cliente*> fila;
    std::list<Cliente*> fila_de_saida;
    std::list<Cliente*>::iterator it;
    int fila_maxima= 40;
    int j,i;
    int lucro;

        for(int i = 0; i < numCaixas; i++)
            caixa[i] = nullptr;

        for(i = 0; i < tempo; i++){
            //Gerando numero de clientes aleatorios
            int nclientes = rand_mm(min_cli, max_cli);
            for(int j = 0; j <= nclientes; j++){
                //Inserindo aleatoriamente clientes(Valor da paciencia e Numero de documentos)
                //
                if(fila.size() < fila_maxima){
                     fila.push_back(new Cliente(rand_mm(min_pac, max_pac),
                                                rand_mm(min_doc, max_doc)));
                     }
//                else{
//                    fila_de_saida.push_back(new Cliente(rand_mm(min_pac, max_pac),
//                                                        rand_mm(min_doc, max_doc)));
//                }
                     //Retirar o Cliente caso paciencia chegue a 0;
                     for(it = fila.begin() ; it != fila.end() ; it++){
                        Cliente *p = *it;
                        if(p->paciencia == 0){
                        it = fila.erase(it);
                        it--;
                        delete p;
                        }else{
                         (*it)->paciencia--;
                        }
                        //Adicionar clientes para os caixas
                     for(int j = 0; j < numCaixas; j++){
                         Cliente *p = caixa[i];
                         if(p == nullptr){
                             caixa[i] = fila.front();
                             fila.pop_front();
                            }
                         //Decrementar documentos e adicionar no lucro
                         if(p != nullptr && p->documentos > 0){
                             p->documentos--;
                             lucro++;
                          //Documentos chegar a zero, retira o cliente e deixa o caixa livre
                         }else if(p != nullptr){
                             delete p;
                             caixa[i] = nullptr;
                         }
                     }
                  }
            }

        } //Devolver a Memória utilizada para o sistema
        for(int i = 0; i < numCaixas; i++){
            if(caixa[i] != nullptr){
                delete caixa[i];
            caixa[i] = nullptr;
            }
        }//Enquanto fila != de vazia, deleta o 1º dela e remove da lista
        while(!fila.empty()){
            delete fila.front();
            fila.pop_front();
        }
//        while(!fila_de_saida.empty()){
//            delete fila.front();
//            fila_de_saida.pop_front();
//        }
      return lucro;

}
int lucro_otimizado(int min_pac,int max_pac , int min_doc, int max_doc, int min_cli, int max_cli){
    int maior = 0;
    int caixas = 0;
    //Numero de caixas começando de 1 e no max = MAX_CAIXAS = 10.
    for(int i = 1; i <= 10; i++){
        int resto = 0;
        for(int j = 0; j < N_EXEC_TESTE; j++){
           //Nao entendi o porque do +=
            resto += simulacao2();

           resto = N_EXEC_TESTE/resto;
        //Se resto for maior que 'maior', maior recebe o valor de resto e caixas recebe o valor da posição de i(Numero de caixas)
           if(maior < resto){
               maior = resto;
               caixas = i;
           }
        }

    }
            return caixas;
}

void simulacao(){
    //Essa simulação é apenas uma mostragem de como
    //funciona a visualização.
    Pintor pintor;
   int min_pac = 1, max_pac = 10;
    int min_doc = 1, max_doc = 5;

   //Tempo da simulação
       const unsigned int tempo = TURNOS_DIA;
       const unsigned int numCaixas = 5;//5 caixas no banco

   //    // Estruturas para representar os clientes
   //    // no caixa e na fila
       std::vector<Cliente*> caixa(numCaixas);
       std::list<Cliente*> fila;

    int qtd = 30;
    for(int i = 0; i < qtd; i++)
        fila.push_back(new Cliente(rand_mm(min_pac, max_pac),
                                   rand_mm(min_doc, max_doc)));

    caixa[0] = new Cliente(MAX_PACIENCIA, 5);//tem cliente no primeiro caixa
    caixa[2] = new Cliente(0, 5);//tem cliente no terceiro caixa


    for (unsigned int i = 0; i < tempo; i++)
    {
        caixa[2]->documentos = i;//aumentando os documentos desse cliente
        pintor.desenhar(caixa, fila, 1000);

        //removendo um cliente da fila aleatoriamente
        if(!fila.empty()){
            Cliente * cliente = fila.front();
            fila.pop_front();
            delete cliente;
        }

        //inserindo clientes aleatoriamente
        if(rand_mm(0, 9) < 7){
            fila.push_back(new Cliente(rand_mm(15, 20), rand_mm(10, 20)));
        }
    }


    delete caixa[1];
    caixa[1] = nullptr;

    for(int i = 1; i < qtd; i++){
        delete fila.front();
        fila.pop_front();
    }

}
int main(){
    int min_doc = 1, max_doc = 10;
    int min_pac = 1, max_pac = 5;
    int min_cli = 1, max_cli = 30;
    //simulacao();
    simulacao2();
    //executar_testes();
    cout << "Quantidade de caixas ideal: " << lucro_otimizado(min_pac,max_pac,min_doc,max_doc,min_cli,max_cli) << endl;
    return 0;
}
