/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:12:50 by theonewhokn       #+#    #+#             */
/*   Updated: 2023/10/27 13:13:04 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_m(char **m)
{
	int	i;

	i = 0;
	if (m)
	{
		while (m[i])
		{
			free(m[i]);
			i++;
		}
		free(m);
	}
}
