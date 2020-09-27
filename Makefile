export CFLAGS := -Og -g -ggdb

.PHONY: all clean

all:
	$(info [*] make all)
	$(MAKE) -C ./test_makefile
	$(MAKE) -C ./c_macro
	$(MAKE) -C ./c_getopt
	$(MAKE) -C ./c_glib

clean:
	$(info [*] clean-up)
	$(MAKE) -C ./test_makefile clean
	$(MAKE) -C ./c_macro clean
	$(MAKE) -C ./c_getopt clean
	$(MAKE) -C ./c_glib clean
