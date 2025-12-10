#include "../include/array.hpp"
#include <stdexcept>
#include <iostream>

Array::Array() : figures(nullptr), capacity(0), size_(0) {}

Array::~Array() {
    clear();
}

void Array::resize() {
    size_t newCapacity = (capacity == 0) ? 2 : capacity * 2;
    Figure** newFigures = new Figure*[newCapacity];
    
    for (size_t i = 0; i < size_; ++i) {
        newFigures[i] = figures[i];
    }
    
    delete[] figures;
    
    figures = newFigures;
    capacity = newCapacity;
}

void Array::addFigure(Figure* figure) {
    if (figure == nullptr) {
        throw std::invalid_argument("Cannot add null figure");
    }
    
    if (size_ >= capacity) {
        resize();
    }
    
    figures[size_] = figure;
    size_++;
}

void Array::removeFigure(int index) {
    if (index < 0 || index >= static_cast<int>(size_)) {
        throw std::out_of_range("Index out of range");
    }
    
    delete figures[index];
    
    for (size_t i = index; i < size_ - 1; ++i) {
        figures[i] = figures[i + 1];
    }
    
    size_--;
    figures[size_] = nullptr; 
}

double Array::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size_; ++i) {
        total += figures[i]->area();
    }
    return total;
}

void Array::printAllFigures(std::ostream& os) const {
    for (size_t i = 0; i < size_; ++i) {
        os << "Figure " << i << ": " << *figures[i] << std::endl;
    }
}

Figure* Array::operator[](int index) const {
    if (index < 0 || index >= static_cast<int>(size_)) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

void Array::clear() {
    for (size_t i = 0; i < size_; ++i) {
        delete figures[i];
    }
    delete[] figures;       
    
    figures = nullptr;
    capacity = 0;
    size_ = 0;
}

Array::Array(Array&& other) noexcept 
    : figures(other.figures), capacity(other.capacity), size_(other.size_) {
    other.figures = nullptr;
    other.capacity = 0;
    other.size_ = 0;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        clear();
        
        figures = other.figures;
        capacity = other.capacity;
        size_ = other.size_;
        
        other.figures = nullptr;
        other.capacity = 0;
        other.size_ = 0;
    }
    return *this;
}