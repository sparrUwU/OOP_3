#include "../include/pentagon.hpp"
#include <stdexcept>

Pentagon::Pentagon(const std::vector<Point>& vertices) {
    if (vertices.size() != 5) {
        throw std::invalid_argument("Pentagon must have exactly 5 vertices");
    }
    setVertices(vertices);
}

Pentagon::Pentagon(std::vector<Point>&& vertices) {
    if (vertices.size() != 5) {
        throw std::invalid_argument("Pentagon must have exactly 5 vertices");
    }
    setVertices(std::move(vertices));
}

Pentagon::Pentagon(const Pentagon& other) {
    setVertices(other.getVertices());
}

Pentagon::Pentagon(Pentagon&& other) noexcept {
    setVertices(std::move(const_cast<Pentagon&>(other).getVertices()));
}

Point Pentagon::center() const {
    const auto& verts = getVertices();
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : verts) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Point(sum_x / 5, sum_y / 5);
}

double Pentagon::area() const {
    const auto& verts = getVertices();
    double area = 0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        area += verts[i].x * verts[j].y - verts[j].x * verts[i].y;
    }
    return std::abs(area) / 2.0;
}

void Pentagon::print(std::ostream& os) const {
    const auto& verts = getVertices();
    os << "Pentagon vertices: ";
    for (size_t i = 0; i < verts.size(); ++i) {
        os << verts[i];
        if (i < verts.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

void Pentagon::read(std::istream& is) {
    std::vector<Point> newVertices;
    for (int i = 0; i < 5; ++i) {
        Point p;
        is >> p;
        newVertices.push_back(p);
    }
    setVertices(newVertices);
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* pentagon = dynamic_cast<const Pentagon*>(&other);
    if (!pentagon) return false;
    return getVertices() == pentagon->getVertices();
}

Pentagon& Pentagon::operator=(const Figure& other) {
    const Pentagon* pentagon = dynamic_cast<const Pentagon*>(&other);
    if (!pentagon) {
        throw std::invalid_argument("Cannot assign non-Pentagon to Pentagon");
    }
    setVertices(pentagon->getVertices());
    return *this;
}

Pentagon& Pentagon::operator=(Figure&& other) {
    Pentagon* pentagon = dynamic_cast<Pentagon*>(&other);
    if (!pentagon) {
        throw std::invalid_argument("Cannot move assign non-Pentagon to Pentagon");
    }
    setVertices(std::move(pentagon->getVertices()));
    return *this;
}