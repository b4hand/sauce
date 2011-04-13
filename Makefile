GMOCK = vendor/gmock-1.5.0
GTEST = vendor/gmock-1.5.0/gtest

HEADERS      = $(shell find include -type f -name "*.h")
SOURCES      = $(shell find src     -type f -name "*.cc")
TEST_SOURCES = $(shell find test    -type f -name "*.cc")

OBJECTS      = $(patsubst src/%.cc,build/%.o,$(SOURCES))
TEST_OBJECTS = \
	$(patsubst test/%.cc,build/%.o,$(TEST_SOURCES)) \
	$(OBJECTS)                                      \
	$(GMOCK)/src/gmock-all.o                        \
	$(GMOCK)/src/gmock_main.o                       \
	$(GTEST)/src/gtest-all.o

all: test

build/%.o: src/%.cc $(HEADERS)
	mkdir -p build/sauce && $(CXX) $(CPPFLAGS) $< -c -o $@

$(GMOCK)/src/gmock-all.o $(GMOCK)/src/gmock_main.o $(GTEST)/src/gtest-all.o:
	cd $(GMOCK) && ./configure && make

build/%.o: test/%.cc $(HEADERS)
	mkdir -p build/sauce && \
	$(CXX) $(CPPFLAGS) -I$(GMOCK)/include -I$(GTEST)/include $< -c -o $@

build/tests: $(TEST_OBJECTS)
	mkdir -p build/sauce && $(CXX) $(CPPFLAGS) $+ -o $@

clean:
	rm -rf build/*

test: build/tests
	cd build && ./tests