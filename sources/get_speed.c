/*
** get_speed.c for n4s in /home/lenorm
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Tue Apr 26 14:12:48 2016 lenorm
** Last update Wed May 18 11:53:01 2016 lenorm
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

int		change_info_speed(char *str, int idx, t_infos *info)
{
  char		*s;
  int		cpt;
  int		idx2;

  cpt = 0;
  idx2 = idx;
  while (str[idx2] != ':')
    {
      idx2 = idx2 + 1;
      cpt = cpt + 1;
    }
  if ((s = malloc(sizeof(char) * (cpt + 1))) == NULL)
    return (-1);
  cpt = 0;
  while (str[idx] != ':')
    {
      s[cpt] = str[idx];
      cpt = cpt + 1;
      idx = idx + 1;
    }
  s[cpt] = '\0';
  info->speed = my_getdouble(s);
  return (0);
}

int		get_info_speed(char *str, t_infos *info)
{
  int		idx;
  int		cpt;

  cpt = 0;
  idx = 0;
  if (get_value_id(str) == -1)
    {
      write(1, "An error occured!\n", 18);
      return (-1);
    }
  while (cpt < 3)
    {
      if (str[idx] == ':')
	cpt = cpt + 1;
      idx = idx + 1;
    }
  if (change_info_speed(str, idx, info) == -1)
    {
      write(1, "An error occured!\n", 18);
      return (-1);
    }
  return (0);
}
