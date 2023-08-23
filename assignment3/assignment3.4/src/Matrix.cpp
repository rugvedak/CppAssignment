/*
 * Matrix.cpp
 *
 *  Created on: 04-Aug-2023
 *      Author: sunbeam
 */
#include "../include/Matrix.h"
Matrix::Matrix() {
	this->mat = NULL;
	this->row = 0;
	this->cols = 0;
}
//paramterized constructor
Matrix::Matrix(int rows, int cols) {
	this->row = rows;
	this->cols = cols;
	this->mat = new int*[row];
	for (int i = 0; i < rows; i++) {
		this->mat[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			this->mat[i][j] = 0;
		}
	}
}
void Matrix::accept() {
	cout << "Enter " << row << " rows " << cols << " Cols Element :";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> this->mat[i][j]; //*(*(mat+i)+j)
		}
	}
}
//displaying the input matrix data
void Matrix::print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cout << this->mat[i][j] << " "; //*(*(mat+i)+j)
			//cout << "mat[" << i << "][" << j << "] : " << this->mat[i][j]
			//	<< " "; //*(*(mat+i)+j)
		}
		cout << endl;
	}
}
void Matrix::add(Matrix &m1, Matrix &m2) {
	for (int i = 0; i < this->row; ++i)
		for (int j = 0; j < this->cols; ++j)
			this->mat[i][j] = m1.mat[i][j] + m2.mat[i][j];

}

void Matrix::subtract(Matrix &m1, Matrix &m2) {

	for (int i = 0; i < this->row; ++i)
		for (int j = 0; j < this->cols; ++j)
			this->mat[i][j] = m1.mat[i][j] - m2.mat[i][j];

}
void Matrix::multiply(Matrix &m1, Matrix &m2) {

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->cols; j++) {
			for (int k = 0; k < cols; k++) {
				this->mat[i][j] = this->mat[i][j]
						+ (m1.mat[i][k] * m2.mat[j][k]);
			}
			cout << this->mat[i][j] << " ";
		}
		cout << endl;
	}
}void Matrix::transponse() {
	int t;
	for (int i = 0; i < this->row; i++) {
		for (int j = i + 1; j < this->cols; j++) {
			t = this->mat[i][j];
			this->mat[i][j] = this->mat[j][i];
			this->mat[j][i] = t;
		}
	}
}
