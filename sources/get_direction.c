/*
** get_direction.c for n4s in /home/lenornm
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Wed Apr 27 10:57:47 2016 lenorm
** Last update Mon May 23 17:21:32 2016 lenorm
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

double		get_average(const double *pos)
{
  int		cpt;
  double	result;

  cpt = 0;
  result = 0.0;
  while (cpt < 6)
    {
      result = result + pos[cpt];
      cpt = cpt + 1;
    }
  result = result / 6;
  return (result);
}

t_average	*biggest_average(t_average *average)
{
  t_average	*tmp;
  t_average	*tmp2;

  tmp = average;
  tmp2 = average;
  while (tmp != NULL)
    {
      if (tmp->average > tmp2->average)
	tmp2 = tmp;
      tmp = tmp->next;
    }
  return (tmp2);
}

double		find_true_angle(t_average *average)
{
  double	result;

  if ((average->idx) + 3 == 16)
    return (0.0);
  else
    {
      result = ((average->idx + 3) - 16) * 1.875;
      return (result);
    }
  return (0.0);
}

double		find_angle(t_average *average)
{
  double	angle;
  double	true_angle;

  true_angle = find_true_angle(average);
  if (true_angle == 0.0)
    angle = true_angle;
  else
    angle = (true_angle / 40) * -1;
  return (angle);
}

double		get_angle(t_infos *info)
{
  t_average	*average;
  double	angle;
  int		cpt;

  angle = 0.0;
  average = NULL;
  cpt = 1;
  while (cpt <= 26)
    {
      if ((average = my_append_average(average, info->lidar, cpt)) == NULL)
	return (-2.0);
      cpt = cpt + 1;
    }
  angle = find_angle(biggest_average(average));
  return (angle);
}
