#include "guess_n.h"

void	ft_rules(t_opt opt)
{
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("  RULES\n");
	ft_printf("  Guess the number between [%d] and [%d]", opt.min, opt.max);
	if (opt.att_lmt > 0)
		ft_printf(" in no more than [%d] attempts", opt.att_lmt);
	ft_printf(".\n");
	ft_printf("-------------------------------------------------------------\n");
}
