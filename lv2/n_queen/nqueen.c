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

int nqueen(int *arr_int, int n, int col)
{
	if (col == n)
		print_pos(arr_int, n)
	else 
	{
	
	}
}

int queen_is_safe(int row, int col, )
{

}

int	main(int argc, char **argv)
{
	int *pos = NULL;
	int n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	pos = calloc(n, sizeof(int));
	if (!pos)
		return (0);
	nqueen(pos, n, 0)

	return (0);
}
