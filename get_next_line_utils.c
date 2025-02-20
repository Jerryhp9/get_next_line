/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:13:42 by jhor              #+#    #+#             */
/*   Updated: 2025/01/06 14:13:42 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int main()
// {
	// char *str1 = "Hello there";
// 
	// printf("%s", str1);
// }

char	*ft_strchr(const char *s, int c)
{
	c = ((unsigned char)c);
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
// 
// int main()
// {
	// char *str = "Hello world";
// 
	// printf("%s", ft_strchr(str, 'o'));
// }

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*newstr;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	newstr = (char *)malloc(sizeof (char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	size_t	s1;
	char	*dup;
	int		i;

	s1 = ft_strlen(s);
	dup = (char *) malloc(sizeof(char) * (s1 + 1));
	i = 0;
	if (dup == 0)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
