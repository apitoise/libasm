#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dst, const char *src);
extern int		ft_strcmp(const char *s1, const char *s2);
extern ssize_t	ft_write(int fd, const void *buff, size_t count);
extern ssize_t	ft_read(int fd, void *buff, size_t count);

#define	MAX_LEN	4096

static int	exit_error(const char *str) {
	fprintf(stderr, "Error: %s\n", str);
	return (1);
}

int			main(int ac, char **argv) {
	char	dst[MAX_LEN];
	char	buff[MAX_LEN];
	char	*ft_ret, *real_ret;
	char	*bad_str = "imabadstring";
	char	*empty_str = "";
	int		ret = 0;

	if (ac != 2)
		return (exit_error("Need at least 1 arg"));

	printf("#### STRLEN ####\n\n");

	printf("ft_strlen:\n%lu\n", ft_strlen(argv[1]));
	printf("strlen:\n%lu\n", strlen(argv[1]));

	printf("\n\n#### STRCPY ####\n\n");

	ft_ret = ft_strcpy(dst, argv[1]);
	printf("ft_strcpy:\n%s | %s\n", dst, ft_ret);
	real_ret = strcpy(dst, argv[1]);
	printf("strcpy:\n%s | %s\n", dst, real_ret);

	printf("\n\n#### STRCMP ####\n\n");

	printf("good ft_strcmp:\n%i\n", ft_strcmp(ft_ret, real_ret));
	printf("good strcmp:\n%i\n", strcmp(ft_ret, real_ret));
	printf("bad ft_strcmp:\n%i\n", ft_strcmp(ft_ret, bad_str));
	printf("bad strcmp:\n%i\n", strcmp(ft_ret, bad_str));
	printf("empty ft_strcmp:\n%i\n", ft_strcmp(ft_ret, empty_str));
	printf("empty strcmp:\n%i\n", strcmp(ft_ret, empty_str));

	printf("\n\n#### WRITE ####\n\n");

	int ft_fd = open("ft_write_fd", O_APPEND | O_CREAT | O_WRONLY, 0644);
	int fd = open("write_fd", O_APPEND | O_CREAT | O_RDWR, 0644);

	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("ft_write stdout:\n");
	ret = ft_write(STDOUT_FILENO, argv[1], ft_strlen(argv[1]));
	printf("ft_write result: %d\n", ret);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("write stdout:\n");
	ret = write(STDOUT_FILENO, argv[1], strlen(argv[1]));
	printf("write result: %d\n", ret);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("ft_write good fd:\n");
	ret = ft_write(ft_fd, argv[1], ft_strlen(argv[1]));
	printf("ft_write result: %d\n", ret);
	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("write good fd:\n");
	ret = write(fd, argv[1], strlen(argv[1]));
	printf("write result: %d\n", ret);
	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("ft_write wrong fd:\n");
	ret = ft_write(4242, argv[1], ft_strlen(argv[1]));
	printf("ft_write result: %d\n", ret);
	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("write wrong fd:\n");
	ret = write(4242, argv[1], strlen(argv[1]));
	printf("ft_write result: %d\n", ret);
	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;

	printf("\n\n#### READ ####\n\n");

	bzero(buff, MAX_LEN);
	printf("Errno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read stdin:\n");
	ret = ft_read(STDIN_FILENO, buff, MAX_LEN);
	printf("ft_read_result: %d | %s", ret, buff);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	bzero(buff, MAX_LEN);
	printf("read stdin:\n");
	ret = read(STDIN_FILENO, buff, MAX_LEN);
	printf("read_result: %d | %s", ret, buff);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	bzero(buff, MAX_LEN);
	printf("ft_read good fd:\n");
	lseek(fd, 0, SEEK_SET);
	ret = ft_read(fd, buff, MAX_LEN);
	printf("ft_read_result: %d | %s", ret, buff);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	bzero(buff, MAX_LEN);
	printf("read good fd:\n");
	lseek(fd, 0, SEEK_SET);
	ret = read(fd, buff, MAX_LEN);
	printf("read_result: %d | %s", ret, buff);
	bzero(buff, MAX_LEN);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read bad fd:\n");
	ret = ft_read(4242, buff, MAX_LEN);
	printf("ft_read_result: %d | %s", ret, buff);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	bzero(buff, MAX_LEN);
	printf("read wrong fd:\n");
	ret = read(4242, buff, MAX_LEN);
	printf("read_result: %d | %s", ret, buff);
	printf("\nErrno_value: %d\nErrno_str: %s\n\n", errno, strerror(errno));
	errno = 0;
	return (0);
}
