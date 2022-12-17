// Copyright 2022 Yunin Daniil
#include "../../../modules/task_2/yunin_d_gauss_ribbon_horizontal_scheme/gauss_ribbon_horizontal_scheme.h"
#include <mpi.h>
#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>

using std::vector;
using std::mt19937;
using std::random_device;

// Метод Гаусса используется для решения систем алгебраических уравнений
// Матрицы являются плотными - большинство элементов отличны от нуля
// Если СЛУ - невырожденная (определить матрицы коэффициентов системы отличен от нуля) - решение с определённой точностью
// Подразумевается, что решаем квадратные матрицы
//Решение системы линейных уравнений существует только в случае, когда матрица системы линейных уравнений невырожденная (определитель отличен от нуля)

// Help functions start
void UpdateRandNumbers(mt19937 *gen) {
    random_device rd;
    (*gen).seed(rd());
}
// Help functions end

// Сonsequent Gauss Start

// 1. Метод создания случайной квадратной матрицы
// 2. Решение системы
// 2.1. Прямой ход алгоритма
// 2.2. Обратный ход алгоритма
// 3. Вывод результата
// 4. Посчитать определитель?

void CreateMatrix(vector<double> &matrix, int size) {
    // чтобы сразу было всё хорошо (невырожденная матрица типа)
    /*
    1 2 3 4
    2 1 2 3
    3 2 1 2
    4 3 2 1
    */
    int number = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i*size+j] = number;
            (j < i) ? number-- : number++;
        }
        number = i+2;
    }
    
}

void CreateVector(vector<double> &vec, int size) {
    // чтобы сразу было всё хорошо
    for (int i = 0; i < size; i++) {
        vec[i] = i+(i+1);
    }
    

}

void CreateMatrixRandom(vector<double> &matrix, int size, mt19937 *gen) {
    // дело случая
    for (int i = 0; i < size * size; i++) {
        matrix[i] = (*gen)() % size; 
    }
    
}

void CreateVectorRandom(vector<double> &vec, int size, mt19937 *gen) {
    // дело случая
    for (int i = 0; i < size; i++) {    
        vec[i] = (*gen)() % size;
    }
    
}


vector<double> GaussConsequent(int matrix_size) {
    vector<double> matrix(matrix_size * matrix_size); // матрица коэффициентов (одномерный массив, где элементы хранятся построчно) индекс массива - i*size-matrix+j
    vector<double> right_vector(matrix_size); // правая части (после знака =) СЛАУ
    vector<double> results(matrix_size); // вектор с ответами (значения вычесленных x)
    const int size_matrix = matrix_size; // на всякий случай сохраню
    mt19937 gen;
    UpdateRandNumbers(&gen);
    // CreateVectorRandom(right_vector, size_matrix, &gen);
    CreateMatrix(matrix, size_matrix);
    // return right_vector; DEBUG
    return matrix;
    // return results; // True code
} 


// Сonsequent Gauss End
