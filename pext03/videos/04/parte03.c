/*
O if é conhecido como estrutura de decisão simples. 
Ele é utilizado quando queremos executar um trecho de código apenas se determinada condição
for verdadeira.
A palavra if, em inglês, significa ‘se’. Então a lógica funciona assim: se algo acontecer, o
programa executa determinada ação. Caso a condição seja falsa, o bloco simplesmente é
ignorado.
A estrut

if <condicao>{
    bloco de comandos so executado se a condicao for verdadeira;
}

*/


#include <stdio.h>

int main() {
    int peso = 100;
    int limite = 110;

    if (peso<limite){
        printf("Pode participar da competicao\n\n");
    }

    if (peso<limite) 
        printf("SEM {} Pode participar da competicao\n");

    if (peso<limite)
        printf("\nOUTRO Pode participar da competicao\n");
        printf("Sempre aparece\n");

    if (peso<limite){
        printf("\nFINAL Pode participar da competicao\n");
        printf("So aparece com o de cima\n");
    }

    return 0;
}
