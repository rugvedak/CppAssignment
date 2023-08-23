/*
 * Matrix.h
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
using namespace std;
class Matrix {
private:
	int **mat;
	int row;
	int cols;
public:
	Matrix();
	Matrix(int rows, int cols);
	void accept();
	void print();
	void add(Matrix&, Matrix&);
	void subtract(Matrix&, Matrix&);
	void multiply(Matrix&, Matrix&);
	void transponse();
};
#endif /* MATRIX_H_ */
