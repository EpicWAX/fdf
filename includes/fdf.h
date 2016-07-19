/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 19:51:30 by qhusler           #+#    #+#             */
/*   Updated: 2016/07/19 18:59:01 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>

# define TRUE		1
# define FALSE		0

# define RIGHT		124
# define LEFT		123
# define UP			126
# define DOWN		125
# define ESCAPE		 53

typedef struct		s_mlx_struct
{
	void	*mlx;
	void	*window;
	void	*param;
	int		x;
	int		y;
}					t_mlx_struct;

typedef struct		s_image
{
	int		fd;
	void	*img_ptr;
	char	*file_name;
	char	*file;
}					t_image;

typedef struct		s_rfile
{
	int		fd;
	int		Y_AXIS;
	int		X_AXIS;
//	int		stopY;
//	int		stopX;
	char	**map;
	int		**tab;
}					t_rfile;

//main.c proto



//recovery_file.c proto
int		**atoi_on_full_file(char **map);
char	**map_reader(int fd);
#endif
