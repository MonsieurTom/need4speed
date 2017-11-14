/*
** my_getnumber.c for my_getnumber in /home/lenorm_t/
**
** Made by tom lenormand
** Login   <lenorm_t@epitech.net>
**
** Started on  Sat Oct 10 14:17:09 2015 tom lenormand
** Last update Tue Apr 26 23:47:27 2016 lenorm
*/

int	str_ii(char str)
{
  if (str >= '0' && str <= '9')
    return (1);
  else
    return (0);
}

int	my_getnumber(char *str)
{
  int	i;
  int	numb;
  int	result;

  result = 0;
  numb = 1;
  i = 0;
  if ((str[i] < '0' && str[i] > '9') && (str[i] != '-' || str[i] != '+'))
    return (0);
  while ((str[i] == '-' || str[i] == '+') && str[i] != 0)
    i = i + 1;
  if (str[i - 1] == '-')
    numb = -1;
  while (str_ii(str[i]) == 1 && str[i] != 0)
    {
      if (str_ii(str[i]) == 1)
	{
	  result = ((result * 10) + (str[i] - 48));
	}
      i = i + 1;
    }
  return (result * numb);
}
