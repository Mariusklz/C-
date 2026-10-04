#include "Complex2D.h"

// --- FONCTION MAIN DE TEST ---
int main() {
    // Test des constructeurs
    Complex2D c1;          // Constructeur par défaut (0 + 0i)
    Complex2D c2(3.0, 4.0); // Constructeur avec réel et imaginaire (3 + 4i)
    Complex2D c3(c2);      // Constructeur par copie

    std::cout << "c2 = ";
    c2.afficher();

    Complex2D c4(1.0, 2.0);
    std::cout << "c4 = ";
    c4.afficher();

    // Test des opérateurs
    Complex2D somme = c2 + c4;
    std::cout << "c2 + c4 = ";
    somme.afficher();

    Complex2D diff = c2 - c4;
    std::cout << "c2 - c4 = ";
    diff.afficher();

    Complex2D produit = c2 * c4;
    std::cout << "c2 * c4 = ";
    produit.afficher();

    Complex2D quotient = c2 / c4;
    std::cout << "c2 / c4 = ";
    quotient.afficher();

    // Test des comparaisons
    if (c4 < c2) {
        std::cout << "c4 est plus petit que c2 (selon la partie réelle)" << std::endl;
    }

    return 0;
}