#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <cstdio>
#include <iostream>

// Header de l'exo 1.3
std::string ex1();


//Header de l'exo 1.4
class my_class{
private: 
    std::string prive;

public: 
    // Constructeur par défaut
    my_class();

    // Constructeur avec un argument de type string
    my_class(const std::string& message); 
    
    // Fonction publique demandée
    void print_my_element() const;
};

#endif