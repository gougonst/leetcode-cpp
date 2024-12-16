CPP = g++
CPPFLAGS = -std=c++14 -Iinclude
LDFLAGS = -lgtest -lpthread

.PHONY: all
all:
	@echo "Usage: make <file_name>"
	@echo "Example: make two_sum"

%: ./test/test_%.cpp ./src/%.cpp
	$(CPP) $(CPPFLAGS) -o test_$@.out $^ ${LDFLAGS}
