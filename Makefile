.SILENT:
NAME		= 	so_long

CC 			= 	clang

CFLAGS		= 	-Wall -Wextra

RM 			= 	rm -f

INC_PATH	=	inc/

SRC_PATH	=	src/

SRC_		= 	so_long.c window.c image.c events.c \
				map.c utils.c path.c player.c

SRC			=	$(addprefix $(SRC_PATH), $(SRC_))

OBJ 		= 	$(SRC_:%.c=%.o)

GREEN		= 	\033[0;32m

RESET		=	\033[0m

$(NAME):		$(OBJ)
				make -C inc/libft
				make -C inc/minilibx-linux/
				$(CC) $(OBJ) -lXext -lX11 -lm -Linc/libft -lft -Linc/minilibx-linux -lmlx -o $(NAME)
				make done

$(OBJ):	 		$(SRC)
				$(CC) -c $(CFLAGS) $(SRC)

all: 			$(NAME)

clean:	
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)
				make fclean -C inc/libft

re:				fclean	all

done:
				printf "															 	\n"
				printf "$(GREEN)	$(NAME)							 			$(RESET)\n"
				printf "$(GREEN)                             _  _             _ $(RESET)\n"
				printf "$(GREEN)                            (_)| |           | |$(RESET)\n"
				printf "$(GREEN)  ____   ___   ____   ____   _ | |  ____   _ | |$(RESET)\n"
				printf "$(GREEN) / ___) / _ \ |    \ |  _ \ | || | / _  ) / || |$(RESET)\n"
				printf "$(GREEN)( (___ | |_| || | | || | | || || |( (/ / ( (_| |$(RESET)\n"
				printf "$(GREEN) \____) \___/ |_|_|_|| ||_/ |_||_| \____) \____|$(RESET)\n"
				printf "$(GREEN)                     |_|                        $(RESET)\n"
				printf "																\n"

.PHONY: 		all clean fclean re