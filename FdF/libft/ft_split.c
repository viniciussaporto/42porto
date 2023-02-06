/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:40:16 by vsa-port          #+#    #+#             */
/*   Updated: 2023/01/26 16:37:30 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_string(char c, char charset)
{
	if (charset == c)
		return (0);
	return (1);
}

int	ft_strlen_s(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && in_string(str[i], charset))
		i++;
	return (i);
}

int	count_strings(char const *str, char charset)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && !in_string(str[i], charset))
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] != '\0' && in_string(str[i], charset))
			i++;
	}
	return (counter);
}

char	*word_allocate(char const *str, char charset)
{
	int		len_word;
	char	*word;
	int		i;

	i = 0;
	len_word = ft_strlen_s(str, charset);
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len_word] = 0;
	while (str[i] != '\0' && in_string(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

char	**ft_split(char const *str, char charset)
{
	char	**list_str;
	int		number_str;
	int		g;

	g = 0;
	number_str = count_strings(str, charset);
	list_str = (char **)malloc((number_str + 1) * sizeof(char *));
	if (!list_str)
		return (NULL);
	list_str[number_str] = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && !in_string(*str, charset))
			str++;
		if (*str != '\0')
		{
			list_str[g] = word_allocate(str, charset);
			g++;
		}
		while (*str != '\0' && in_string(*str, charset))
			str++;
	}
	return (list_str);
}

// #include "libft.h"

// static int	counter(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0' && *s == c)
// 		s++;
// 	while (*s != '\0')
// 	{
// 		count++;
// 		while (*s && *s != c)
// 			s++;
// 		while (*s && *s == c)
// 			s++;
// 	}
// 	return (count);
// }

// static int	word_length(char const *str, char c)
// {
// 	int	l;

// 	l = 0;
// 	while (str[l] && str[l] != c)
// 		l++;
// 	return (l);
// }

// static char	**sub_split(char **res, char const *s, char c, int words_count)
// {
// 	int		i;
// 	int		j;
// 	int		word_len;

// 	i = 0;
// 	while (*s && *s == c)
// 		s++;
// 	while (i < words_count)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		word_len = word_length(s, c);
// 		res[i] = (char *)malloc(sizeof(char) * word_len + 1);
// 		j = 0;
// 		while (j < word_len)
// 		{
// 			res[i][j] = *s;
// 			j++;
// 			s++;
// 		}
// 		res[i][j] = '\0';
// 		i++;
// 	}
// 	res[i] = NULL;
// 	return (res);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**res;
// 	int		words_count;

// 	if (!s)
// 		return (NULL);
// 	words_count = counter(s, c);
// 	res = (char **)malloc(sizeof(char *) * (words_count + 1));
// 	if (!res)
// 		return (NULL);
// 	res = sub_split(res, s, c, words_count);
// 	return (res);
// }
