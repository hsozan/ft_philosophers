/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:56:25 by hsozan            #+#    #+#             */
/*   Updated: 2023/01/30 13:56:29 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus.h"

void	take_forks(t_philo *philo)
{
	uint64_t	reel_time;

	sem_wait(philo->env->chopsticks);
	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
	sem_wait(philo->env->chopsticks);
	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is eating");
	philo->last_eat = reel_time;
	philo->count_eat++;
	usleep(philo->env->time_to_eat * 1000);
	sem_post(philo->env->chopsticks);
	sem_post(philo->env->chopsticks);
}

void	philo_sleep(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is sleeping");
	usleep(philo->env->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is thinking");
}
