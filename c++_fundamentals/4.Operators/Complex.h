#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    public:
        Complex(double real, double imag);
        Complex operator + (const Complex& obj) const;
        bool operator < (const Complex& obj) const;
        bool operator < (double value) const;
        friend bool operator < (double value, const Complex& obj); // Friend function declaration, not a member of the class (same as creating a free function below the class)
        Complex operator - (const Complex& obj) const;
        double GetReal() const;
        double GetImaginary() const;

    private:
        double real;
        double imag;
};

// bool operator < (double value, const Complex& obj); // Free function declaration, not a member of the class (same as creating a friend function above the class)

#endif // COMPLEX_H