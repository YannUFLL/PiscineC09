/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:13:26 by ydumaine          #+#    #+#             */
/*   Updated: 2022/02/03 17:47:19 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// fuction which detects if the char match with the charset
_Bool	ft_match(char str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] == str)
			return (1);
		i++;
	}
	return (0);
}

// function that allow and set the good size for the pointer tab

char	**occurence_counter(char *str, char *to_find)
{
	int		i;
	int		counter;
	char	**tab;

	i = 0;
	counter = 0;
	while ((ft_match(str[i], to_find) == 1))
		i++;
	while (str[i])
	{
		if (ft_match(str[i], to_find) == 1)
		{
			counter++;
			i++;
			while ((ft_match(str[i], to_find) == 1))
				i++;
		}
		else
			i++;
	}
	if ((ft_match(str[i - 1], to_find) == 0) && str[0] != 0)
		counter++;
	tab = malloc(sizeof(char *) * (counter + 1));
	tab[counter] = NULL;
	return (tab);
}

void	ft_advance(int *i, char *str, char *charset)
{
	int	u;

	u = *i;
	while (ft_match(str[u], charset) == 1)
		u++;
	*i = u;
}

/* a fuction that count the size of the string to copy,
 copy the array and affect a pointer to tab*/

void	ft_strlcpy(char *src, char **tab, char *str, int r)
{
	int				i;
	char			*string;
	int				size;
	char			*ptr;

	ptr = src;
	i = 0;
	while (ptr != str)
	{
		i++;
		ptr++;
	}
	size = i;
	string = malloc(sizeof(char) * size + 1);
	i = 0;
	while ((src[i] != '\0') && (i < size))
	{
		string[i] = src[i];
		i++;
	}
	if (size > 0)
		string[i] = '\0';
	tab[r] = string;
}

char	**ft_split(char *str, char *charset)
{
	int			i;
	char		*old_add;
	int			r;
	char		**tab;

	tab = occurence_counter(str, charset);
	i = 0;
	r = 0;
	while ((ft_match(str[i], charset) == 1))
		i++;
	old_add = &str[i];
	while (str[i])
	{
		if (ft_match(str[i], charset))
		{
			ft_strlcpy(old_add, tab, &str[i++], r++);
			ft_advance(&i, str, charset);
			old_add = &str[i];
		}
		else
			i++;
	}
	if ((ft_match(str[i - 1], charset) == 0) && str[0] != 0)
		ft_strlcpy(old_add, tab, &str[i], r);
	return (tab);
}
/*
#include <stdio.h>
int	main()
{
	char chaine[] = "a12b12c";
	char occurence[] = "12";
	char **tab; 
	tab = ft_split(chaine,occurence);
    printf("\ntab 0 : %s", tab[0]);
	printf("\ntab 1 : %s", tab[1]);
	printf("\ntab 2 : %s", tab[2]);
	printf("\ntab 3 : %s", tab[3]);
}
*/
