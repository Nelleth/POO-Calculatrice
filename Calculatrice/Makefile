CC=g++
CXXFLAG=-Wall -std=c++11
LIBS=`wx-config --cxxflags --libs`
INCLUDE = -include wx/wx.h

PATH_TEST_BIN=test-bin/
PATH_OBJ=obj/
PATH_SRC=src/
PATH_HEADERS=headers/

EXEC_TEST= $(PATH_TEST_BIN)Stack-test
EXEC_PROG=calculator




OBJ_STACK_TEST=$(PATH_OBJ)StackTest.o $(PATH_OBJ)Stack.o
OBJ_CALCULATOR= $(PATH_OBJ)Stack.o $(PATH_OBJ)Operations.o $(PATH_OBJ)Display.o obj/Application.o


ifneq ("$(wildcard make.d)","")
all:: $(EXEC_PROG)
else
all:: depend $(EXEC_PROG)
endif


depend::
		$(CC) -MM $(LIBS) $(INCLUDE) $(CXXFLAG) $(PATH_SRC)*.cpp >>make.d

-include make.d

test:: $(EXEC_TEST)

calculator:: $(OBJ_CALCULATOR)
	$(CC) -o $@ $^ $(LIBS)



$(PATH_TEST_BIN)Stack-test: $(OBJ_STACK_TEST)
	$(CC) -o $@ $^ $(LIBS)
	
$(PATH_OBJ)StackTest.o: $(PATH_SRC)StackTest.cpp
	$(CC) -c $^ $(CXXFLAG) 
	@mv *.o $(PATH_OBJ)


$(PATH_OBJ)%.o: $(PATH_SRC)%.cpp $(PATH_HEADERS)%.hpp
	$(CC) -c  $< $(CXXFLAG) $(LIBS)  $(INCLUDE)
	@mv *.o $(PATH_OBJ)




cleaner: clean
	@rm -f $(EXEC_TEST)
	@rm -f $(EXEC_PROG)

clean: 
	@rm -f $(PATH_OBJ)*.o
	@rm -f $(PATH_HEADERS)*.gch
	@rm -f make.d

