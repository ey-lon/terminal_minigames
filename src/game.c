#include "guess_n.h"

void    ft_game(t_opt opt)
{
    char    *str;
    int n;
    int att;

    ft_printf("GAME ON!\n");
    str = NULL;
    att = 0;
    n = rand() % (opt.max + 1 - opt.min) + opt.min;
    while (1)
    {
        att++;
        if (str)
            free(str);
        str = get_next_line(0);
        if (!ft_strncmp("exit\n", str, 5))
        {
            free(str);
            ft_printf("You gave up!\n");
            break ;
        }
        else if (ft_digits_check(str))
        {
            if (ft_atoi(str) == n)
            {
                free(str);
                ft_printf("Congrats! You Won in %d attempts.\n", att);
                break ;
            }
            else if (ft_atoi(str) > n)
                ft_printf("The number to find is smaller\n");
            else if (ft_atoi(str) < n)
                ft_printf("The number to find is greater\n");
            ft_printf("attempts = %d\n", att);
        }
        else
            ft_printf("Invalid argument.\n");
        if (opt.att_lmt > 0 && att == opt.att_lmt)
        {
            free(str);
            ft_printf("You Lose! Too many attempts.\n");
            break ;
        }
        
    }
}