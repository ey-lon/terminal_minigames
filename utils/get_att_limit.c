#include "utils.h"

static void	ft_get_attempts_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  ATTEMPTS                  |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

static void	ft_get_att_status(int *n)
{
	if (*n > 0)
		ft_printf("ATTEMPTS = [%d]\n", *n);
	else
	{
		*n = 0;
		ft_printf("ATTEMPTS = [Unlimited]\n");
	}
}

int	ft_get_attempts(int *n)
{
	ft_get_attempts_header();
	ft_printf("Insert the maximum number of attempts:\n");
	if (ft_get_n(n))
		return (1);
	ft_get_att_status(n);
	return (0);
}
