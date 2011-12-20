#ifndef GAME_FUNCT_H
#define GAME_FUNCT_H
#include"struct.h"

void init(int** grid);
void display(int** grid);
int test_col(int** grid,int col);
void choose_col(int** grid,int activePlayer);
int check_col(int** grid, int player);
int check_line(int** grid, int player);
int verif_grid(int** grid);
void edit_score(int victory, s_player *p1, s_player *p2);
#endif //GAME_FUNCT_H
