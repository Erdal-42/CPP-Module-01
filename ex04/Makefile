NAME = replace_word

CC = g++

CFLAGS = -Wall -Werror -Wextra -g

SRCS = main.cpp \
		replace_word.cpp


OBJS = $(SRCS:.cpp=.o)

#all rule
all:	$(NAME)

replace_word: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#clean rule
clean:
	rm -f $(OBJS)

#fclean rule
fclean: clean
	rm -f $(NAME)

#re rule
re: fclean all

.PHONY: all clean fclean re