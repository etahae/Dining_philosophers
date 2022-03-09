/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnamir <tnamir@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:49:35 by tnamir            #+#    #+#             */
/*   Updated: 2022/03/08 20:55:54 by tnamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_info
{
	long			start;
	int				philo_id;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				nbr_of_times_philo_eat;
	long			death_time_reset;
	int				*philo_nbr;
	int				*state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_info;

typedef struct s_philo
{
	int				death_checker;
	int				philo_nbr;
	int				nbr_of_forks;
	int				state;
	t_info			*info;
	pthread_mutex_t	*forks;
}	t_philo;

int			ft_atoi(const char *str);
void		initializer(int c, char	**v, t_philo *philo, int x);
int			eating(t_info	*info, int *one_time_wait);
int			sleeping(t_info	*info);
int			thinking(t_info	*info);
long long	current_time(void);
void		*death(void	*info);

#endif