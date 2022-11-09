
#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"


int ft_check_type(char c)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (c == LST_TYPES[i])
			return (i);
		i++;		
	}
	return (-1);
}


void	ft_convert_caract(int i_type)
{
	char *tab[9];

	tab[0] = 



}


int ft_printf(const char *str, ...)
{

	size_t	size_str;
	size_t	i;
	int		i_type;

	size_str = ft_strlen(str);

	printf("size_str = %zu\n", size_str);

	i = 0;
	while (i < size_str)
	{
		
		if (str[i] != '%')
		{
			if (write(1,&str[i],1) == -1)
				return(-1);
		}
		else
		{
			i_type = ft_check_type(str[i + 1]);
		}
		
		i++;
	}
	

	return 0;
}

int main()
{
	ft_printf("Ce %d caractere a parser", 12, 22,12);


	return 0;
}
