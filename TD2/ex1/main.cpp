#include <iostream>
#include <vector>
#include "recherche.h"

int main() {
    // Pour JumpSearch et BinarySearch, le vecteur doit être trié
    std::vector<int> data = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int targetToFind = 72;
    int targetNotFound = 99;

    std::cout << "La Valeur à trouver est : " << targetToFind << "\n\n";

    std::cout << "===== TEST LINEAR SEARCH =====\n";
    LinearSearch ls;
    int resLS = ls.search(data, targetToFind);
    ls.displaySearchResults(std::cout, resLS, targetToFind);

    std::cout << "===== TEST JUMP SEARCH =====\n";
    JumpSearch js;
    int resJS = js.search(data, targetToFind);
    js.displaySearchResults(std::cout, resJS, targetToFind);

    std::cout << "===== TEST BINARY SEARCH =====\n";
    BinarySearch bs;
    int resBS = bs.search(data, targetToFind);
    bs.displaySearchResults(std::cout, resBS, targetToFind);

    return 0;
}