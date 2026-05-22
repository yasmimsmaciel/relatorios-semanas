#include <stdio.h>


int main() {
    // Sensores de um controlador industrial
    int pressao = 100;
    int limite = 80;
    int verif_pressao = pressao > limite;
    int uno = 1;
    int emergencia_ativa = 0; // 0 para falso, 1 para verdadeiro

    printf("verif_pressao = %d\t\tuno = %d\t\temergencia_ativa = %d\n",verif_pressao,uno,emergencia_ativa);

    int resultado_vago = emergencia_ativa && verif_pressao <= uno;
 
    int resultado_seguro = (emergencia_ativa && verif_pressao) <= uno;


    printf("Resultado sem clareza: %d\n", resultado_vago);
    printf("Resultado com parenteses: %d\n\n", resultado_seguro);


    // Exemplo de calculo matematico
    float calculo_ambiguo = 10 + 20 / 2 * 5;
    float calculo_claro = (10.0 + 20.0) / (2.0 * 5.0);


    printf("Calculo automatico do C: %.2f\n", calculo_ambiguo);
    printf("Calculo forcado por parenteses: %.2f\n", calculo_claro);


    return 0;
}
