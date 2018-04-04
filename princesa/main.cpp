#include <iostream>
#include <list>
using namespace std;

void rodar(list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();

}
int main()
{
   int qtd = 0, escolhido = 0 ;
   cout << "Digite qtd e escolhido" << endl;
   cin >> qtd >> escolhido;

   list<int> lista;
   for(int i = 1; i <= qtd; i++)
       lista.push_back(i);
   while(lista.front() != escolhido)
       rodar(lista);
    while(lista.size() > 1){
        int j = lista.front();
        rodar(lista);
        lista.pop_front();
        for( int j = 0 ; j < saltos; j++)
            rodar(lista);

    }


}
