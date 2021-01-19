NAME = uls

TMP_DIR = ./obj

OBJ = ./*.o
TMP_OBJ = ./obj/*.o

SRC = ./src/*.c
INC = ./inc/*.h

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make -C libmx -f Makefile install
	@mkdir $(TMP_DIR)
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@mv $(OBJ) $(TMP_DIR)
	@clang $(CFLGS) $(TMP_OBJ) libmx/libmx.a -o $(NAME)

uninstall: clean
	@make -C libmx -f Makefile uninstall
	@rm $(NAME)

clean:
	@make -C libmx -f Makefile clean
	@rm -rf $(TMP_DIR)

reinstall: uninstall all
