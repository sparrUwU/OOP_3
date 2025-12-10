#ifndef ARRAY_H
#define ARRAY_H
#include "figure.hpp"

class Array {
private:
    Figure** figures;           
    size_t capacity;          
    size_t size_;              
    
    void resize();             

public:
    Array();
    ~Array();
    
    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;
    
    Array(Array&& other) noexcept;
    Array& operator=(Array&& other) noexcept;
    
    void addFigure(Figure* figure);
    void removeFigure(int index);
    double totalArea() const;
    void printAllFigures(std::ostream& os) const;
    
    size_t size() const { 
        return size_; 
    }
    
    Figure* operator[](int index) const;
    
    void clear();
};

#endif