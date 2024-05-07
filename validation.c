#include "PushSwap.h"
static int is_valid_number(char const *str);

static int is_valid_number(char const *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (isdigit(str[i]) == 0)
		{
			write(2, "Error! nondigit char found\n", 21);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(2, "Error! Invalid ammount of arguments\n", 36);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{
		if (is_valid_number(argv[i]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
