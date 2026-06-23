/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamelo <acamelo@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:50 by acamelo           #+#    #+#             */
/*   Updated: 2026/02/16 18:47:00 by acamelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if ((str[a] >= 'a' && str[a] <= 'z')
			|| (str[a] >= 'A' && str[a] <= 'Z'))
		{
			a++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*int main ()
{
    char str[] = "j!!!HHHu";
    int result = ft_str_is_alpha(str);
    printf("%d\n", result);
}*/