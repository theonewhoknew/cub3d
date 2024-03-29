/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:56:37 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/16 11:29:33 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_argv(argc, argv))
		return (1);
	init_parse(&cub, argv);
	if (parse(&cub) || check(&cub))
	{
		free_cub(&cub);
		return (1);
	}
	game(&cub);
	free_cub(&cub);
}
