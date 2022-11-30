#include <iostream>
#include <string>
#include <math.h> //pow(a,b) == a^b
#include <conio.h>
#include "Polynomial.hpp"

using namespace std;




void Polynominal::set_coef(double value, int id) {
	this->data[id] = value;
}
void Polynominal::set_step(int  step) {
	this->step = step;
	this->data = new double[step + 1];
}
int Polynominal::get_step() const {
	return step;
}
double Polynominal::get_coef(int id) const {
	if ((id > step) || (id < 0)) {
		return 0;
	}
	else {
		return data[id];
	}
}
Polynominal::Polynominal(int step) {
	this->step = step;
	this->data = new double[step + 1];
	for (int i = 0; i < step + 1; i++) {
		data[i] = 0;
	}
}
Polynominal::Polynominal() {
	this->step = 0;
	this->data = new double[0];
}
double& Polynominal :: operator[](int& id) {
	if ((id < 0) || (id > step)) {
		int newid;
		cout << "Неккоректный ввод index введите новый индекс: ";
		cin >> newid;
		return (*this)[newid];
	}
	else {
		return data[id];
	}
}
void Polynominal::Print() {
	for (int i = 0; i <= step; i++) {
		if (data[i] == 0) {
			cout << "";
		}
		else if (i == 0) {
			cout << get_coef(i) << " + ";
		}
		else if ((i == step) && (i == 1)) {
			cout << get_coef(i) << "x";
		}
		else if (i == 1) {
			cout << get_coef(i) << "x " << " + ";
		}
		else if (i == step) {
			cout << get_coef(i) << "x^" << i;
		}
		else {
			cout << get_coef(i) << "x^" << i << " + ";
		}
	}
}
int Polynominal::maximum(int a, int b) const {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
Polynominal Polynominal:: operator+(Polynominal other) const {
	int maxStep = maximum(this->step, other.step);
	Polynominal temp;
	temp.set_step(maxStep);
	for (int i = 0; i <= maxStep; i++) {
		temp.set_coef(this->get_coef(i) + other.get_coef(i), i);
	}
	return temp;
}
Polynominal Polynominal:: operator-(Polynominal other) const {
	int maxStep = maximum(this->step, other.step);
	Polynominal temp;
	temp.set_step(maxStep);
	for (int i = 0; i <= maxStep; i++) {
		temp.set_coef(this->get_coef(i) - other.get_coef(i), i);
	}
	return temp;
}
Polynominal Polynominal:: operator*(double value) {
	Polynominal temp;
	temp.set_step(this->step);
	for (int i = 0; i <= this->step; i++) {
		temp.set_coef(this->get_coef(i) * value, i);
	}
	return temp;
}

ostream& operator << (ostream& os, Polynominal poly) {
	for (int i = 0; i <= poly.get_step(); i++) {
		if (poly[i] == 0) {
			os << "";
		}
		else if (i == 0) {
			os << poly.get_coef(i) << " + ";
		}
		else if ((i == poly.get_step()) && (i == 1)) {
			os << poly.get_coef(i) << "x";
		}
		else if (i == 1) {
			cout << poly.get_coef(i) << "x " << " + ";
		}
		else if (i == poly.get_step()) {
			os << poly.get_coef(i) << "x^" << i;
		}
		else {
			os << poly.get_coef(i) << "x^" << i << " + ";
		}
	}
	return os;
}
bool Polynominal::operator==(Polynominal& other) const {
	if (step == other.step) {
		for (int i = 0; i < step; i++) {
			if (get_coef(i) != other.get_coef(i)) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

bool Polynominal::operator!=(Polynominal& other) const {
	if (step != other.step) {
		return true;
	}
	else {
		for (int i = 0; i < step; i++) {
			if(get_coef(i)!=other.get_coef(i)){
				return true;
			}
			return false;
		}
	}
}

double Polynominal::valueX(double x) {
	double summ = 0;
	for (int i = 0; i < step + 1; i++) {
		summ += (data[i] * pow(x, i));
	}
	return summ;
}
int Polynominal::equation_roots(double*& arr) {//a=data[2] b=data[1] c=data[0]//прописать исключения 
	double discriminant, x1, x2, x;
	if (step == 2) {
		if (data[2] == 0) {
			x = data[0] * -1 / data[1];
			arr[0] = x;
			return 1;
		}
		discriminant = (pow(data[1], 2) - (4 * data[2] * data[0]));
		if (discriminant < 0) {
			string a = "Действительных корней нет!";
			throw a;
		}
		else if (discriminant == 0) {
			x1 = (-1 * data[1]) / 2 * data[2];
			arr[0] = x1;
			return 1;
		}
		else {
			x1 = ((-1 * this->data[1]) + sqrt(discriminant)) / (2 * this->data[2]);
			x2 = ((-1 * this->data[1]) - sqrt(discriminant)) / (2 * this->data[2]);
			arr[0] = x1;
			arr[1] = x2;
			return  2;
		}
	}
	else if (step == 1) {
		string a = "Error";
		if ((data[1] == 0) && (data[0] != 0)) {
			throw a;
		}
		else if ((data[1] == 0) && (data[0] == 0)) {
			string a = "(-; +)";
			throw a;
		}
		else {
			x = data[0] * -1 / data[1];
			arr[0] = x;
			return 1;
		}
	}
	else if (step > 2) {
		string a = "Я не умею решать ур-ния > 2 степени";
		throw a;
	}
}

