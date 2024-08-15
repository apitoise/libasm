NAME = libasm.a

CC = gcc
CFLAGS = -Wall -Wextra

SRC_DIR = srcs

ASM_SRCS = $(wildcard $(SRC_DIR)/*.s)
ASM_OBJS = $(ASM_SRCS:.s=.o)

all:	$(NAME)

$(NAME):	$(ASM_OBJS)
		ar rcs $@ $^

%.o:	%.s
	nasm -f elf64 $< -o $@

test:	main.o $(NAME)
	$(CC) $(CFLAGS) -o $@ main.o -L. -lasm -z noexecstack

test.o:	main.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(ASM_OBJS) main.o

fclean: clean
	rm -rf $(NAME) test ft_write_fd write_fd

re: fclean all

.PHONY: all clean fclean re
