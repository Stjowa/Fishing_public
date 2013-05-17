C = g++
OPTS = -Wall -g

###############################################################
# The first rule is run of only make is typed
msg:
@echo 'Targets are:'
@echo ' tests:'
@echo ' clean:'

###############################################################
# Build and run all tests and output demonstration
run: 
	$(GCC) $(OPTS) -o myprogram exampleSDL.cpp -lSDL -lSDL_ttf -lSDL_mixer 
	./myprogram

###############################################################
clean:
#rm -f *.o
