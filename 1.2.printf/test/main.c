/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uuenkhba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:32:48 by uuenkhba          #+#    #+#             */
/*   Updated: 2025/11/25 19:42:13 by uuenkhba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"
int main()
{
	ft_printf("Hello %s, та %d настай, pointer: %p\n", "", 42, "0");
	ft_printf("Hex: %x, HEX: %X, %%\n", 255, 255);
	ft_printf("Unsigned: %u\n", -1);

	printf("real Hello %s, та %d настай, pointer: %p\n", "", 42, "0");
	printf("real Hex: %x, HEX: %X, %%\n", 255, 255);
	printf("real Unsigned: %u\n", -1);
	return (0);
}

