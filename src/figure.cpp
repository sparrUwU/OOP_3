#include "../include/figure.hpp"
#include <algorithm>

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}

double Figure::area() const {
    size_t n = vertices.size();
    if (n < 3) return 0.0;

    double cx = 0, cy = 0;
    for (const auto& p : vertices) {
        cx += p.x;
        cy += p.y;
    }
    cx /= n;
    cy /= n;

    std::vector<Point> sorted = vertices;
    std::sort(sorted.begin(), sorted.end(),
              [&](const Point& a, const Point& b) {
                  return atan2(a.y - cy, a.x - cx) <
                         atan2(b.y - cy, b.x - cx);
              });

    double area = 0.0;
    for (size_t i = 0; i < n; i++) {
        size_t j = (i + 1) % n;
        area += sorted[i].x * sorted[j].y - sorted[j].x * sorted[i].y;
    }

    return std::abs(area) * 0.5;
}
