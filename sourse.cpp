#include <iostream>
#include <string>
#include <math.h> //pow(a,b) == a^b
using namespace std;


class Polynominal {
private:
	double *data;
	int step;
public:
	void set_coef(double value,int id){
		this->data[id] = value;
	}
	void set_step(int step) {
		this->step = step;
		this->data = new double[step+1];
	}
	int get_step() {
		return step;
	}
	double get_coef(int id) {
		if ((id > step) || (id < 0)) {
			return 0;
		}
		else{ 
			return data[id]; 
		}
	}
	Polynominal() {
		this->step = 0+1;
		this->data = new double[0];
	}
	double & operator[](int id) {
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
	void Print() {
		for (int i = 0; i <step+1; i++) {
			if (data[i] == 0) {
				cout << "";
			}
			else if (i == 0) {
				cout << get_coef(i) <<" + ";
			}
			else if (i == 1) {
				cout << get_coef(i) << " x "<<" + ";
			}
			else if (i==step){
				cout << get_coef(i)<<" x^"<< i;
			}
			else {
				cout << get_coef(i) <<" x^"<<i<< " + ";
			}
		}
	}
	int maximum(int a, int b) {
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}
	Polynominal & operator+( Polynominal other) {
		int maxStep = maximum(this->step, other.step);
		Polynominal temp;
		temp.set_step(maxStep);
		for (int i = 0; i <= maxStep;i++) {
			temp.set_coef(this->get_coef(i) + other.get_coef(i), i);
		}
		return temp;
	}
	Polynominal& operator-(Polynominal other) {
		int maxStep = maximum(this->step, other.step);
		Polynominal temp;
		temp.set_step(maxStep);
		for (int i = 0; i <= maxStep; i++) {
			temp.set_coef(this->get_coef(i) - other.get_coef(i), i);
		}
		return temp;
	}
	Polynominal& operator*(double value) {
		Polynominal temp;
		temp.set_step(this->step);
		for (int i = 0; i <= this->step; i++) {
			temp.set_coef(this->get_coef(i) * value, i);
		}
		return temp;
	}

	double valueX(double x) {
		double summ=0;
		for (int i = 0; i < step + 1; i++) {
			summ+=(data[i]*pow(x,i));
		}
		return summ;
	}

};
int main() {
	setlocale(LC_ALL, "RUS");
	Polynominal** collection = NULL;
	Polynominal a = Polynominal();
	cout << "ВВедите степень: ";
	int step;
	cin >> step;
	a.set_step(step);
	for (int i = 0; i <= step; i++) {
		double ch;
		cout << "["<< i << "]";
		cin >> ch;
		a.set_coef(ch, i);
	}
	cout << "\n первый многочлен:";
	a.Print();
	cout << "\n cтепень первого многочлена: "<<a.get_step();

	//cout << "\nВведите индекс которых хотите получить: ";
	//int index;
	//cin >> index;
	//cout << "\n"<< a[index];
//======================================
	Polynominal b = Polynominal();
	cout << "\n\n\n\n ВВедите степень: ";
	int step1;
	cin >> step1;
	b.set_step(step1);
	for (int i = 0; i <= step1; i++) {
		double ch;
		cout << "[" << i << "]";
		cin >> ch;
		b.set_coef(ch, i);
	}
	cout << "\n второй многочлен:";
	b.Print();
	cout << "\n cтепень второго многочлена: " << b.get_step();
	Polynominal c = a + b;
	cout<< "\nсложение двух многочленов:\n ";
	c.Print();
	cout << "\n Введите х для 1 многочлена: ";
	int X;
	cin >> X;
	a.Print();
	cout <<" \t при х= "<< X <<" === " << a.valueX(X);
	return 0;
}