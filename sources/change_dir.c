/*
** chaneg_dir.c for n4s in /home/lenorm/epitech-projects/
**
** Made by lenorm
** Login   <lenorm_t@epitech.net>
**
** Started on  Wed May 18 11:44:08 2016 lenorm
** Last update Wed May 18 12:01:47 2016 lenorm
*/

#include <unistd.h>
#include "my.h"
#include "get_next_line.h"
#include "struct.h"

static int	change_right(t_infos *info)
{
  char		*str;
  int		err;
  double	angle;

  angle = get_angle(info);
  write(1, "WHEELS_DIR:", 11);
  my_put_double(angle);
  write(1, "\n", 1);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  write(1, "CYCLE_WAIT:1\n", 13);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  return (0);
}

static int		change_left(t_infos *info)
{
  char		*str;
  double	angle;
  int		err;

  angle = get_angle(info);
  write(1, "WHEELS_DIR:", 11);
  my_put_double(angle);
  write(1, "\n", 1);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  return (0);
}

int		change_dir(t_infos *info)
{
  char		*str;
  int		err;

  write(1, "CAR_FORWARD:0.125\n", 18);
  if ((err = check_point((str = get_next_line(0)), 3)) == 0 || err == -1)
    return (-1);
  if ((info->lidar[1] <= 200 && info->lidar[16] <= 550) ||
      (info->lidar[32] <= 200 && info->lidar[16] <= 550))
    {
      if (change_left(info) == -1)
	return (-1);
    }
  else
    {
      if (change_right(info) == -1)
	return (-1);
    }
  return (0);
}
