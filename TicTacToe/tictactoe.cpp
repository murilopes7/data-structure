/*
    Feature of Tic-Tac-Toe in C++

    This game provides the following features:

        This game is developed on a 3x3 grid.
        This game is designed for two players.
        Every player may choose a letter between X and O.
        Both players will get their chances to turn by turn.

    Components of the Game

    The game is made of the following components that include the functions and data structures to provide the basic operations of the game.
        1. Game Board

    The game board is managed by the Board class which contains:

        A 3x3 character grid to represent the board.
        A counter to track filled cells.

        2. Player Management

    Players are represented by the Player class which stores:

        The player's symbol (X or O)
        The player's name

        3. Movement Of Player

    The Boardclass includes methods to handle player moves:

        drawBoard() to display the current state of the board
        isValidMove() to check if a move is valid
        makeMove() to update the board with a player's move

    How to check if the input is valid or not?

        Valid input: If the cell is empty and is within the boundary (0-2 for internal tracking, 1-3 for user input)
        Invalid input: If the cell has already been filled with another letter or is outside the bounds

        4. Game Logic

    The TicTacToe class manages the overall game logic:

        Handles player turns
        Processes user input
        Checks for win/draw conditions

        5. Win, Lose or Draw

    The Board class includes methods to check game status:

        checkWin() to determine if a player has won
        isFull() to check if the board is full (a draw)
*/

#include <iostream>
#include <cstdlib> // system()
using namespace std;

void drawBoard(char (&board)[3][3])
{
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t     |     |     \n\n";
}

// retorna 'W' se quem jogou agora venceu, 'D' se empate (tabuleiro cheio), 'L' se continuar
char checkWin(char (&board)[3][3], int r, int c, int contador) {
    char sym = board[r][c]; // símbolo que acabou de ser colocado ('X' ou 'O')

    // checar linha r
    if (board[r][0] == sym && board[r][1] == sym && board[r][2] == sym)
        return 'W';

    // checar coluna c
    if (board[0][c] == sym && board[1][c] == sym && board[2][c] == sym)
        return 'W';

    // checar diagonal principal (se o movimento está nela)
    if (r == c) {
        if (board[0][0] == sym && board[1][1] == sym && board[2][2] == sym)
            return 'W';
    }

    // checar anti-diagonal (se o movimento está nela)
    if (r + c == 2) {
        if (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym)
            return 'W';
    }

    // empate: contador deve contar jogadas incluindo a atual
    if (contador >= 9)
        return 'D';

    // caso contrário: não houve vitória nem empate -> continuar
    return 'L';
}

void makeMove(char (&board)[3][3], const string &nomeX, const string &nomeO)
{
    int contador = 0; // número de jogadas válidas já feitas (0..9)
    // desenhar o tabuleiro inicial
    system("clear");
    drawBoard(board);

    while (contador < 9) // loop até tabuleiro cheio ou até alguém vencer (neste loop saímos com return)
    {
        char move;
        bool valid = false;
        char currentSym = (contador % 2 == 0) ? 'X' : 'O';
        const string &currentName = (contador % 2 == 0) ? nomeX : nomeO;

        // pedir movimento até ser válido (mesmo jogador repete enquanto inválido)
        while (!valid)
        {
            cout << (currentSym == 'X' ? "\tVEZ DO X: " : "\tVEZ DO O: ");
            cout << "[" << currentName << "] ";
            cout << "Digite o seu " << (contador/2 + 1) << "º movimento (" << currentSym << ") [1-9]: ";

            cin >> move;

            if (!cin) { // segurança extra (não comum com >> char)
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada inválida. Tente novamente.\n";
                continue;
            }

            if (move < '1' || move > '9') {
                cout << "Valor inválido. Digite um número entre 1 e 9.\n";
                continue;
            }

            int idx = move - '1'; // 0..8
            int r = idx / 3;
            int c = idx % 3;

            if (board[r][c] == 'X' || board[r][c] == 'O') {
                cout << "A célula já está ocupada. Escolha outra.\n";
                continue;
            }

            // movimento válido: colocar o símbolo
            board[r][c] = currentSym;
            valid = true;

            // agora que a jogada foi feita, incrementamos o contador (contando esta jogada)
            contador++;

            // desenhar o tabuleiro atualizado
            system("clear");
            drawBoard(board);

            // verificar resultado imediato
            char status = checkWin(board, r, c, contador);
            if (status == 'W') {
                cout << "Jogador " << currentSym << " (" << currentName << ") venceu!\n";
                return; // encerra makeMove, termina o jogo
            } else if (status == 'D') {
                cout << "Empate! Tabuleiro cheio e ninguém ganhou.\n";
                return; // encerra makeMove, termina o jogo
            } else {
                // 'L' -> continuar; apenas saia do while(!valid) e siga para próxima iteração
            }
        } // fim while(!valid)

        // se chegou aqui, houve uma jogada válida e ninguém venceu -> próxima jogada (loop continua)
    } // fim while(contador < 9)

    // caso não tenha retornado por vitória/empate (proteção extra)
    cout << "Tabuleiro cheio (9 jogadas). Termine ou verifique vitória fora desta função.\n";
}

int main()
{
    string nomeX, nomeO;
    char board[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};

    cout << "Tic-Tac-Toe" << endl << endl;
    cout << "Digite o nome do player que jogará com X: ";
    cin >> nomeX;

    cout << endl;

    cout << "Digite o nome do player que jogará com O: ";
    cin >> nomeO;

    makeMove(board, nomeX, nomeO);

    return 0;
}
