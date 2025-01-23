/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:11:42 by jhor              #+#    #+#             */
/*   Updated: 2025/01/07 17:11:42 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	int	read_bytes;
	char	*temp;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!line)
	{
		line = (char *)malloc(1);
		if (!line)
			return (free(buffer), NULL);
		line[0] = '\0';
	}
	read_bytes = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
	}
	free(buffer);
	return (line);
}

char	*new_line(char *line)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}
	
char	*ft_get_next_line(char *line)
{
	int	i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*get_next_line(int fd)
{
	static char	*line;
	char	*buffer;
	char	*next_line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	line = ft_get_line(fd, line);
	if (!line)
		return (NULL);

	next_line = ft_get_next_line(line);
	line = new_line(line);
	return (next_line);
}

// int main()
// {
// 	int fd = open ("text.txt", O_RDONLY);
// 	if (fd < 0)
// 		return 1;
// 	// printf("gnl\n");
// 	char *line;
// 	int i;
// 	line = NULL;
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }
