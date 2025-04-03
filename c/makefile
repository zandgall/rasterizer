include_lib := -I/mnt/Code/c++/_lib
library_lib := -L/mnt/Code/c++/_lib
INCLUDES := $(include_lib)/gl/linux/include
LIBRARY_PATHS := 
LIBRARIES := -lSDL2 -lm

# Heavily referencing https://makefiletutorial.com
target_exec := source

build_dir := ./build
src := ./

# Grab all C and C++ files to compile, or enter them manually
srcs := $(shell find $(src) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# Grab all .o files
objs := $(srcs:%=$(build_dir)/%.o)

inc_dirs := $(shell find $(src) -type d)
# grab as include paths
inc_flags := $(addprefix -I,$(inc_dirs))

# autogen makefiles
cppflags := $(inc_flags) -MMD -MP

all: $(target_exec)

release: CFLAGS += -O3
release: $(target_exec)

debug: CFLAGS += -DDEBUG -g -Wall
debug: $(target_exec)

# prep
$(target_exec): $(objs)
	$(CC) $(objs) -o $@ $(LDFLAGS) $(LIBRARY_PATHS) $(LIBRARIES)

# c build
$(build_dir)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(cppflags) $(INCLUDES) $(CFLAGS) -c $< -o $@ $(LIBRARY_PATHS) $(LIBRARIES)

# c++ build
#$(build_dir)/%.cpp.o: %.cpp
#	mkdir -p $(dir $@)
#	$(CXX) $(cppflags) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(build_dir)

-include $(DEPS)
