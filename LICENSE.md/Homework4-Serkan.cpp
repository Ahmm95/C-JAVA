//ComplexNumber.h

#ifndef COMPLEXNUMBER_H

#define COMPLEXNUMBER_H

#include <iostream>

using namespace std;

class ComplexNumber

{

public:

    ComplexNumber();

    ComplexNumber(double real, double imaginary);    

    ComplexNumber& operator=(const ComplexNumber& rhs);    

    double Magnitude();

    void SetReal(double realValue);

    void SetImaginary(double imaginaryValue);

friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);

friend ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);

friend ostream& operator<<(ostream& os, const ComplexNumber& cNum);

private:

    double _real, _imag;

};

#endif

File Name: ComplexNumber.cpp

//ComplexNumber.cpp

#include <iostream>

#include <cstdlib>

#include "ComplexNumber.h"

using namespace std;

//Defaukt constructor

ComplexNumber::ComplexNumber()

{

     _real=0;

     _imag=0;

}

//Overloaded constructor

ComplexNumber::ComplexNumber(double real, double imaginary)

{

     _real=real;

     _imag=imaginary;

}

//Overloading = operator

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs)

{

     _real=rhs._real;

     _imag=rhs._imag;

     return *this;

}

//method return the magnitude of the complex number

double ComplexNumber::Magnitude()

{

     double sq=_real*_real+_imag*_imag;

     return sqrt(static_cast<double> (sq));

}

//Method sets the real part

void ComplexNumber::SetReal(double realValue)

{

     _real=realValue;

}

//Method sets the imaginary part

void ComplexNumber::SetImaginary(double imaginaryValue)

{

     _imag=imaginaryValue;

}

//Method performs the addition of two complex numbers

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs)

{

     ComplexNumber cp;

     cp._real=lhs._real+rhs._real;

     cp._imag=lhs._imag+rhs._imag;

     return cp;

}

//Method performs the multiplication of two complex numbers

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs)

{

     ComplexNumber cp;

     cp._real=lhs._real*rhs._real -lhs._imag*rhs._imag;

     cp._imag=lhs._real*rhs._imag+rhs._real*lhs._imag;

     return cp;

}

//Displaying complex number cNum

ostream& operator<<(ostream& os, const ComplexNumber& cNum)

{

     os<<cNum._real<<"+"<<cNum._imag<<"i";

     return os;

}

File Name: Mandelbrot.h

//Mandelbrot.h

#ifndef MANDELBROT_H

#define MANDELBROT_H

#include "ComplexNumber.h"

class Mandelbrot

{

public:

    Mandelbrot(int width, int height);

    ~Mandelbrot();

    void Draw();

    bool Compute(const ComplexNumber z0);

private:

    int _width, _height;

    bool* _data;   

};

#endif

File Name: Mandelbrot.cpp

//Mandelbrot.cpp

#include <iostream>

#include "Mandelbrot.h"

using namespace std;

const int MAX_ITERATIONS = 1000;

Mandelbrot::Mandelbrot(int width, int height)

{

    _width = width;

    _height = height;

}

Mandelbrot::~Mandelbrot()

{

    // Only needed for completeness

}

void Mandelbrot::Draw()

{

    double x, y;

    ComplexNumber z0; // Set up a complex number

for (int row = 0; row < _height; row++) // Iterate over the rows of the image

    {

        z0.SetImaginary((4.0 * row) / _height - 2.0);

for (int col = 0; col < _width; col++)// Iterate over the column of the image

        {

            z0.SetReal((4.0 * col) / _width - 2.0);

if (Compute(z0)) // Determine if this point is in the set

            {

                   cout << "*"; // And draw it as such

            }

            else

                   cout << ".";

          }

        cout << endl;

    }

    cout << endl;

}

bool Mandelbrot::Compute(const ComplexNumber z0)

{

    ComplexNumber z = z0;

    int iterations = 0;

    while (z.Magnitude() < 2 && iterations < MAX_ITERATIONS)

    {

        z = z*z + z0;

        iterations++;

    }

    return z.Magnitude() < 2;

}

File Name: Hw4Main.cpp

//Hw4Main.cpp

#include <iostream>

#include "Mandelbrot.h"

#include "ComplexNumber.h"

using namespace std;

int main()

{

    ComplexNumber cNum(1.0, 1.0);

    ComplexNumber aNum(2.0, 2.0);

    ComplexNumber result = aNum * cNum;

    cout << aNum << " " << cNum << endl;

    cout << result << endl;

    cout << aNum * cNum << endl;

    cout << aNum + cNum << endl;

    Mandelbrot myFractal(100, 60);

    myFractal.Draw();

    system("pause");

    return 0;

}
