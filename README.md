## RPG Project

Run `make`

Specification and rough TODO list located in docs.

### Klee
`docker pull klee/klee`

`docker run --rm -ti --volume={Path to RPG}:/home/klee/Code --ulimit='stack=-1:-1' klee/klee`

`cd Code/test/klee`

`make`

`ktest-tool --write-ints klee-last/test#.ktest`