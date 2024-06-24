/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocaio-re <ocaio-re@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:49:27 by ocaio-re          #+#    #+#             */
/*   Updated: 2024/06/24 14:49:27 by ocaio-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocaio-re <ocaio-re@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:05:044 by ocaio-re          #+#    #+#            */
/*   Updated: 2024/06/24 14:35:53 by ocaio-re         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
int		nextline(char *s);
char	*read_line(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strrchr(char *s, int c);

#endif