/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:54:21 by eseferi           #+#    #+#             */
/*   Updated: 2024/04/09 19:43:31 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_base_error(char *base)
{
    int	i;
    int	j;

    i = 0;
    while (base[i])
    {
        j = 0;
        while (base[j])
        {
            if (base[i] == base[j] && i != j)
                return (0);
            j++;
        }
        if (base[i] == ' ' || base[i] == '\f' || base[i] == '\n'
            || base[i] == '\r' || base[i] == '\t' || base[i] == '\v'
            || base[i] == '-' || base[i] == '+')
            return (0);
        i++;
    }
    return (i);
}

static int	ft_atoi_base_test(char str, char *base)
{
    int	i;

    i = 0;
    while (base[i])
    {
        if (str == base[i])
            return (i);
        i++;
    }
    return (-1);
}

static int	ft_atoi_base_search(char *str, int *i)
{
    int	mult;

    mult = 1;
    while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n'
        || str[*i] == '\r' || str[*i] == '\t'
        || str[*i] == '\v')
        *i += 1;
    while (str[*i] == '-' || str[*i] == '+')
    {
        if (str[*i] == '-')
            mult *= -1;
        *i += 1;
    }
    return (mult);
}

long long int	ft_atoi_base(char *str, char *base)
{
    int				i;
    int				mult;
    long long int	nb;
    int				tmp;
    int				len;

    nb = 0;
    i = 0;
    len = ft_atoi_base_error(base);
    if (len >= 2)
    {
        mult = ft_atoi_base_search(str, &i);
        tmp = ft_atoi_base_test(str[i], base);
        while (tmp != -1)
        {
            nb = (nb * len) + tmp;
            i++;
            tmp = ft_atoi_base_test(str[i], base);
        }
        return (nb * mult);
    }
    return (0);
}
