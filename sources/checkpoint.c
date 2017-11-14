/*
** checkpoint.c for n4s in /home/lenorm
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Wed May 11 17:23:01 2016 lenorm
** Last update Wed May 18 11:52:20 2016 lenorm
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"

int		my_strcmp(char *s1, char *s2)
{
  int		idx;

  idx = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[idx] != '\0')
    {
      if (s1[idx] != s2[idx])
	return (1);
      idx = idx + 1;
    }
  if (s2[idx] != '\0')
    return (1);
  return (0);
}

int		find_lap_dote(char *str, int mode)
{
  int		idx;
  int		cpt;

  idx = 0;
  cpt = 0;
  while (cpt != mode)
    {
      if (str[idx] == ':')
	cpt = cpt + 1;
      idx = idx + 1;
    }
  return (idx);
}

char		*copy_info(char *str, int idx)
{
  char		*cpy;
  int		cpt;
  int		save_idx;

  cpt = 0;
  save_idx = idx;
  while (str[save_idx] != ':' && str[save_idx] != '\0')
    {
      save_idx = save_idx + 1;
      cpt = cpt + 1;
    }
  if ((cpy = malloc(sizeof(char) * (cpt + 1))) == NULL)
    return (NULL);
  cpt = 0;
  while (str[idx] != ':' && str[idx] != '\0')
    {
      cpy[cpt] = str[idx];
      cpt = cpt + 1;
      idx = idx + 1;
    }
  cpy[cpt] = '\0';
  return (cpy);
}

int		check_lap(char *str, int mode)
{
  char		*lap;
  int		idx;

  idx = find_lap_dote(str, mode);
  if ((lap = copy_info(str, idx)) == NULL)
    {
      write(2, "malloc failled!\n", 16);
      return (-1);
    }
  if (my_strcmp(lap, "Track Cleared") == 0)
    {
      free(lap);
      write(1, "CAR_FORWARD:0.0\n", 16);
      get_next_line(0);
      write(1, "CYCLE_WAIT:10\n", 14);
      get_next_line(0);
      return (0);
    }
  free(lap);
  return (1);
}

int		check_point(char *str, int mode)
{
  int		err;

  if ((err = check_lap(str, mode)) == 0)
    return (0);
  else if (err == -1)
    return (-1);
  return (1);
}
