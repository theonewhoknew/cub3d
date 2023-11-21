/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:54:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:47 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_open(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

static int	texture_error(char *texture)
{
	ft_printf(2, "%s texture could not be opened or found.\n", texture);
	return (1);
}

int	check_textures(t_cub *cub)
{
	int	rtn;

	rtn = check_open(cub->n_p);
	if (rtn)
		return (texture_error("North"));
	rtn = check_open(cub->s_p);
	if (rtn)
		return (texture_error("South"));
	rtn = check_open(cub->w_p);
	if (rtn)
		return (texture_error("West"));
	rtn = check_open(cub->e_p);
	if (rtn)
		return (texture_error("East"));
	return (0);
}
