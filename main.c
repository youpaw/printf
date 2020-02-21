//
// Created by alina on 13.02.2020.
//
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>

int main(void)
{
    long double d = 1.5;

    long double d1 = 0.0L;

    ft_printf("%-23.90Lf\n", d);
    printf("%-23.90Lf\n", d);
    return (0);
}
