## RPG Project

Run `make`

Specification and rough TODO list located in docs.

### Klee
`docker run --rm -ti --volume={Path to RPG}/RPG:/home/klee/Code --ulimit='stack=-1:-1' klee/klee`

`clang -I ~/klee_src/include -emit-llvm -c -g ~/Code/test/Klee/Klee.cpp`

`klee Klee.bc`