#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

void carre(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 1:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 2:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 3:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 4:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	default:
		break;
	}
}

void petit_carre(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("         ");
		break;
	case 1:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 2:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 3:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 4:
		printf("         ");
		break;
	default:
		break;
	}
}

void carre_trou(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 1:
		printf("%c %c   %c %c", s, s, s, s);
		break;
	case 2:
		printf("%c       %c", s, s);
		break;
	case 3:
		printf("%c %c   %c %c", s, s, s, s);
		break;
	case 4:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	default:
		break;
	}
}

void petit_carre_trou(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("         ");
		break;
	case 1:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 2:
		printf("  %c   %c  ", s, s);
		break;
	case 3:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 4:
		printf("         ");
		break;
	default:
		break;
	}
}

void rond(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 1:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 2:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 3:
		printf("%c %c %c %c %c", s, s, s, s, s);
		break;
	case 4:
		printf("  %c %c %c  ", s, s, s);
		break;
	default:
		break;
	}
}

void petit_rond(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("         ");
		break;
	case 1:
		printf("    %c    ", s);
		break;
	case 2:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 3:
		printf("    %c    ", s);
		break;
	case 4:
		printf("         ");
		break;
	default:
		break;
	}
}

void rond_troue(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("  %c %c %c  ", s, s, s);
		break;
	case 1:
		printf("%c %c   %c %c", s, s, s, s);
		break;
	case 2:
		printf("%c       %c", s, s);
		break;
	case 3:
		printf("%c %c   %c %c", s, s, s, s);
		break;
	case 4:
		printf("  %c %c %c  ", s, s, s);
		break;
	}
}

void petit_rond_trou(char s, int n)
{
	switch (n)
	{
	case 0:
		printf("         ");
		break;
	case 1:
		printf("    %c    ", s);
		break;
	case 2:
		printf("  %c   %c  ", s, s);
		break;
	case 3:
		printf("    %c    ", s);
		break;
	case 4:
		printf("         ");
		break;
	default:
		break;
	}
}

void piece_vide(int n)
{
	switch (n)
	{
	case 0:
		printf("         ");
		break;
	case 1:
		printf("         ");
		break;
	case 2:
		printf("         ");
		break;
	case 3:
		printf("         ");
		break;
	case 4:
		printf("         ");
		break;
	default:
		break;
	}
}

void affiche_pion(enum color color, enum shape shape, enum size size, enum top top, int ligne)
{
	char s = '.';
	if (color == 0)
	{
		if (shape == 0)
		{
			if (size == 0)
			{
				if (top == 0)
				{
					carre(s, ligne);
				}
				else
				{
					carre_trou(s, ligne);
				}
			}
			else
			{
				if (top == 0)
				{
					petit_carre(s, ligne);
				}
				else
				{
					petit_carre_trou(s, ligne);
				}
			}
		}
		else
		{
			if (size == 0)
			{
				if (top == 0)
				{
					rond(s, ligne);
				}
				else
				{
					rond_troue(s, ligne);
				}
			}
			else
			{
				if (top == 0)
				{
					petit_rond(s, ligne);
				}
				else
				{
					petit_rond_trou(s, ligne);
				}
			}
		}
	}
	else
	{
		s = '#';
		if (shape == 0)
		{
			if (size == 0)
			{
				if (top == 0)
				{
					carre(s, ligne);
				}
				else
				{
					carre_trou(s, ligne);
				}
			}
			else
			{
				if (top == 0)
				{
					petit_carre(s, ligne);
				}
				else
				{
					petit_carre_trou(s, ligne);
				}
			}
		}
		else
		{
			if (size == 0)
			{
				if (top == 0)
				{
					rond(s, ligne);
				}
				else
				{
					rond_troue(s, ligne);
				}
			}
			else
			{
				if (top == 0)
				{
					petit_rond(s, ligne);
				}
				else
				{
					petit_rond_trou(s, ligne);
				}
			}
		}
	}
}

void binaire(int tab[4], int n)
{

    if (n < 2)
    {
        tab[0] = 0;
        tab[1] = 0;
        tab[2] = 0;
        tab[3] = n;
    }
    else if (n < 4)
    {
        tab[0] = 0;
        tab[1] = 0;
        tab[2] = 1;
        tab[3] = n%2;
    }
    else if (n < 8)
    {
        tab[0] = 0;
        tab[1] = 1;
        tab[2] = (n - 4) - 2 >= 0;
        tab[3] = n % 2;
    } else {
        tab[0] = 1;
        tab[1] = (n - 8) >= 4;
        tab[2] = (n  - 8 - tab[1]*4) >= 2;
        tab[3] = n%2;
    }

}

void affiche_game(board game){
	int ligne = 0;
	int ligne_ligne = 0;
	int colonne = 0;

    //affiche_quarto();
    printf("     0         1         2         3         Pièce restante :\n");
	for (int j = 0; j < 5 * 4 + 3; j++)
	{
        if (ligne_ligne == 2){
            printf("%d ",ligne);
        } else {
            printf("  ");

        }
		if (j == 5 || j == 11 || j == 17)
		{
			for (int i = 0; i < 9 * 4 + 3; i++)
			{
				printf("-");
			}
			ligne++;
			ligne_ligne = 0;
            
		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				if (i == 1 || i == 3 || i == 5)
				{
					printf("|");
					colonne++;
				}
				else
				{

					//piece a_piece = get_piece(game, ligne,colonne);
                    piece a_piece = NULL;
					if (a_piece == NULL)
					{
						printf("         ");
					}
					else
					{
						enum color color = piece_color(a_piece);
						enum shape shape = piece_shape(a_piece);
						enum size size = piece_size(a_piece);
						enum top top = piece_top(a_piece);
						affiche_pion(color, shape, size, top, ligne_ligne);
					}

                    
                    
                    
				}
                
			}
			colonne = 0;
			ligne_ligne++;
		
            printf("     ");

            
            if ( ligne == 0){
                for (int k = 0; k < 4; k++){
                    int tab[4] = {0};
                    binaire(tab, k);

                    enum color color = tab[0];
	        	    enum shape shape = tab[1];
	        	    enum size size = tab[2];
	        	    enum top top = tab[3];
                    piece a_piece = get_piece_from_characteristics(size,shape,color,top);
                    if (!is_present_on_board(game, a_piece)){
                        affiche_pion(color, shape, size, top, ligne_ligne-1);
                    } else {
                        printf("         ");
                    }
                    
                    printf(" | ");
                }
            } else if (ligne == 1) {
                for (int k = 4; k < 8; k++){
                    int tab[4] = {0};
                    binaire(tab, k);

                    enum color color = tab[0];
	        	    enum shape shape = tab[1];
	        	    enum size size = tab[2];
	        	    enum top top = tab[3];
                    piece a_piece = get_piece_from_characteristics(size,shape,color,top);
                    if (!is_present_on_board(game, a_piece)){
                        affiche_pion(color, shape, size, top, ligne_ligne-1);
                    } else {
                        printf("         ");
                    }
                    printf(" | ");
                }
            } else if (ligne == 2) {
                for (int k = 8; k < 12; k++){
                    int tab[4] = {0};
                    binaire(tab, k);

                    enum color color = tab[0];
	        	    enum shape shape = tab[1];
	        	    enum size size = tab[2];
	        	    enum top top = tab[3];
                    piece a_piece = get_piece_from_characteristics(size,shape,color,top);
                    if (!is_present_on_board(game, a_piece)){
                        affiche_pion(color, shape, size, top, ligne_ligne-1);
                    } else {
                        printf("         ");
                    }
                    printf(" | ");
                }
            } else {
                for (int k = 12; k < 16; k++){
                    int tab[4] = {0};
                    binaire(tab, k);

                    enum color color = tab[0];
	        	    enum shape shape = tab[1];
	        	    enum size size = tab[2];
	        	    enum top top = tab[3];
                    piece a_piece = get_piece_from_characteristics(size,shape,color,top);
                    if (!is_present_on_board(game, a_piece)){
                        affiche_pion(color, shape, size, top, ligne_ligne-1);
                    } else {
                        printf("         ");
                    }
                    printf(" | ");
                }
            }
        }
	    printf("\n");	
	}
}



int main(int args, char **argv)
{
    // Change la graine du random
	srand(time(NULL));

    // Initialise les variables
    board game = new_game();
    affiche_game(game);

    
    //affiche_game(game);
    /*
    player player = NO_PLAYER;
	
    enum color color = RED;
    enum shape shape = SQUARE;
    enum size size = TALL;
    enum top top = SOLID;
	piece a_piece  = get_piece_from_characteristics(size,shape,color,top);

    int tour = 0;


    debut_game(&player);

	while (tour < 16){

        

		// Fonction de demande valide
        a_piece = demande_piece(game, player);

        // Fonction pour demander au joueur de placer le pion
        placement_piece(game,&player,a_piece);
		
		

		// Si le joueur qui vient de placer la pièce a gagné
		if (has_winner(game) != 0)
		{
            system("clear");
            affiche_game(game);
			printf("\n\nLe joueur %d a gagné !!!\n", player);
            break; // Fini la boucle while
		}

        tour++;
	}
    if (tour == 16){
        printf("Égalité !\n");
    }
    */
	return 0;
}
