/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apardo-m <apardo-m@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:40:15 by spereyra          #+#    #+#             */
/*   Updated: 2024/05/29 15:22:26 by apardo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_only_digits(char *str)
{
	int		i;
	char	*trim;

	i = 0;
	trim = ft_strtrim(str, " ");
	if (((trim[0] == '-' || trim[0] == '+') && ft_strlen(trim) > 1) \
			|| ft_isdigit(trim[0]))
		i++;
	else
	{
		free(trim);
		return (0);
	}
	while (trim[i])
	{
		if (!ft_isdigit(trim[i]))
		{
			free(trim);
			return (0);
		}
		i++;
	}
	free(trim);
	return (1);
}

static long long	ft_atoll(const char *str)
{
	long long	number;
	int			sign;
	int			i;

	number = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = (-1) * sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		number = number * 10;
		number = number + str[i] - '0';
		i++;
	}
	return (sign * number);
}

static int	check_neg_llong(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i] == '0')
		i++;
	if ((ft_strlen(num) - i) > 19)
		return (0);
	else if ((ft_strlen(num) - i) == 19)
	{
		if ((ft_strncmp(&num[i], "9223372036854775808", 19)) > 0)
			return (0);
	}
	return (1);
}

static int	check_long_long(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		return (check_neg_llong(num));
	if (num[i] == '+')
		i++;
	while (num[i] == '0')
		i++;
	if ((ft_strlen(num) - i) > 19)
		return (0);
	else if ((ft_strlen(num) - i) == 19)
	{
		if ((ft_strncmp(&num[i], "9223372036854775807", 19)) > 0)
			return (0);
	}
	return (1);
}

void	builtin_exit(char **argv_exec, t_shell *shell)
{
	if (shell->pipes == 1)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (argv_exec[1] == 0)
		exit (shell->exit_st);
	else if (argv_exec[1] && argv_exec[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (!check_only_digits(argv_exec[1]) \
			|| !check_long_long(argv_exec[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv_exec[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(255);
	}
	else
		exit(ft_atoll(argv_exec[1]) % 256);
}
