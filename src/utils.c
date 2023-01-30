/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:00:50 by hsozan            #+#    #+#             */
/*   Updated: 2023/01/30 14:01:10 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

void	destroy_threads(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		pthread_detach(env->philos[i].th_id);
	free(env->philos);
}

void	destroy_mutexes(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->number_of_philo)
		pthread_mutex_destroy(&env->chopsticks[i]);
	free(env->chopsticks);
}

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

	res = 0;
	sing = 1;
	i = 0;
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
