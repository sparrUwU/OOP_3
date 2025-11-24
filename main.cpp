#include "include/array.hpp"
#include "include/pentagon.hpp"
#include "include/hexagon.hpp"
#include "include/octagon.hpp"
#include <iostream>
#include <vector>


int main() {
    Array figures;
    
    figures.addFigure(new Pentagon({{0,0}, {1,0}, {1,1}, {0.5,1.5}, {0,1}}));
    figures.addFigure(new Hexagon({{0,0}, {1,0}, {1,1}, {0,1}, {-0.5,0.5}, {-0.5,-0.5}}));
    figures.addFigure(new Octagon({{0,0}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}}));
    
    figures.printAllFigures(std::cout);
    
    std::cout << "Total area: " << figures.totalArea() << std::endl;
    std::cout << std::endl;  
      
    return 0;
}