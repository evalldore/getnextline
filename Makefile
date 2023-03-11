BONUS	= gnl_bonus
NAME	= gnl
BINDIR	= bin/
BSRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS	= get_next_line.c get_next_line_utils.c
OBJS	= $(addprefix $(BINDIR), $(SRCS:.c=.o))
BOBJS	= $(addprefix $(BINDIR), $(BSRCS:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g -D BUFFER_SIZE=5
RM		= rm -f

all : $(NAME)

$(NAME) : $(NAME).c $(BINDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(OBJS)

$(BONUS) : $(BONUS).c $(BINDIR) $(BOBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS).c $(BOBJS)

$(BINDIR)%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $^ 

$(BINDIR) :
	mkdir $(BINDIR)

clean :
	$(RM) -r $(BINDIR)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)