NAME = push_swap

SRCS = $(wildcard ./*.c)
INCLUDE = swap_push.h

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
	ARG=$$(seq -500 500 | shuf -n $(n) | tr '\n' ' '); ./push_swap $$ARG

runwc: all
	ARG=$$(seq -500 500 | shuf -n $(n) | tr '\n' ' '); ./push_swap $$ARG | wc -l

$(NAME): $(SRCS) $(INCLUDE)
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $(NAME)

