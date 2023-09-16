/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:05 by amennad           #+#    #+#             */
/*   Updated: 2023/09/15 13:43:56 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../include/libft/libft.h"
# include "../include/so_long.h"
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		line_chr(char *s);
int		ft_strlen_gnl(char *s);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char *s, int start, int len);

#endif
