Dbin = bin# Binary directory path
Dsrc = src# Source directory path
Dobj = obj# Object directory path

M = main# sub-directory for main block
T = test# sub-directory for test blockё

so_file = libso2gl.so# Binary share-library file

oMain = $(Dobj)/$(M)
sMain = $(Dsrc)/$(M)
bMain = $(Dbin)/$(M)

inc = $(sMain)/include# Include directory path

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
res_include: $(shLib)
	rm -rf $(sTest)/include
	cp -r  $(inc) $(sTest)/
	rm -rf $(sTest)/lib
	rm -rf $(bTest)/lib
	mkdir $(sTest)/lib
	mkdir $(bTest)/lib
	cp $(shLib) $(sTest)/lib
	cp $(shLib) $(bTest)/lib

$(oTest)/unitTest.o: $(sTest)/unitTest.cpp $(oTest)
	gcc -Wall -c $(sTest)/unitTest.cpp -o $(oTest)/unitTest.o

UT_gameObject: $(bTest)/ut_gameObject res_include
	./$(bTest)/ut_gameObject > ./testsReport.html

$(bTest)/ut_gameObject: $(oTest)/ut_gameObject.o $(oTest)/unitTest.o $(bTest) res_include
	gcc -o $(bTest)/ut_gameObject $(oTest)/ut_gameObject.o -lstdc++ -lso2gl -Wl,-rpath,./lib

$(oTest)/ut_gameObject.o: $(sTest)/ut_gameObject.cpp res_include $(oTest)
	gcc -Wall -c $(sTest)/ut_gameObject.cpp -o $(oTest)/ut_gameObject.o

start_test:
	rm -rf ./testsReport.html
	touch ./testsReport.html
	echo "<html><head></head><body>" > ./testsReport.html
	make UT_gameObject
	echo "</body></html>" > ./testsReport.html
	

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
	rm -rf $(sTest)/include
	rm -rf $(sTest)/lib

clear:
	make clear_obj
	make clear_bin
