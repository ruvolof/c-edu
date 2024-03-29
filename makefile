CC=gcc
CFLAGS=-Wall -g -O -pedantic -Wformat=2 -Wextra -lm

obj/dynamic.o : lib-src/dynamic.c include/dynamic.h include/array.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/dynamic-test.o : test-src/dynamic-test.c include/dynamic.h
	$(CC) $(CFLAGS) -o $@ -c $<

dynamic-test : obj/dynamic-test.o obj/dynamic.o obj/array.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/sort.o : lib-src/sort.c include/sort.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/sort_test.o : test-src/sort_test.c obj/sort.o
	$(CC) $(CFLAGS) -o $@ -c $<

sort_test : obj/sort_test.o obj/sort.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/heap.o : lib-src/heap.c include/heap.h include/sort.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/heap_test.o : test-src/heap_test.c obj/heap.o
	$(CC) $(CFLAGS) -o $@ -c $<

heap_test : obj/heap_test.o obj/heap.o obj/sort.o
	$(CC) $(CFLAGS) -o bin/$@ $^

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

obj/queue.o : lib-src/queue.c include/queue.h include/list.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/queue_test.o : test-src/queue_test.c obj/queue.o
	$(CC) $(CFLAGS) -o $@ -c $<

queue_test : obj/queue_test.o obj/queue.o obj/list.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/hash.o : lib-src/hash.c include/hash.h include/list.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/hash_test.o : test-src/hash_test.c obj/hash.o
	$(CC) $(CFLAGS) -o $@ -c $<

hash_test : obj/hash_test.o obj/hash.o obj/list.o
	$(CC) $(CFLAGS) -o bin/$@ $^

obj/graph.o : lib-src/graph.c include/graph.h
	$(CC) $(CFLAGS) -o $@ -c $<

obj/graph_test.o : test-src/graph_test.c obj/graph.o
	$(CC) $(CFLAGS) -o $@ -c $<

graph_test : obj/graph_test.o obj/graph.o obj/list.o obj/hash.o obj/queue.o
	$(CC) $(CFLAGS) -o bin/$@ $^

clean :
	rm -rv bin/*
	rm -rv obj/*