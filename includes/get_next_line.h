/*
** get_next_line.h for get_next_line in /home/lenorm_t/CPE_2015_getnextline
**
** Made by tom lenormand
** Login   <lenorm_t@epitech.net>
**
** Started on  Mon Jan  4 14:40:35 2016 tom lenormand
** Last update Mon May 23 17:31:42 2016 lenorm
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (100)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	*my_reallic(char *str, int size);
int	check_buff(const int fd, char *chara, char (*buff)[], int *cpt);

#endif /* !GET_NEXT_LINE_H_ */
