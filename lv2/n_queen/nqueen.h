#ifndef NQUEEN_H
# define NQUEEN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_queen
{
	int n
	int pos_row;
	int pos_collum;
	t_queen *next;
} t_queen;

typedef struct s_holder
{
	int queen_in_struct;
	int sum_queen;
	int salt;
	t_queen **queen;
} t_holder;

#endif // !nqueen
