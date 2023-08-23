/*
 * Matrix.h
 *
 *  Created on: 05-Aug-2023
 *      Author: sunbeam
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix {
private:
	int **mat;
	int row;
	int cols;
public:
	Matrix();
	Matrix(int rows, int cols);

	//copy constructor
	Matrix(const Matrix &other) :
			row(other.row), cols(other.cols); 
	void operator=(const Matrix &other );
	void accept();
	void print();
	void add(Matrix&, Matrix&);
	void subtract(Matrix&, Matrix&);
	void multiply(Matrix&, Matrix&);
	void transponse();
};

#endif /* MATRIX_H_ */
