#include "guess_n.h"

int	ft_gn_status_update(int n, int nbr, int att)
{
	if (nbr == n)
	{
		ft_printf("Congrats! You Won in %d attempts.\n", att);
		return (1);
	}
	else if (nbr > n)
		ft_printf("The number to find is smaller\n");
	else if (nbr < n)
		ft_printf("The number to find is greater\n");
	ft_printf("attempts = %d\n", att);
	return (0);
}