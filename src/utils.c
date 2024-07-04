#include "init.h"

int	ft_strlen(const char *str)
{
	const char	*tmp;

	tmp = str;
	while (*str)
		str++;
	return (str - tmp);
}

char	*ft_new_str(int nb, int len, va_list args, char sep)
{
	char	*r_value;
	char	*tmp;
	int		i;

	i = 0;
	if (!sep)
		r_value = (char *)malloc(sizeof(char) * (len + nb));
	else
		r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (NULL);
	while (nb)
	{
		tmp = (char *)va_arg(args, char *);
		while (*tmp)
			r_value[i++] = *(tmp++);
		if (nb > 1 && sep)
			r_value[i++] = '/';
		nb--;
	}
	r_value[i] = '\0';
	return (r_value);
}

char	*ft_join_path(int nb, ...)
{
	int		i;
	int		len;
	char	*str;
	va_list	args;
	va_list	cp;

	i = nb;
	len = 0;
	va_start(args, nb);
	va_copy(cp, args);
	while (i--)
		len += ft_strlen((char *)va_arg(cp, char *));
	str = ft_new_str(nb, len, args, '/');
	va_end(args);
	return (str);
}

char	*ft_strjoins(int nb, ...)
{
	int		i;
	int		len;
	char	*str;
	va_list	args;
	va_list	cp;

	i = nb;
	len = 0;
	va_start(args, nb);
	va_copy(cp, args);
	while (i--)
		len += ft_strlen((char *)va_arg(cp, char *));
	str = ft_new_str(nb, len, args, 0);
	va_end(args);
	return (str);
}

char	*ft_capitalize(char *str)
{
	char	*r_value;
	int		i;

	i = 0;
	r_value = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!r_value)
		return (NULL);
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			r_value[i] = *str - ' ';
		else
			r_value[i] = *str;
		str++;
		i++;
	}
	return (r_value);
}
