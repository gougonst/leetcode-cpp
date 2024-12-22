CPP = g++
CPPFLAGS = -std=c++14 -Iinclude
LDFLAGS = -lgtest -lpthread

LINK_LIST_NODE = 0

.PHONY: all
all:
	@echo "Usage: make <file_name>"
	@echo "Example: make two_sum"

%: ./test/test_%.cpp ./src/%.cpp
ifeq ($(LINK_LIST_NODE), 1)
	$(CPP) $(CPPFLAGS) -o test_$@.out $^ src/list_node.cpp ${LDFLAGS}
else
	$(CPP) $(CPPFLAGS) -o test_$@.out $^ ${LDFLAGS}
endif
