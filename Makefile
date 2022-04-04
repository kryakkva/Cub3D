NAME		=	cub3D
CC			=	gcc
# FL			=	-Wall -Wextra -Werror 
LIB			=	./libft/libft.a
H_LIB		=	./libft/libft.h
LIB_D		=	./libft/
MLX 		=	-Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
SRCS_D 		=	source/
UTILS_D 	=	utils/
SRCS_D_B 	=	source_bonus/
INCLUDE_D	=	includes/
SRCS 		= 	$(addprefix $(SRCS_D),		cub3d.c check_map.c init.c parse_attr.c key.c	\
											parse_map.c move.c move_2.c draw.c draw_2.c		\
											put_texture.c close_clear.c set_color.c)
SRCU 		= 	$(addprefix $(UTILS_D), 	utils.c utils_2.c utils_3.c get_next_line.c)
SRCB 		= 	$(addprefix $(SRCS_D_B),	cub3d_b.c check_map_b.c init_b.c parse_attr_b.c	\
											key_b.c move_b.c parse_map_b.c put_texture_b.c	\
											draw_b.c draw_2_b.c screenshot_b.c mini_map_b.c	\
											move_2_b.c mouse_controls_b.c close_clear_b.c	\
											change_resolution_b.c set_color_b.c draw_3_b.c	\
											sprite_b.c sprite_2_b.c sprite_utils_b.c		\
											check_exit_b.c touch_wall_b.c parse_texture_b.c	\
											put_texture_touch_b.c parse_attr_2_b.c 			\
											init_pos_b.c set_color_add_b.c refresh_b.c		\
											mini_map_2_b.c)
INCLUDE 	=	$(addprefix $(INCLUDE_D), 	cub3d.h cub3d_b.h)
vpath %.h includes

OBJS_D	=	objs/
OBJS_S	=	objs/source/
OBJS_U	=	objs/utils/
OBJS_B	=	objs/source_bonus/

OBJS	=	$(SRCS:.c=.o)
OBJU	=	$(SRCU:.c=.o)
OBJB	=	$(SRCB:.c=.o)
OBJ_S	=	$(addprefix $(OBJS_D), $(OBJS))
OBJ_U	=	$(addprefix $(OBJS_D), $(OBJU))
OBJ_B	=	$(addprefix $(OBJS_D), $(OBJB))
RM		=	rm -rf

BLUE	=	\033[36m
YEL		=	\033[33m
GREEN	=	\033[32m
DEF		=	\033[0m

all:  $(OBJS_S) $(NAME)

$(OBJS_S):
	@mkdir -p $(OBJS_S) $(OBJS_U) $(OBJS_B)

$(OBJ_S) $(OBJ_U):  $(INCLUDE_D)cub3d.h
$(OBJ_B):  			$(INCLUDE_D)cub3d_b.h

$(OBJS_D)%.o: %.c
	@echo "$(BLUE)❱❱$(DEF)\c"
	@$(CC) $(FL) -Iminilibx_macos -c -o $@ $< 
	
$(NAME): $(OBJ_S) $(OBJ_U) $(LIB_D)ft_*.c $(H_LIB)
	@echo "\n$(NAME): $(BLUE)Object files created$(DEF)"
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(FL) -Llibft $(OBJ_S) $(OBJ_U) $(LIB) $(MLX) -o $@
	@echo "$(NAME): $(BLUE)Executable file created$(DEF)"

bonus: $(OBJS_S) $(OBJ_U) $(OBJ_B) $(LIB_D)ft_*.c $(H_LIB)
#	@echo "\n$(NAME): $(GREEN)Object files created$(DEF)"
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(FL) -Llibft $(OBJ_U) $(OBJ_B) $(LIB) $(MLX) -o $(NAME)
#	@echo "$(NAME): $(GREEN)Executable file created$(DEF)"
	
clean:
	@$(RM) $(OBJ_S) $(OBJ_U) $(OBJ_B)
	@$(MAKE) clean -C libft
	@echo "libft:  $(YEL)Object files deleted$(DEF)"
	@$(RM)	$(OBJS_D)
	@echo "$(NAME):  $(YEL)Object files deleted$(DEF)"

fclean: clean
	@$(MAKE) fclean -C libft
	@echo "libft:  $(YEL)Library files deleted$(DEF)"
	@$(MAKE) clean -C minilibx_macos
	@echo "libmlx: $(YEL)Files deleted$(DEF)"
	@$(RM) $(NAME)
	@echo "$(NAME):  $(YEL)Executable file deleted$(DEF)"

re: fclean all

norm:
	norminette $(SRCS) $(SRCU) $(SRCB) $(SRCK) $(INCLUDE)

.PHONY : all clean fclean re bonus