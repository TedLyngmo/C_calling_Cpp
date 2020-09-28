#ifndef CUBE_HPP_B5BC44B8_FCCA_11EA_A01B_90B11C0C0FF8
#define CUBE_HPP_B5BC44B8_FCCA_11EA_A01B_90B11C0C0FF8

class Cube {
public:
    explicit Cube(int side);

    int side() const;
    int volume() const;

private:
    int m_side;
};

#endif
