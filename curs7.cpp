// # = directiva de preprocesare 


// operatorul []
// banal pt vector adr+ index
// pt a[i][j][k] avem 3 supraincarcari pt op []

//extragere biti prin op &:
// avem elem cu biti: bbbb si vrem b2b1; atunci facem b3b2b1b0 & 0110 = 0b2b10
// alta optiune este |:
// avem b3b2b1b0 | 0110 => b311b0

// a trick for vector and string to avoid null handling is to alwasy have an elem; string has \0;
#include <iostream>
using namespace std;

class Comparator{
public: 
    virtual bool operator()(double a, double  b) = 0;
};
class MaiMic : public Comparator{
public: 
    bool operator()(double a, double  b){
        return a < b;
    };
};
class MaiMare : public Comparator{
public: 
    bool operator()(double a, double  b){
        return a > b;
    };
};
class Vector
{
private:
	int dim;
	double* pe;
public:
    static double errPoint;
	Vector(int d = 1) : dim(d)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = 0.0;
	}
	Vector(int d, double* v) : dim(d)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = v[i];
	}

	Vector(Vector& src) : dim(src.dim)
	{
		pe = new double[dim];
		for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
	}

	~Vector() { delete[] pe; }

	Vector& operator=(Vector& src)
	{
        // check pt autoasignare
		if (pe != src.pe)
		{
			delete[] pe; dim = src.dim;
			pe = new double[dim];
			for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
		}
		return *this;
	}

    //dubla functie de acces(read & write)
	friend ostream& operator<<(ostream& os, Vector& v)
	{
		for (int i = 0; i < v.dim; i++) os << v.pe[i] << "\t";
		return os;
	}
    double& operator[](int idx){
        if(idx>=0 && idx < dim)
            return pe[idx];
        else{
            cerr << "\n Out of range";
            return errPoint;
        }
        
    }

};
double Vector::errPoint = 0.0;
int main()
{

	double vd[] = { 12,-5.5, 67, -32 };
	Vector v1(4, vd);
	cout << v1;
    cout <<"\nv1[3]: " << v1[3];
    v1[0] = 21.5;
    cout <<"\nModificat v1[0]: " << v1[0];
	getchar();
}
