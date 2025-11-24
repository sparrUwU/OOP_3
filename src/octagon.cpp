#include "../include/octagon.hpp"
#include <stdexcept>

Octagon::Octagon(const std::vector<Point>& vertices) {
    if (vertices.size() != 8) {
        throw std::invalid_argument("Octagon must have exactly 8 vertices");
    }
    setVertices(vertices);
}

Octagon::Octagon(std::vector<Point>&& vertices) {
    if (vertices.size() != 8) {
        throw std::invalid_argument("Octagon must have exactly 8 vertices");
    }
    setVertices(std::move(vertices));
}

Octagon::Octagon(const Octagon& other) {
    setVertices(other.getVertices());
}

Octagon::Octagon(Octagon&& other) noexcept {
    setVertices(std::move(const_cast<Octagon&>(other).getVertices()));
}

Point Octagon::center() const {
    const auto& verts = getVertices();
    double sum_x = 0, sum_y = 0;
    for (const auto& vertex : verts) {
        sum_x += vertex.x;
        sum_y += vertex.y;
    }
    return Point(sum_x / 8, sum_y / 8);
}

double Octagon::area() const {
    const auto& verts = getVertices();
    double area = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area += verts[i].x * verts[j].y - verts[j].x * verts[i].y;
    }
    return std::abs(area) / 2.0;
}

void Octagon::print(std::ostream& os) const {
    const auto& verts = getVertices();
    os << "Octagon vertices: ";
    for (size_t i = 0; i < verts.size(); ++i) {
        os << verts[i];
        if (i < verts.size() - 1) os << " ";
    }
    os << " | Center: " << center() << " | Area: " << area();
}

void Octagon::read(std::istream& is) {
    std::vector<Point> newVertices;
    for (int i = 0; i < 8; ++i) {
        Point p;
        is >> p;
        newVertices.push_back(p);
    }
    setVertices(newVertices);
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* octagon = dynamic_cast<const Octagon*>(&other);
    if (!octagon) return false;
    return getVertices() == octagon->getVertices();
}

Octagon& Octagon::operator=(const Figure& other) {
    const Octagon* octagon = dynamic_cast<const Octagon*>(&other);
    if (!octagon) {
        throw std::invalid_argument("Cannot assign non-Octagon to Octagon");
    }
    setVertices(octagon->getVertices());
    return *this;
}

Octagon& Octagon::operator=(Figure&& other) {
    Octagon* octagon = dynamic_cast<Octagon*>(&other);
    if (!octagon) {
        throw std::invalid_argument("Cannot move assign non-Octagon to Octagon");
    }
    setVertices(std::move(octagon->getVertices()));
    return *this;
}