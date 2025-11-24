#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.hpp"

class Hexagon : public Figure {
public:
    Hexagon() = default;
    Hexagon(const std::vector<Point>& vertices);
    Hexagon(std::vector<Point>&& vertices);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Hexagon& operator=(const Figure& other) override;
    Hexagon& operator=(Figure&& other) override;
    
    // Конструкторы копирования и перемещения
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;
};

#endif