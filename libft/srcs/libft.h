/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivogel <mivogel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:40:58 by mivogel           #+#    #+#             */
/*   Updated: 2024/11/08 10:58:16 by mivogel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

// struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// libc
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t n, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(const char *src);
// a verif surtout les mem*
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
void				*ft_memchr(const void *block, int c, size_t n);
void				*ft_memset(void *ptr, int value, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

#endif
