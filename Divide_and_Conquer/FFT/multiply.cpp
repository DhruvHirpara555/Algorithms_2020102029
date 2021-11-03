#include"FFT.hpp"
#include<iostream>


// fuction to append zeros to the end of the array to make it of power of 2
void resize(std::vector<com> &a, int old, int nnew) {

    for (int i = old; i < nnew; i++)
    {
        a.push_back(com(0, 0));
    }

}

// fuction to multiply two arrays/vectors representing two polynomials
// to multiply two polynomials, we need to convolute the vector of  the coefficients of the polynomials
// formula for convolution is given by
// ans = IFFT(FFT(a) * FFT(b))
// where IFFT is the inverse FFT and FFT is the FFT
std::vector<double> multiply(std::vector<double> &a, std::vector<double> &b) {
    int n = 1;
    while(a.size() + b.size() > n)
    {
        n= n<<1;
    }
    std::vector<com> val_a(a.size()), val_b(b.size()), val_c(n);

    for (int i = 0; i < a.size(); i++) {
        val_a[i] = a[i];
    }
    for (int i = 0; i < b.size(); i++) {
        val_b[i] = b[i];
    }
    resize(val_a, a.size(), n);
    resize(val_b, b.size(), n);

    val_a = FFT(val_a, 1);
    val_b = FFT(val_b, 1);

    for (int i = 0; i < n; i++) {
        val_c[i] = val_a[i] * val_b[i];
    }
    std::vector<double> c(n);
    val_c = FFT(val_c, -1);
    for (int i = 0; i < n; i++) {
        c[i] = val_c[i].real();
    }
    return c;
}

int main()
{
    std::vector<double> a = {1.12,2.23,3.34,4.567,5,6,7,8,9,10};
    std::vector<double> b = {1.12,2.23,3.34,4.567,5,6,7,8,9,10};
    std::vector<double> c = multiply(a,b);
    for(int i=0;i<(a.size()+b.size()-1);i++)
    {
        std::cout<<c[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
