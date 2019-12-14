/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:10:27 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 18:25:21 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
size_t				ft_strlen(const char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t siz);
char				*ft_strnstr(const char *h, const char *n, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putnbr_fd(long n, int fd);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putendl(char *s);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *str, char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
long				ft_pow(long num, int pow);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **alst, t_list *a);
void				ft_lstadd_front(t_list **alst, t_list *a);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
								void (*del)(void *));

/*
** Printf
*/

typedef struct		s_params
{
	int				start;
	char			*flag;
	int				spec_width;
	int				width;
	int				spec_precision;
	int				precision;
	int				double_length;
	char			length;
	char			specifier;
	int				end;
}					t_params;

void				ft_putstr_free(char *s, int to_free);
int					ft_hex_len(uintptr_t n, uintptr_t num);
int					ft_int_len(long i);
char				*ft_memalloc(size_t nmemb, size_t size, int c);
void				ft_printhex(long n, int upper);
int					ft_abs(long x);
int					ft_c_in_s(char *s, char c);
int					is_printf_type(char c);
int					is_flag(char c);
int					is_width(char c);
int					is_length(char c);
void				search_flag(t_params **param, int *start, char *s);
void				search_width(char *s, int *start, t_params **param);
void				search_precision(char *s, int *start, t_params **param);
void				search_length(char *s, int *start, t_params **param);
t_params			*parse_params(char *s, int *start);
t_params			**ft_count_params(int *n, char *s);
int					printuint_flag(t_params *param, int precision, \
									long to_write, int len);
int					printuint(t_params *param, int precision, \
									long to_write, int len);
void				uint_manager(va_list v1, int *bwrote, t_params *param);
int					printint_flag(t_params *param, int precision, \
									long to_write, int len);
int					intutils(t_params *param, long *to_write, int len, \
									int precision);
int					printint(t_params *param, int precision, \
									long to_write, int len);
void				int_manager(va_list v1, int *bwrote, t_params *param);
int					printchar(t_params *param, char to_write, int len);
void				char_manager(va_list v1, int *bwrote, t_params *param);
int					printstring(t_params *param, char *to_write, \
									int len, int precision);
void				string_manager(va_list v1, int *bwrote, t_params *param);
int					printptr(t_params *param, uintptr_t to_write, int len, \
									int p);
void				ptr_manager(va_list v1, int *bwrote, t_params *param);
int					printhex_flag(t_params *param, long to_write, \
									int len, int precision);
int					printhex(t_params *param, long to_write, \
									int len, int precision);
void				hex_manager(va_list v1, int *bwrote, \
									t_params *param);
int					ft_manager(int *bwrote, va_list v1, t_params *param);
void				printf_loop(t_params **params, int *n, va_list v1, \
									char *s);
int					ft_printf(const char *s, ...);
void				print_width(t_params *param, int len);
void				wrong_manager(va_list v1, int *bwrote, t_params *param);
void				perc_manager(va_list v1, int *bwrote, t_params *param);

/*
** GNL
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int					get_next_line(int fd, char **line);

#endif
