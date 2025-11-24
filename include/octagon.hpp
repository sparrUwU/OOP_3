#ifndef OCTAGON_H
#define OCTAGON_H
#include "figure.hpp"

class Octagon : public Figure {
public:
    Octagon() = default;
    Octagon(const std::vector<Point>& vertices);
    Octagon(std::vector<Point>&& vertices);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Octagon& operator=(const Figure& other) override;
    Octagon& operator=(Figure&& other) override;
    
    // Конструкторы копирования и перемещения
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
};

#endif