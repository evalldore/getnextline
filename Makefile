NAME	= gnl
BINDIR	= bin/
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -D BUFFER_SIZE=42
RM		= rm -f

all : $(NAME)

$(NAME) : $(NAME).c $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(OBJS)

$(BINDIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^ 

$(BINDIR) :
	mkdir $(BINDIR)

clean :
	$(RM) -r $(BINDIR)

fclean : clean
	$(RM) $(NAME)