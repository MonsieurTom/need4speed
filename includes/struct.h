/*
** struct.h for  in /home/alex/Rendu/C_Prog_Elem/N4S/CPE_2015_n4s
**
** Made by Alex
** Login   <lavenu_a@epitech.net>
**
** Started on  Tue Apr 26 13:30:08 2016 Alex
** Last update Wed Apr 27 11:51:51 2016 lenorm
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_infos
{
  double		wheels_pos;
  double		speed;
  double		lidar[33];
}			t_infos;

typedef struct		s_average
{
  double		*pos;
  int			idx;
  double		average;
  struct s_average	*next;
}		t_average;

#endif // !STRUCT_H_
