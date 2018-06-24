##
## EPITECH PROJECT, 2018
## Cmakefile
## File description:
## Makefile
##

LIGHT_GREEN = "\033[1;32m"
RESET = "\033[0m"

all: build
	@$(MAKE) -j4 -s -C build
	@$(MAKE) -s -C sources/client/

build:
	@cmake -E make_directory build
	@cd build && cmake ..

clean:
	@if [ -d build ]; then $(MAKE) -s -C build/ clean; fi
	@$(MAKE) -s -C sources/client/ clean

fclean: clean
	@rm -rf build
	@echo -e $(LIGHT_GREEN) \
		 "Removed build directory" \
		 $(RESET)

re: fclean all

.PHONY: all clean fclean re build
