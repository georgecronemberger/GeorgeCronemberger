*Como eu fiz – 
	Cortarabo -> Começa da cabeça da lista até encontrar o valor dado na main e então removo ele e todos os que vierem após ele.
	Push_back -> Condição de se o node for nullptr, node receber novo value, senão o proximo node recebe a funcao com parametro node-next para andar na lista.
	Size iterativo -> criei a variavel cont iniciada em 0, fiz o laço coma  condição de rodar enquanto node for diferente de nullptr(Fim da lista) e cada volta cont incrementa. Depois node recebe o proximo da lista. No fim retorna cont.
	Size recursivo -> Cria a variável cont iniciando em 0, coloca a condição de node == nullptr ( caso a lista seja vazia. Fora da condição cont recebe a função sizeR recebendo node->next(proximo elemento da lista. No fim retorna cont + 1.
	Inserir Ordenado Recursivo -> Fiz a condição de se node == nullptr ou o valor dele for menor igual ao valor da main, então node recebe novo valor e retorna node no fim, senão proximo node recebe a função passando por paramentro, node apontando pro proximo e value.
	Somar Recursivo -> Cria a condição de caso a lista seja vazia, retornar 0. Depois Retorna valor do node + a função recebendo node->next(proximo elemento da lista) como paramentro.
	Remove Iterativo -> Crio dois nodes para receber cabeça e um auxiliar(anterior, inicializando como nullptr), então cria o laço com as condições de enquanto node for diferente de nullptr e valor do node for igual ao valor dado, anterior recebe node e node recebe o valor do proximo(vai apontar pro seguinte ao numero que foi removido). Depois cria a condição para verificar se a lista é válida ou vazia, e a condição para remover do inicio(node == nullptr) ou do meio ou do meio e fim (anterior->next = node-> next).

 
*Com quem fez – Tive ajuda de Jeronimo e Adan.

*Oque eu aprendi – Aprendi a trabalhar com struct e a funcionamento das listas e ponteiros, apesar da dificuldade.

*Quais as dificuldades – Dificuldade na Linguagem C++ em geral, nesse programa mais especifico, em trabalhar com ponteiros.

*Tempo gasto – 1 semana mais ou menos.


George Cronemberger EC 3º semestre
