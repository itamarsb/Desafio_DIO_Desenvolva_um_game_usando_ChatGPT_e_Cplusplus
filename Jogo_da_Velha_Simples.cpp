#include <iostream>
#include <vector>
#include <string>

const int BOARD_SIZE = 8;
const char EMPTY = '.';
const char PLAYER1_PIECE = 'o';
const char PLAYER1_KING = 'O';
const char PLAYER2_PIECE = 'x';
const char PLAYER2_KING = 'X';

struct Position {
    int row, col;
};

class CheckersBoard {
public:
    CheckersBoard() {
        board.resize(BOARD_SIZE, std::vector<char>(BOARD_SIZE, EMPTY));
        setupBoard();
    }

    void display() const {
        std::cout << "  ";
        for (int col = 0; col < BOARD_SIZE; ++col)
            std::cout << col << ' ';
        std::cout << '\n';

        for (int row = 0; row < BOARD_SIZE; ++row) {
            std::cout << row << ' ';
            for (int col = 0; col < BOARD_SIZE; ++col)
                std::cout << board[row][col] << ' ';
            std::cout << '\n';
        }
    }

    bool movePiece(Position from, Position to) {
        if (!isValidMove(from, to)) return false;

        char piece = board[from.row][from.col];
        board[from.row][from.col] = EMPTY;
        board[to.row][to.col] = piece;

        // Promotion to King
        if ((piece == PLAYER1_PIECE && to.row == 0) || (piece == PLAYER2_PIECE && to.row == BOARD_SIZE - 1)) {
            board[to.row][to.col] = (piece == PLAYER1_PIECE) ? PLAYER1_KING : PLAYER2_KING;
        }

        // Capture
        if (abs(to.row - from.row) == 2) {
            int midRow = (from.row + to.row) / 2;
            int midCol = (from.col + to.col) / 2;
            board[midRow][midCol] = EMPTY;
        }

        return true;
    }

private:
    std::vector<std::vector<char>> board;

    void setupBoard() {
        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                if ((row + col) % 2 == 1) {
                    if (row < 3) board[row][col] = PLAYER2_PIECE;
                    else if (row > 4) board[row][col] = PLAYER1_PIECE;
                }
            }
        }
    }

    bool isValidMove(Position from, Position to) const {
        if (to.row < 0 || to.row >= BOARD_SIZE || to.col < 0 || to.col >= BOARD_SIZE)
            return false;

        if (board[to.row][to.col] != EMPTY)
            return false;

        char piece = board[from.row][from.col];
        if (piece == PLAYER1_PIECE && (to.row >= from.row || abs(to.row - from.row) > 2 || abs(to.col - from.col) != abs(to.row - from.row)))
            return false;
        if (piece == PLAYER2_PIECE && (to.row <= from.row || abs(to.row - from.row) > 2 || abs(to.col - from.col) != abs(to.row - from.row)))
            return false;
        if ((piece == PLAYER1_KING || piece == PLAYER2_KING) && abs(to.row - from.row) != abs(to.col - from.col))
            return false;

        // Capture check
        if (abs(to.row - from.row) == 2) {
            int midRow = (from.row + to.row) / 2;
            int midCol = (from.col + to.col) / 2;
            char midPiece = board[midRow][midCol];
            if (midPiece == EMPTY || (piece == PLAYER1_PIECE || piece == PLAYER1_KING) && (midPiece == PLAYER1_PIECE || midPiece == PLAYER1_KING))
                return false;
            if ((piece == PLAYER2_PIECE || piece == PLAYER2_KING) && (midPiece == PLAYER2_PIECE || midPiece == PLAYER2_KING))
                return false;
        }

        return true;
    }
};

int main() {
    CheckersBoard board;
    bool player1Turn = true;

    while (true) {
        board.display();
        std::string player = player1Turn ? "Player 1" : "Player 2";
        std::cout << player << "'s turn. Enter move (from_row from_col to_row to_col): ";

        Position from, to;
        std::cin >> from.row >> from.col >> to.row >> to.col;

        if (board.movePiece(from, to)) {
            player1Turn = !player1Turn;
        } else {
            std::cout << "Invalid move, try again.\n";
        }
    }

    return 0;
}
