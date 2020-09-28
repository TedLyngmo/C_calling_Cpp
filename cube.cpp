#include "cube.hpp"
#include "cube.h"

#include <new>

// ----------------------------------------------------------------------------
// This is the C++ part of the library
// ----------------------------------------------------------------------------

Cube::Cube(int side) : m_side(side) {}

int Cube::side() const {
    return m_side;
}
int Cube::volume() const {
    return m_side * m_side * m_side;
}

// ----------------------------------------------------------------------------
// This is the C interface part of the library
// ----------------------------------------------------------------------------

extern "C" {

cube_t Cube_Create(int side) {
    return {new(std::nothrow) Cube(side)};
}

int Cube_Side(const cube_t c) {
    return static_cast<const Cube*>(c.obj)->side();
}

int Cube_Volume(const cube_t c) {
    return static_cast<const Cube*>(c.obj)->volume();
}

void Cube_Destroy(const cube_t c) {
    delete static_cast<const Cube*>(c.obj);
}

} // extern "C"
