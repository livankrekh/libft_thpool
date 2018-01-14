/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:03:13 by liabanzh          #+#    #+#             */
/*   Updated: 2018/01/14 18:03:14 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THPOOL_H
# define THPOOL_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# define TP_ON_EXEC 0
# define TP_ON_START 1
# define false 0
# define true 1

typedef char bool;
typedef struct 	s_tp_thread t_tp_thread;

struct 			s_tp_thread
{
	int			id;
	bool		created;
	void		*data;
	pthread_t	*thread;
	t_tp_thread	*next;
};



t_tp_thread		*tp_create(int count, char flag);
int				tp_exec_queue_add(t_tp_thread *queue, void *(*f)(void *), void *data);
int				tp_wait_for_queue(t_tp_thread *queue);
int				tp_get_nbr_proc(void);

#endif
