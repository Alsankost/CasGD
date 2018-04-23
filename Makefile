Dbin = bin# Binary directory path
Dsrc = src# Source directory path
Dobj = obj# Object directory path

M = main# sub-directory for main block
T = test# sub-directory for test block

inc = $(src)/$(M)/include# Include directory path

so_file = libso2gl.so# Binary share-library file

oMain = $(Dobj)/$(M)
sMain = $(Dsrc)/$(M)
bMain = $(Dbin)/$(M)

oTest = $(Dobj)/$(T)
sTest = $(Dsrc)/$(T)
bTest = $(Dbin)/$(T)

shLib = $(Dbin)/$(M)/$(so_file)

# Compilation main:
cmain: $(shLib)
	echo $(oMain)
	make $(shLib)

$(shLib): $(bMain) $(oMain)/gameObject.o
	gcc -shared -o $(shLib) $(oMain)/gameObject.o -lstdc++
	
$(oMain)/gameObject.o: $(oMain) $(sMain)/gameObject.cpp
	gcc -Wall -fPIC -c $(sMain)/gameObject.cpp -o $(oMain)/gameObject.o

# Compilation tests:
ctest: $(sTest)/include $(sTest)/lib/so_file
	cp -r $(inc) $(sTest)/

$(sTest)/include:
	cp -r $(inc) $(sTest)/

$(sTest)/lib/so_file: shLib
	mkdir -p $(sTest)/lib
	cp $(shLib) $(sTest)/lib/

# Make direcories:
$(Dobj):
	mkdir -p $(Dobj)

$(Dbin):
	mkdir -p $(Dbin)

$(oMain): $(Dobj)
	mkdir -p $(oMain)

$(bMain): $(Dbin)
	mkdir -p $(bMain)

$(oTest): $(Dobj)
	mkdir -p $(oTest)

$(bTest): $(Dbin)
	mkdir -p $(bTest)

# Clear:
clear_obj:
	rm -rf $(Dobj)

clear_bin:
	rm -rf $(Dbin)

clear:
	make clear_obj
	make clear_bin
