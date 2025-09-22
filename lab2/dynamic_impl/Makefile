TARGET = netcalc
LIBNAME = netcalc
NETWORK_LIBFILE = network_lib/lib$(LIBNAME).so
BROADCAST_LIBFILE = broadcast_lib/lib$(LIBNAME).so

CPPFLAGS += -g
LDFLAGS += -L./network_lib -L./broadcast_lib
LDLIBS += -l$(LIBNAME)

ifeq ($(shell uname -m),x86_64) 
 CPPFLAGS += -fPIC
endif

all: $(TARGET) $(NETWORK_LIBFILE) $(BROADCAST_LIBFILE)

# clean binary files
clean:
	rm -rf $(TARGET) $(NETWORK_LIBFILE) $(BROADCAST_LIBFILE) *.o network_lib/*.o broadcast_lib/*.o

# create directories if they don't exist
network_lib:
	mkdir -p network_lib

broadcast_lib:
	mkdir -p broadcast_lib

# creating dynamic library for network calculation
$(NETWORK_LIBFILE): network_lib/netcalc.o | network_lib
	@echo "\nCreating network dynamic library...\n"
	g++ $(CPPFLAGS) $^ -shared -o $@
	@echo "\nNetwork dynamic library created: '$(NETWORK_LIBFILE)'.\n"

# creating dynamic library for broadcast calculation  
$(BROADCAST_LIBFILE): broadcast_lib/netcalc.o | broadcast_lib
	@echo "\nCreating broadcast dynamic library...\n"
	g++ $(CPPFLAGS) $^ -shared -o $@
	@echo "\nBroadcast dynamic library created: '$(BROADCAST_LIBFILE)'.\n"

# creating application (default linked with network_lib)
$(TARGET): netcalc.cpp $(NETWORK_LIBFILE)
	@echo "\nCreating application...\n"
	g++ $(CPPFLAGS) $< -L./network_lib -l$(LIBNAME) -o $@
	@echo "\nApplication '$(TARGET)' is ready.\n"
	@echo "Set path to library: 'export LD_LIBRARY_PATH=./network_lib' for network address!\n"
	@echo "Set path to library: 'export LD_LIBRARY_PATH=./broadcast_lib' for broadcast address!\n"
