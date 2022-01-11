#ifndef _BOT_H_
#define _BOT_H_

struct bot
{
    int niveau;
    player player;
};

void binaire(int tab[4], int n);

bool placement_piece_bot(board game, player *player, piece a_piece, struct bot bot);

piece demande_piece_bot(board game, struct bot bot);

#endif
