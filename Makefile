NAME = uls

TMP_DIR = ./obj

OBJ = ./*.o
TMP_OBJ = ./obj/*.o

SRC = ./src/*.c
TMP_SRC = ./obj/*.c

INC = ./inc/*.h
TMP_INC = ./obj/*.h

CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

all: install clean

install:
	@make -C libmx -f Makefile install
	@mkdir $(TMP_DIR)
	@cp $(SRC) $(TMP_DIR)
	@cp $(INC) $(TMP_DIR)
	@clang $(CFLAGS) -c $(TMP_SRC) -I $(TMP_INC)
	@mv $(OBJ) $(TMP_DIR)
	@clang $(CFLGS) $(TMP_OBJ) libmx/libmx.a -o $(NAME)

uninstall: clean
	@make -C libmx -f Makefile uninstall
	@rm $(NAME)

clean:
	@make -C libmx -f Makefile clean
	@rm -rf $(TMP_DIR)

reinstall: uninstall all
