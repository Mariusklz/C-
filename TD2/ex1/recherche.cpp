#include "recherche.h"
#include <cmath>
#include <algorithm>

// --- INITIALISATION DES VARIABLES STATIQUES ---
// C'est obligatoire de le faire dans le .cpp pour éviter les erreurs de Linker
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;

// Constructeur par défaut
SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

// Fonction d'affichage et de calculs statiques
void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target) {
    // Calcul selon la consigne 4
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    os << "--- Resultats de la recherche ---\n";
    if (results != -1) {
        os << "Cible (" << target << ") trouvee a l'indice : " << results << "\n";
    } else {
        os << "Cible (" << target << ") NON trouvee (-1)\n";
    }
    os << "Comparaisons (cette recherche) : " << numberComparisons << "\n";
    os << "Comparaisons totales (global)  : " << totalComparisons << "\n";
    os << "Recherches totales (global)    : " << totalSearch << "\n";
    os << "Moyenne des comparaisons       : " << averageComparisons << "\n\n";
}

// --- IMPLÉMENTATION : Linear Search ---
int LinearSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    for (size_t i = 0; i < elements.size(); ++i) {
        numberComparisons++; // On compte chaque comparaison avec 'target'
        if (elements[i] == target) {
            return i;
        }
    }
    return -1;
}

// --- IMPLÉMENTATION : Jump Search ---
// Note : Le tableau doit être trié pour JumpSearch et BinarySearch
int JumpSearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    if (elements.empty()) return -1;

    int n = elements.size();
    int step = std::sqrt(n);
    int prev = 0;

    numberComparisons++;
    while (elements[std::min(step, n) - 1] < target) {
        prev = step;
        step += std::sqrt(n);
        numberComparisons++;
        if (prev >= n) return -1;
    }

    while (elements[prev] < target) {
        numberComparisons++;
        prev++;
        if (prev == std::min(step, n)) return -1;
    }

    numberComparisons++;
    if (elements[prev] == target) {
        return prev;
    }
    return -1;
}

// --- IMPLÉMENTATION : Binary Search ---
int BinarySearch::search(const std::vector<int>& elements, int target) {
    numberComparisons = 0;
    int left = 0;
    int right = elements.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        numberComparisons++;
        if (elements[mid] == target) {
            return mid;
        }
        
        numberComparisons++;
        if (elements[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}