/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:30:23 by msintas-          #+#    #+#             */
/*   Updated: 2022/06/16 20:40:42 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
