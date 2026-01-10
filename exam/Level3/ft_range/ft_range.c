/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:43:37 by uuenkhba          #+#    #+#             */
/*   Updated: 2026/01/09 11:30:08 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int *ft_range(int start, int end)
{
	int *tab;
	int i;
	int size;
	i = 0;
	size = 0;
	if(start < end)
		size = end - start;
	else
		size = start - end;
	tab = malloc(sizeof(int) * (size + 1));
	if(!tab)
		return(NULL);
	while(i <= size)
	{
		tab[i] = start;
		if(start < end)
			start++;
		else
			start--;
		i++;
	}
	return(tab);
}
#include <stdio.h>
#include <string.h>
void print_array(int *arr, int size)
{
	int i;
	i = 0;
	while(i < size)
	{
		printf("%d", arr[i]);
		if(i < size - 1)
			printf(", ");
		i++;
	}
	printf("\n");
}
int main(void)
{
	int *res;
	int size;
	
	res = ft_range(-1 , 3);
	size = (1 <= 3) ? 3 - 1 + 1 : 1 - 3 + 1;
	printf("Test(-1, 3)  ->");
	print_array(res, size);
	free(res);
	return (0);
}
