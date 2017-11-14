/*
** get_next_line.c for get_next_line in /home/lenorm_t/CPE_2015_getnextline
**
** Made by tom lenormand
** Login   <lenorm_t@epitech.net>
**
** Started on  Mon Jan  4 18:08:52 2016 tom lenormand
** Last update Wed Apr 27 13:37:29 2016 Alex
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/get_next_line.h"

char		*my_realloc(char *str, int size)
{
  char		*new_str;
  int		i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * size + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  new_str[size] = '\0';
  free(str);
  return (new_str);
}

int		check_buff(const int fd, char *chara, char (*buff)[], int *cpt)
{
  static int	idx;

  if (idx >= *cpt || idx == 0)
    {
      idx = 0;
      if ((*cpt = read(fd, (*buff), READ_SIZE)) < 0)
	return (-1);
    }
  if (*cpt == 0)
    {
      idx = 0;
      *chara = '\0';
    }
  else
    {
      if ((*buff)[idx] == '\n')
	*chara = '\0';
      else
	*chara = (*buff)[idx];
    }
  idx = idx + 1;
  return (*cpt);
}

char		*get_next_line(const int fd)
{
  static int	cpt;
  static char	buff[READ_SIZE];
  char		*next_line;
  int		i;
  int		check;

  i = 0;
  if (buff == NULL)
    cpt = READ_SIZE;
  if ((next_line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((check = check_buff(fd, &next_line[i], &buff, &cpt)) == -1)
    return (NULL);
  else if (check == 0)
    return (NULL);
  while (next_line[i] != '\0')
    {
      if (i % READ_SIZE == 0)
	if ((next_line = my_realloc(next_line, i + READ_SIZE + 1)) == NULL)
	  return (NULL);
      if (check_buff(fd, &next_line[++i], &buff, &cpt) == -1)
	return (NULL);
    }
  next_line[i + 1] = '\0';
  return (next_line);
}
