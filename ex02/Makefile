CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
NAME =  Account
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = Account.hpp

all: $(NAME)	

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
