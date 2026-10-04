#include "Complex2D.h"

// --- IMPLÉMENTATION DES CONSTRUCTEURS ---

Complex2D::Complex2D() {
    reel = 0.0;
    imaginaire = 0.0;
}

Complex2D::Complex2D(double r, double i) {
    reel = r;
    imaginaire = i;
}

Complex2D::Complex2D(double r) {
    reel = r;
    imaginaire = 0.0;
}

Complex2D::Complex2D(const Complex2D& autre) {
    reel = autre.reel;
    imaginaire = autre.imaginaire;
}

// --- IMPLÉMENTATION DES GETTERS / SETTERS ---

double Complex2D::getReel() const {
    return reel;
}

double Complex2D::getImaginaire() const {
    return imaginaire;
}

void Complex2D::setReel(double r) {
    reel = r;
}

void Complex2D::setImaginaire(double i) {
    imaginaire = i;
}

// --- IMPLÉMENTATION DES OPÉRATEURS MATHÉMATIQUES ---

// Addition : (a + bi) + (c + di) = (a + c) + (b + d)i
Complex2D Complex2D::operator+(const Complex2D& autre) const {
    return Complex2D(reel + autre.reel, imaginaire + autre.imaginaire);
}

// Soustraction : (a + bi) - (c + di) = (a - c) + (b - d)i
Complex2D Complex2D::operator-(const Complex2D& autre) const {
    return Complex2D(reel - autre.reel, imaginaire - autre.imaginaire);
}

// Multiplication : (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
Complex2D Complex2D::operator*(const Complex2D& autre) const {
    double r = (reel * autre.reel) - (imaginaire * autre.imaginaire);
    double i = (reel * autre.imaginaire) + (imaginaire * autre.reel);
    return Complex2D(r, i);
}

// Division : (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c^2 + d^2)
Complex2D Complex2D::operator/(const Complex2D& autre) const {
    double denominateur = (autre.reel * autre.reel) + (autre.imaginaire * autre.imaginaire);
    if (denominateur == 0) {
        std::cerr << "Erreur : Division par zéro !" << std::endl;
        return Complex2D(0, 0);
    }
    double r = ((reel * autre.reel) + (imaginaire * autre.imaginaire)) / denominateur;
    double i = ((imaginaire * autre.reel) - (reel * autre.imaginaire)) / denominateur;
    return Complex2D(r, i);
}

// --- IMPLÉMENTATION DES COMPARATEURS ---
bool Complex2D::operator<(const Complex2D& autre) const {
    return this->reel < autre.reel; // Comparaison simple basée sur la partie réelle
}

bool Complex2D::operator>(const Complex2D& autre) const {
    return this->reel > autre.reel;
}

// --- FONCTION D'AFFICHAGE ---
void Complex2D::afficher() const {
    std::cout << reel << " + " << imaginaire << "i" << std::endl;
}
