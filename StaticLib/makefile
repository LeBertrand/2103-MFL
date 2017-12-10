CC=gcc

CFLAGS=-c -I

CLEANUP=rm -rf *.o

all: makeRanLib

makeRanLib: makeLib
	ranlib libArr.a
	
makeLib: create_vector.o empty_vector.o insert.o print_vec.o delete_vector.o copy.o \
	copy_range.o clear_vector.o zeros.o fill.o read_from_file.o write_to_file.o \
	get_from_con.o add_from_con.o swap.o sort.o reverse.o dbl_equals.o \
	search.o sum.o avg.o var.o stdv.o add.o sub.o mul.o divv.o dot.o equals.o
	
	ar rc libArr.a create_vector.o empty_vector.o insert.o print_vec.o delete_vector.o copy.o \
	copy_range.o clear_vector.o zeros.o fill.o read_from_file.o write_to_file.o \
	get_from_con.o add_from_con.o swap.o sort.o reverse.o dbl_equals.o \
	search.o sum.o avg.o var.o stdv.o add.o sub.o mul.o divv.o dot.o equals.o


# Object Files	
create_vector.o: create_vector.c
	$(CC) $(CFLAGS) create_vector.c
	
empty_vector.o: empty_vector.c
	$(CC) $(CFLAGS) empty_vector.c

insert.o: insert.c
	$(CC) $(CFLAGS) insert.c
	
print_vec.o: print_vec.c
	$(CC) $(CFLAGS) print_vec.c
	
delete_vector.o: delete_vector.c
	$(CC) $(CFLAGS) delete_vector.c
	
copy.o: copy.c
	$(CC) $(CFLAGS) copy.c
	
copy_range.o: copy_range.c
	$(CC) $(CFLAGS) copy_range.c
	
clear_vector.o: clear_vector.c
	$(CC) $(CFLAGS) clear_vector.c
	
zeros.o: zeros.c
	$(CC) $(CFLAGS) zeros.c
	
fill.o: fill.c
	$(CC) $(CFLAGS) fill.c
	
read_from_file.o: read_from_file.c
	$(CC) $(CFLAGS) read_from_file.c
	
write_to_file.o: write_to_file.c
	$(CC) $(CFLAGS) write_to_file.c
	
get_from_con.o: get_from_con.c
	$(CC) $(CFLAGS) get_from_con.c
	
add_from_con.o: add_from_con.c
	$(CC) $(CFLAGS) add_from_con.c
	
swap.o: swap.c
	$(CC) $(CFLAGS)  swap.c
	
sort.o: sort.c
	$(CC) $(CFLAGS) sort.c

reverse.o: reverse.c
	$(CC) $(CFLAGS) reverse.c
	
dbl_equals.o: dbl_equals.c
	$(CC) $(CFLAGS) -lm dbl_equals.c
	
search.o: search.c
	$(CC) $(CFLAGS) search.c
	
sum.o: sum.c
	$(CC) $(CFLAGS) sum.c
	
avg.o: avg.c
	$(CC) $(CFLAGS) avg.c
	
var.o: var.c
	$(CC) $(CFLAGS) var.c
	
stdv.o: stdv.c
	$(CC) $(CFLAGS) -lm stdv.c
	
add.o: add.c
	$(CC) $(CFLAGS) add.c
	
sub.o: sub.c
	$(CC) $(CFLAGS) sub.c
	
mul.o: mul.c
	$(CC) $(CFLAGS) mul.c
	
divv.o: divv.c
	$(CC) $(CFLAGS) divv.c
	
dot.o: dot.c
	$(CC) $(CFLAGS) dot.c
	
equals.o: equals.c
	$(CC) $(CFLAGS) equals.c
	
# Compile command
compile:
	echo "Compile Commande Reached"
	gcc -o runnable.exe main.c -L. -lArr -lm
	
# remove object
clean:
	$(CLEANUP)