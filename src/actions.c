/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:58:52 by hsozan            #+#    #+#             */
/*   Updated: 2023/01/30 13:59:33 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philosophers.h"

void	take_forks(t_philo *philo)
{
	uint64_t	reel_time;

	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_l]);
	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->env->chopsticks[philo->chopstick_r]);
	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "has taken a fork");
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_l]);
	pthread_mutex_unlock(&philo->env->chopsticks[philo->chopstick_r]);
}

void	philo_eat(t_philo *philo)
{
	uint64_t	reel_time;

	reel_time = get_time_ms() - philo->env->start_time;
	printf("%llu %d %s\n", reel_time, philo->id, "is eating");
	philo->last_eat = reel_time;
	philo->count_eat++;
	usleep(philo->env->time_to_eat * 1000);
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
