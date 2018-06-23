##
## EPITECH PROJECT, 2018
## zappy
## File description:
## .

PY	=	pyinstaller
PYFLAGS	+=	--onefile --clean --log-level=WARN

SRC	+=	main.py					\
		classes/AI.py			\
		classes/client.py		\
		classes/inventory.py	\
		classes/player.py		\
		common/vec.py

all: build
.PHONY: all

help:
	@echo "build:\t\tBuilds the exexcutable in the dist/ folder"
	@echo "install:\tBuilds then move the executable in the root of the repository"
	@echo "clean:\t\tRemoves the binary and the .spec file"

build:
	$(PY) $(PYFLAGS) $(SRC)
.PHONY: build

install:
	$(PY) $(PYFLAGS) $(SRC)
	mv -v ./dist/main zappy_ai
.PHONY: install

clean:
	rm -v -f ./dist/main
	rm -v -f ./zappy_ai
	rm -v -f ./main.spec
.PHONY: clean
