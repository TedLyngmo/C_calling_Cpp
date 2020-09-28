# C calling C++

This is an example of how you can create a C++ library with classes and
how you can provide C functions for interacting with C++ objects in the
library.

#### `cube.hpp`

This contains a simple C++ class called `Cube`:
```
class Cube {
public:
    explicit Cube(int side);

    int side() const;
    int volume() const;

private:
    int m_side;
};
```

#### `cube.h`

This contains declarations of functions with C linkage to be able to create
`Cube` objects and call `Cube` member functions.

It also has a `cube_t` `typedef` which carries the object pointer. When adding
more C++ classes, create one `typedef` for each class and also a similar set of
functions to call member functions.
```
typedef struct { void* obj; } cube_t;

cube_t Cube_Create(int side);
int Cube_Side(cube_t c);
int Cube_Volume(cube_t c);
void Cube_Destroy(cube_t c);
```

#### `cube.cpp`

This contains the actual implementation of the C++ class' member functions as
well as the C functions. It's used to create a common C and C++ library,
`libclasses.a`.

#### Example apps `main.c` and `main.cpp`

These contains usage examples. Both programs are linked with the same library
(`libclasses.a`).
