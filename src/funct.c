#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include"../include/funct.h"
#include"../include/game_funct.h"

void help()
{

  return;
}

/**
 * \fn void mods(int argc,char *argv[],s_game *mod)
 * \brief this funct analyze mods of the game
 *
 * \param int argc number of arguments in main.
 * \param char *argv[] set of arguments
 * \param s_game *mod list of possible mods.
 *
 */
void mods(int argc,char *argv[],s_game *mod)
{
  int i;
  mod->help=0;
  mod->gui=0;
  mod->log=0;
  for(i=0;i<argc;i++)
    {
      if(strcmp(argv[i],'--help')==0)
	mod->help=1;
      if(strcmp(argv[i],'--gui')==0)
	mod->gui=1;
      if(strcmp(argv[i],'--log')==0)
	mod->log=1;
    }
  return;
}

/**
 * \fn void about (s_player *pPlayer)
 * \brief function of player creation.
 *
 * \param pPlayer player that'll be created.
 *
 */
void about(s_player *pPlayer)
{
  int i;
  char txt[3];
  pPlayer->score=0;
  printf("Joueur, entre ton nom en 3 lettres :\n");
  for(i=0;i<3;i++)
    {
      scanf("%c",&txt[i]);
      if(txt[i]=='\n')
	scanf("%c",&txt[i]);
      pPlayer->name[i]=toupper(txt[i]);
    }
  return ;
}
/**
 * \fn void print_score(s_player *p1,s_player *p2)
 * \brief function to display score of the game.
 *
 * \param p1 struct of player1.
 * \param p2 struct of player2.
 *
 */
void print_score(s_player *p1,s_player *p2,s_game *mod)
{
  if(mod->log)
    {
      struct s_score buffer;
      buffer.scoreP1=p1->score;
      buffer.scoreP2=p2->score;
      FILE* save;
      save=fopen("score.sav","a");
      fwrite(&buffer,sizeof(s_score),1,save);
      fclose(save);
    }
  printf("\n FIN DE LA PARTIE \n");
  if((p1->score)==(p2->score))
    printf("\n EGALITE \n");
  else
    if((p1->score)<(p2->score))
      printf("\n VICTOIRE DE %c%c%c \n",p2->name[0],p2->name[1],p2->name[2]);
    else
      printf("\n VICTOIRE DE %c%c%c \n",p1->name[0],p1->name[1],p1->name[2]);
  return;
}

int new_game()
{
  char choice;
  int again;
  printf("Voulez vous faire une nouvelle partie ? (O/n) \n");
  scanf("%c",&choice);
  while(choice=='\n')
    scanf("%c",&choice);
  again=(choice=='N'||choice=='n')?0:1;
  printf("\n");
  return again;
}

void start_game( s_player *p1, s_player *p2,int** grid, s_game *mod)
{
  int victory=0;
  int round=0;
  int activePlayer=1;
  init(grid);
  while(!victory && round<42)
    {
      if(mod->gui)
	display(grid);
      choose_col(grid,activePlayer);
      if(activePlayer==1)
	activePlayer=2;
      else
	{
	  victory=verif_grid(grid);
	  activePlayer=1;
	}
      round++;
    }
  edit_score(victory,p1,p2);
  return;
}
