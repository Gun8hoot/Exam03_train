// NOT FINISHED YET

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	powerset(int to_find, int *arr, int arr_len, int i, int j, int sum, int *arr_in_sum)
{
	if (sum == to_find)
	{
		;
	}
	else if (sum > to_find)
	{
		sum = 0;
		return 0;
	}

	powerset(to_find, arr, i, j, sum)

	return (0);
}

int main(int argc, char **argv)
{
	int	*arr;
	int	len;

	if (argc < 3)
		return (1);
	len = argc - 2;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (1);
	for (int i = 0;i < len; i++)
		arr[i] = atoi(argv[2 + i]);
	powerset(atoi(argv[1]), arr, len, 0, 0, 0 , arr);
}
