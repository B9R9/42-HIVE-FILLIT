#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		ft_random(int min, int max)
{
	srand(clock() * clock());
	return (rand() % max + min);
}

int		ft_generate(char tab[4][4])
{
	int count = 0;
	int r = 0;

	for (int y = 0; y < 4; y++)
	{
		for(int x = 0; x < 4; x++)
		{
			r = ft_random(1, 7 - (x + y));
			if (r == 1 && count < 4)
			{
				tab[x][y] = '#';
				count++;
			}
			else
				tab[x][y] = '.';
			r = 0;
		}
	}
	if (count == 4)
		return (1);
	return (0);
}
void	ft_print_tab(char tab[4][4])
{
	for (int y = 0; y < 4; y++)
	{
		for(int x = 0; x < 4; x++)
		{
			printf("%c", tab[x][y]);
		}
		printf("\n");
	}
}
int		ft_check_sider(char tab[4][4])
{
	int count = 0;

	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (tab[x][y] == '#')
			{
				if (x - 1 >= 0 && tab[x - 1][y] == '#')
					count++;
				if (x + 1 <= 3 && tab[x + 1][y] == '#')
					count++;
				if (y - 1 >= 0 && tab[x][y - 1] == '#')
					count++;
				if (y + 1 <= 3 && tab[x][y + 1] == '#')
					count++;
			}
		}
	}
	return (count < 6 ? 0 : 1);
}
int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("usage: tetriminos-generator number\n");
		return (1);
	}
	int len = atoi(argv[1]);
	for(int i = 0; i < len; i++)
	{
		char tab[4][4];
		if (!ft_generate(tab) || !ft_check_sider(tab))
		{
			i--;
			continue;
		}
		ft_print_tab(tab);
		if (i < len - 1)
			printf("\n");
	}
}

