/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:47:54 by tnamir            #+#    #+#             */
/*   Updated: 2022/03/10 19:05:43 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eating(t_info	*info, int *one_time_wait)
{
	if (info->philo_id % 2 == 1 && *one_time_wait == 0)
	{
		usleep(info->time_to_eat);
		*one_time_wait = 1;
	}
	pthread_mutex_lock(info->left_fork);
	if (*info->state == 1)
		printf("%.4lld philosofer %d has taken a fork\n",
			current_time() - info->start, info->philo_id);
	pthread_mutex_lock(info->right_fork);
	if (*info->state == 1)
		printf("%.4lld philosofer %d has taken a fork\n",
			current_time() - info->start, info->philo_id);
	if (*info->state == 1)
		printf("%.4lld philosofer %d is eating\n", current_time() - info->start,
			info->philo_id);
	info->death_time_reset = current_time();
	if (*info->state == 1)
		ultra_sleep(info->time_to_eat * 1000);
	pthread_mutex_unlock(info->left_fork);
	pthread_mutex_unlock(info->right_fork);
	info->nbr_of_times_philo_eat--;
	return (1);
}

int	sleeping(t_info	*info)
{
	if (*info->state == 1)
		printf("%.4lld philosofer %d is sleeping\n",
			current_time() - info->start, info->philo_id);
	if (*info->state == 1)
		ultra_sleep(info->time_to_sleep * 1000);
	return (1);
}

int	thinking(t_info	*info)
{
	if (*info->state == 1)
		printf("%.4lld philosofer %d is thinking\n",
			current_time() - info->start, info->philo_id);
	return (1);
}

long long	current_time(void)
{
	long long		total;
	struct timeval	time;

	gettimeofday(&time, NULL);
	total = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (total);
}

void	ultra_sleep(long long sleeptime)
{
	long long	start;

	start = current_time();
	while (current_time() < start + sleeptime / 1000)
		usleep(50);
}
