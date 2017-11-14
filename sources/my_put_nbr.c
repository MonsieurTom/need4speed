/*
** my_put_nbr.c for  in /home/lavenu_a/rendu/j03
**
** Made by alexis lavenu
** Login   <lavenu_a@epitech.net>
**
** Started on  Thu Oct  1 10:18:10 2015 alexis lavenu
** Last update Tue Jun  7 11:13:03 2016 Alex
*/

#include "my.h"

void	my_pushit()
{
  my_putchar('2');
  my_putchar('1');
  my_putchar('4');
  my_putchar('7');
  my_putchar('4');
  my_putchar('8');
  my_putchar('3');
  my_putchar('6');
  my_putchar('4');
  my_putchar('8');
}

int	my_put_nbr(int nbr)
{
  int	a;

  a = 1;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  if (nbr == -2147483648)
    my_pushit();
  while ((nbr / a) >= 10)
    a = a * 10;
  while (a > 0)
    {
      my_putchar((nbr / a) % 10 + '0');
      a = a / 10;
    }
  return (0);
}
