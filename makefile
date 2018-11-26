all : run

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11 -isystem $(SRC_DIR)/headers

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./test/googletest

RAPIDCHECK_DIR = ./test/rapidcheck

# Where to find user code.
TEST_DIR = ./test
SRC_DIR = ./src

# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
GTEST_INCLUDE += -isystem $(GTEST_DIR)/include

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_INCLUDE) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(GTEST_INCLUDE) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

EQUIP = Equipment.o Body.o Helm.o Pants.o Shield.o Weapon.o

run : build
	./RPG

build : $(SRC_DIR)/main.cpp Creature.o Player.o Monster.o $(EQUIP) Dungeon.o World.o
	$(CXX) $(CXXFLAGS) -o RPG $^

unit_test : unit_tests
	./unit_tests

prop_test : prop_tests
	./prop_tests

clean_rapidcheck : 
	rm -rf $(RAPIDCHECK_DIR)/CMakeFiles $(RAPIDCHECK_DIR)/cmake_install.cmake \
	$(RAPIDCHECK_DIR)/CMakeCache.tst $(RAPIDCHECK_DIR)/Makefile \
	$(RAPIDCHECK_DIR)/CMakeCache.txt $(RAPIDCHECK_DIR)/librapidcheck.a

clean : clean_rapidcheck
	rm -f gtest.a gtest_main.a *.o RPG unit_tests


# Equipment
Equipment.o : $(SRC_DIR)/Equipment.cpp $(SRC_DIR)/headers/Equipment.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Equipment.cpp

# Other Equipment
Body.o : $(SRC_DIR)/Body.cpp $(SRC_DIR)/headers/Body.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Body.cpp

Helm.o : $(SRC_DIR)/Helm.cpp $(SRC_DIR)/headers/Helm.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Helm.cpp

Pants.o : $(SRC_DIR)/Pants.cpp $(SRC_DIR)/headers/Pants.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Pants.cpp

Shield.o : $(SRC_DIR)/Shield.cpp $(SRC_DIR)/headers/Shield.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Shield.cpp

Weapon.o : $(SRC_DIR)/Weapon.cpp $(SRC_DIR)/headers/Weapon.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Weapon.cpp

#Creature
Creature.o : $(SRC_DIR)/Creature.cpp $(SRC_DIR)/headers/Creature.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Creature.cpp

# Monster
Monster.o : $(SRC_DIR)/Monster.cpp $(SRC_DIR)/headers/Monster.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Monster.cpp

# Player
Player.o : $(SRC_DIR)/Player.cpp $(SRC_DIR)/headers/Player.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Player.cpp

# Dungeon
Dungeon.o : $(SRC_DIR)/Dungeon.cpp $(SRC_DIR)/headers/Dungeon.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/Dungeon.cpp

# World
World.o : $(SRC_DIR)/World.cpp $(SRC_DIR)/headers/World.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/World.cpp
	

# Start Unit Tests
Equipment_unittest.o : $(TEST_DIR)/Equipment_unittest.cpp $(GTEST_HEADERS)
	$(CXX) $(GTEST_INCLUDE) $(CXXFLAGS) -c $(TEST_DIR)/Equipment_unittest.cpp

Creature_unittest.o : $(TEST_DIR)/Creature_unittest.cpp $(GTEST_HEADERS)
	$(CXX) $(GTEST_INCLUDE) $(CXXFLAGS) -c $(TEST_DIR)/Creature_unittest.cpp

Player_unittest.o : $(TEST_DIR)/Player_unittest.cpp $(GTEST_HEADERS)
	$(CXX) $(GTEST_INCLUDE) $(CXXFLAGS) -c $(TEST_DIR)/Player_unittest.cpp

Monster_Generation.o : $(TEST_DIR)/Monster_Generation.cpp $(GTEST_HEADERS)
	$(CXX) $(GTEST_INCLUDE) $(CXXFLAGS) -c $(TEST_DIR)/Monster_Generation.cpp

UNIT_TESTS = Equipment_unittest.o Player_unittest.o Creature_unittest.o Monster_Generation.o

unit_tests : $(EQUIP) Creature.o Player.o Monster.o Dungeon.o $(UNIT_TESTS) gtest_main.a
	$(CXX) $(GTEST_INCLUDE) $(CXXFLAGS) -lpthread $^ -o $@

# Start Property Tests
RAPIDCHECK_INCLUDE = -isystem $(RAPIDCHECK_DIR)/include

Proptest.o : $(TEST_DIR)/Proptest.cpp
	$(CXX) $(RAPIDCHECK_INCLUDE) $(CXXFLAGS) $(CXXFLAGS) -c $(TEST_DIR)/Proptest.cpp 

librapidcheck.a : $(RAPIDCHECK_DIR)/CMakeLists.txt
	cd $(RAPIDCHECK_DIR) && cmake CMakeLists.txt && make

PROP_TESTS = Proptest.o

prop_tests : $(EQUIP) Creature.o Player.o Monster.o Dungeon.o $(PROP_TESTS) librapidcheck.a
	$(CXX) -lpthread $(EQUIP) Creature.o Player.o Monster.o Dungeon.o $(PROP_TESTS) $(RAPIDCHECK_DIR)/librapidcheck.a -o $@
