# The different directories
IDIR=../include
ODIR=obj

# Which compiler to use
CC=g++

# The list of flags to pass into the command
CFLAGS=-I$(IDIR)

# The cpp files are dependent on these include files
# patsubst adds the directory structure before the filename
_DEPS=raytracerFunctions.h vec3.h ray.h surface.h sphere.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

# The object files
_OBJ=raytracer.o raytracerFunctions.o vec3.o ray.o sphere.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

# -c means generate the object file
# $@ means the left side of the ':'
# $^ means the right side of the ':'
# $< means the first item on the right side of the ':'
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# The rule gets executed if any of the files after the ':' change
raytracer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Prevents make from doing anything with a file named clean
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ raytracer