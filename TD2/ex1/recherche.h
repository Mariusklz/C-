#ifndef RECHERCHE_H
#define RECHERCHE_H

#include <vector>
#include <iostream>

// Classe de base abstraite
class SearchingAlgorithm {
protected:
    // Compte le nombre de comparaisons pour chercher un élément
    int numberComparisons;

public:
    // Variables statiques partagées par toutes les instances
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons; // Utilisation d'un double pour la moyenne

    // Constructeur par défaut
    SearchingAlgorithm();
    
    // Destructeur virtuel (bonne pratique pour les classes avec héritage)
    virtual ~SearchingAlgorithm() = default;

    // Fonction virtuelle pure : rend la classe abstraite
    virtual int search(const std::vector<int>& elements, int target) = 0;

    // Affiche les résultats et calcule les variables statiques
    void displaySearchResults(std::ostream& os, int results, int target);
};

// Algorithme 1 : Recherche Linéaire
class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

// Algorithme 2 : Recherche par Saut (Jump Search)
class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

// Algorithme 3 : Recherche Dicho/Binaire (Binary Search)
class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& elements, int target) override;
};

#endif // RECHERCHE_H