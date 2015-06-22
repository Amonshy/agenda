OBJECTS = main.o paciente.o agenda.o
CPPFLAGS = -c -g -ansi -Wall -std=c++11 

agenda.x: $(OBJECTS)
	g++ -o agenda.x $(OBJECTS) 

main.o: main.cpp macros.hpp agenda.hpp
	g++ $(CPPFLAGS) main.cpp 

paciente.o: paciente.cpp paciente.hpp citas.hpp
	g++ $(CPPFLAGS) paciente.cpp 

agenda.o: agenda.cpp agenda.hpp
	g++ $(CPPFLAGS) agenda.cpp 
	
.PHONY: clean

clean:
	@echo Borrando ficheros .o...
	rm -f $(OBJECTS)
