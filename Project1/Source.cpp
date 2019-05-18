#include <iostream>
#include <math.h>
#define PI 3.14159265
using namespace std;
class complex
{
	double real, imag, magn, angel;
public:
	complex();
	void set_complex_rec(double, double);
	void set_complex_pol(double, double);
	double get_real();
	double get_imag();
	double get_magn();
	double get_angel();
	complex rec();
	complex pol();
	complex operator + (complex);
	complex operator - (complex);
	complex operator * (complex);
	complex operator / (complex);
};
complex::complex() {
	real = 0;
	imag = 0;
	magn = 0;
	angel = 0;
}
void complex::set_complex_rec(double i, double j) {
	real = i;
	imag = j;
	magn = 0;
	angel = 0;
}
void complex::set_complex_pol(double i, double j) {
	magn = i;
	angel = j;
	real = 0;
	imag = 0;
}
double complex::get_real() {
	return real;
}
double complex::get_imag() {
	return imag;
}
double complex::get_magn() {
	return magn;
}
double complex::get_angel() {
	return angel;
}
complex complex::rec() {
	if (magn == 0 && angel == 0) {
		return *this;
	}
	if (angel<0)
	{
		angel = 360 + angel;
	}
	real = sqrt((magn*magn) / (1.0 + (tan(angel*PI / 180.0)*tan(angel*PI / 180.0))));
	imag = tan(angel*PI / 180.0)*real;
	if ((180>angel) && (angel>90))
	{
		real = -abs(real);
		imag = abs(imag);
	}
	if ((270>angel) && (angel>180))
	{
		real = -abs(real);
		imag = -abs(imag);
	}
	if ((360>angel) && (angel>270))
	{
		imag = -abs(imag);
		real = abs(real);
	}
	magn = 0;
	angel = 0;
	return *this;
}
complex complex::pol() {
	if ((real == 0) && (imag == 0))
	{
		return *this;
	}
	magn = sqrt(real*real + imag*imag);
	angel = atan(abs(imag) / abs(real)) * (180 / PI);
	if ((real<0) && (imag >= 0))
	{
		angel = 180 - angel;
	}
	if ((real>0) && (imag<0))
	{
		angel = 360 - angel;
	}
	if ((real<0) && (imag<0))
	{
		angel = 180 + angel;
	}
	real = 0;
	imag = 0;
	return  *this;
}
complex complex::operator+(complex c) {
	complex t;
	rec();
	c.rec();
	t.real = real + c.real;
	t.imag = imag + c.imag;
	return t;
}
complex complex :: operator-(complex c) {
	complex t;
	rec();
	c.rec();
	t.real = real - c.real;
	t.imag = imag - c.imag;
	return t;
}
complex complex :: operator*(complex c) {
	complex t;
	pol();
	c.pol();
	t.magn = magn * c.magn;
	t.angel = angel + c.angel;
	t.rec();
	return t;
}
complex complex :: operator/(complex c) {
	complex t;
	pol();
	c.pol();
	t.magn = magn / c.magn;
	t.angel = angel - c.angel;
	t.rec();
	return t;
}

ostream& operator << (ostream&r, complex c) {
	if (c.get_real() == 0 && c.get_imag() == 0)
	{
		r << c.get_magn() << ",ang(" << c.get_angel() << ")";
		return r;
	}
	if (c.get_magn() == 0 && c.get_angel() == 0)
	{
		r << c.get_real() << " + " << c.get_imag() << " i";
		return r;
	}
}

int main() {
	complex x, y;
	cout << "\n                                  *** C O M P L E X  Number  Calculator ***\n For >> X :\n ";
	cout << " Choose Complex Number Form :\n   1 >> rec \n   2 >> pol\n   ";
	int t, s;
	cin >> t;
	if (t == 1)
	{
		cout << "   X(real),X(imag)= ";
		double i, j;
		cin >> i >> j;
		x.set_complex_rec(i, j);
	}
	else if (t == 2)
	{
		cout << "   X(magnetude),X(angel)= ";
		double i, j;
		cin >> i >> j;
		x.set_complex_pol(i, j);
	}
	else
	{
		cout << "invalid choice !\n";
		system("pause");
		return 0;
	}
	cout << endl << " For >> Y :\n";
	cout << "  Choose:\n   1 >> rec \n   2 >> pol\n   ";
	cin >> s;
	if (s == 1)
	{
		cout << "   Y(real),Y(imag)= ";
		double i, j;
		cin >> i >> j;
		y.set_complex_rec(i, j);
	}
	else if (s == 2)
	{
		cout << "   Y(magnetude),Y(angel)= ";
		double i, j;
		cin >> i >> j;
		y.set_complex_pol(i, j);
	}
	else
	{
		cout << "invalid choice !\n";
		system("pause");
		return 0;
	}
	cout << "\n********************************************\n";
	//*******************************************
	cout << " X(rec) = " << (x.rec()) << "\n X(pol) = " << (x.pol()) << endl;
	cout << " Y(rec) = " << (y.rec()) << "\n Y(pol) = " << (y.pol()) << endl << endl;
	cout << " (x+y) = " << (x + y) << "   or    " << (x + y).pol() << endl;
	cout << " (x-y) = " << (x - y) << "   or    " << ((x - y).pol()) << endl;
	cout << " (x*y) = " << (x*y) << "   or    " << ((x*y).pol()) << endl;
	cout << " (x/y) = " << (x / y) << "   or    " << ((x / y).pol()) << endl << " Done..!" << endl;
	system("pause");
}
