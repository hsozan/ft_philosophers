/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:55:25 by hsozan            #+#    #+#             */
/*   Updated: 2023/01/30 13:55:51 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

uint64_t	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(char *s)
{
	int	res;
	int	sing;
	int	i;
	int	j;

	res = 0;
	sing = 1;
	i = 0;
	j = -1;
	while (s[++j])
		if (s[j] < '0' || s[j] > '9')
			exit(-1);
	while (s[i] <= 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - 48);
	return (res * sing);
}

void	destroy_semaphores(void)
{
	sem_unlink("./chopsticks");
	sem_unlink("./isdied");
	sem_unlink("./typing");
}

static void	destroy_zombies(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		kill(env->philos[i].pid, SIGKILL);
}

void	destroy(t_env *env)
{
	destroy_zombies(env);
	destroy_semaphores();
	free(env->philos);
}
