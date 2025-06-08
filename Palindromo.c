#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura para permitir a acentuação do portugues
    
    // Declaração de variáveis
    int numero_gerado, numero_temp, numero_invertido, digito, pontuacao = 0, rodada_atual, total_rodadas = 5;
    char resposta_usuario;

    srand(time(NULL)); // Inicializa o gerador de números aleatórios para garantia de uma sequência diferente de números gerados a cada execução do programa.

    printf("Quiz palíndromo numericode, seja bem vindo!\n");
    printf("Você terá que identificar se os números gerados são palíndromos.\n");
    printf("Responda 'S' para Sim ou 'N' para Não.\n\n");

    for (rodada_atual = 1; rodada_atual <= total_rodadas; rodada_atual++) {

        numero_gerado = rand() % 9999 + 1; // Gera um número aleatório e ajusta o deslocamento da escala

        printf("--- Rodada %d de %d ---\n", rodada_atual, total_rodadas);
        printf("O número gerado é: %d\n", numero_gerado);
        printf("Este número é um palindromo? (S/N): ");

        scanf(" %c", &resposta_usuario); //Antes da leitura realiza alimpeza do buffer de entrada
        
        // Lógica que permite a verificação se numero_gerado é um palíndromo e sua inicialização
        numero_temp = numero_gerado;
        numero_invertido = 0;

		// Inversão do número através do loop
        while (numero_temp > 0) {
            digito = numero_temp % 10;
            numero_invertido = numero_invertido * 10 + digito;
            numero_temp = numero_temp / 10;
        }

		// Após inversão, verifica se o número original é igual ao invertido
        if (numero_gerado == numero_invertido) {
            if (resposta_usuario == 'S' || resposta_usuario == 's') {
                printf("Resposta correta! %d é realmente um palíndromo.\n", numero_gerado);
                pontuacao++;
            } else if (resposta_usuario == 'N' || resposta_usuario == 'n') {
                printf("Resposta incorreta. %d é um palíndromo.\n", numero_gerado);
            } else {
                printf("Resposta inválida. O número %d é um palíndromo.\n", numero_gerado);
            }
        } else {
            if (resposta_usuario == 'N' || resposta_usuario == 'n') {
                printf("Resposta correta! %d não é um palíndromo.\n", numero_gerado);
                pontuacao++;
            } else if (resposta_usuario == 'S' || resposta_usuario == 's') {
                printf("Resposta incorreta. %d não é um palíndromo.\n", numero_gerado);
            } else {
                printf("Resposta inválida. O número %d não é um palíndromo.\n", numero_gerado);
            }
        }
        printf("\n");
    }

    printf("Fim do jogo!\n");
    printf("Sua pontuação final é: %d de %d\n", pontuacao, total_rodadas);

    return 0;
}

