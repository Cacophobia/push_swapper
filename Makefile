NAME = pushswap

SRCS = $(wildcard ./*.c)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(NAME)

.PHONY: fclean
fclean:
	rm -f $(NAME)

.PHONY: re 
re: clean all

.PHONY: run
run: all
	ARG=$$(shuf -i 1-250 -n $(n)); ./pushswap $$ARG

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

