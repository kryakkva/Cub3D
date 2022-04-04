#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
#SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

BLUE	=	\033[36m
DEF		=	\033[0m

all: $(NOM)

%.o: %.c
	@echo "$(BLUE)❱❱$(DEF)\c"
	@$(CC) $(FL) -c -o $@ $< 

%.o: %.m
	@echo "$(BLUE)❱❱$(DEF)\c"
	@$(CC) $(FL) -c -o $@ $< 

$(NOM):	$(OBJ)
	@echo "\n"
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
