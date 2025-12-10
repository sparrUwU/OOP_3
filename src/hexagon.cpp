#include "../include/hexagon.hpp"
#include <stdexcept>

Hexagon::Hexagon(const std::vector<Point>& vertices) {
    if (vertices.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 vertices");
    }
    setVertices(vertices);
}

Hexagon::Hexagon(std::vector<Point>&& vertices) {
    if (vertices.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 vertices");
    }
    setVertices(std::move(vertices));
}

Hexagon::Hexagon(const Hexagon& other) {
    setVertices(other.getVertices());
}

Hexagon::Hexagon(Hexagon&& other) noexcept {
    setVertices(std::move(const_cast<Hexagon&>(other).getVertices()));
}

Point Hexagon::center() const {
    const auto& verts = getVertices();
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : verts) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Point(sum_x / 6, sum_y / 6);
}

double Hexagon::area() const {
    return Figure::area();
}

void Hexagon::print(std::ostream& os) const {
    const auto& verts = getVertices();
    os << "Hexagon vertices: ";
    for (size_t i = 0; i < verts.size(); ++i) {
        os << verts[i];
        if (i < verts.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

void Hexagon::read(std::istream& is) {
    std::vector<Point> newVertices;
    for (int i = 0; i < 6; ++i) {
        Point p;
        is >> p;
        newVertices.push_back(p);
    }
    setVertices(newVertices);
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* hexagon = dynamic_cast<const Hexagon*>(&other);
    if (!hexagon) return false;
    return getVertices() == hexagon->getVertices();
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        vertices = other.vertices;
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

Hexagon& Hexagon::operator=(const Figure& other) {
    const Hexagon* hexagon = dynamic_cast<const Hexagon*>(&other);
    if (!hexagon) {
        throw std::invalid_argument("Cannot assign non-Hexagon to Hexagon");
    }
    setVertices(hexagon->getVertices());
    return *this;
}

Hexagon& Hexagon::operator=(Figure&& other) {
    Hexagon* hexagon = dynamic_cast<Hexagon*>(&other);
    if (!hexagon) {
        throw std::invalid_argument("Cannot move assign non-Hexagon to Hexagon");
    }
    setVertices(std::move(hexagon->getVertices()));
    return *this;
}