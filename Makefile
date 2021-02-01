CC=g++
CFLAGS=-c

library: main.o Audio.o  Book.o  Dvd.o  LibraryItem.o  LibraryItems.o  Loan.o  Loans.o Patron.o  Patrons.o
	$(CC) -o library main.o Audio.o  Book.o  Dvd.o  LibraryItem.o  LibraryItems.o  Loan.o  Loans.o Patron.o  Patrons.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
Book.o: Book.cpp Book.h
	$(CC) $(CFLAGS) Book.cpp
Audio.o: Audio.cpp Audio.h
	$(CC) $(CFLAGS) Audio.cpp
Dvd.o: Dvd.cpp Dvd.h
	$(CC) $(CFLAGS) Dvd.cpp
LibraryItem.o: LibraryItem.cpp LibraryItem.h
	$(CC) $(CFLAGS) LibraryItem.cpp
LibraryItems.o: LibraryItems.cpp LibraryItems.h
	$(CC) $(CFLAGS) LibraryItems.cpp
Patron.o: Patron.cpp Patron.h
	$(CC) $(CFLAGS) Patron.cpp
Patrons.o: Patrons.cpp Patrons.h
	$(CC) $(CFLAGS) Patrons.cpp
Loan.o: Loan.cpp Loan.h
	$(CC) $(CFLAGS) Loan.cpp
Loans.o: Loans.cpp Loans.h
	$(CC) $(CFLAGS) Loans.cpp

run:
	./library

clean:
	rm *.o library
