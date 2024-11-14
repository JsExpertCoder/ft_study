/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:07:59 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/12 22:51:02 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	signal = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signal = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signal);
}

int	ft_atoi2(const char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int main() {
    const char *test_cases[] = {
        "42",
        "-42",
        "  42",
        "+42",
        "---42",
        "-0",
        "123456789",
        "-123456789",
        "  +12345",
        "00001234",
        "abc123",   // Invalid input
        "-abc123",  // Invalid input
        "123abc",   // Invalid input
        "2147483647",   // Max int value
        "-2147483648",  // Min int value
        "",           // Empty string
        NULL
    };

      for (int i = 0; test_cases[i] != NULL; i++) {
        const char *test_case = test_cases[i];

        printf("test    :\"%s\"\n", test_case);
        printf("atoi    : %d\n", atoi(test_case));
  		printf("ft_atoi : %d\n", ft_atoi(test_case));
		printf("ft_atoi2: %d\n", ft_atoi2(test_case));
        printf("\n");
    }

    return 0;
}
