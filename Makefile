CPP = g++
CPPFLAGS = -std=c++14 -Iinclude
LDFLAGS = -lgtest -lpthread

LINK_LIST_NODE = 0
LINK_TREE_NODE = 0

LINK_FILE_LIST =

ifeq ($(LINK_LIST_NODE), 1)
	LINK_FILE_LIST += src/list_node.cpp
endif

ifeq ($(LINK_TREE_NODE), 1)
	LINK_FILE_LIST += src/tree_node.cpp
endif

.PHONY: all
all:
	@echo "Usage: make <file_name>"
	@echo "Example: make two_sum"

%: ./test/test_%.cpp ./src/%.cpp
	$(CPP) $(CPPFLAGS) -o test_$@.out $^ ${LINK_FILE_LIST} ${LDFLAGS}
