
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int count;
	int count1;

	char non_util2;
	non_util2 = '0';

	char non_util3;
	non_util3 = '0';	

	char non_util6;
	non_util6 = '0';

	printf("\n\n");
	count = ft_printf("ft_printf : %% %% S:%s C:%c D:%d P:%p U:%u x:%x\n", NULL, 'c', -1, &non_util3, 0, 17);
	count1 = printf("   printf : %% %% S:%s C:%c D:%d P:%p U:%u x:%x\n", NULL, 'c', -1, &non_util3, 0, 17);
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d\n", count1);

	printf("\n\n");
	count = ft_printf("ft_printf : %pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	count1 = printf("   printf : %pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d\n", count1);

	printf("\n\n");
	count = ft_printf("ft_printf :  %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	//count1 = printf("   printf :  %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("   printf :  %x %x %lx %lx %lx %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("count ft_printf = %d\n", count);
	//printf("count    printf = %d\n", count1);

	printf("\n\n");
	count = ft_printf("ft_printf :  %x\n", 1);
	printf("count ft_printf = %d\n", count);

	printf("\n\n");
	count = ft_printf("ft_printf :  %x\n", 0);
	printf("count ft_printf = %d\n", count);

	printf("\n\n");
	count = ft_printf("ft_printf :  %X\n", 2147453647);
	count1 = printf("   printf :  %X\n", 2147453647);
	printf("count ft_printf = %d\n", count);
	printf("count ft_printf = %d\n", count1);


	check_leaks();

	return 0;
}