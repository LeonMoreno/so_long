#Standard

NAME 		= so_long
INCLUDES	= include/
SRC_DIR		= src/
OBJ_DIR		= obj/
CC 			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -I
MLX		= -L /usr/x11/lib/ -lmlx -lXext -lX11
#MLX		= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

#Libft
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#sources

SRC_FILES	=	so_long read_map errors parser_map check_map game_start new_window \
				xpm_image render_start render_utils key_hook control_player check_map_utils

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@echo "$(GRAY)     - Making libft... $(DEF_COLOR)"
			@make -C $(LIBFT_DIR)	
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME) $(MLX)
			@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "$(BLUE)So_Long objects files cleaned!$(DEF_COLOR)"

fclean:				clean
				@$(RM) -f $(NAME)
				@make -C $(LIBFT_DIR) fclean
				@echo "$(CYAN)So_Long executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for So_Long!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
