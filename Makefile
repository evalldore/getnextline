NAME	= gnl
BINDIR	= bin/
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all : $(NAME)

$(NAME) : $(NAME).c $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) -g -D BUFFER_SIZE=2 -o $(NAME) $(NAME).c $(OBJS)

$(BINDIR)%.o : %.c
	$(CC) -g -c $(CFLAGS) -o $@ $^ 

$(BINDIR) :
	mkdir $(BINDIR)

clean :
	$(RM) -r $(BINDIR)

fclean :
	$(RM) $(NAME)