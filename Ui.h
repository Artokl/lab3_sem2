#ifndef UI_H
#define UI_H
#include <ostream>
#include <iostream>

void StartMenu()
{
    std::cout << "Choose what you want to work with: " << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "1) Vector" << std::endl;
    std::cout << "2) RectangularMatrix" << std::endl;
}
void PrintMenuVector() {
    std::cout << "0) Return to StartMenu" << std::endl;
    std::cout << "1) Run tests" << std::endl;
}
void PrintMenuMatrix() {

}
void PrintVector(int Status)
{
    if (Status == 0) {
        std::cout << "Return to StartMenu";
    }
    if (Status == 1) {
        std::cout << "Tests for vector passed" << std::endl;
    }
    else {
        std::cout << "Unknown Programm" << std::endl;
    }
}
void PrintCase(int Status)
{
    if (Status == 0) {
        std::cout << "Programm ended";
    }
    else if (Status == 1) {
        PrintMenuVector();
    }
    else if (Status == 2) {
        PrintMenuMatrix();
    }
    else {
        std::cout << "Unknown command" << std::endl;
    }
}


#endif //UI_H
