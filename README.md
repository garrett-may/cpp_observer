## C++ Observer

This is an implementation of the Observer design pattern in C++

This allows users to easily add functions so that they can be called when a certain type is fired

### Requirements

 - C++ version: C++14

### Compiling

`g++ -std=c++14 event.cpp main.cpp -o test`

### Running

`./test`

Expected output:

```
int is: 42
SpecificEvent is: 1
SpecificEvent is: 1
Event is: 1
```