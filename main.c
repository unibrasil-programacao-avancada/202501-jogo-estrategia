#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int jogadores;
    int rodadas;
    int pontosRodada;
    int pontuacaoGeral[] = {1, 1, 1, 1, 2, 2, 2, 3, 3};
    int qtd_pontos = 0;
    int guardaPontuacao[] = {0, 0, 0};
    int contador = 0;
    jogadores = 3;
    rodadas = 3;

    if (1 <= jogadores && rodadas <= 500)
    {
        for (int i = 1; i <= rodadas; i++)
        {
            for (int j = 1; j <= jogadores; j++)
            {
                guardaPontuacao[contador] = guardaPontuacao[contador] + pontuacaoGeral[qtd_pontos];
                printf("Rodada: %d, jogador %d, quantidade de ponto na rodada: %d\n", i, j, pontuacaoGeral[i]);
                contador++;
                qtd_pontos++;
            }
            contador = 0;
        }
    }

    int maiorQtdDePontosTotal = 0;
    int maiorQtdPontosAtual = 0;
    int indexJogadorGanhador = 0;

    for (int i = 0; i < 3; i++)
    {
        maiorQtdPontosAtual = guardaPontuacao[i];
        if (maiorQtdPontosAtual >= maiorQtdDePontosTotal)
        {
            maiorQtdDePontosTotal = maiorQtdPontosAtual;
            indexJogadorGanhador = i;
        }
    }
    printf("Jogador ganhador: %d", indexJogadorGanhador + 1);
}
