/*
** my_putchar.c for my_putchar in /home/lenorm_t/rendu/Piscine_C_J10/lib/my
**
** Made by tom lenormand
** Login   <lenorm_t@epitech.net>
**
** Started on  Fri Oct  9 09:25:47 2015 tom lenormand
** Last update Wed Apr 27 16:10:33 2016 lenorm
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
