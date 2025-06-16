#include<stdio.h>

int main(int argc, char const *argv[])
{
    // Variáveis para a Carta 1
    char codigocarta1[6];
    char nomepais1[50];
    int populacao1;
    float area1;
    long long int pib1;
    int pontotur1;
    float densdemo1;
    float rendper1;
    long long int superpower1;
    double densdinversa1;
     
    // Variáveis para a Carta 2
    char codigocarta2[6];
    char nomepais2[50];
    int populacao2;
    float area2;
    long long int pib2;
    int pontotur2;
    float densdemo2;
    float rendper2;
    long long int superpower2;
    double densdinversa2;
     
    int opcao;
    int resultado;

    printf("******** CADASTRO DAS CARTAS JOGO SUPER TRUNFO ********\n\n");

    // Cadastro Carta 1
    printf("Digite o codigo da carta 1: ");
    scanf("%4s", codigocarta1);
    printf("Entre com o nome do país 1: ");
    scanf(" %49[^\n]", nomepais1);
    printf("Qual o total de habitantes?: ");
    scanf("%d", &populacao1);
    printf("Qual a area (em km2)?: ");
    scanf("%f", &area1);
    printf("Qual o PIB? (digite o valor integral sem usar pontos ou vírgula): ");
    scanf("%lld", &pib1);
    printf("Quantos pontos turisticos existem nesse país?: ");
    scanf("%d", &pontotur1);
  
    while (getchar() != '\n');
     
    printf("\n****** Pronto para cadastrar a segunda carta? ******\n\n");
     
    // Cadastro Carta 2
    printf("Digite o codigo da carta 2: ");
    scanf("%4s", codigocarta2);
    printf("Entre com o nome do país 2: ");
    scanf(" %49[^\n]", nomepais2);
    printf("Qual o total de habitantes?: ");
    scanf("%d", &populacao2);
    printf("Qual a area (em km2)?: ");
    scanf("%f", &area2);
    printf("Qual o PIB? (digite o valor integral sem usar pontos ou vírgula): ");
    scanf("%lld", &pib2);
    printf("Quantos pontos turisticos existem nesse país?: ");
    scanf("%d", &pontotur2);

    // Cálculos para Carta 1
    densdemo1 = (float) populacao1 / area1;
    densdinversa1 = (double) 1 / densdemo1;
    rendper1 = (float) pib1 / populacao1;
    superpower1 = (long long int) populacao1 + area1 + pib1 + pontotur1 + rendper1 + densdinversa1;
     
    // Cálculos para Carta 2
    densdemo2 = (float) populacao2 / area2;
    densdinversa2 = (double) 1 / densdemo2;
    rendper2 = (float) pib2 / populacao2;
    superpower2 = (long long int) populacao2 + area2 + pib2 + pontotur2 + rendper2 + densdinversa2;
    
    // Exibição dos dados
    printf("\n****** CONFIRA AS INFORMAÇÕES DIGITADAS! ******\n");
    
    printf("\nCarta 1:\n");
    printf("Código: %s\n", codigocarta1);
    printf("País: %s\n", nomepais1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %lld\n", pib1);
    printf("Pontos Turísticos: %d\n", pontotur1);
    printf("Densidade Demográfica: %.2f hab/km²\n", densdemo1);
    printf("Densidade Demográfica Inversa: %.8f\n", densdinversa1);
    printf("Renda Per Capita: R$ %.2f\n", rendper1);
    printf("SUPER PODER: %lld\n", superpower1);
    
    printf("\nCarta 2:\n");
    printf("Código: %s\n", codigocarta2);
    printf("País: %s\n", nomepais2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %lld\n", pib2);
    printf("Pontos Turísticos: %d\n", pontotur2);
    printf("Densidade Demográfica: %.2f hab/km²\n", densdemo2);
    printf("Densidade Demográfica Inversa: %.8f\n", densdinversa2);
    printf("Renda Per Capita: R$ %.2f\n", rendper2);
    printf("SUPER PODER: %lld\n", superpower2);
    
    // Loop principal para múltiplas comparações
    do {
        printf("\n****** COMPARAÇÃO DE ATRIBUTOS ******\n");
        printf("Escolha qual atributo comparar:\n");
        printf("1 - População (maior vence)\n");
        printf("2 - Área (maior vence)\n");
        printf("3 - PIB (maior vence)\n");
        printf("4 - Pontos Turísticos (maior vence)\n");
        printf("5 - Densidade Demográfica (menor vence)\n");
        printf("6 - Densidade Demográfica Inversa (maior vence)\n");
        printf("7 - Renda Per Capita (maior vence)\n");
        printf("8 - SUPER PODER (maior vence)\n");
        printf("0 - SAIR\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if(opcao == 0) {
            printf("\nSaindo do programa...\n");
            break;
        }

        printf("\n****** RESULTADO DA COMPARAÇÃO ******\n");
        printf("País 1: %s\n", nomepais1);
        printf("País 2: %s\n", nomepais2);

        switch(opcao) {
            case 1:
                printf("\nAtributo: POPULAÇÃO\n");
                printf("%s: %d habitantes\n", nomepais1, populacao1);
                printf("%s: %d habitantes\n", nomepais2, populacao2);
                resultado = populacao1 > populacao2;
                if(populacao1 == populacao2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 2:
                printf("\nAtributo: ÁREA\n");
                printf("%s: %.2f km²\n", nomepais1, area1);
                printf("%s: %.2f km²\n", nomepais2, area2);
                resultado = area1 > area2;
                if(area1 == area2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 3:
                printf("\nAtributo: PIB\n");
                printf("%s: %lld\n", nomepais1, pib1);
                printf("%s: %lld\n", nomepais2, pib2);
                resultado = pib1 > pib2;
                if(pib1 == pib2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 4:
                printf("\nAtributo: PONTOS TURÍSTICOS\n");
                printf("%s: %d\n", nomepais1, pontotur1);
                printf("%s: %d\n", nomepais2, pontotur2);
                resultado = pontotur1 > pontotur2;
                if(pontotur1 == pontotur2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 5:
                printf("\nAtributo: DENSIDADE DEMOGRÁFICA (menor vence)\n");
                printf("%s: %.2f hab/km²\n", nomepais1, densdemo1);
                printf("%s: %.2f hab/km²\n", nomepais2, densdemo2);
                resultado = densdemo1 < densdemo2;
                if(densdemo1 == densdemo2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 6:
                printf("\nAtributo: DENSIDADE DEMOGRÁFICA INVERSA (maior vence)\n");
                printf("%s: %.8f\n", nomepais1, densdinversa1);
                printf("%s: %.8f\n", nomepais2, densdinversa2);
                resultado = densdinversa1 > densdinversa2;
                if(densdinversa1 == densdinversa2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 7:
                printf("\nAtributo: RENDA PER CAPITA\n");
                printf("%s: R$ %.2f\n", nomepais1, rendper1);
                printf("%s: R$ %.2f\n", nomepais2, rendper2);
                resultado = rendper1 > rendper2;
                if(rendper1 == rendper2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            case 8:
                printf("\nAtributo: SUPER PODER\n");
                printf("%s: %lld\n", nomepais1, superpower1);
                printf("%s: %lld\n", nomepais2, superpower2);
                resultado = superpower1 > superpower2;
                if(superpower1 == superpower2) {
                    printf("\nEMPATE!\n");
                } else {
                    printf("\nVENCEDOR: %s\n", resultado ? nomepais1 : nomepais2);
                }
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        
        // Limpa o buffer de entrada
        while (getchar() != '\n');
        
    } while(opcao != 0);
    
    printf("\n****** OBRIGADO POR JOGAR SUPER TRUNFO! ******\n");
    return 0;
}