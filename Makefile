##
# ShellSortComparision
#
# @file
# @version 0.1

FLAGS?=-Os -pedantic -Wall

install:
	$(CC) $(CFLAGS) main.c sort.c -o compare
	mkdir -p /usr/local/bin
	cp -f compare /usr/local/bin/

reinstall: clean
	$(CC) $(CFLAGS) main.c -o compare
	mkdir -p /usr/local/bin
	cp -f compare /usr/local/bin/

clean:
	rm -f compare
	rm -f /usr/local/bin/compare

# end