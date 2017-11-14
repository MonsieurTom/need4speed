/*
** set_speed.c for  in /home/alex/Rendu/C_Prog_Elem/N4S/CPE_2015_n4s
**
** Made by Alex
** Login   <lavenu_a@epitech.net>
**
** Started on  Wed Apr 27 11:20:23 2016 Alex
** Last update Wed Apr 27 11:37:42 2016 Alex
*/

double		set_speed(double angle)
{
  double	speed;
  double	tmp;

  speed = 0.2;
  tmp = 1.0;
  if (angle == -2.0)
    return (-1);
  else if (angle == 0)
    return (1);
  else if (angle < 0)
    angle *= -1;
  else
    {
      while (tmp > angle)
	{
	  speed += 0.1;
	  tmp -= 0.1;
	}
    }
  if (speed > 1)
    return (1);
  return (speed);
}
