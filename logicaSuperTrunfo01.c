#include <stdio.h>
#include <string.h>

// essas são as estruturas para armazenar as cartas.
typedef struct {
    char estado[50];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Começando com essa função para calcular a densidade populacional.
float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

// Em seguida usei a mesma função para calcular PIB per capita.
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

// Decidi usar "void" porque rodou melhor e estava dando erro anteriormente e misturando tudo.
void compararCartas(Carta carta1, Carta carta2, char atributo[]) {
    float valor1, valor2;

    if (strcmp(atributo, "Populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributo, "Area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributo, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributo, "PontosTuristicos") == 0) {
        valor1 = carta1.pontosTuristicos;
        valor2 = carta2.pontosTuristicos;
    } else if (strcmp(atributo, "DensidadePopulacional") == 0) {
        valor1 = calcularDensidadePopulacional(carta1.populacao, carta1.area);
        valor2 = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    } else if (strcmp(atributo, "PIBPerCapita") == 0) {
        valor1 = calcularPIBPerCapita(carta1.pib, carta1.populacao);
        valor2 = calcularPIBPerCapita(carta2.pib, carta2.populacao);
    } else {
        printf("Atributo inválido!\n");
        return;
    }

    // Código que usei para determinar o vencedor, bem simples mas funcional.
    printf("Comparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    if ((strcmp(atributo, "DensidadePopulacional") == 0 && valor1 < valor2) || 
        (strcmp(atributo, "DensidadePopulacional") != 0 && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }
}

int main() {
    Carta carta1, carta2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Estado: "); scanf("%s", carta1.estado);
    printf("Código da Carta: "); scanf("%s", carta1.codigo);
    printf("Nome da Cidade: "); scanf("%s", carta1.nomeCidade);
    printf("População: "); scanf("%d", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontosTuristicos);

    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Estado: "); scanf("%s", carta2.estado);
    printf("Código da Carta: "); scanf("%s", carta2.codigo);
    printf("Nome da Cidade: "); scanf("%s", carta2.nomeCidade);
    printf("População: "); scanf("%d", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%f", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    // decidi fazer desse jeito o modo de escolha do atributo para comparação
    char atributo[30];
    printf("\nDigite o atributo para comparação (Populacao, Area, PIB, PontosTuristicos, DensidadePopulacional, PIBPerCapita): ");
    scanf("%s", atributo);

    // Comando base
    compararCartas(carta1, carta2, atributo);

    return 0;
}