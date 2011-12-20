#ifndef FUNCT_H
#define FUNCT_H
#include"struct.h"

void help();
void mods(int argc,char *argv[],s_game *mod);
void about( s_player *pPlayer);
void print_score( s_player *p1, s_player *p2, s_game *mod);
int new_game();
void start_game( s_player *p1, s_player *p2,int** grid, s_game *mod);


#endif //FUNCT_H
