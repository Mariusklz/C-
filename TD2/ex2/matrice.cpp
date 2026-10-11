#include <iostream>
#include "matrice.h"

int main() {
    std::cout << "--- TEST MATRICES ---\n";

    // Test Question 12 : Matrice Identité
    std::cout << "Matrice Identite 3x3 :\n";
    MatrixNumerical<int> id = MatrixNumerical<int>::getIdentity(3);
    id.Display();
    std::cout << "\n";

    // Création de deux matrices 2x2
    MatrixNumerical<double> mat1(2, 2);
    mat1.addElement(0, 0, 4); mat1.addElement(0, 1, 7);
    mat1.addElement(1, 0, 2); mat1.addElement(1, 1, 6);

    MatrixNumerical<double> mat2(2, 2);
    mat2.addElement(0, 0, 1); mat2.addElement(0, 1, 2);
    mat2.addElement(1, 0, 3); mat2.addElement(1, 1, 4);

    std::cout << "Matrice 1 :\n";
    mat1.Display();
    std::cout << "\nMatrice 2 :\n";
    mat2.Display();

    // Test Question 9 : Opérateurs
    std::cout << "\nAddition (Mat1 + Mat2) :\n";
    (mat1 + mat2).Display();

    std::cout << "\nMultiplication (Mat1 * Mat2) :\n";
    (mat1 * mat2).Display();

    // Test Question 7 : Déterminant
    std::cout << "\nDeterminant de Matrice 1 : " << mat1.getDeterminant(2) << "\n";

    // Test Question 10 : Inverse
    std::cout << "\nInverse de Matrice 1 :\n";
    MatrixNumerical<double> inv = mat1.getInverse();
    inv.Display();

    // Test Question 11 : Division (Mat1 / Mat1 devrait donner l'Identité)
    std::cout << "\nDivision (Mat1 / Mat1) (Doit etre proche de l'identite) :\n";
    (mat1 / mat1).Display();

    return 0;
}