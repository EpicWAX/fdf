/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:05:33 by qhusler           #+#    #+#             */
/*   Updated: 2016/07/18 17:20:22 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**atoi_on_full_file(char **map)
{
	int		**tab;// pareil try hard deref de type
	char	**map_line;
	int 	x = 0; //gd
	int		y = -1; //hb
	int		stop, stopx;

	while (map[++y])
		;
	tab = (int**)malloc(sizeof(int*) * (y));
	stopx = y;
	y = 0;
	while (map[y])
	{
		map_line = ft_strsplit(map[y], ' ');
		x = -1;
		while (map_line[++x])
			;
		tab[y] = (int*)malloc(sizeof(int) * (x));
		stop = x;
		x = 0 ;
		while (x < stop)
		{
			tab[y][x] = ft_atoi(map_line[x]);
			x++;
		}
		free(map_line);
		y++;
	}
	y = -1;
	while (++y < stopx)
	{
		x=-1;
		while (++x < stop)
		{
			printf("%d  ", tab[y][x]);		
		}
		printf("\n");
	}

	free(map);
	return (tab);
}

int		line_tester(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) != 1 && line[i] != ' ' && line[i] != '-'/* && *line != ',' && *line != 'x' && !(line[i] >= 'A' && line[i] <= 'F')*/)
			return (0);
		i++;
	}
	return (1);
}

char	**map_reader(int fd/*, ((char ***map)) <-> dereferencement pour mettre le type avent l 'appel de la fn pour pouvoir le free*/)
{
	char	*line;//
	char	*pam;//
	char	**map;
	int		y;//
	
	line = NULL;
	pam = "\0";
	y = 0;
	while(get_next_line(fd, &line) == 1)
	{
		if (line_tester(line) != 1)
			exit(0);
		y++;
		pam = ft_strjoin(pam, line);
		pam = ft_strjoin(pam, "\n");
	}
   	map = ft_strsplit(pam, '\n');
	free(pam);
	free(line);//
	return (map);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**tab;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	tab = atoi_on_full_file(map_reader(fd));
	return (0);
}




	
	
	/*y = -1;
	while (++y < stopx)
	{
		x=-1;
		while (++x < stop)
		{
			printf("%d  ", tab[y][x]);		
		}
		printf("\n");
	}*/
