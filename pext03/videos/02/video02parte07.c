/*
> Além de ler e escrever, você também pode converter dados usando strings.

>> Para isso, temos as funções:
>>> sscanf
    - lê dados de uma string (diferente da scanf que lê dados do teclado que o usuário digitar)
    - faz comparação de formatos e atribui valores a variáveis
    - retorna o número de variáveis que receberam valores corretamente (ele só lê a segunda se a primeira tiver sido feita corretamente, e assim em diante)
    - parâmetros: sscanf (string original char* ou vetor char,  formato que quer ser lido, endereços de memoria das variaveis que quer guardar no formato definido)
>>> sprintf
    - pega variáveis separadas e escreve dentro de uma string conforme formato definido. Nao joga na tela e sim em uma string
    - parâmetros: sprintf (a ,  b, c);
        -- a: string destino char* ou vetor char
        -- b: formato que quer ser lido
        -- c: variaveis que quer guardar no formato definido - nao usa o &, assim como no printf
    - evolução: o snprintf tem uma entrada extra para limitar a string final - se passar do tamanho, ele corta o texto em vez dar erro no programa
    - parâmetros: snprintf (a ,  b, c, d);
        -- a: string destino char* ou vetor char
        -- b: tamanho maximo da string
        -- c: formato que quer ser lido
        -- d: variaveis que quer guardar no formato definido - nao usa o &, assim como no printf   

>> Essas funções permitem transformar dados sem precisar de entrada direta do usuário, por isso são muito úteis quando você trabalha com:
	•	Arquivos
	•	Interfaces
	•	Manipulação de dados
*/

#include <stdio.h>

int main(){
    char str[]="12 3";
    int num;
    printf("num=%d\n",num);
    sscanf(str, "%d", &num);
    printf("num=%d\n\n",num);

    num=456;
    printf("str=\"%s\"\n",str);
    sprintf(str, "%d", num);
    printf("str=\"%s\"\n",str);
}