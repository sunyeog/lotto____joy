/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lotto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunhnoh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:12:34 by sunhnoh           #+#    #+#             */
/*   Updated: 2024/07/12 01:48:48 by sunhnoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	find_equal(int *a)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (i<6)
	{
		while (j<6)
		{
			if(*(a + i) == *(a + j))
				cnt++;
			j++;
		}
		i++;
	}
	if (cnt >= 2)
		return (0);
	else
		return (1);
}

int main(void)
{
	int rnd;
	int a[6];
	int	res;

	retry:
	srand(time(NULL));
	for(int i = 0; i < 6;i++)
	{
		rnd = (rand() % 45) + 1;
		a[i] = rnd;
	}
	res = find_equal(a);
	if (res == 0)
		goto retry;
	int	i = 0;
	while (i < 6)
	{
		printf("[%d]\n", a[i]);
		i++;
	}
	return (0);
}
