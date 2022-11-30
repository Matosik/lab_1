
class Polynominal {
private:
	double* data;
	int step;
public:
	void set_coef(double value, int id);
	void set_step(int step);
	int get_step() const;
	double get_coef(int id) const;
	Polynominal();
	Polynominal(int step);
	void Print();
	int maximum(int a, int b) const;
	double& operator[](int& id);
	Polynominal operator+(Polynominal other)const;
	Polynominal operator-(Polynominal other)const;
	Polynominal operator*(double value);
	bool operator==(Polynominal& other) const;
	bool operator!=(Polynominal& other)const;
	double valueX(double x);
	int equation_roots(double*& arr);
	friend std::ostream& operator <<(std::ostream& os, const Polynominal poly);

};
