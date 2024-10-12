// \n


#include <unistd.h>

int	main(void)
{
	ft_fun();
	return (0);
}

1 - int function "print_comb" these lines of code
"
for (i = 0; i < n; i++)
	{
		if (comb[i] != 10 - n + i)
		{
			is_last_comb = 0;
			break;
		}
	}
"

 checks if is the last combination, but i think this just check if the digit in the first position of the array is the last digit that we can initialize a combination of n digits, for example for n = 2 the last combination will have 8 in the first position of the array (10 - 2 = 8), for n = 3 the last combination will have 7 in the first position of the array (10 - 3 = 7) .... for n = 9 the last combination will have 1 in the first position of the array (10 - 9 = 1) and so on for other values, so why do we need to put this in a for loop if just want to check if the value of the first position of the array is the value of the last combination? it is a wrong approach do something like: comb[0] != 10 - n
