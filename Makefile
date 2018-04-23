dir_bin = bin
dir_src = src
dir_obj = obj

dir_src_main = $(dir_src)/main
dir_src_test = $(dir_src)/test

dir_obj_main = $(dir_obj)/main
dir_obj_test = $(dir_obj)/test

dir_bin_main = $(dir_bin)/main
dir_bin_test = $(dir_bin)/test

dir_include = $(dir_src)/main/include

share_lib = so2gl.so

# Compilation main:
main: $(share_lib) $(dir_include)
	cp -r $(dir_include) $(dir_bin_main)/

$(share_lib): $(dir_bin_main) $(dir_obj_main)/gameObject.o
	gcc -shared -o $(dir_bin_main)/$(share_lib) $(dir_obj_main)/gameObject.o -lstdc++
	
$(dir_obj_main)/gameObject.o: $(dir_src_main)/gameObject.cpp $(dir_obj_main)
	gcc -Wall -fPIC -c $(dir_src_main)/gameObject.cpp -o $(dir_obj_main)/gameObject.o

# Compilation tests:


# Make direcories:
$(dir_obj):
	mkdir -p $(dir_obj)

$(dir_bin):
	mkdir -p $(dir_obj)

$(dir_obj_main): $(dir_obj)
	mkdir -p $(dir_obj_main)

$(dir_obj_test): $(dir_obj)
	mkdir -p $(dir_obj_test)

$(dir_bin_main): $(dir_bin)
	mkdir -p $(dir_bin_main)

$(dir_bin_test): $(dir_bin)
	mkdir -p $(dir_bin_test)

# Clear:
clear_obj:
	rm -rf $(dir_obj)

clear_bin:
	rm -rf $(dir_bin)

clear:
	make clear_obj
	make clear_bin
