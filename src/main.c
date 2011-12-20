/**
 * \file main.c
 * \brief Puissance 4.
 * \author Mickael.B
 * \version 1.0
 * \date 10 decembre 2011
 *
 * Puissance 4 réalisé pour un TD de programmation.
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include"../include/funct.h"
#include"../include/struct.h"



/**
 * \fn int main(int argc,char *argv[])
 * \brief Entry of the programm
 *
 * \return 0 - normally stop of the programm.
 */
int main(int argc,char *argv[])
{
  s_game mod;
  int i;
  mods(argc,argv,&mod);
  if(mod.help==1)
    help();
  else
    {
      s_player player1,player2;
      int again = 1;
      int** grid = (int**)malloc(7*sizeof(int*));
      for(i=0;i<7;i++)
	grid[i]=(int*)malloc(6*sizeof(int));
      about(&player1);
      about(&player2);
      while(again)
	{
	  start_game(&player1,&player2,grid,&mod);
	  again=new_game();
	}
      print_score(&player1,&player2,&mod);
      for(i=0;i<7;i++)
	free(grid[i]);
      free(grid);
    }
  return 0;
}
