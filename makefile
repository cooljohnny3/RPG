run : build
			./RPG

build : 
				g++ -o RPG src/*.cpp

test : 
				

clean : 
				rm ./RPG ./*.o