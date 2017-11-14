/*
** my.h for  in /home/alex/Rendu/C_Prog_Elem/N4S/CPE_2015_n4s
**
** Made by Alex
** Login   <lavenu_a@epitech.net>
**
** Started on  Tue Apr 26 13:58:48 2016 Alex
** Last update Mon May 23 17:36:36 2016 lenorm
*/

#ifndef MY_H_
# define MY_H_

#include "struct.h"

void		my_put_double(double nb);
double		my_getdouble(char *str);
char		*get_next_line(int fd);
int		get_value_id(char *str);
int		check_point(char *str, int mode);
int		get_info_speed(char *str, t_infos *info);
int		get_info_wheels(char *str, t_infos *info);
int		change_dir(t_infos *info);
void		get_info_lidar(char *str, t_infos *info);
double		get_angle(t_infos *info);
double		set_speed(double angle);
int		my_getnumber(char *str);
int		my_put_nbr(int n);
int		my_putchar(char c);
t_average	*my_append_average(t_average *average, double *lidar, int cpt);
double		*get_info(const double *lidar, int idx);
double		get_average(const double *pos);
int		check_left_sides(t_infos *info);
int		check_right_sides(t_infos *info);
int		check_right_sides2(void);
int		check_wall(t_infos *info);
int		move_forward(void);

#endif /* !MY_H_ */
