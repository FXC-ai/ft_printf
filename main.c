
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

	count = ft_printf("ft_printf : %% %% S:%s C:%c D:%d P:%p U:%u x:%x\n", NULL, 'c', -1, &non_util3, 0, 17);
	count1 = printf("   printf : %% %% S:%s C:%c D:%d P:%p U:%u x:%x\n", NULL, 'c', -1, &non_util3, 0, 17);
	printf("\n");
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d\n", count1);

	printf("\n\n");
	count = ft_printf("ft_printf : %pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX); //: returned: 2, but expected: 3
	count1 = printf("   printf : %pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("\n");
	printf("count ft_printf = %d\n", count);
	printf("count    printf = %d\n", count1);

	count = ft_printf("ft_printf :  %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	count = printf("   printf :  %x", 42);




	check_leaks();

	return 0;
}