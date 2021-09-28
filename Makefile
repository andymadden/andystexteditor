default: build

build:
	@gcc main.c app_windows.c fileio.c -o main.exe $(shell pkg-config json-c gtk+-3.0 --libs --cflags)

run: build
	@./main.exe testfile.txt