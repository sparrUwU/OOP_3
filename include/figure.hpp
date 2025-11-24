#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return std::abs(x - other.x) < 1e-6 && std::abs(y - other.y) < 1e-6;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

class Figure {
protected:
    std::vector<Point> vertices;

public:
    Figure() = default;
    Figure(const std::vector<Point>& vertices) : vertices(vertices) {}
    Figure(std::vector<Point>&& vertices) : vertices(std::move(vertices)) {}
    virtual ~Figure() = default;
    
    const std::vector<Point>& getVertices() const { 
        return vertices; 
    }

    void setVertices(const std::vector<Point>& newVertices) { 
        vertices = newVertices; 
    }

    void setVertices(std::vector<Point>&& newVertices) { 
        vertices = std::move(newVertices); 
    }
    
    virtual Point center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};

std::ostream& operator<<(std::ostream& os, const Figure& fig);
std::istream& operator>>(std::istream& is, Figure& fig);

#endif