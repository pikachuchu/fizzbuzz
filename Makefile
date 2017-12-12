SHELL=/bin/bash
CFLAGS=-O2 -Wno-shift-op-parentheses -Wno-bitwise-op-parentheses
main: main.c
check: main
	@./main | diff correct.out - \
		&& echo -e "\033[0;32mpass\033[0m"\
		|| echo -e "\033[0;31mfail\033[0m"
clean:
	rm -f main
