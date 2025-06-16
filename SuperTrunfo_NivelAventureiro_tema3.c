#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
// Estrutura para representar uma carta de pa�s
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} CartaPais;

// Fun��o para exibir os dados de uma carta
void exibirCarta(CartaPais carta) {
    printf("\nDados do país %s:\n", carta.nome);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km2\n", carta.area);
    printf("PIB: %.2f trilhões de dólares\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade demográfica: %.2f hab/km2\n", carta.densidade_demografica);
}

// Função para comparar duas cartas
void compararCartas(CartaPais carta1, CartaPais carta2, int atributo) {
    printf("\nComparando %s vs %s:\n", carta1.nome, carta2.nome);

    switch(atributo) {
        case 1: // Popula��o
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);

            if(carta1.populacao > carta2.populacao) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if(carta2.populacao > carta1.populacao) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 2: // �rea
            printf("Atributo: área\n");
            printf("%s: %.2f km2\n", carta1.nome, carta1.area);
            printf("%s: %.2f km2\n", carta2.nome, carta2.area);

            if(carta1.area > carta2.area) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if(carta2.area > carta1.area) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f trilhôes de dólares\n", carta1.nome, carta1.pib);
            printf("%s: %.2f trilhôes de dólares\n", carta2.nome, carta2.pib);

            if(carta1.pib > carta2.pib) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if(carta2.pib > carta1.pib) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 4: // Pontos tur�sticos
            printf("Atributo: Pontos turísticos\n");
            printf("%s: %d\n", carta1.nome, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.nome, carta2.pontos_turisticos);

            if(carta1.pontos_turisticos > carta2.pontos_turisticos) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if(carta2.pontos_turisticos > carta1.pontos_turisticos) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        case 5: // Densidade demogr�fica (regra invertida - menor valor vence)
            printf("Atributo: Densidade demográfica (menor valor vence)\n");
            printf("%s: %.2f hab/km2\n", carta1.nome, carta1.densidade_demografica);
            printf("%s: %.2f hab/km2\n", carta2.nome, carta2.densidade_demografica);

            if(carta1.densidade_demografica < carta2.densidade_demografica) {
                printf("Vencedor: %s\n", carta1.nome);
            } else if(carta2.densidade_demografica < carta1.densidade_demografica) {
                printf("Vencedor: %s\n", carta2.nome);
            } else {
                printf("Empate!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    // Criando duas cartas de exemplo (poderia ser substitu�do pelo cadastro do desafio anterior)
    CartaPais brasil = {
        "Brasil",
        213317639,
        8515767.049,
        1.609,
        15,
        25.05  // densidade calculada: popula��o/�rea
    };

    CartaPais eua = {
        "Estados Unidos",
        331449281,
        9833517.0,
        22.675,
        25,
        33.71  // densidade calculada: popula��o/�rea
    };

    int opcao;

    do {
        // Exibindo menu
        printf("\n=== SUPER TRUNFO - COMPARAR CARTAS ===\n");
        printf("1 - Comparar por População\n");
        printf("2 - Comparar por área\n");
        printf("3 - Comparar por PIB\n");
        printf("4 - Comparar por Pontos Turísticos\n");
        printf("5 - Comparar por Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Limpar buffer do teclado
        while(getchar() != '\n');

        if(opcao == 0) {
            printf("Saindo do jogo...\n");
            break;
        }

        // Exibir as cartas para refer�ncia
        exibirCarta(brasil);
        exibirCarta(eua);

        // Comparar as cartas conforme a op��o escolhida
        if(opcao >= 1 && opcao <= 5) {
            compararCartas(brasil, eua, opcao);
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }

        printf("\nPressione Enter para continuar...");
        getchar();

    } while(opcao != 0);

    return 0;
}
