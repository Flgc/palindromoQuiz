#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int numero_gerado, numero_temp, numero_invertido, digito, pontuacao = 0, rodada_atual, total_rodadas = 5;
    char resposta_usuario;

    srand(time(NULL));

    printf("Quiz pal�ndromo numericode, seja bem vindo!\n");
    printf("Voc� ter� que identificar se os n�meros gerados s�o pal�ndromos.\n");
    printf("Responda 'S' para Sim ou 'N' para N�o.\n\n");

    for (rodada_atual = 1; rodada_atual <= total_rodadas; rodada_atual++) {

        numero_gerado = rand() % 9999 + 1;

        printf("--- Rodada %d de %d ---\n", rodada_atual, total_rodadas);
        printf("O n�mero gerado �: %d\n", numero_gerado);
        printf("Este n�mero � um palindromo? (S/N): ");

        scanf(" %c", &resposta_usuario);
        numero_temp = numero_gerado;
        numero_invertido = 0;

        while (numero_temp > 0) {
            digito = numero_temp % 10;
            numero_invertido = numero_invertido * 10 + digito;
            numero_temp = numero_temp / 10;
        }

        if (numero_gerado == numero_invertido) {
            if (resposta_usuario == 'S' || resposta_usuario == 's') {
                printf("Resposta correta! %d � realmente um pal�ndromo.\n", numero_gerado);
                pontuacao++;
            } else if (resposta_usuario == 'N' || resposta_usuario == 'n') {
                printf("Resposta incorreta. %d � um pal�ndromo.\n", numero_gerado);
            } else {
                printf("Resposta inv�lida. O n�mero %d � um pal�ndromo.\n", numero_gerado);
            }
        } else {
            if (resposta_usuario == 'N' || resposta_usuario == 'n') {
                printf("Resposta correta! %d n�o � um pal�ndromo.\n", numero_gerado);
                pontuacao++;
            } else if (resposta_usuario == 'S' || resposta_usuario == 's') {
                printf("Resposta incorreta. %d n�o � um pal�ndromo.\n", numero_gerado);
            } else {
                printf("Resposta inv�lida. O n�mero %d n�o � um pal�ndromo.\n", numero_gerado);
            }
        }
        printf("\n");
    }

    printf("Fim do jogo!\n");
    printf("Sua pontua��o final �: %d de %d\n", pontuacao, total_rodadas);

    return 0;
}

