#include "guess_n.h"

void ft_att_limit_header(void)
{
    ft_printf("----------------------------\n");
    ft_printf("|  ATTEMPTS                |\n");
    ft_printf("|                          |\n");
    ft_printf("|  type 'exit' to go back  |\n");
    ft_printf("----------------------------\n");
}

void ft_set_att_limit(int *n)
{
    char    *str;
    
    str = NULL;
    while (1)
    {
        ft_att_limit_header();
        ft_printf("Insert the maximum number of attempts:\n");
        if (str)
            free(str);
        str = get_next_line(0);
        if (!ft_strncmp("exit\n", str, 5))
        {
            free(str);
            return ;
        }
        else if (ft_digits_check(str))
        {
            *n = ft_atoi(str);
            free(str);
            break ;
        }
        else
            ft_printf("Invalid argument.\n");
    }
    if (*n > 0)
        ft_printf("ATTEMPTS = [%d]\n", *n);
    else
    {
        *n = 0;
        ft_printf("ATTEMPTS = [Unlimited]\n");
    }
}