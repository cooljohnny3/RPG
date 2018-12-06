all : run

clean : clean-bc clean-klee

clean-bc : 
	rm *.bc

clean-klee : 
	rm -r klee-*

# Flags passed to the clang compiler.
FLAGS += -I $(SRC_DIR)/headers -std=c++11 -emit-llvm -c -g

# Where to find user code.
TEST_DIR = ~/Code/test
SRC_DIR = ~/Code/src

run : Klee.bc compile
	klee -link-llvm-lib=Source.bc Klee.bc

Klee.bc : $(TEST_DIR)/Klee/Klee.cpp
	clang -I ~/klee_src/include -emit-llvm -c -g $(TEST_DIR)/Klee/Klee.cpp

SOURCE_FILES = Equipment.bc Body.bc Helm.bc Pants.bc Shield.bc Weapon.bc Creature.bc Monster.bc Player.bc Dungeon.bc

compile : $(SOURCE_FILES)
	llvm-link $^ -o Source.bc

# Equipment
Equipment.bc : $(SRC_DIR)/Equipment.cpp $(SRC_DIR)/headers/Equipment.h
	clang $(FLAGS) $(SRC_DIR)/Equipment.cpp

# Other Equipment
Body.bc : $(SRC_DIR)/Body.cpp $(SRC_DIR)/headers/Body.h
	clang $(FLAGS) $(SRC_DIR)/Body.cpp

Helm.bc : $(SRC_DIR)/Helm.cpp $(SRC_DIR)/headers/Helm.h
	clang $(FLAGS) $(SRC_DIR)/Helm.cpp

Pants.bc : $(SRC_DIR)/Pants.cpp $(SRC_DIR)/headers/Pants.h
	clang $(FLAGS) $(SRC_DIR)/Pants.cpp

Shield.bc : $(SRC_DIR)/Shield.cpp $(SRC_DIR)/headers/Shield.h
	clang $(FLAGS) $(SRC_DIR)/Shield.cpp

Weapon.bc : $(SRC_DIR)/Weapon.cpp $(SRC_DIR)/headers/Weapon.h
	clang $(FLAGS) $(SRC_DIR)/Weapon.cpp

#Creature
Creature.bc : $(SRC_DIR)/Creature.cpp $(SRC_DIR)/headers/Creature.h
	clang $(FLAGS) $(SRC_DIR)/Creature.cpp

# Monster
Monster.bc : $(SRC_DIR)/Monster.cpp $(SRC_DIR)/headers/Monster.h
	clang $(FLAGS) $(SRC_DIR)/Monster.cpp

# Player
Player.bc : $(SRC_DIR)/Player.cpp $(SRC_DIR)/headers/Player.h
	clang $(FLAGS) $(SRC_DIR)/Player.cpp

# Dungeon
Dungeon.bc : $(SRC_DIR)/Dungeon.cpp $(SRC_DIR)/headers/Dungeon.h
	clang $(FLAGS) $(SRC_DIR)/Dungeon.cpp

# World
World.bc : $(SRC_DIR)/World.cpp $(SRC_DIR)/headers/World.h
	clang $(FLAGS) $(SRC_DIR)/World.cpp