#Sources and Useful Ressources:
#https://web.eecs.umich.edu/~sugih/pointers/make.html
#https://stackoverflow.com/questions/42938483/file-linking-with-c-makefile
#https://stackoverflow.com/questions/4130681/undefined-reference-maybe-makefile-is-wrong
#https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
#https://askubuntu.com/questions/115500/how-to-find-location-of-installed-library
#https://stackoverflow.com/questions/1517138/trying-to-include-a-library-but-keep-getting-undefined-reference-to-messages
#https://stackoverflow.com/questions/7004702/how-can-i-create-a-makefile-for-c-projects-with-src-obj-and-bin-subdirectories
#https://www.tutorialspoint.com/makefile/makefile_example.htm
#https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#C
#https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
#https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
#https://stackoverflow.com/questions/19078920/makefile-for-a-single-target-with-multiple-c-and-h-dependencies

CC = g++
LFLAGS = -L/usr/lib
CFLAGS  = -g -Wall
LIBS = -lGL -lGLU -lglut -lGLEW -lglfw
CODE = spheredraw.cpp helper.cpp

test1234: spheredraw.o
	${CC} ${CFLAGS} ${CODE} -o $@ ${LFLAGS} ${LIBS}

clean:
	$(RM) *.o test1234

cpp.o:
	${CC} ${CFLAGS} -c $<

