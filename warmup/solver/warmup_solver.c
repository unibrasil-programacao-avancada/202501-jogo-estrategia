#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/warmup_solver.h"

const char OUTPUT_DIR[] = "output/";
const char SOLUTION_FILE[] = "solution.txt";

// Função solução, vai ser utlizada para determinar o jogador ganhador com base nos inputs.
// Ela lê do ponteiro ptr_in_file os inputs, faz os cálculos e grava o resultado no arquivo out_filename
void executa_solucao(FILE* ptr_in_file, const char* out_filename) {
    int jogadores, rodadas;

    // Aqui a função lê a primeira linha, de qtd de jogadores e rodadas
    if (fscanf(ptr_in_file, "%d %d", &jogadores, &rodadas) != 2) {
         printf("Erro ao ler número de jogadores e rodadas.\n");
         exit(1);
    }

    int totalJogadas = jogadores * rodadas;
    int *pontuacaoGeral = malloc(totalJogadas * sizeof(int));
    if (pontuacaoGeral == NULL) {
         printf("Erro de alocação.\n");
         exit(1);
    }

    // Lê a sequência de pontos
    for (int i = 0; i < totalJogadas; i++) {
         if(fscanf(ptr_in_file, "%d", &pontuacaoGeral[i]) != 1){
             printf("Erro ao ler a pontuação da jogada %d.\n", i + 1);
             free(pontuacaoGeral);
             exit(1);
         }
    }

    // Aloca vetor para guardar a pontuação acumulada de cada jogador
    int *guardaPontuacao = calloc(jogadores, sizeof(int));
    if (guardaPontuacao == NULL) {
         printf("Erro de alocação.\n");
         free(pontuacaoGeral);
         exit(1);
    }

    int qtd_pontos = 0;

    // Processa cada rodada, somando os pontos para cada jogador
    for (int i = 1; i <= rodadas; i++) {
        for (int j = 1; j <= jogadores; j++) {
            guardaPontuacao[j - 1] += pontuacaoGeral[qtd_pontos];
            qtd_pontos++;
        }
    }

    // Determina o jogador ganhador: no caso de mais de um jogador com mesma quantidade de pontos, vence o último a jogar
    int maiorQtdDePontosTotal = 0;
    int indexJogadorGanhador = 0;
    for (int i = 0; i < jogadores; i++) {
        if (guardaPontuacao[i] >= maiorQtdDePontosTotal) {
            maiorQtdDePontosTotal = guardaPontuacao[i];
            indexJogadorGanhador = i;
        }
    }

    // Grava o resultado no arquivo de saída
    FILE *fout = fopen(out_filename, "w");
    if(fout == NULL) {
         printf("Erro ao abrir o arquivo de saída '%s' para escrita.\n", out_filename);
         free(pontuacaoGeral);
         free(guardaPontuacao);
         exit(1);
    }
    fprintf(fout, "Jogador ganhador: %d\n", indexJogadorGanhador + 1);
    fclose(fout);

    free(pontuacaoGeral);
    free(guardaPontuacao);
}

void solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance) {

    FILE *froutptr, *fwsolptr;
    char line[100];
    char out_file[100];

    out_file[0] = '\0';
    strcat(out_file, warmup_instance);
    strcat(out_file, OUTPUT_DIR);
    strcat(out_file, file_name);

    // Creating solution file
    fwsolptr = fopen(SOLUTION_FILE, "w");
    if (fwsolptr == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Aqui chamei a função para executar a solução
    executa_solucao(ptr_in_file, out_file);

    // Opening answer file
    froutptr = fopen(out_file, "r");
    if (froutptr == NULL) {
        printf("File '%s' can't be opened\n", out_file);
        exit(1);
    }

    // Reading from the answer file and writing to the solution file
    while (fgets(line, 100, froutptr)) {
        fputs(line, fwsolptr);
    }

    fclose(froutptr);

    /* *************************************** */

    fclose(fwsolptr);
}

int check_warmup_solution(const char* file_name, const char* warmup_instance) {

    FILE *fanswer, *fsolution;
    char answer_line[100], solution_line[100], answer_file[100];
    int is_correct = 1;

    answer_file[0] = '\0';
    strcat(answer_file, warmup_instance);
    strcat(answer_file, OUTPUT_DIR);
    strcat(answer_file, file_name);

    // Opening answer file
    fanswer = fopen(answer_file, "r");
    if (fanswer == NULL) {
        printf("File '%s' can't be opened\n", answer_file);
        exit(1);
    }

    // Opening solution file
    fsolution = fopen(SOLUTION_FILE, "r");
    if (fsolution == NULL) {
        printf("File '%s' can't be opened\n", SOLUTION_FILE);
        exit(1);
    }

    // Reading from the answer file and comparing with the solution file
    while (fgets(answer_line, 100, fanswer)) {

        fgets(solution_line, 100, fsolution);

        if (strcmp(answer_line, solution_line)) {
            is_correct = 0;
            break;
        }
    }

    fclose(fanswer);
    fclose(fsolution);

    return is_correct;
}
