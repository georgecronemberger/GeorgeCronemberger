#include <iostream>
#include <random>

using namespace std;
//Normal - Espada passando pro seguinte
/*int mata_entrega(int espada, int vet[], int tamanho){
    espada = (espada + 1) % tamanho;

    while(vet[espada] == 0)
        espada = (espada + 1) % tamanho;

    vet[espada] = 0;

    while(vet[espada] == 0)
        espada = (espada + 1) % tamanho;

    return espada;
}
*/
int mata_passa(int espada, int vet[], int tamanho,int saltos){
    espada = (espada + saltos) % tamanho + 1;

    while(espada == 0)
        espada = (espada + saltos) % tamanho + 1;

    vet[espada] = 0;

    while(espada == 0)
        espada = (espada + saltos) % tamanho + 1;

    return espada;
}

int main()
{
    int qtd, inicial, vivos;
    int i, espada;

    cout << "Quantidade de cavaleiros : ";
    cin >> qtd;

    int *vet = new int[qtd];

    for(i = 1 ; i <= qtd ; i++){
        vet[i] = i;
    }

    cout << "Informe um numero para começar: ";
    cin >> inicial ;

    vivos = qtd;
    espada = inicial;

    int saltos;

    cout << "Digite o numero de saltos" << endl;
    cin >> saltos;

    while(vivos > 1){

        espada = mata_passa(espada, vet, qtd,saltos);
        vivos--;

    }

    cout << "Vencedor : " << espada << endl;
    return 0;
}
