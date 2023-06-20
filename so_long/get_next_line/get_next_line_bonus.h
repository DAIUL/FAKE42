/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:03:41 by qpuig             #+#    #+#             */
/*   Updated: 2023/03/10 17:18:06 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_check(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_rest(char *rest);
char	*ft_restjoin(int fd, char *rest);
char	*ft_return(char *rest);
char	*ft_free(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
