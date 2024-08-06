#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dst, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);

#define	MAX_LEN	4096

static int	exit_error(const char *str) {
	fprintf(stderr, "Error: %s\n", str);
	return (1);
}

int			main(int ac, char **argv) {
	char	dst[MAX_LEN];
	char	*ft_ret, *real_ret;
	char	*bad_str = "imabadstring";
	char	*empty_str = "";

	if (ac != 2)
		return (exit_error("Need at least 1 arg"));
	printf("#### STRLEN ####\n\n");
	printf("ft_strlen: %lu\n", ft_strlen(argv[1]));
	printf("strlen: %lu\n", strlen(argv[1]));
	printf("\n\n#### STRCPY ####\n\n");
	ft_ret = ft_strcpy(dst, argv[1]);
	printf("ft_strcpy: %s | %s\n", dst, ft_ret);
	real_ret = strcpy(dst, argv[1]);
	printf("strcpy: %s | %s\n", dst, real_ret);
	printf("\n\n#### STRCMP ####\n\n");
	printf("good ft_strcmp: %i\n", ft_strcmp(ft_ret, real_ret));
	printf("good strcmp: %i\n", strcmp(ft_ret, real_ret));
	printf("bad ft_strcmp: %i\n", ft_strcmp(ft_ret, bad_str));
	printf("bad strcmp: %i\n", strcmp(ft_ret, bad_str));
	printf("empty ft_strcmp: %i\n", ft_strcmp(ft_ret, empty_str));
	printf("empty strcmp: %i\n", strcmp(ft_ret, empty_str));

	return (0);
}
