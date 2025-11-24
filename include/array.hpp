#ifndef ARRAY_H
#define ARRAY_H
#include "figure.hpp"

class Array {
private:
    Figure** figures;          // Массив указателей на Figure
    size_t capacity;           // Вместимость массива
    size_t size_;              // Текущий размер массива
    
    void resize();             // Увеличение capacity при необходимости

public:
    Array();
    ~Array();
    
    // Запрещаем копирование (или можно реализовать глубокое копирование)
    Array(const Array& other) = delete;
    Array& operator=(const Array& other) = delete;
    
    // Перемещение
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
    
    // Очистка массива (удаление всех фигур)
    void clear();
};

#endif