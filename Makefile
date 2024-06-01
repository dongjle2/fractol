NAME	:= fractol

CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./MLX42
MLX_HEADERS	:= -I ./include -I $(LIBMLX)/include
MY_HEADER := fractol.h
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=  main.c math_utils.c init.c utils.c atoi_f.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone --depth 1 --branch v2.3.2 https://github.com/codam-coding-college/MLX42 $(LIBMLX) && \
		cmake -S $(LIBMLX) -B $(LIBMLX)/build && \
		make -C $(LIBMLX)/build -j4; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c $(MY_HEADER)
	@$(CC) $(CFLAGS) -o $@ -c $< $(MLX_HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(MLX_HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx