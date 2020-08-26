export CFLAGS := -Og -g -ggdb

.PHONY: all clean

all:
	$(info [*] make all)
	$(MAKE) -C ./test_makefile

clean:
	$(info [*] clean-up)
	$(MAKE) -C ./test_makefile clean
