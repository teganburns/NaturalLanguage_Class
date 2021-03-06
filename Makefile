CXX=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-L/usr/local/lib `pkg-config --libs grpc++`            \
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed \
           -lprotobuf -ldl


#LIBS_SFML=-lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio 
#LIBS=-lpthread
#INC=-I /home/owner/Documents/Development/git/SMFL/include -I /usr/include -I /usr/local/include

PROTO_TARGET=NaturalLanguage
PROTO_PROTOC=protoc
PROTO_PATH=.
PROTO_PROTO=proto

CPP_TARGET=test
NL_CLASS=natural_language

GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = .


vpath %.proto $(PROTOS_PATH)


all: system-check $(NL_CLASS)

$(NL_CLASS): $(PROTO_TARGET).pb.o $(PROTO_TARGET).grpc.pb.o $(NL_CLASS).o $(NL_CLASS).h $(CPP_TARGET).o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS)  -o $@

.PRECIOUS: %.grpc.pb.cc
%.grpc.pb.cc: %.proto
	$(PROTO_PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $(PROTO_TARGET).proto

.PRECIOUS: %.pb.cc
%.pb.cc: %.proto
	$(PROTO_PROTOC) -I $(PROTOS_PATH) --cpp_out=. $(PROTO_TARGET).proto

clean:
	$(RM) $(NL_CLASS) $(CPP_TARGET) *.o *.pb.cc *.pb.h



# The following is to test your system and ensure a smoother experience.
# They are by no means necessary to actually compile a grpc-enabled software.

PROTOC_CMD = which $(PROTO_PROTOC)
PROTOC_CHECK_CMD = $(PROTO_PROTOC) --version | grep -q libprotoc.3
PLUGIN_CHECK_CMD = which $(GRPC_CPP_PLUGIN)
HAS_PROTOC = $(shell $(PROTOC_CMD) > /dev/null && echo true || echo false)
ifeq ($(HAS_PROTOC),true)
HAS_VALID_PROTOC = $(shell $(PROTOC_CHECK_CMD) 2> /dev/null && echo true || echo false)
endif
HAS_PLUGIN = $(shell $(PLUGIN_CHECK_CMD) > /dev/null && echo true || echo false)

SYSTEM_OK = false
ifeq ($(HAS_VALID_PROTOC),true)
ifeq ($(HAS_PLUGIN),true)
SYSTEM_OK = true
endif
endif

system-check:
ifneq ($(HAS_VALID_PROTOC),true)
	@echo " DEPENDENCY ERROR"
	@echo
	@echo "You don't have protoc 3.0.0 installed in your path."
	@echo "Please install Google protocol buffers 3.0.0 and its compiler."
	@echo "You can find it here:"
	@echo
	@echo "   https://github.com/google/protobuf/releases/tag/v3.0.0"
	@echo
	@echo "Here is what I get when trying to evaluate your version of protoc:"
	@echo
	-$(PROTOC) --version
	@echo
	@echo
endif
ifneq ($(HAS_PLUGIN),true)
	@echo " DEPENDENCY ERROR"
	@echo
	@echo "You don't have the grpc c++ protobuf plugin installed in your path."
	@echo "Please install grpc. You can find it here:"
	@echo
	@echo "   https://github.com/grpc/grpc"
	@echo
	@echo "Here is what I get when trying to detect if you have the plugin:"
	@echo
	-which $(GRPC_CPP_PLUGIN)
	@echo
	@echo
endif
ifneq ($(SYSTEM_OK),true)
	@false
endif
