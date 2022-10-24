#include <iostream>
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
		this->data = new double[step];
	}
	double get_coef(int id) {
		return data[id];
	}
	Polynominal(int step) {
		this->step = step;
		this->data = new double[step];
		for (int i = 0; i < step; i++) {
			data[i] = 0;
		}
	}
	void Print() {
		for (int i = 0; i <step; i++) {
			if (data[i] == 0) {
				cout << "";
			}
			else if (i == 0) {
				cout << get_coef(i) <<"+";
			}
			else if (i == 1) {
				cout << get_coef(i) << "x"<<"+";
			}
			else if (i==step-1){
				cout << get_coef(i)<<"x^"<< i;
			}
			else {
				cout << get_coef(i) <<"x^"<<i<< "+";
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	Polynominal a = Polynominal(4);
	cout << "ВВедите степень: ";
	int step;
	cin >> step;
	a.set_step(step);
	for (int i = 0; i < step; i++) {
		double ch;
		cout << "["<< i << "]";
		cin >> ch;
		a.set_coef(ch, i);
	}
	a.Print();
	return 0;
}