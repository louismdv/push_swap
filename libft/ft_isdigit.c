/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louismdv <louismdv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:10 by lmerveil          #+#    #+#             */
/*   Updated: 2024/01/15 14:53:40 by louismdv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 0 && c <= 9)
		return (1);
	return (0);
}

// int	main()
// {
// 	int	i = 1;
// 	printf("i: %d\n", ft_isdigit(i));
// }

/* #include <stdio.h>
#include <ctype.h>
int	main()
{
	int	emptystr = ' ';
	int	lowerstr= 'c';
	int	upperstr = 'L';
	int	numberstr = '1';

	printf("emptystr: %d\n", ft_isdigit(emptystr));
	printf("lowerstr: %d\n", ft_isdigit(lowerstr));
	printf("upperstr: %d\n", ft_isdigit(upperstr));
	printf("numberstr: %d\n", ft_isdigit(numberstr));

	printf("emptystr: %d\n", isdigit(emptystr));
	printf("lowerstr: %d\n", isdigit(lowerstr));
	printf("upperstr: %d\n", isdigit(upperstr));
	printf("numberstr: %d\n", isdigit(numberstr));
} */