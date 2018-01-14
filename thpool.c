/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thpool.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liabanzh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:03:33 by liabanzh          #+#    #+#             */
/*   Updated: 2018/01/14 18:03:34 by liabanzh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"

static void		*loop(void *lol)
{
	lol = NULL;
	while (1);
}

/*flags = TP_ON_EXEC or TP_ON_START*/
t_tp_thread		*tp_create(int count, char flag)
{
	t_tp_thread		*res;
	t_tp_thread		*tmp;
	int				i;

	i = 0;
	res = NULL;
	tmp = res;
	while (i < count)
	{
		if (i == 0)
			tmp = (t_tp_thread*)malloc(sizeof(t_tp_thread));
		else
		{
			tmp->next = (t_tp_thread*)malloc(sizeof(t_tp_thread));
			tmp = tmp->next;
		}
		tmp->id = i;
		tmp->created = (flag == TP_ON_START ? true : false);
		tmp->data = NULL;
		tmp->thread = NULL;
		flag == TP_ON_START ? pthread_create(tmp->thread, NULL, loop, NULL) : 0;
		tmp->next = NULL;
		i++;
	}
	return (res);
}

int				tp_exec_queue_add(t_tp_thread *queue, void *(*f)(void *), void *data)
{
	t_tp_thread		*cp;

	cp = queue;
	while (cp->created && cp)
		cp = cp->next;
	if (cp == NULL)
		return (-1);
	cp->data = data;
	cp->thread = (pthread_t*)malloc(sizeof(pthread_t));
	if (pthread_create(cp->thread, NULL, f, data) != 0)
		return (-1);
	cp->created = true;
	return (0);
}

int			tp_wait_for_queue(t_tp_thread *queue)
{
	t_tp_thread		*tmp;
	int				res;
	int				tmp2;

	res = 0;
	tmp = NULL;
	while (tmp->created && tmp)
	{
		tmp2 = pthread_join(*(queue->thread), NULL);
		if (tmp2 != 0)
			res = tmp2;
		tmp = tmp->next;
	}
	return (res);
}

int		tp_get_nbr_proc(void)
{
	return (sysconf(_SC_NPROCESSORS_ONLN));
}
