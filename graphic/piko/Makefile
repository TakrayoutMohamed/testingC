NAME = piko
CC = cc
CFLAGS= -Imlx 
LIBCUB = libpiko.a
SRC= test.c
SRC_MAIN = main.c
OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
RM = rm -rf

all : $(NAME)

$(NAME): $(LIBCUB) $(OBJ_MAIN)
		$(CC) $(OBJ_MAIN) $(LIBCUB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "the file $@ has been created from $<"

$(LIBCUB) : $(OBJ)
	ar rc $@ $(OBJ)

clean:
		@$(RM) $(OBJ) $(OBJ_MAIN) $(LIBCUB)
		@echo "all the .o has been deleted successfully"

fclean: clean
		@$(RM) $(NAME)
		@echo "the executable client and server has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) $(LIBCUB) all fclean bonus re