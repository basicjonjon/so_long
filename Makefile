NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 
RM = rm -f

FILES = main game error verif display_info player utils asset display direction end get destroy


#tout les repertoire 
LIBFT_PATH = ./lib/libft
SRCS_DIR = ./src/
OBJS_DIR = ./objet/

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

GREEN = \033[1;32m
BLUE =  \033[1;34m
RED = \033[1;31m
NC = \033[0m 

LIBFT = $(LIBFT_PATH)/libft.a
MLX_DIR = ./lib/minilibx-linux/libmlx.a

OBJ = $(OBJS)
INCLUDE = $(LIBFT) $(MLX_DIR)

#creation des .o pour les files generale
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJ) 
	@$(CC) -lX11 -lXext $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo "$@ : $(BLUE)[READY]$(NC)"

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "libft : $(GREEN)[OK]$(NC)"

all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all
	@echo "\n$(BLUE)================= [ OK ] =================$(NC)\n"


.PHONY: all clean fclean re
