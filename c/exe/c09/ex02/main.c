/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:08:18 by fnicolau          #+#    #+#             */
/*   Updated: 2025/03/23 19:36:05 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

void free_split(char **split)
{
    int i = 0;
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

int main(void)
{
    char **tokens;
    int i;

    // Test 1: Basic input with a single delimiter.
    char *str1 = "Hello World";
    char *charset1 = " ";
    printf("Test 1:\nInput: \"%s\"\nDelimiter: \"%s\"\n", str1, charset1);
    tokens = ft_split(str1, charset1);
    i = 0;
    while (tokens && tokens[i])
    {
        printf("Token %d: \"%s\"\n", i, tokens[i]);
        i++;
    }
    free_split(tokens);

    // Test 2: Input with multiple delimiters.
    char *str2 = "This,is a-test string";
    char *charset2 = ",- ";
    printf("\nTest 2:\nInput: \"%s\"\nDelimiter: \"%s\"\n", str2, charset2);
    tokens = ft_split(str2, charset2);
    i = 0;
    while (tokens && tokens[i])
    {
        printf("Token %d: \"%s\"\n", i, tokens[i]);
        i++;
    }
    free_split(tokens);

    // Test 3: Input with consecutive delimiters.
    char *str3 = "Hello,,,World!!!";
    char *charset3 = ",!";
    printf("\nTest 3:\nInput: \"%s\"\nDelimiter: \"%s\"\n", str3, charset3);
    tokens = ft_split(str3, charset3);
    i = 0;
    while (tokens && tokens[i])
    {
        printf("Token %d: \"%s\"\n", i, tokens[i]);
        i++;
    }
    free_split(tokens);

    // Test 4: Input with no delimiters found.
    char *str4 = "NoDelimiters";
    char *charset4 = " ,.-";
    printf("\nTest 4:\nInput: \"%s\"\nDelimiter: \"%s\"\n", str4, charset4);
    tokens = ft_split(str4, charset4);
    i = 0;
    while (tokens && tokens[i])
    {
        printf("Token %d: \"%s\"\n", i, tokens[i]);
        i++;
    }
    free_split(tokens);

    // Test 5: Empty string.
    char *str5 = "";
    char *charset5 = " ";
    printf("\nTest 5:\nInput: \"%s\"\nDelimiter: \"%s\"\n", str5, charset5);
    tokens = ft_split(str5, charset5);
    if (!tokens || tokens[0] == NULL)
        printf("No tokens found.\n");
    else
    {
        i = 0;
        while (tokens[i])
        {
            printf("Token %d: \"%s\"\n", i, tokens[i]);
            i++;
        }
    }
    free_split(tokens);

    return 0;
}

