/*
** my_getdouble.c for  in /home/alex/Rendu/C_Prog_Elem/N4S/CPE_2015_n4s
**
** Made by Alex
** Login   <lavenu_a@epitech.net>
**
** Started on  Tue Apr 26 13:47:16 2016 Alex
** Last update Tue Apr 26 15:59:54 2016 Alex
*/

int		str_i(char str, int *check)
{
  if (*check == 1)
    return (2);
  else if ((str >= '0' && str <= '9'))
    return (1);
  else if (str == '.')
    {
      *check = 1;
      return (2);
    }
  else
    return (0);
}

double		my_getdouble(char *str)
{
  int		i;
  double	nbr;
  int		nbr2;
  double	rst;
  int		check;

  i = 0;
  nbr = 1;
  nbr2 = 1;
  rst = 0;
  check = 0;
  if ((str[i] < '0' && str[i] > '9') && (str[i] != '-' || str[i] != '+'))
    return (0);
  while ((str[i] == '-' || str[i] == '+') && str[i] != 0)
    i = i + 1;
  if (str[i - 1] == '-')
    nbr = -1;
  while (str_i(str[i], &check) != 0 && str[i] != 0)
    {
      if (str_i(str[i], &check) == 1)
	rst = ((rst * 10) + (str[i] - 48));
      else if (str_i(str[i], &check) == 2)
	{
	  if (str[i] == '.')
	    ++i;
	  rst += (double)((str[i] - 48) / (double)(10 * nbr2));
	  nbr2 *= 10;
	}
      ++i;
    }
  return (rst * nbr);
}
