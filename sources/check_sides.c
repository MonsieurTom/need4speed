/*
** check_sides.c for n4s in /home/lenorm/epitech-projects
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Mon May 23 17:33:13 2016 lenorm
** Last update Mon May 23 17:37:58 2016 lenorm
*/

#include <unistd.h>
#include "struct.h"
#include "my.h"

int		check_wall(t_infos *info)
{
  int		idx;

  idx = 15;
  while (idx < 17)
    {
      if (info->lidar[idx] <= 550)
	return (0);
      idx = idx + 1;
    }
  return (1);
}

int		check_right_sides2(void)
{
  int		err;
  char		*str;

  write(1, "CAR_FORWARD:0.3\n", 16);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  write(1, "WHEELS_DIR:0.120\n", 17);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  return (0);
}

int		check_right_sides(t_infos *info)
{
  int		idx;
  int		cpt;

  idx = 27;
  cpt = 1;
  while (idx <= 32)
    {
      if (info->lidar[idx] <= 450 && info->lidar[cpt] > info->lidar[idx])
	{
	  if (info->lidar[idx] <= 200)
	    change_dir(info);
	  else
	    {
	      if (check_right_sides2() == -1)
		return (-1);
	    }
	  return (0);
	}
      idx = idx + 1;
      cpt = cpt + 1;
    }
  return (1);
}

int		check_left_sides(t_infos *info)
{
  int		idx;
  int		cpt;

  idx = 1;
  cpt = 27;
  while (idx <= 5)
    {
      if (info->lidar[idx] <= 450 && info->lidar[cpt] > info->lidar[idx])
	{
	  if (info->lidar[idx] <= 200)
	    change_dir(info);
	  else
	    {
	      if (move_forward() == -1)
		return (-1);
	    }
	  return (0);
	}
      idx = idx + 1;
      cpt = cpt + 1;
    }
  return (1);
}
