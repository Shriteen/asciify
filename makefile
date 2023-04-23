all: asciify.o letters.o move_cursor.o 
	gcc $^ -o asciify

%.o: %.c %.h
	gcc $< -c

%.o: %.c 
	gcc $< -c

clean:
	rm *.o
	rm asciify
