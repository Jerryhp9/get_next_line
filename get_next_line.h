/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:17 by jhor              #+#    #+#             */
/*   Updated: 2025/01/07 16:34:17 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strdup(const char *s);
char	*ft_get_line(int fd, char *line, char *buffer);
char	*new_line(char *line);
char	*ft_get_next_line(char *line);
char	*get_next_line(int fd);

#endif