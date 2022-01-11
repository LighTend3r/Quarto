#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "bot.h"



void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

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

void affiche_quarto(){
    printf("                 ___   _____  _____   _       _______   _________    ___    \n");
    printf("               .'   `.|_   _||_   _| / \\     |_   __ \\ |  _   _  | .'   `.  \n");
    printf("              /  .-.  \\ | |    | |  / _ \\      | |__) ||_/ | | \\_|/  .-.  \\\n");
    printf("              | |   | | | '    ' | / ___ \\     |  __ /     | |    | |   | |\n");
    printf("              \\  `-'  \\_ \\ \\__/ /_/ /   \\ \\_  _| |  \\ \\_  _| |_   \\  `-'  /\n");
    printf("               `.___.\\__| `.__.'|____| |____||____| |___||_____|   `.___.' \n");
    printf("\n\n");
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


void affiche_game(board game){
	int ligne = 0;
	int ligne_ligne = 0;
	int colonne = 0;

    affiche_quarto();
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

					piece a_piece = get_piece(game, ligne,colonne);
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

piece demande_piece(board game, player player){

    // Variable "bool" pour savoir si la pièce saisie est déjà sur le board
	int present;

    piece a_piece;

    enum color color;
    enum shape shape;
    enum size size;
    enum top top;

	int ent_color;
	int ent_shape;
	int ent_size;
	int ent_top;

    ent_color = 2; // Initialise une valeur pour qu'on entre dans le while
    while (present == 1 ||  !(0 <= ent_color && ent_color <= 1 && 0 <= ent_shape && ent_shape <= 1 && 0 <= ent_size && ent_size <= 1 && 0 <= ent_top && ent_top <= 1))
	{
		system("clear");

		affiche_game(game);

		if (present == 1)
		{
			printf("\n La pièce est deja placée, vous devez en saisir une nouvelle \n");
		}
		else
		{
			printf("\n Vous devez saisir une des valeurs suivantes : 0 ou 1 \n");
		}

		present = 0;

		switch(player)
		{
			case(PLAYER1) :
				printf("\n Joueur 1 : \n Veuillez choisir une pièce pour votre adversaire \n\n");
				break;
			case(PLAYER2) :
				printf("\n Joueur 2 : \n Veuillez choisir une pièce pour votre adversaire \n\n");
				break;
			case(NO_PLAYER) :
				printf("WARNING, aucun joueur n'a été selectionné \n");
				break;
		}

		printf("Vous devez choisir une pièce : \n\n Foncée : 1 ou Claire : 0 \n Ronde : 1 ou Carrée : 0 \n Petite : 1 ou Grande : 0 \n Creuse : 1 ou Pleine : 0\n\n");
		printf("Exemple : \n 1 0 0 1  --> {foncée, carrée, grande, creuse}\n");

		printf("Claire ou foncée ? : ");
		while (scanf("%d", &ent_color) == 0){
			getchar();
		}
		printf("Carrée ou ronde ? : ");
		while (scanf("%d", &ent_shape) == 0)
		{
			getchar();
		}
		printf("Grande ou petite ? : ");
		while (scanf("%d", &ent_size) == 0)
		{
			getchar();
		}
		printf("Pleine ou creuse ? : ");
		while (scanf("%d", &ent_top) == 0)
		{
			getchar();
		}

		// Faire un test que tout les entiers sont compris entre 0 et 1
		switch(ent_color)
		{
			case 0: color = RED; break;
			case 1: color = BLUE; break;
		}
		switch(ent_shape)
		{
			case 0: shape = SQUARE; break;
			case 1: shape = CIRCULAR; break;
		}
		switch(ent_size)
		{
			case 0: size = TALL; break;
			case 1: size = SHORT; break;
		}
		switch(ent_top)
		{
			case 0: top = HOLLOW; break;
			case 1: top = SOLID; break;
		}

		a_piece = get_piece_from_characteristics(size,shape,color,top);

		if (is_present_on_board(game, a_piece) == 1)
		{
			printf("La pièce est déjà présente sur le board \n");
			present = 1;
		} else {
            return a_piece;
        }
	}
    return a_piece;
}

void placement_piece(board game, player *player, piece a_piece){
    enum return_code code = POSITION;


	int changement = 0;
	while (code == POSITION || code == PIECE)
	{
		system("clear");
		affiche_game(game);
		if (changement == 1)
		{
			if (code == POSITION)
			{
				printf("La position n'est pas valide \n");
			}
			else if (code == PIECE)
			{
				printf("La pièce saisie n'existe pas, elle ne peut donc pas être jouée\n");
			}
			else
			{
				printf("Erreur de saisie\n");
			}
		}
		// Changement de joueur si c'est le premier tour de boucle

        printf("\nVoici la pièce choisie %d %d %d %d = {%s,%s,%s,%s}\n\n", !(piece_color( a_piece)==0),!(piece_shape( a_piece)==0),!(piece_size( a_piece)==0),!(piece_top( a_piece)==0),  (!(piece_color( a_piece)==0))?"Foncée":"Claire", (!(piece_shape( a_piece)==0))?"Ronde":"Carrée",(!(piece_size( a_piece)==0))?"Petite":"Grande",(!(piece_top( a_piece)==0))?"Creuse":"Pleine") ;
		if (changement == 0)
		{
			switch(*player)
			{
				case(PLAYER1) : *player = PLAYER2; printf("Joueur 2, veuillez indiquer la ligne et la colonne où vous voulez placer la pièce \n"); changement = 1;
				break;
				case(PLAYER2) : *player = PLAYER1; printf("Joueur 1, veuillez indiquer la ligne et la colonne où vous voulez placer la pièce\n"); changement= 1;
				break;
				case(NO_PLAYER) : printf("WARNING, aucun joueur n'a été selectionné");
				break;
			}
		}
		else
		{
			switch(*player)
			{
				case(PLAYER1) : printf("Joueur 1, veuillez indiquer la ligne et la colonne où vous voulez placer la pièce\n");
				break;
				case(PLAYER2) : printf("Joueur 2, veuillez indiquer la ligne et la colonne où vous voulez placer la pièce\n");
				break;
				case(NO_PLAYER) : printf("WARNING, aucun joueur n'a été selectionné");
				break;
			}
		}
		int i_ligne;
		int j_colonne;
		printf("La ligne : "); // Faire un scanf si il y a un problème
		while (scanf("%d",&i_ligne) == 0)
		{
			getchar();
		}
		printf("La colonne : ");
		while (scanf("%d",&j_colonne) == 0)
		{
			getchar();
		}
		// Faire un test si la place indiquée est bien libre
		code = place_piece(game, i_ligne, j_colonne, a_piece); // La pièce est placée
        if (code == SUCCESS)
        {
            break;
        }
	}
}

void debut_game(player* player, int* have_bot, struct bot* bot){

    int j;

    char m = 'p';


	// On demande à l'utilisateur de lancer la partie
    system("clear");
    affiche_quarto();

    printf("\n\n\n\n");
    printf("Bienvenue à vous jeunes joueurs !\n");
	printf("Vous voulez jouer contre un ordinateur, ou un autre joueur ?\n");
	printf("Veuillez entrer 'o' pour ordinateur et 'j' pour joueur\n");
	while (m != 'o' && m != 'j')
	{
		scanf("%c", &m);
		viderBuffer();
	}
	if (m == 'o')
	{
		int n;
		printf("\nChoisisez le niveau du BOT, \n    - 1 : Facile\n    - 2 : Moyen\n");

		while (scanf("%d", &n) == 0 && n != 1 && n != 2)
		{
			getchar();
		}
		bot->niveau = n;
		*have_bot = 1;
		printf("Une fois que cela est fait, je vous invite à appuyer sur [ENTRER]");
	}
	else
	{
		printf("Avant de commencer, les règles sont simples : ce jeu se joue à 2, vous devez vous attribuer votre numéro de joueur entre vous, soit 1 ou 2\n\n");
		printf("Une fois que cela est fait, je vous invite à appuyer sur [ENTRER]");
	}


    while (m != '\n'){
        scanf("%c",&m);
        viderBuffer();
    }


	// On choisit un des 2 joueurs
	j = ( rand() % 2 ) + 1;
	*player = j;
	bot->player = (rand() % 2) + 1; // Le bot est le joueur x
	if (*have_bot == 0){
		switch (*player)
		{
			case (NO_PLAYER):
				printf("Pas de joueur retourné\n");
				break;
			case (PLAYER1):
				printf("Le joueur 1 commence\n");
				break;
			case (PLAYER2):
				printf("Le joueur 2 commence\n");
				break;
			default:
				printf("Erreur\n");
				break;
		}
	} else {
		if (bot->player == *player)
		{
			printf("Le Bot commence\n");
		}
		else
		{
			printf("Le joueur commence\n");
		}
	}

	printf("\n");
}



int main(int args, char **argv)
{
    // Change la graine du random
	srand(time(NULL));

    // Initialise les variables
    board game = new_game();

    player player = NO_PLAYER;

	enum color color = RED;
	enum shape shape = SQUARE;
    enum size size = TALL;
    enum top top = SOLID;
	piece a_piece  = get_piece_from_characteristics(size,shape,color,top);

    int tour = 0;
	int have_bot = 0; // Si il y a un bot ou non
	struct bot bot;
	debut_game(&player, &have_bot, &bot);

	while (tour < 16){



		// Fonction de demande valide
		if (have_bot == 0 || (player != bot.player)){
			a_piece = demande_piece(game, player);
		} else {
			a_piece = demande_piece_bot(game, bot);
		}


        // Fonction pour demander au joueur de placer le pion
		if (have_bot == 0 || (player == bot.player))
		{
			placement_piece(game, &player, a_piece);
		}
		else
		{
			placement_piece_bot(game, &player, a_piece, bot);
		}

		// Si le joueur qui vient de placer la pièce a gagné

		if (has_winner(game) != 0)
		{
            system("clear");
            affiche_game(game);
			if (have_bot == 1 && player == bot.player)
			{
				printf("Le BOT a gagne !!!\n");
			}
			else
			{
				printf("\n\nLe joueur %d a gagne !!!\n", player);
			}

            break; // Fini la boucle while
		}

        tour++;
	}
    if (tour == 16){
        printf("Egalite !\n");
    }
	return 0;
}
