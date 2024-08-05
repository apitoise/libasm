#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);

static int	exit_error(const char *str) {
	fprintf(stderr, "Error: %s\n", str);
	return (1);
}

int			main(int ac, char **argv) {
	if (ac != 2)
		return (exit_error("Need at least 1 arg"));
	printf("ft_strlen: %lu\n", ft_strlen(argv[1]));
	printf("strlen: %lu\n", strlen(argv[1]));
	return (0);
}
