# Desafio_DIO_Desenvolva_um_game_usando_ChatGPT_e_Cplusplus
Desafio DIO - Desenvolva um Game com Suporte da Ferramenta ChatGPT e C++
Estrutura do Código
Tabuleiro e peças: Representar o tabuleiro e as peças.
- Movimentação: Implementar a lógica de movimentação das peças.
- Regras básicas: Captura de peças e promoção a dama.
- Interface: Um loop de jogo que permita a interação dos jogadores.

Explicação do Código

Estrutura do tabuleiro:

O tabuleiro é representado por uma matriz 8x8.
Cada célula do tabuleiro pode ser vazia (representada por '.'), conter uma peça do jogador 1 ('o'), uma dama do jogador 1 ('O'), uma peça do jogador 2 ('x'), ou uma dama do jogador 2 ('X').

Movimentação:

A função movePiece verifica se o movimento é válido e executa a movimentação.
A promoção a dama ocorre quando uma peça chega ao lado oposto do tabuleiro.
Captura de peças é realizada ao pular sobre uma peça adversária.

Interface:

Um loop contínuo permite que os jogadores alternem turnos e façam movimentos.
A entrada do jogador é lida e validada antes de executar o movimento.
Este exemplo é básico e pode ser expandido para incluir mais funcionalidades, como verificação de vitória, tratamento de múltiplas capturas, e uma interface gráfica, se necessário.
