/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:40:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/05/13 10:57:59 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gt_strdup(char const *s);
char	*gt_strjoin(char **s1, char const *s2, int len2);
char	*gt_charshifter(char *s1, int shift);
char	*gt_free_error(char **s1, char *s2);
int		gt_get_line(int fd, char **readed, int firstrun);
int		gt_strnlen(char const *s);
size_t	gt_strlen(char const *s);

#endif
