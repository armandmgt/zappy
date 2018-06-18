##
## EPITECH PROJECT, 2018
## Zappy
## File description:
## Client_makefile

GO	=	$(shell go 2> /dev/null)
ifndef GO
 $(error You need the Go runtime to proceed)
endif

ifndef GOPATH
 $(info GOPATH is undefined, /usr/local/bin will be used instead)
 IPATH	=	/usr/local/bin
else
 IPATH	=	${GOPATH}/bin
endif

GOCMD	=	go

GOBUILD	=	$(GOCMD) build
GOCLEAN	=	$(GOCMD) clean

NAME	=	zappy_ai


all: help
.PHONY: all

help:
	@echo "List of possible commands :\n"
	@echo "make build   -- build the binary in the current directory"
	@echo "make clean   -- cleans the folder and removes the binary"
	@echo "make install -- install the binary either in the gopath or in /usr/local/bin"
	@echo "make remove  -- uninstall the binary"
.PHONY: help

build:
	$(GOBUILD) -o $(NAME) -v
.PHONY: build

clean:
	$(GOCLEAN)
	$(RM) $(NAME)
.PHONY: clean

install: build
	cp -v $(NAME) $(IPATH)
.PHONY: install

remove:
	$(GOCLEAN)
	$(RM) $(IPATH)/$(NAME)
.PHONY: remove
