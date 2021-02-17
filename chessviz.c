#include <stdio.h>

typedef enum {
    none = ' ',
    rook_w = 'r',
    knight_w = 'n',
    bishop_w = 'b',
    queen_w = 'q',
    king_w = 'k',
    pawn_w = 'p',
    rook_b = 'R',
    knight_b = 'N',
    bishop_b = 'B',
    queen_b = 'Q',
    king_b = 'K',
    pawn_b = 'P'
} Piece;

typedef struct {
    Piece board[8][8];
} Board;

void Init_Board(Board* pb)
{
    int i, j;
    pb->board[0][0] = rook_b;
    pb->board[0][1] = knight_b;
    pb->board[0][2] = bishop_b;
    pb->board[0][3] = queen_b;
    pb->board[0][4] = king_b;
    pb->board[0][5] = bishop_b;
    pb->board[0][6] = knight_b;
    pb->board[0][7] = rook_b;
    for (i = 0; i <= 8; ++i) {
        pb->board[1][i] = pawn_b;
        pb->board[6][i] = pawn_w;
    }
    for (i = 2; i <= 5; ++i) {
        for (j = 0; j < 8; ++j) {
            pb->board[i][j] = none;
        }
    }
    pb->board[7][0] = rook_w;
    pb->board[7][1] = knight_w;
    pb->board[7][2] = bishop_w;
    pb->board[7][3] = queen_w;
    pb->board[7][4] = king_w;
    pb->board[7][5] = bishop_w;
    pb->board[7][6] = knight_w;
    pb->board[7][7] = rook_w;
}

void Print_Board(Board* pb, FILE* txt)
{
    int i, j;
    for (i = 7; i >= 0; --i) {
        fprintf(txt, "%d", i + 1);
        for (j = 0; j < 8; ++j) {
            fprintf(txt, " %c", pb->board[i][j]);
        }
        fprintf(txt, "\n");
    }   fprintf(txt, "  a b c d e f g h\n");
}

int main()
{
    Board Board;
    FILE* txt = fopen("chessviz.txt", "w");
    if (txt == NULL) {
        printf("Возникла ошибка при открытии chessviz.txt");
        return 0;
    }
    Init_Board(&Board);
    Print_Board(&Board, txt);
    fclose(txt);
    return 0;
}