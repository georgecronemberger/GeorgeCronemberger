Como eu fiz – Primeiro fiz um laço para deixar todos os caixas abertos(Caixas[i] = nullptr), depois tudo dentro do laço de tempo, para nao passar das 6h. Dentro gero um numero aleatorio de clientes por minuto, após isso outro laço com 'j' menor ou igualo numero de clientes gerados, entao inseri esse numero de clientes na fila, mas com a condição de que fila.size tem que ser menor que fila_maxima, ou seja, tem que ter espaço. Fora da condição mas dentro do 2º laço, faço um 3º laço para retirar da fila os clientes quando paciencia chegar a zero, caso não esteja em 0, paciencia decrementa. Dentro do ainda do 2º laço, mas fora do 3º, crio um 4º laço para adicionar os clientes nos caixas com ponteiro recebendo valor do vetor na posiçao [i], então a condição de que se o caixa tiver livre, caixa[i] vai receber o primeiro da fila(.front), depois apaga o 1º da fila(pop_front), outra condição para se caixa ja estiver com cliente e o cliente tiver documentos, numero de documentos decrementa e lucro aumenta, caso caixa não esteja livre e clientes com 0 documentos, delete p e caixa fica livre recebendo nullptr.
Fora de todos os laços, quando o tempo acabar, foi criado um laço para retirar os clientes dos caixas e outro retirar os clientes da fila, dando a função 'delete' em ambos. No fim retornando 'Lucro'. 

*Com quem fez – Contei com ajuda do Paulo, pois estava com dificuldade na parte de pegar os valores de documentos e paciencia.

*Oque eu aprendi – Aprendi a trabalhar mais um pouco com ponteiro.

*Quais as dificuldades – Ainda com dificuldade em ponteiros, passar por referencia, ainda me confundo na hora de usar '.', '->', e tive um pouco de dificuldade na utilização do iterator(Que foi onde recebi a ajuda).

*Tempo gasto – 2 dias mais ou menos.

George Cronemberger EC 3º semestre


# GeorgeCronemberger
