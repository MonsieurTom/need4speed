/*
** main.c for  in /home/alex/Rendu/C_Prog_Elem/N4S/CPE_2015_n4s/sources
**
** Made by Alex
** Login   <lavenu_a@epitech.net>
**
** Started on  Tue Apr 26 13:29:10 2016 Alex
** Last update Mon May 23 17:36:49 2016 lenorm
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"
#include "struct.h"

void		my_put_double(double nb)
{
  if (nb < 0)
    {
      nb = nb * -1;
      write(1, "-", 1);
    }
  my_put_nbr((int)nb);
  nb = nb * 10000000;
  write(1, ".", 1);
  nb = (int)nb % 10000000;
  my_put_nbr((int)nb);
}

int		move_forward(void)
{
  char		*str;
  int		err;

  write(1, "CAR_FORWARD:0.3\n", 16);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0
      || err == -1)
    return (-1);
  write(1, "WHEELS_DIR:-0.120\n", 18);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0
      || err == -1)
    return (-1);
  return (0);
}

int		sustain_dir(t_infos *info)
{
  int		err;
  char		*str;

  if (check_left_sides(info) == 1 &&
      check_right_sides(info) == 1)
    {
      write(1, "WHEELS_DIR:0.0\n", 15);
      if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
	return (-1);
      if (info->lidar[16] >= 1200)
	write(1, "CAR_FORWARD:1.0\n", 16);
      else if (info->lidar[16] >= 1500 && info->lidar[1] <= 500
	       && info->lidar[32] <= 500)
	write(1, "CAR_FORWARD:0.3\n", 16);
      else
	write(1, "CAR_FORWARD:0.3\n", 16);
      if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
	return (-1);
    }
  return (0);
}

void		start_simulation(void)
{
  write (1, "START_SIMULATION\n", 17);
  get_next_line(0);
  write(1, "CAR_FORWARD:0.4\n", 16);
  get_next_line(0);
}

int		main(void)
{
  int		err;
  t_infos	info;
  char		*str;

  start_simulation();
  while (42)
    {
      write(1, "GET_INFO_LIDAR\n", 15);
      if ((err = check_point((str = get_next_line(0)), 35)) == 0 || err == -1)
	return (0);
      get_info_lidar(str, &info);
      if ((err = check_wall(&info)) == 0)
	{
	  if (change_dir(&info) == -1)
	    return (-1);
	}
      else if (err == 1)
	{
	  if (sustain_dir(&info) == -1)
	    return (-1);
	}
      else if (err == -1)
	return (-1);
    }
  return (0);
}
