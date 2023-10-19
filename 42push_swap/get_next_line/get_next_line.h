/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:03:41 by qpuig             #+#    #+#             */
/*   Updated: 2023/10/19 17:14:00 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen_g(char *s);
int		ft_check_g(char *s, int c);
char	*ft_strdup_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_rest(char *rest);
char	*ft_restjoin(int fd, char *rest);
char	*ft_return(char *rest);
char	*ft_free(char *s);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
