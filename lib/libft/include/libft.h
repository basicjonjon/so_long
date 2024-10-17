/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:58:52 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/17 15:52:35 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define NC "\033[0m"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *tab, size_t n);
void				*ft_calloc(size_t nelement, size_t size);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_putstr_color(char *str);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

void				*ft_memchr(void *mem, int search, size_t n);
void				*ft_memchr(void *mem, int search, size_t n);
int					ft_memcmp(const void *mem1, const void *mem2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *mem, int value, size_t n);

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_puterror(char *str);
int					ft_printf(const char *str, ...);
int					ft_putchar(int c);
int					ft_putstr(char *str);
int					ft_putnbr(int n);
int					ft_putunsigned(unsigned int n);
int					ft_putnbrbase(unsigned int n, char *base);
int					ft_putadresse(void *a, char *base);

char				*ft_strchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strdup(const char *str);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlen(const char *string);
size_t				ft_strlennojl(const char *string);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *search, const char *find, size_t n);
char				*ft_strrchr(const char *str, int c);

int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

size_t				ft_gnl_strlen(char *s);
char				*ft_gnl_strchr(char *s, int c);
char				*ft_gnl_strjoin(char *s1, char *s2);
char				*ft_gnl_strdup(char *str);

char				*get_next_line(int fd);
char				*ft_read(int fd, char *res);
char				*ft_start_next_line(char *res);
char				*ft_cut_line(char *res);

void				ft_free_bidimentionnal(void **tab);

#endif
