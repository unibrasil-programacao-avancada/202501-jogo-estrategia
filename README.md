# --- Jogo de Estratégia em C ---
Neste projeto implementamos um jogo de estratégia desenvolvido em linguagem C, focado na determinação do jogador vencedor com base nas pontuações obtidas durante as rodadas.

## --- Descrição do Projeto ---
O jogo consiste em vários jogadores participando de inúmeras rodadas, onde cada um dos participantes acumula pontos a cada jogada. O objetivo é determinar o jogador com a maior pontuação ao final de todas as rodadas. Se tiver empate, o último jogador a alcançar a pontuação máxima vence o jogo.

## --- Funcionalidades ---
- Leitura de dados de entrada contendo o número de jogadores, número de rodadas e as pontuações individuais de cada jogada.
- Cálculo da pontuação acumulada para cada jogador.
- Determinação do jogador vencedor com base nas regras estabelecidas.
- Escrita do resultado em um arquivo de saída especificado.

## --- Estrutura do Código ---
- `executa_solucao(FILE* ptr_in_file, const char* out_filename)`: Função principal que processa os dados de entrada, calcula as pontuações e determina o vencedor, escrevendo o resultado no arquivo de saída.
- `solve_warmup(FILE* ptr_in_file, char* file_name, const char* warmup_instance)`: Função que gerencia a execução da solução, criando arquivos necessários e chamando `executa_solucao`.
- `check_warmup_solution(const char* file_name, const char* warmup_instance)`: Função que compara a solução gerada com a resposta esperada para verificar a correção.

## --- Desenvolvedores ---
Henrique Rocha, 2022202432
Marcos Irenos, 2023101873
Otavio Mello, 2023200542
