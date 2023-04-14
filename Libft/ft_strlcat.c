/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:53:15 by msintas-          #+#    #+#             */
/*   Updated: 2022/06/09 16:13:36 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_count;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	src_count = 0;
	if (dstsize < dst_len + 1)
	{
		return (dstsize + src_len);
	}
	if (dstsize > dst_len + 1)
	{
		while (src[src_count] != '\0' && dst_len + 1 + src_count < dstsize)
		{
			dst[dst_len + src_count] = src[src_count];
			src_count++;
		}
	}
	dst[dst_len + src_count] = '\0';
	return (dst_len + src_len);
}
