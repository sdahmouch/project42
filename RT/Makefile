NAME = rt

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

SRC_NAME = main.c \
		scene.c \
		error.c \
		general.c \
		camera.c \
		light.c \
		object.c \
		object_bis.c \
		object_inter.c \
		object_type.c \
		rotation.c \
		valid_file.c \
		rt.c \
		rt_bis.c \
		sdl.c \
		opencl.c \
		opencl_bis.c \
		divers.c \
		divers_bis.c \
		alloc_mem.c \
		delete_mem.c \
		calculus.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

PATHFT = ./libft

PATHSDL = ./sdl

FLAGS = -Wall -Werror -Wextra

INCLUDE = -I./includes

LIBFT = -L$(PATHFT) -lft

SDL = -L$(PATHSDL)/build/.libs -lSDL2

OPENCL = -framework opencl

VAR = "find ./sdl/build/libs/libSDL2-2.0.0.dylib"

all: libft sdl $(NAME)

libft:
	make -C $(PATHFT)

sdl:
	@test -f ./sdl/build/.libs/libSDL2-2.0.0.dylib || { cd $(PATHSDL) && ./configure && make; }

$(NAME): $(OBJ)
	gcc $(FLAGS) $(INCLUDE) $(LIBFT) $(SDL) $(OPENCL) -o $(NAME) $^
	@install_name_tool -change /usr/local/lib/libSDL2-2.0.0.dylib @executable_path/sdl/build/.libs/libSDL2-2.0.0.dylib rt

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	make -C $(PATHFT) clean
	/bin/rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C $(PATHFT) fclean
	@test ! -f ./sdl/build/.libs/libSDL2-2.0.0.dylib || { cd $(PATHSDL) && make clean && make distclean; }
	/bin/rm -f $(NAME)

re: fclean all

norminette:
	norminette ./libft/**/*[ch]
	norminette ./includes/*.h
	norminette ./srcs/*.c

.PHONY: all clean fclean re norminette libft sdl
