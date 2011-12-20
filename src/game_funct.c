#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include"../include/game_funct.h"

/**
 * \fn void init(int** grid)
 * \brief funct to init the grid
 *
 * \param grid the grid of the game
 *
 */
void init(int** grid)
{
  int i,j;
  for(i=0;i<7;i++)
    for(j=0;j<6;j++)
      grid[i][j]=0;
  return;
}

void display(int** grid)
{
  int i,j;
  printf("[A][B][C][D][E][F][G]\n");
  for(j=0;j<6;j++)
    {
      for(i=0;i<7;i++)
	{
	  printf("[");
	  if(grid[i][j]==1)
	    printf("X");
	  else
	    if(grid[i][j]==2)
	      printf("O");
	    else
	      printf(" ");
	  printf("]");
	}
      printf("\n");
    }
  return;
}

int test_col(int** grid,int col)
{
  int place,i;
  place=0;
  for(i=0;i<6;i++)
    {
      if(grid[col][i]==0)
	place++;
    }
  if(place==0)
    place=-1;
  else
    place-=1;
  return place;
}

void choose_col(int** grid,int activePlayer)
{
  char choice;
  int good=0;
  int i,place;
  printf("Joueur %d : choisi une colonne (A~G)",activePlayer);
  while(!good)
    {
      choice='\n';
      while(choice=='\n')
	scanf("%c%*c",&choice);
      choice=toupper(choice);
      switch(choice)
	{
	case 'A':
	  {
	    place=test_col(grid,0);
	    if(place!=(-1))
	      {
		grid[0][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'B':
	  {
	    place=test_col(grid,1);
	    if(place!=(-1))
	      {
		grid[1][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'C':
	  {
	    place=test_col(grid,2);
	    if(place!=(-1))
	      {
		grid[2][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'D':
	  {
	    place=test_col(grid,3);
	    if(place!=(-1))
	      {
		grid[3][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'E':
	  {
	    place=test_col(grid,4);
	    if(place!=(-1))
	      {
		grid[4][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'F':
	  {
	    place=test_col(grid,5);
	    if(place!=(-1))
	      {
		grid[5][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	case 'G':
	  {
	    place=test_col(grid,6);
	    if(place!=(-1))
	      {
		grid[6][place]=activePlayer;
		good=1;
	      }
	    break;
	  }
	default:
	  {
	    printf("test ! %c",choice);
	    break;
	  }
	}
    }
  return;
}

int check_line(int** grid,int player)
{
  int victory,line,place,col;
  line=0;
  victory=0;
  while(!victory && line<6)
    {
      col=0;
      place=0;
      while(place<4 && col<7)
	{
	  if(grid[col][line]==player)
	    place++;
	  else
	    place=0;
	  col++;
	}
      if(place==4)
	victory=player;
      else
	line++;
    }
  return victory;
}

int check_col(int** grid,int player)
{
  int victory,line,place,col;
  col=0;
  victory=0;
  while(!victory && col<7)
    {
      place=0;
      line=0;
      while(place<4 && line<6)
	{
	  if(grid[col][line]==player)
	    place++;
	  else
	    place=0;
	  line++;
	}
      if(place==4)
	victory=player;
      else
	col++;
    }
  return victory;
}

int verif_grid(int** grid)
{
  int victory,player,line,col,place;
  player=1;
  victory=0;
  while(!victory && player!=3)
    {
      victory=check_line(grid,player);
      victory=check_col(grid,player);
      //victory=check_diagL(grid,player);
      //victory=check_diagR(grid,player);

      player++;
    }
  return victory;
}

void edit_score(int victory, s_player *p1, s_player *p2)
{
  if(victory==1)
    p1->score++;
  else
    if(victory==2)
      p2->score++;
  return;
}
