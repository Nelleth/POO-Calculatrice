#
# Makefile suivant les recommendations de 
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
#

# Compilateur à utiliser
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -std=c++11 -g -O0 `wx-config --cxxflags`
LDFLAGS=`wx-config --libs` 

# Répertoires des fichiers d'en-tête
INCS = -I./inc
# Fichier s d'en-tête
INCLUDES = inc/Display.hpp inc/Stack.hpp inc/Operations.hpp
# Fichiers source
SRCS = src/Display.cpp src/Stack.cpp src/Operations.cpp src/main.cpp
# Fichiers objet
OBJS = Debug/src/Display.o Debug/src/Stack.o Debug/src/Operations.o Debug/src/main.o
# Répertoires de compilation des sources
TEMP = Debug/src
# Executable
PROG = SC3000
# Fichier d'en-tête des tests
INCLUDES_TEST = inc/Display.hpp inc/Stack.hpp inc/Operations.hpp
# Fichiers de tests
TESTS_SRC = test/TestStack.cpp
# Fichiers objet de tests
TESTS_OBJS = Debug/test/TestStack.o Debug/src/Stack.o Debug/src/Operations.o
# Répertoires de compilation des tests
TEMP_TEST = Debug/test
# Executable de test
TEST = test-SC3000


.PHONY: depend clean

all: prepare $(PROG) test
	@echo " "
	@echo \'$(PROG)\' has been compiled. Do \'make run\' to execute.

# Préparer les dossiers de compilation
prepare: 
	@if [ ! -d $(TEMP) ]; then mkdir -p $(TEMP); fi
	@if [ ! -d $(TEMP_TEST) ]; then mkdir -p $(TEMP_TEST); echo Compilation folders prepared.; fi

$(PROG): $(OBJS)
	$(CXX) -o $@ $^ `wx-config --libs`

# Construire les .o à partir des .cpp
Debug/src/Display.o: src/Display.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/Stack.o: src/Stack.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/Operations.o: src/Operations.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/main.o: src/main.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

test: $(TEST)
	@echo " "
	@echo \'$<\' has been compiled. Do \'make runtest\' to execute.

$(TEST): $(TESTS_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

Debug/test/TestStack.o: test/TestStack.cpp $(INCLUDES_TEST)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

run:
	./$(PROG)

runtest:
	./$(TEST)

cleaner: clean
	$(RM) $(PROG)
	$(RM) $(TEST)

clean:
	$(RM) Debug/src/*.o src/*~
	$(RM) -r Debug

depend: $(SRCS)
	makedepend $(INCS) $^

# DO NOT DELETE THIS LINE -- make depend needs it
