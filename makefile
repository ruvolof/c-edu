CC=gcc
CFLAGS=-Wall -g -O -pedantic -Wformat=2 -Wextra -lm

dynamic-test : obj/dynamic-test.o obj/dynamic.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/dynamic-test.o : test-src/dynamic-test.c include/dynamic.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/dynamic.o : lib-src/dynamic.c include/dynamic.h
	$(CC) $(CFLAGS) -o $@ -c $<

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

clean :
	rm -rv bin/*
	rm -rv obj/*