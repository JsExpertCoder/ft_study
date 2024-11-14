/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnicolau <fnicolau@student.42luanda.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:53:52 by fnicolau          #+#    #+#             */
/*   Updated: 2024/11/12 19:21:05 by fnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// from site
size_t site1(const char *s, const char *reject)
{
    size_t i;
    size_t j;
    
    i = 0;
    // Looping over the whole string
    while(s[i])
    {
        j = 0;
        // Check the current string char against every char in charset
        while (reject[j])
        {
            // If character found, return index in current string
            if (s[i] == reject[j])
            	return (i);
			j++;
        }
		i++;
    }
    // If we spanned the whole string, return i, in that case the
    // rejected char found is the NULL-terminating one
    return (i);
}

size_t site2(const char *s, const char *reject)
{
    // Save a pointer to the start of s
    const char *og = s;
    const char *s2;
    
    // Looping over the whole string 
    while (*s)
    {
        // Set s2 to be the start of reject
        // that way we keep the reject pointer to its original position
        // Then loop over the whole charset
        s2 = reject;
        while (*s2)
        {
            // If current string charcter found in charset, return the
            // number of characters spanned
            if (*s == *s2)
                // Here we make use of the original pointer to calculate
                // the number of char. spanned
                return (s - og);
			s2++;
        }
		s++;
    }
    // Same as above, we use the original pointer to calculate the number
    // of character spanned
    return (s - og);
}


int main() {
    // Array of test cases
	const char *test_cases[][2] = {
        {"Hell!oW orld!", " !"},                      // Test case 1: Match at index 0
        {"Hell!oW orld!", "@#&"},                      // Test case 2: Match at index 13
        {"Hello, World!", "H"},                         // Test case 3: Match at index 0
        {"", "abc"},                                    // Test case 4: Empty string
        {"The quick brown fox jumps over the lazy dog", "xj"},  // Test case 5: First match at index 18
        {"hello world", "aeiou"},                       // Test case 6: First match at index 1 (character 'e')
        {"hello world", "h"},                           // Test case 7: Match at index 0
        {"hello world", "xyz"},                         // Test case 8: Match at index 11
        {"hello world", "o"},                           // Test case 9: Match at index 4
        {"abcdefgh", "b"},                              // Test case 10: Match at index 1
        {"abcdefgh", "bc"},                             // Test case 11: Match at index 1 (character 'b')
        {"abcdef", "xyz"},                              // Test case 12: No match, should return 6
        {"abcdefgh", "z"},                              // Test case 13: No match, should return 8
        {"1234567890", "456"},                          // Test case 14: Match at index 3
        {"1234567890", "890"},                          // Test case 15: Match at index 6
        {"hello world", "w"},                           // Test case 16: Match at index 6
        {"this is a long test string", "test"},        // Test case 17: Match at index 4
        {"longteststring", "l"},                        // Test case 18: Match at index 0
        {"longteststring", "t"},                        // Test case 19: Match at index 3
        {"hello there, how are you?", "arw"},           // Test case 20: Match at index 14
        {"abcdefgh", "d"},                              // Test case 21: Match at index 3
        {"aaa", "z"},                                   // Test case 22: No match, should return 3
        {"no match here", "xyz"},                       // Test case 23: No match, should return 14
        {"", ""},                                       // Test case 24: Both strings empty, should return 0
        {"abcdef", ""},                                 // Test case 25: Empty reject, should return 6
        {"", "abc"},                                    // Test case 26: Empty string s, should return 0
        {"abcdefgh", "a"},                              // Test case 27: Match at index 0
        {"abcdefgh", "b"},                              // Test case 28: Match at index 1
        {"abcdefgh", "h"},                              // Test case 29: Match at index 7
        {"the quick brown fox", "a quick"},             // Test case 30: Match at index 4
        {"", "abc"},                                    // Test case 31: Empty s, any reject string, should return 0
        {"abc", "z"}                                    // Test case 32: No match, should return 3
    };


    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (size_t i = 0; i < num_tests; i++) {
        const char *s1 = test_cases[i][0];
        const char *s2 = test_cases[i][1];

        size_t standard = strcspn(s1, s2);
 		size_t custom = ft_strcspn(s1, s2);
		size_t s1v = site1(s1, s2);
		size_t s2v = site2(s1, s2);



        // Print results
		if (standard != custom || standard != s1v || standard != s2v)
		{
	        printf("falied test case %zu:\n", i + 1);
    	    printf(" s1: \"%s\"\n", s1);
        	printf(" s2: \"%s\"\n", s2);
	        printf("  s: %zu\n", standard);
 			printf("  g: %zu\n", custom);
			printf("s1v: %zu\n", s1v);
			printf("s2v: %zu\n", s2v);
			return (1);
		}
    }
	printf("all tests passed!");
    return 0;
}
