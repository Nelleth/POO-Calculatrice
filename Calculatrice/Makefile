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
INCLUDES = inc/display.hpp inc/functions.hpp
# Fichiers source
SRCS = src/display.cpp src/functions.cpp src/main.cpp
# Fichiers objet
OBJS = Debug/src/display.o Debug/src/functions.o Debug/src/main.o
# Répertoires de compilation des sources
TEMP = Debug/src
# Executable
PROG = calculatrice
# Fichier d'en-tête des tests
INCLUDES_TEST = inc/display.hpp inc/functions.hpp
# Fichiers de tests
TESTS_SRC = test/functionstest.cpp
# Fichiers objet de tests
TESTS_OBJS = Debug/test/functionstest.o Debug/src/functions.o
# Répertoires de compilation des tests
TEMP_TEST = Debug/test
# Executable de test
TEST = test-calculatrice


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
Debug/src/functions.o: src/functions.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/display.o: src/display.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

Debug/src/main.o: src/main.cpp $(INCLUDES)
	$(CXX) $(CXXFLAGS) $(INCS) -o $@ -c $<

test: $(TEST)
	@echo " "
	@echo \'$<\' has been compiled. Do \'make runtest\' to execute.

$(TEST): $(TESTS_OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

Debug/test/functionstest.o: test/functionstest.cpp $(INCLUDES_TEST)
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
