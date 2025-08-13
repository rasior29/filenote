# FileNote - Makefile
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -O2
INSTALL_DIR=/usr/local/bin
TARGETS=filenote-add filenote-list

all: $(TARGETS)

filenote-add: filenote-add.c
	$(CC) $(CFLAGS) -o filenote-add filenote-add.c

filenote-list: filenote-list.c
	$(CC) $(CFLAGS) -o filenote-list filenote-list.c

clean:
	rm -f $(TARGETS)

install: all
	sudo cp $(TARGETS) $(INSTALL_DIR)/

uninstall:
	sudo rm -f $(INSTALL_DIR)/filenote-add $(INSTALL_DIR)/filenote-list

.PHONY: all clean install uninstall
