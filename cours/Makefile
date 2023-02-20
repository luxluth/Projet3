# Silent mode
# -Wall -Wextra -Werror -pedantic -std=c99
.SILENT:
run:
	gcc src/main.c -o bin/main -fuse-ld=mold -O3 -Wall
	./bin/main

build:
	gcc src/main.c -o bin/main -O3 -Wall -std=c99 -fuse-ld=mold

debug:
	mkdir -p debug
	gcc -g src/main.c -o debug/main
	gdb debug/main

bench:
	hyperfine ./bin/main --runs 5 --warmup 10 --prepare ./bin/main --export-markdown bench.md -N
