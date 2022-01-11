#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "bot.h"


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
        tab[3] = n % 2;
    }
    else if (n < 8)
    {
        tab[0] = 0;
        tab[1] = 1;
        tab[2] = (n - 4) - 2 >= 0;
        tab[3] = n % 2;
    }
    else
    {
        tab[0] = 1;
        tab[1] = (n - 8) >= 4;
        tab[2] = (n - 8 - tab[1] * 4) >= 2;
        tab[3] = n % 2;
    }
}

bool placement_piece_bot(board game, player *player, piece a_piece, struct bot bot);

piece demande_piece_bot(board game, struct bot bot)
{
    piece a_piece;
    piece p;

    int All_piece[16][4];
    enum color color;
    enum shape shape;
    enum size size;
    enum top top;

    // On initialise le tableau avec toutes les pièces
    for (int i = 0; i < 16; i++)
    {
        binaire(All_piece[i], i);
    }
    // On regarde toute les pieces qu'on ne peut pas jouer
    int nb_piece_jouable = 16;
    for (int i = 0; i < 16; i++)
    {
        switch (All_piece[i][0])
        {
        case 0:
            color = RED;
            break;
        case 1:
            color = BLUE;
            break;
        }
        switch (All_piece[i][1])
        {
        case 0:
            shape = SQUARE;
            break;
        case 1:
            shape = CIRCULAR;
            break;
        }
        switch (All_piece[i][2])
        {
        case 0:
            size = TALL;
            break;
        case 1:
            size = SHORT;
            break;
        }
        switch (All_piece[i][3])
        {
        case 0:
            top = HOLLOW;
            break;
        case 1:
            top = SOLID;
            break;
        }

        p = get_piece_from_characteristics(size, shape, color, top);
        if (is_present_on_board(game, p))
        {
            nb_piece_jouable--;
            for (int j = 0; j < 4; j++)
            {
                All_piece[i][j] = -1;
            }
        }
    }
    int **piece_jouable = malloc(nb_piece_jouable * sizeof(*piece_jouable));
    for (int i = 0; i < nb_piece_jouable; i++)
    {
        piece_jouable[i] = malloc(4 * sizeof(**piece_jouable));
    }
    int k = 0;
    for (int i = 0; i < 16; i++)
    {
        if (All_piece[i][0] != -1)
        {
            for (int j = 0; j < 4; j++)
            {
                piece_jouable[k][j] = All_piece[i][j];
            }
            k++;
        }
    }
    if (bot.niveau == 1)
    { // On choisit une piece au hasard
        int coup = rand() % nb_piece_jouable;
        switch (piece_jouable[coup][0])
        {
        case 0:
            color = RED;
            break;
        case 1:
            color = BLUE;
            break;
        }
        switch (piece_jouable[coup][1])
        {
        case 0:
            shape = SQUARE;
            break;
        case 1:
            shape = CIRCULAR;
            break;
        }
        switch (piece_jouable[coup][2])
        {
        case 0:
            size = TALL;
            break;
        case 1:
            size = SHORT;
            break;
        }
        switch (piece_jouable[coup][3])
        {
        case 0:
            top = HOLLOW;
            break;
        case 1:
            top = SOLID;
            break;
        }
        a_piece = get_piece_from_characteristics(size, shape, color, top);
    }
    else if (bot.niveau == 2)
    {
        int nb_piece_jouable2 = nb_piece_jouable;
        for (int i = 0; i < nb_piece_jouable; i++)
        {
            board game2 = copy_game(game);
            player player2 = PLAYER2;

            switch (piece_jouable[i][0])
            {
            case 0:
                color = RED;
                break;
            case 1:
                color = BLUE;
                break;
            }
            switch (piece_jouable[i][1])
            {
            case 0:
                shape = SQUARE;
                break;
            case 1:
                shape = CIRCULAR;
                break;
            }
            switch (piece_jouable[i][2])
            {
            case 0:
                size = TALL;
                break;
            case 1:
                size = SHORT;
                break;
            }
            switch (piece_jouable[i][3])
            {
            case 0:
                top = HOLLOW;
                break;
            case 1:
                top = SOLID;
                break;
            }
            a_piece = get_piece_from_characteristics(size, shape, color, top);

            if (placement_piece_bot(game2, &player2, a_piece, bot))
            {
                nb_piece_jouable2--;
                for (int j = 0; j < 4; j++)
                {
                    piece_jouable[i][j] = -1;
                }
            }
            destroy_game(game2);
        }
        if (nb_piece_jouable2 > 0)
        {
            int **piece_jouable2 = malloc(nb_piece_jouable2 * sizeof(*piece_jouable2));
            for (int i = 0; i < nb_piece_jouable2; i++)
            {
                piece_jouable2[i] = malloc(4 * sizeof(**piece_jouable2));
            }
            int k = 0;
            for (int i = 0; i < nb_piece_jouable; i++)
            {
                if (piece_jouable[i][0] != -1)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        piece_jouable2[k][j] = piece_jouable[i][j];
                    }
                    k++;
                }
            }

            int coup = rand() % nb_piece_jouable2;

            switch (piece_jouable2[coup][0])
            {
            case 0:
                color = RED;
                break;
            case 1:
                color = BLUE;
                break;
            }
            switch (piece_jouable2[coup][1])
            {
            case 0:
                shape = SQUARE;
                break;
            case 1:
                shape = CIRCULAR;
                break;
            }
            switch (piece_jouable2[coup][2])
            {
            case 0:
                size = TALL;
                break;
            case 1:
                size = SHORT;
                break;
            }
            switch (piece_jouable2[coup][3])
            {
            case 0:
                top = HOLLOW;
                break;
            case 1:
                top = SOLID;
                break;
            }
            a_piece = get_piece_from_characteristics(size, shape, color, top);
        }
        else
        {
            int coup = rand() % nb_piece_jouable;
            switch (piece_jouable[coup][0])
            {
            case 0:
                color = RED;
                break;
            case 1:
                color = BLUE;
                break;
            }
            switch (piece_jouable[coup][1])
            {
            case 0:
                shape = SQUARE;
                break;
            case 1:
                shape = CIRCULAR;
                break;
            }
            switch (piece_jouable[coup][2])
            {
            case 0:
                size = TALL;
                break;
            case 1:
                size = SHORT;
                break;
            }
            switch (piece_jouable[coup][3])
            {
            case 0:
                top = HOLLOW;
                break;
            case 1:
                top = SOLID;
                break;
            }
            a_piece = get_piece_from_characteristics(size, shape, color, top);
        }
    }

    return a_piece;
}

bool placement_piece_bot(board game, player *player, piece a_piece, struct bot bot) // Renvoie 1 si le bot gagne avec cette piece
{
    enum return_code code = POSITION;

    switch (*player)
    {
    case (PLAYER1):
        *player = PLAYER2;
        break;
    case (PLAYER2):
        *player = PLAYER1;
        break;
    case (NO_PLAYER):
        printf("WARNING, aucun joueur n'a été selectionné");
        break;
    }
    int nb_emplacement = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            piece a_piece = get_piece(game, i, j);
            if (a_piece == NULL)
            {
                nb_emplacement++;
            }
        }
    }
    int **emplacement = malloc(nb_emplacement * sizeof(*emplacement));
    for (int i = 0; i < nb_emplacement; i++)
    {
        emplacement[i] = malloc(2 * sizeof(**emplacement));
    }
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            piece a_piece = get_piece(game, i, j);
            if (a_piece == NULL)
            {
                emplacement[k][0] = i;
                emplacement[k][1] = j;
                k++;
            }
        }
    }
    int find = 0;
    if (bot.niveau == 1)
    { // Le bot joue aléatoirement
        int coup = rand() % nb_emplacement;
        code = place_piece(game, emplacement[coup][0], emplacement[coup][1], a_piece);
    }
    else if (bot.niveau == 2)
    { // Le bot cherche si il peut gagner en un coup

        for (int i = 0; i < nb_emplacement; i++)
        {

            board game2 = copy_game(game);
            place_piece(game2, emplacement[i][0], emplacement[i][1], a_piece);
            if (has_winner(game2))
            {
                code = place_piece(game, emplacement[i][0], emplacement[i][1], a_piece);
                find = 1;
                break;
            }
            destroy_game(game2);
        }
        if (find == 0)
        {
            int coup = rand() % nb_emplacement;
            code = place_piece(game, emplacement[coup][0], emplacement[coup][1], a_piece);
        }
    }

    if (code != SUCCESS)
    {
        printf("Il y a eu un problème lors du placement de la pièce\n");
        while (1)
        {
        }
    }
    if (find == 1)
    {
        return 1;
    }
    return 0;
}
