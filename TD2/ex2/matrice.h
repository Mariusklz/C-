#ifndef MATRICE_H
#define MATRICE_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <type_traits>

// --- QUESTION 1 : Définir la classe MatrixBase ---
template <typename T>
class MatrixBase {
protected:
    std::vector<std::vector<T>> data; // vecteur template en 2D
    size_t rows;                      // variables size_t
    size_t cols;

public:
    // --- QUESTION 2 : Constructeurs ---
    MatrixBase(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(rows, std::vector<T>(cols, T())); // Initialisation avec des zéros par défaut
    }
    virtual ~MatrixBase() = default;

    // --- QUESTION 3 : addElement et getElement ---
    void addElement(size_t r, size_t c, T value) {
        if (r >= rows || c >= cols) throw std::out_of_range("Index hors limites");
        data[r][c] = value;
    }

    T getElement(size_t r, size_t c) const {
        if (r >= rows || c >= cols) throw std::out_of_range("Index hors limites");
        return data[r][c];
    }

    // --- QUESTION 4 : getRows et getCols ---
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // --- QUESTION 5 : Fonction Display ---
    virtual void Display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
};

// --- Déclaration anticipée de MatrixNumerical pour le hint de la question 10 ---
template <typename T> class MatrixNumerical;

// --- HINT (Question 10) : Fonction hors classe getCoFactor ---
template <typename T>
MatrixNumerical<T> getCoFactor(const MatrixNumerical<T>& mat, size_t p, size_t q, size_t n) {
    MatrixNumerical<T> temp(n - 1, n - 1);
    size_t i = 0, j = 0;
    for (size_t row = 0; row < n; row++) {
        for (size_t col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp.addElement(i, j++, mat.getElement(row, col));
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return temp;
}

// --- QUESTION 6 : Classe MatrixNumerical ---
// static_assert s'assure qu'on ne l'utilise qu'avec des types numériques (int, double, float)
template <typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(std::is_arithmetic<T>::value, "MatrixNumerical requiert un type numerique (int, double, float...)");

public:
    // --- QUESTION 8 : Constructeurs ---
    MatrixNumerical(size_t r, size_t c) : MatrixBase<T>(r, c) {}

    // --- QUESTION 9 : Opérateurs +, - et * ---
    MatrixNumerical<T> operator+(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) throw std::invalid_argument("Dimensions incompatibles pour l'addition");
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < this->cols; ++j)
                result.addElement(i, j, this->data[i][j] + other.data[i][j]);
        return result;
    }

    MatrixNumerical<T> operator-(const MatrixNumerical<T>& other) const {
        if (this->rows != other.rows || this->cols != other.cols) throw std::invalid_argument("Dimensions incompatibles pour la soustraction");
        MatrixNumerical<T> result(this->rows, this->cols);
        for (size_t i = 0; i < this->rows; ++i)
            for (size_t j = 0; j < this->cols; ++j)
                result.addElement(i, j, this->data[i][j] - other.data[i][j]);
        return result;
    }

    MatrixNumerical<T> operator*(const MatrixNumerical<T>& other) const {
        if (this->cols != other.rows) throw std::invalid_argument("Dimensions incompatibles pour la multiplication");
        MatrixNumerical<T> result(this->rows, other.cols);
        for (size_t i = 0; i < this->rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                T sum = 0;
                for (size_t k = 0; k < this->cols; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.addElement(i, j, sum);
            }
        }
        return result;
    }

    // --- QUESTION 7 : Fonction getDeterminant ---
    T getDeterminant(size_t n) const {
        if (this->rows != this->cols) throw std::logic_error("La matrice doit etre carree");
        if (n == 1) return this->data[0][0];
        if (n == 2) return (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]);

        T D = 0;
        int sign = 1;
        for (size_t f = 0; f < n; f++) {
            MatrixNumerical<T> temp = getCoFactor(*this, 0, f, n);
            D += sign * this->data[0][f] * temp.getDeterminant(n - 1);
            sign = -sign;
        }
        return D;
    }

    // --- QUESTION 10 : Fonction getInverse ---
    // L'inverse retourne souvent des nombres à virgule, on force une matrice de double
    MatrixNumerical<double> getInverse() const {
        if (this->rows != this->cols) throw std::logic_error("Matrice non carree");
        T det = getDeterminant(this->rows);
        if (det == 0) throw std::logic_error("Matrice singuliere, pas d'inverse");

        MatrixNumerical<double> adj(this->rows, this->cols);
        if (this->rows == 1) {
            adj.addElement(0, 0, 1);
            return adj;
        }

        int sign = 1;
        for (size_t i = 0; i < this->rows; i++) {
            for (size_t j = 0; j < this->cols; j++) {
                MatrixNumerical<T> temp = getCoFactor(*this, i, j, this->rows);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                // Transposition de la comatrice (Adjointe)
                adj.addElement(j, i, (sign * temp.getDeterminant(this->rows - 1)) / static_cast<double>(det));
            }
        }
        return adj;
    }

    // --- QUESTION 11 : Opérateur / ---
    // A / B équivaut généralement à A * Inverse(B)
    MatrixNumerical<double> operator/(const MatrixNumerical<T>& other) const {
        MatrixNumerical<double> invOther = other.getInverse();
        
        // Convertir this en double pour la multiplication
        MatrixNumerical<double> thisDouble(this->rows, this->cols);
        for(size_t i=0; i<this->rows; i++)
            for(size_t j=0; j<this->cols; j++)
                thisDouble.addElement(i, j, static_cast<double>(this->data[i][j]));

        return thisDouble * invOther;
    }

    // --- QUESTION 12 : getIdentity (statique) ---
    static MatrixNumerical<T> getIdentity(int size) {
        MatrixNumerical<T> id(size, size);
        for (int i = 0; i < size; ++i) {
            id.addElement(i, i, 1); // 1 sur la diagonale, 0 ailleurs
        }
        return id;
    }
};

#endif // MATRICE_H