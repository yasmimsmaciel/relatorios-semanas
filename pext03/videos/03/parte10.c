#include <stdio.h>


int main() {
    // Variáveis que simulam sensores de um controlador industrial
    int pressao = 100;
    int limite = 80;
    int emergencia_ativa = 0; // 0 para falso, 1 para verdadeiro
    /*
       EXPRESSÃO SEM PARÊNTESES
       A precedência do C resolverá primeiro o '&&', depois o '>',
       o que pode não ser o que o engenheiro pretendia.
    */
    int resultado_vago = emergencia_ativa && pressao > limite;
    /*
       EXPRESSÃO COM PARÊNTESES
       Aqui garantimos que a comparação de pressão ocorra primeiro,
       seguida pela lógica de emergência.
    */
    int resultado_seguro = emergencia_ativa || (pressao > limite);


    printf("Resultado sem clareza: %d\n", resultado_vago);
    printf("Resultado com parenteses (desejado): %d\n\n", resultado_seguro);


    // Exemplo de calculo matematico
    // Sem parenteses: 10 + 20 / 2 * 5 = 60
    // Com parenteses: (10 + 20) / (2 * 5) = 3
    float calculo_ambiguo = 10 + 20 / 2 * 5;
    float calculo_claro = (10.0 + 20.0) / (2.0 * 5.0);


    printf("Calculo automatico do C: %.2f\n", calculo_ambiguo);
    printf("Calculo forcado por parenteses: %.2f\n", calculo_claro);


    return 0;
}
