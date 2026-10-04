#include "main.h"

// Exercice 1.3
std::string ex1() {
    std::string hello = "Hello World\n";
    return hello;
}

// Exercice 1.4 : Implémentation des méthodes de my_class
my_class::my_class() {
    prive = "prive";
}

my_class::my_class(const std::string& message) {
    prive = message; // On assigne bien le paramètre à la variable membre 'prive'
}

void my_class::print_my_element() const {
    std::cout << prive << std::endl;
}

// Fonction main pour tout tester
int main() {
    // Test Exercice 1.3
    std::cout << ex1();

    // Test Exercice 1.4 avec le constructeur par défaut
    my_class obj1;
    obj1.print_my_element();

    // Test Exercice 1.4 avec le constructeur prenant une string en argument
    my_class obj2("Hello World !");
    obj2.print_my_element();

    return 0;
}