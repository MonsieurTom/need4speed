/*
** get_lidar.c for n4s in /home/lenorm
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Tue Apr 26 16:09:17 2016 lenorm
** Last update Mon May 23 17:29:26 2016 Alex
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

double		*get_info(const double *lidar, int idx)
{
  double	*pos;
  int		cpt;

  cpt = 0;
  if ((pos = malloc(sizeof(double) * 6)) == NULL)
    return (NULL);
  while (cpt < 6)
    {
      pos[cpt] = lidar[idx];
      cpt = cpt + 1;
      idx = idx + 1;
    }
  return (pos);
}

t_average	*my_append_average(t_average *average, double *lidar, int cpt)
{
  t_average	*new;
  t_average	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  if ((new->pos = get_info(lidar, cpt)) == NULL)
    return (NULL);
  new->idx = cpt;
  new->average = get_average(new->pos);
  new->next = NULL;
  if (average == NULL)
    return (new);
  tmp = average;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (average);
}

void		get_info_lidar_2(char *str, char *buff, int *idx, int *idx2)
{
  while (str[*idx] != ':')
    {
      buff[*idx2] = str[*idx];
      ++*idx2;
      ++*idx;
    }
  buff[*idx2] = 0;
}

void		get_info_lidar(char *str, t_infos *info)
{
  int		idx;
  int		idx2;
  int		cpt;
  char		buff[10];

  idx = 0;
  cpt = 0;
  if (get_value_id(str) == -1)
    return ;
  while (str[idx] && cpt < 2)
    {
      if (str[idx] == ':')
	cpt = cpt + 1;
      idx = idx + 1;
    }
  if (str[idx] == 0)
    return ;
  while (cpt <= 34)
    {
      ++idx;
      idx2 = 0;
      get_info_lidar_2(str, buff, &idx, &idx2);
      info->lidar[cpt - 2] = my_getdouble(buff);
      ++cpt;
    }
}
