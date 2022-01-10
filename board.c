#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "board.h"

// #define DIMENSION 4

struct board_t {
    piece tab[4][4];
    int last_i;
    int last_j;
};

typedef struct board_t* board;

struct piece_t {
    int tab[4];
};

typedef struct piece_t* piece;


typedef enum players_t player;


board new_game() {
    board game;
    game = malloc(sizeof(struct board_t));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            game -> tab[i][j] = NULL;
        }
    }
    return game;
}


board copy_game(board original_game)
{
    board game;
    game = malloc(sizeof(struct board_t));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            game -> tab[i][j] = original_game -> tab[i][j];
        }
    }
    game -> last_i = original_game -> last_i;
    game -> last_j = original_game -> last_j;
    return game;
}

void destroy_game(board game)
{
    free(game);
}

bool is_occupied(board game, int line, int column)
{
    if (0 <= line && line < 4 && 0 <= column && column < 4)
    {
        if (game -> tab[line][column] == NULL)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}

piece get_piece(board game, int line, int column)
{
    return game -> tab[line][column];
}

enum size piece_size(piece a_piece)
{
    enum size size = a_piece -> tab [2];
    return size;
}

enum top piece_top(piece a_piece)
{
    enum top top = a_piece -> tab [1];
    return top;
}

enum color piece_color(piece a_piece)
{
    enum color color = a_piece -> tab [0];
    return color;
}

enum shape piece_shape(piece a_piece)
{
    enum shape shape = a_piece -> tab [3];
    return shape;
}

bool has_winner(board game)
{
    piece p;
    int have_all_piece = 1;
    int count[4] = {0,0,0,0};
    if (game -> last_i == game -> last_j) { // diagonal NO->SE
        for (int i = 0; i < 4; i++){ //Pour chaque case
            p = game->tab[i][i];
            if (p == NULL)
            {
                have_all_piece = 0;
            }
            for (int elt = 0; elt < 4; elt++){

                if (p != NULL && p->tab[elt] != 0)
                {
                    count[elt] += 1;
                }
            }
        }
        for (int elt = 0; elt < 4; elt++){
            if (count[elt] == 4 || (have_all_piece == 1 && count[elt] == 0))
            {
                return true;
            } else {
                count[elt] = 0;
            }
        }
    }
    have_all_piece = 1;
    if (game -> last_i + game -> last_j == 3) { // diagonal NE->SW
        for (int i = 0; i < 4; i++){ //Pour chaque case
            p = game->tab[i][3 - i];
            if (p == NULL)
            {
                have_all_piece = 0;
            }
            for (int elt = 0; elt < 4; elt++){

                if (p != NULL && p -> tab[elt] != 0){
                    count[elt]++;
                }
            }
        }
        for (int elt = 0; elt < 4; elt++){
            if (count[elt] == 4 || (have_all_piece == 1 && count [elt] == 0))
            {
                return true;
            }
            else
            {
                count[elt] = 0;
            }
        }
    }
    have_all_piece = 1;
    for (int i = 0; i < 4; i++){ // Pour chaque case
        p = game -> tab[i][game->last_j];
        if (p == NULL)
        {
            have_all_piece = 0;
        }
        for (int elt = 0; elt < 4; elt++){
            if (p != NULL && p -> tab[elt] != 0){
                count[elt]++;
            }
        }
    }
    for (int elt = 0; elt < 4; elt++){
        if (count[elt] == 4 || (have_all_piece == 1 && count[elt] == 0)) {
            return true;
        } else {
            count[elt] = 0;
        }
    }
    have_all_piece = 1;
    for (int j = 0; j < 4; j++)
    {
        p = game -> tab[game->last_i][j];
        if (p == NULL)
        {
            have_all_piece = 0;
        }
        for (int elt = 0; elt < 4; elt++){
            if (p != NULL && p -> tab[elt] != 0){
                count[elt]++;
            }
        }
    }
    for (int elt = 0; elt < 4; elt++){
        if (count[elt] == 4 || (have_all_piece == 1 && count[elt] == 0))
        {
            return true;
        }
        else
        {
            count[elt] = 0;
        }
    }
    return false;
}

bool is_present_on_board(board game, piece a_piece)
{
    piece p;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            p = game -> tab[i][j];

            if ( p != NULL && (a_piece -> tab[0] == p -> tab[0] && a_piece -> tab[1] == p -> tab[1] && a_piece -> tab[2] == p -> tab[2] && a_piece -> tab[3] == p -> tab[3])){
                return true;
            }
        }
    }
    return false;
}


enum return_code place_piece(board game, int line, int column, piece a_piece)
{
    enum return_code return_code = SUCCESS;
    if (!(0 <= line && line <= 3 && 0 <= column && column <= 3) || is_occupied(game, line, column)){
        return_code = POSITION;
        return return_code;
    }

    if (!(0 <= a_piece -> tab[0] && a_piece -> tab[0] <= 1 && 0 <= a_piece -> tab[1] && a_piece -> tab[1] <= 1 && 0 <= a_piece -> tab[2] && a_piece -> tab[2] <= 1 && 0 <= a_piece -> tab[3] && a_piece -> tab[3] <= 1)){
        return_code = PIECE;
        return return_code;
    }

    game -> tab[line][column] = a_piece;
    game -> last_i = line;
    game -> last_j = column;
    return return_code;
}

piece get_piece_from_characteristics(enum size a_size, enum shape a_shape, enum color a_color,  enum top a_top)
{
    piece a_piece;
    a_piece = malloc(sizeof(struct piece_t));
    a_piece -> tab[0] = (a_color !=0)?1:0;
    a_piece -> tab[1] = (a_top !=0)?1:0;
    a_piece -> tab[2] = (a_size !=0)?1:0;
    a_piece -> tab[3] = (a_shape !=0)?1:0;
    return a_piece;
}

