
class Polynominal {
private:
	double *data;
	int step;
public:
	void set_coef(double value,int id);
	void set_step(int step);
	int get_step();
	double get_coef(int id) ;
	Polynominal();
	double & operator[](int id);
	void Print() ;
	int maximum(int a, int b);
	Polynominal & operator+( Polynominal other) ;
	Polynominal& operator-(Polynominal other);
	Polynominal& operator*(double value);
	double valueX(double x);
	int equation_roots(double * &arr);

};
