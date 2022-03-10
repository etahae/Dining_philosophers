/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:48:53 by tnamir            #+#    #+#             */
/*   Updated: 2022/03/10 20:50:29 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death(void	*info)
{
	int		x;
	t_philo	*philo;

	philo = info;
	while (1)
	{
		x = -1;
		while (++x < philo->philo_nbr)
		{
			if (philo->info[x].nbr_of_times_philo_eat == 0)
				return (0);
			if (current_time()
				- philo->info[x].death_time_reset > philo->info[x].time_to_die)
			{
				philo->death_checker = 1;
				philo->state = 0;
				printf("%.4lld philosofer %d died\n",
					current_time() - philo->info[x].start,
					philo->info[x].philo_id);
				if (philo->philo_nbr == 1)
					pthread_mutex_unlock(philo->info->left_fork);
				return (0);
			}
		}
	}
}

void	*pass_to(void	*arg)
{
	t_info	*philo;
	int		one_time_wait;

	philo = arg;
	one_time_wait = 0;
	philo->start = current_time();
	philo->death_time_reset = current_time();
	while (1)
	{
		if (*philo->state == 0)
			break ;
		eating(philo, &one_time_wait);
		if (philo->nbr_of_times_philo_eat == 0 || *philo->state == 0)
			break ;
		sleeping(philo);
		if (*philo->state == 0)
			break ;
		thinking(philo);
		if (*philo->state == 0)
			break ;
	}
	return (0);
}

void	to_be_main(int argc, char **argv,
		t_philo	*philo, pthread_t *thread)
{
	pthread_t	deathnote;
	int			x;

	thread = malloc(philo->philo_nbr * sizeof(pthread_t));
	philo->info = malloc(philo->philo_nbr * sizeof(t_info));
	philo->forks = malloc(philo->philo_nbr * sizeof(pthread_mutex_t));
	x = -1;
	while (++x < philo->philo_nbr)
	{
		initializer(argc, argv, philo, x);
		pthread_mutex_init(&philo->forks[x], NULL);
		pthread_create(&thread[x], NULL, pass_to, &philo->info[x]);
	}
	pthread_create(&deathnote, NULL, death, philo);
	x = -1;
	while (++x < philo->philo_nbr)
	{
		pthread_join(thread[x], NULL);
		pthread_mutex_destroy(&philo->forks[x]);
	}
	pthread_join(deathnote, NULL);
}

int	main(int argc, char	**argv)
{
	pthread_t		*thread;
	t_philo			philo;

	if (!(argc == 5 || argc == 6))
		return (0);
	thread = NULL;
	philo.philo_nbr = ft_atoi(argv[1]);
	philo.nbr_of_forks = philo.philo_nbr;
	to_be_main(argc, argv, &philo, thread);
	free(philo.forks);
	free(thread);
	free(philo.info);
	return (0);
}
