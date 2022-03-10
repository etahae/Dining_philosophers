/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:35:02 by tnamir            #+#    #+#             */
/*   Updated: 2022/03/10 20:45:25 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initializer(int c, char **v, t_philo *philo, int x)
{
	philo->info[x].nbr_of_times_philo_eat = -1;
	if (c == 6)
		philo->info[x].nbr_of_times_philo_eat = ft_atoi(v[5]);
	philo->state = 1;
	philo->info[x].philo_id = x + 1;
	philo->info[x].time_to_die = ft_atoi(v[2]);
	philo->info[x].time_to_eat = ft_atoi(v[3]);
	philo->info[x].time_to_sleep = ft_atoi(v[4]);
	philo->info[x].left_fork = &philo->forks[x];
	philo->info[x].right_fork = &philo->forks[(x + 1) % philo->philo_nbr];
	philo->info[x].state = &philo->state;
	philo->info[x].philo_nbr = &philo->philo_nbr;
	philo->info[x].start = current_time();
	philo->info[x].death_time_reset = current_time();
}
