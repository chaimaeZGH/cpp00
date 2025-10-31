CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
SRCS = main.cpp Contact.cpp Phonebook.cpp
NAME = PhoneBook
OBJS = $(SRCS:.cpp=.o)
HEADER = Contact.hpp Phonebook.hpp

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