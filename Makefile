CC=gcc
CFLAGS=-O2 -Wno-shift-op-parentheses -Wno-bitwise-op-parentheses

%: %.c
	$(CC) $(CFLAGS) $< -o $@
