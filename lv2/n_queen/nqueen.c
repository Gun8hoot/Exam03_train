#include "nqueen.h"

void  print_pos(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			fprintf(stdout, "%d ", arr[i]);
		else 
			fprintf(stdout, "%d\n", arr[i]);
	}
}

int	  str_is_number(char *str)
{
	for (int i = 0;str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int	  check_queen(int *arr, int pos_y, int pos_x, int size)
{
	for (int i = 0; i < pos_y; i++)
	{
		if (arr[i] == pos_x)	  // Check colums/row
			return (0);
		else if (pos_y - i == pos_x - arr[i] || pos_y + i == pos_x + arr[i]) // Check diagonal both direction
			return (0);
	}
	return (1);
}

void nqueen(int *arr_pos, int col, int row, int size)
{
	if (col == size)
	{
		print_pos(arr_pos, size);
		return ;
	}
	for (int x = 0; x < size; x++)
	{
		if (check_queen(arr_pos, col, x, size))
		{
			arr_pos[col] = x;
			nqueen(arr_pos, col + 1, x, size);
		}
	}	
	return ;
}

int	main(int argc, char **argv)
{
	int size;
	int *pos;

	if (argc != 2 || !str_is_number(argv[1]))
		return (1);
	size = atoi(argv[1]);
	if (size <= 0)
		return (1);
	pos = calloc(size, sizeof(int));
	if (!pos)
		return (0);
	nqueen(pos, 0, 0, size);

	return (0);
}
