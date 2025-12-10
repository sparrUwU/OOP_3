#ifndef PENTAGON_H
#define PENTAGON_H
#include "figure.hpp"

class Pentagon : public Figure {
public:
    Pentagon() = default;
    Pentagon(const std::vector<Point>& vertices);
    Pentagon(std::vector<Point>&& vertices);
    
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    bool operator==(const Figure& other) const override;
    Pentagon& operator=(const Figure& other) override;
    Pentagon& operator=(Figure&& other) override;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;
};

#endif