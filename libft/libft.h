/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:15:32 by ysantos-          #+#    #+#             */
/*   Updated: 2022/11/02 20:28:45 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 40

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define LLONG unsigned long long

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*cmp, const char *src, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);

void	*ft_calloc(size_t number, size_t size);
void	*ft_memset(void *str, int c, int bytes);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t bytes);

int		ft_isprint(int x);
int		ft_isdigit(int x);
int		ft_isascii(int x);
int		ft_isalpha(int x);
int		ft_isalnum(int x);
int		ft_tolower(int x);
int		ft_toupper(int x);

void	ft_bzero(void *s, size_t bytes);
int		ft_atoi(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ BONUS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list**lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ EXTRAS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

char	*get_next_line(int fd);
int		has_newline(char *buffer);
char	*bufferjoin(char *str, char *buffer);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ PRINTF ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int		ft_printf(const char *str, ...);
int		f_putnbr(int n);
int		base_conversor(LLONG n, char *str, LLONG base);
int		f_putnbr_u(unsigned int n, char *str, LLONG base);
int		f_putnbr_ul(unsigned long n);

#endif
