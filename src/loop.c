/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:00:05 by hsozan            #+#    #+#             */
/*   Updated: 2023/01/30 14:00:26 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

void	*life_cycle_checker(void *arg)
{
	int			i;
	uint64_t	timestamp;
	t_env		*env;

	env = (t_env *)arg;
	i = 0;
	while (1)
	{
		if (env->count_done == env->number_of_philo)
			break ;
		if (i == env->number_of_philo)
			i = 0;
		usleep(100);
		timestamp = get_time_ms() - env->start_time;
		if (((int)(timestamp - env->philos[i].last_eat) > env->time_to_die))
		{
			printf("%s%llu %d %s\n", "\x1B[31m", \
					timestamp, env->philos[i].id, "died");
			env->is_running = false;
			break ;
		}
		i++;
	}
	return (NULL);
}

void	*life_cycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time_ms() - philo->env->start_time;
	if (philo->id % 2 == 1)
	{
		philo_think(philo);
		usleep(philo->env->time_to_eat * 1000);
	}
	while (!philo->done)
	{
		take_forks(philo);
		philo_eat(philo);
		leave_forks(philo);
		if (philo->count_eat == philo->env->must_eat)
		{
			philo->done = true;
			philo->env->count_done++;
			break ;
		}
		philo_think(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
