#include "../includes/Cub3d.h"

char **ft_cpy_tab(char **tab, int sizetab)
{
	char **new;
	int i;

	i = -1;
	new = malloc(sizeof(char *) * (sizetab + 1));
	if (!new)
		return (NULL);
	while (tab[++i])
		new[i] = ft_strdup(tab[i]);
	new[i] = NULL;
	return (new);
}

int ft_return_nb_of_line(int fd, char *line)
{
	int index;

	index = 0;
	while (get_next_line(fd, &line) > 0)
	{
		index++;
		ft_free(line);
	}
	index++;
	ft_free(line);
	return (index);
}