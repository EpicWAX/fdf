/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 19:03:45 by qhusler           #+#    #+#             */
/*   Updated: 2016/07/19 20:51:13 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int		main(int ac, char **av)
{
	t_rfile		file;
	t_mlx_struc	mlx;

	if (ac != 2)
		return (0);
	file.fd = open(av[1], O_RDONLY);
	file.tab = atoi_on_full_file(map_reader(file.fd));
	mlx.mlx = mlx_init();

	mlx.window = mlx_new_window (mlx.mlx , 800, 600, "\\O/")
	return (0);
}
