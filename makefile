CC=gcc
CFLAGS=-Wall -g -O -pedantic -Wformat=2 -Wextra -lm

obj/dynamic.o : lib-src/dynamic.c include/dynamic.h include/array.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/dynamic-test.o : test-src/dynamic-test.c include/dynamic.h
	$(CC) $(CFLAGS) -o $@ -c $<

dynamic-test : obj/dynamic-test.o obj/dynamic.o obj/array.o
	$(CC) $(CFLAGS) -o bin/$@ $^

sort-test : obj/sort-test.o obj/sort.o obj/heap.o obj/array.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/sort-test.o : test-src/sort-test.c include/sort.h include/array.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/sort.o : lib-src/sort.c obj/heap.o include/sort.h include/heap.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/heap.o : lib-src/heap.o include/heap.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/array.o : lib-src/array.c include/array.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/array_test.o : test-src/array_test.c obj/array.o
	$(CC) $(CFLAGS) -o $@ -c $<

array_test : obj/array_test.o obj/array.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/binary_tree.o : lib-src/binary_tree.c include/binary_tree.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/binary_tree_test.o : test-src/binary_tree_test.c obj/binary_tree.o
	$(CC) $(CFLAGS) -o $@ -c $<

binary_tree_test : obj/binary_tree_test.o obj/binary_tree.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/list.o : lib-src/list.c include/list.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/list_test.o : test-src/list_test.c obj/list.o
	$(CC) $(CFLAGS) -o $@ -c $<

list_test : obj/list_test.o obj/list.o obj/array.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/stack.o : lib-src/stack.c include/stack.h include/list.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/stack_test.o : test-src/stack_test.c obj/stack.o
	$(CC) $(CFLAGS) -o $@ -c $<

stack_test : obj/stack_test.o obj/stack.o obj/list.o
	$(CC) $(CFLAGS) -o bin/$@ $^

clean :
	rm -rv bin/*
	rm -rv obj/*