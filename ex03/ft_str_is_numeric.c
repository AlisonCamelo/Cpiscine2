/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:57:17 by acamelo           #+#    #+#             */
/*   Updated: 2026/07/13 16:17:02 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= '0' && str[a] <= '9')
			a++;
		else
			return (0);
	}
	return (1);
}
/*int main()
{
    char str[] = "11q1";
    int result = ft_str_is_numeric(str);
    printf("%d\n", result);
}*/