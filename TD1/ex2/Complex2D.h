// Évite que le fichier soit inclus plusieurs fois.
#ifndef COMPLEX2D_H
#define COMPLEX2D_H
#include <iostream>

class Complex2D {
private:
    double reel;      // La partie réelle
    double imaginaire;// La partie imaginaire

public:
    // 1. Constructeur par défaut (initialise à 0 + 0i)
    Complex2D();

    // 2. Constructeur avec la valeur de réel et d'imaginaire séparées
    Complex2D(double r, double i);

    // 3. Constructeur qui prend une seule valeur (utilisé pour les réels purs, ex: Complex2D c = 5.0;)
    Complex2D(double r);

    // 4. Constructeur par copie (prend un autre Complex2D)
    Complex2D(const Complex2D& autre);

    // Fonctions 'get' et 'set' pour les variables privées
    double getReel() const;
    double getImaginaire() const;
    void setReel(double r);
    void setImaginaire(double i);

    // Surcharge de l'opérateur d'addition (+)
    Complex2D operator+(const Complex2D& autre) const;

    // Surcharge de l'opérateur de soustraction (-)
    Complex2D operator-(const Complex2D& autre) const;

    // Surcharge de l'opérateur de multiplication (*)
    Complex2D operator*(const Complex2D& autre) const;

    // Surcharge de l'opérateur de division (/)
    Complex2D operator/(const Complex2D& autre) const;

    // Surcharge des opérateurs de comparaison (< et >) 
    // (Basés par exemple sur le module ou la partie réelle, ici on compare la partie réelle pour faire simple)
    bool operator<(const Complex2D& autre) const;
    bool operator>(const Complex2D& autre) const;

    // Fonction d'affichage pratique
    void afficher() const;
};

/*
On pourrait remplacer ou compléter la fonction afficher() par l'operator<< ce qui permettrait de faire fonctionner
les objets Complex2D exactement de la même manière que les variables de base du C++ avec std::cout.
*/

#endif
