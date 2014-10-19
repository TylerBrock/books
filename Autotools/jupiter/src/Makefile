all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

clean:
	-rm jupiter

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(bindir)
	install -m 0755 jupiter $(bindir)

uninstall:
	-rm $(bindir)/jupiter

.PHONY: all clean check install
