CPP = g++
OPTS = -Wall -g
EXE = program

###############################################################
# The first rule is run of only make is typed
msg:
@echo 'Targets are:'
@echo ' run:'
@echo ' clean:'

###############################################################
# Build and run all tests and output demonstration
run: 
	g++ -o myprogram driver.cpp -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	./myprogram


###############################################################
clean:
	rm -f *.o
