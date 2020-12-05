#include <fft.h>
#include <iostream>

void dft(std::vector <Complex> &array) { dft(array, array.size()); }

template void dft(std::vector <Complex> &array, int size);

template void dft(Complex *&array, int size);

template void dft(
        std::vector <Complex> &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n
);

template void dft(
        Complex *&array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n
);

template<typename T>
void dft(
        T &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n
) {
    int m = size / n;
    for (int i = 0; i < size; i++) {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                //std::cout << std::floor(size*std::arg(omega[((j*k)%m)*n])/(2*M_PI)) << "\t";
                temp[i * m + j] += array[i * m + k] * omega[((j * k) % m) * n];
            }
            //std::cout << "\n";
        }
        //std::cout << "\n";
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

template<typename T>
void dft(T &array, int size) {
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, omega.size()));
        omega[i].imag(-fft_sin(i, omega.size()));
    }
    dft(array, temp, omega, size, 1);
}

template<typename T>
void idft(T &array, int size) {
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, omega.size()));
        omega[i].imag(fft_sin(i, omega.size()));
    }
    dft(array, temp, omega, size, -1);
    for (int i = 0; i < size; i++) { array[i] /= size; }
}

template<typename T>
void fft2(
        T &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size
) {
    int n = 1;
    for (; n < size; n <<= 1) {
        int m = size / n;
        int q = m >> 1;
        /*permutation*/
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < q; k++) {
                temp[i * m + k] = array[i * m + 2 * k];
                temp[i * m + q + k] = array[i * m + 2 * k + 1];
            }
        }
        for (int i = 0; i < size; i++) { array[i] = temp[i]; }
    }
    for (; n > 1; n >>= 1) {
        int m = size / n;
        int q = n >> 1;
        int r = size / q;
        /*adding up with twiddle factors*/
        for (int i = 0; i < size; i++) { temp[i] = 0; }
        for (int i = 0; i < q; i++) {
            for (int k = 0; k < m; k++) {
                temp[2 * m * i + k] += array[2 * m * i + k];
                temp[2 * m * i + m + k] += array[2 * m * i + k];
                temp[2 * m * i + k] += array[2 * m * i + m + k] * omega[(k % r) * q];
                temp[2 * m * i + m + k] += array[2 * m * i + m + k] * omega[((m + k) % r) * q];
            }
        }
        for (int i = 0; i < size; i++) { array[i] = temp[i]; }
    }
}

void fft2(
        std::vector <Complex> &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega
) {
    fft2(array, temp, omega, array.size());
}

template<typename T>
void fft_prime(T &array, int size, int n, int sign) {
    int p = size / n;
    int len = p - 1;
    bool power2 = true;
    int i = 0;
    for (; len > 1; len >>= 1, i++) {
        if (len & 1) { power2 = false; }
    }
    len = power2 ? p - 1 : (1 << (i + 2));
    /*
    std::cout << "p-1 : " << p-1 << "\n";
    std::cout << "len : " << len << "\n";
    */
    int pad = len - (p - 1);
    int g = primePrimitiveRoot(p);
    int ig = powerMod(g, p - 2, p);
    std::vector <Complex> data(len), temp(len), omega(len), omega2(len);
    for (int i = 0; i < len; i++) {
        omega[i].real(fft_cos(i, len));
        omega[i].imag(-fft_sin(i, len));
        omega2[i].real(fft_cos(powerMod(ig, i % (p - 1), p), p));
        omega2[i].imag(sign * fft_sin(powerMod(ig, i % (p - 1), p), p));
    }
    fft2(omega2, temp, omega);
    for (int i = 0; i < n; i++) {
        data[0] = array[i * p + 1];
        for (int j = 1; j < len; j++) {
            if (j <= pad) {
                data[j] = 0;
            } else {
                data[j] = array[i * p + powerMod(g, j - pad, p)];
            }
        }
        /*===Convolution theorem===*/
        fft2(data, temp, omega);
        for (int j = 0; j < len; j++) { temp[j] = data[j] * omega2[j]; }
        for (int j = 0; j < len; j++) {
            data[j] = temp[j];
            omega[j].imag(-omega[j].imag());
        }
        fft2(data, temp, omega);
        /*add array[i*p] term*/
        for (int j = 0; j < len; j++) {
            data[j].real(data[j].real() / len + array[i * p].real());
            data[j].imag(data[j].imag() / len + array[i * p].imag());
            //data[j] = data[j]/(Complex(len)) + array[i*p];
            //omega[j].imag(-omega[j].imag());
        }
        /*===Convolution theorem end===*/

        /*DC term*/
        temp[0] = 0;
        for (int j = 0; j < p; j++) { temp[0] += array[i * p + j]; }
        array[i * p] = temp[0];

        /*non-DC term*/
        for (int j = 0; j < p - 1; j++) { array[i * p + powerMod(ig, j, p)] = data[j]; }
    }
}

template<typename T>
void fft(
        T &array,
        int size,
        int sign
) {
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, size));
        omega[i].imag(sign * fft_sin(i, size));
    }
    int primes[32];
    int np = 0;
    int n = 1;
    for (;;) {
        int m = size / n;
        int p = 2 + (m & 1);
        for (; p * p <= m; p += 2) {
            if (m % p == 0) {
                /*m is divisible by p*/
                int q = m / p;
                /*permutation*/
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < p; j++) {
                        for (int k = 0; k < q; k++) {
                            temp[i * m + q * j + k] = array[i * m + p * k + j];
                        }
                    }
                }
                for (int i = 0; i < size; i++) {
                    array[i] = temp[i];
                }
                primes[np++] = p;
                n *= p;
                if (q <= FFT_HARDCORD_SIZE) { break; }
                goto next;
            }
        }
        break;
        next:;
    }
    /*bottom of recursion*/
    /*perform dft on n sub-arrays*/
    {
        if (size / n <= FFT_HARDCORD_SIZE) {
            fft_hardcord(array, size, n, sign);
        } else if (size / n <= FFT_PRIME_THRESHOLD) {
            dft(array, temp, omega, size, n);
        } else {
            fft_prime(array, size, n, sign);
        }
    }
    /*sum up with twiddle factors*/
    for (int h = np - 1; h >= 0; h--) {
        int m = size / n;
        int p = primes[h];
        int q = n / p;
        int r = size / q;

        for (int i = 0; i < size; i++) { temp[i] = 0; }
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < p; l++) {
                        temp[i * p * m + (j * m + k)] +=
                                array[i * p * m + (l * m + k)] * omega[(l * (j * m + k) % r) * q];
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) { array[i] = temp[i]; }
        n = q;
    }
}

void fft(std::vector <Complex> &array) { fft(array, array.size()); }

template void fft(std::vector <Complex> &array, int size, int sign);

template void fft(std::vector <Complex> &array, int size);

template void fft(Complex *&array, int size, int sign);

template void fft(Complex *&array, int size);

template<typename T>
void fft(T &array, int size) { fft(array, size, -1); }

template<typename T>
void ifft(T &array, int size) {
    fft(array, size, 1);
    for (int i = 0; i < size; i++) { array[i] /= size; }
}

template<typename T>
void fft2d(T &array, int row, int column, int sign) {
    int size = row * column;
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, size));
        omega[i].imag(sign * fft_sin(i, size));
    }

    int primes[32];
    int np = 0;
    int n = row;
    for (;;) {
        int m = size / n;
        int p = 2 + (m & 1);
        for (; p * p <= m; p += 2) {
            if (m % p == 0) {
                /*m is divisible by p*/
                int q = m / p;
                /*permutation*/
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < p; j++) {
                        for (int k = 0; k < q; k++) {
                            temp[i * m + q * j + k] = array[i * m + p * k + j];
                        }
                    }
                }
                for (int i = 0; i < size; i++) {
                    array[i] = temp[i];
                }
                primes[np++] = p;
                n *= p;
                if (q <= FFT_HARDCORD_SIZE) { break; }
                goto next1;
            }
        }
        break;
        next1:;
    }
    /*bottom of recursion*/
    /*perform dft on n sub-arrays*/
    {
        if (size / n <= FFT_HARDCORD_SIZE) {
            fft_hardcord(array, size, n, sign);
        } else if (size / n <= FFT_PRIME_THRESHOLD) {
            dft(array, temp, omega, size, n);
        } else {
            fft_prime(array, size, n, sign);
        }
    }
    /*integrate array elements multiplied by twiddle factors*/
    for (int h = np - 1; h >= 0; h--) {
        int m = size / n;
        int p = primes[h];
        int q = n / p;
        int r = size / q;

        for (int i = 0; i < size; i++) { temp[i] = 0; }
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < p; l++) {
                        temp[i * p * m + (j * m + k)] +=
                                array[i * p * m + (l * m + k)] * omega[(l * (j * m + k) % r) * q];
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) { array[i] = temp[i]; }
        n = q;
    }

    /*transpose*/
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            temp[j * row + i] = array[i * column + j];
        }
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    np = 0;
    n = column;
    for (;;) {
        int m = size / n;
        int p = 2 + (m & 1);
        for (; p * p <= m; p += 2) {
            if (m % p == 0) {
                /*m is divisible by p*/
                int q = m / p;
                /*permutation*/
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < p; j++) {
                        for (int k = 0; k < q; k++) {
                            temp[i * m + q * j + k] = array[i * m + p * k + j];
                        }
                    }
                }
                for (int i = 0; i < size; i++) {
                    array[i] = temp[i];
                }
                primes[np++] = p;
                n *= p;
                if (q <= FFT_HARDCORD_SIZE) { break; }
                goto next2;
            }
        }
        break;
        next2:;
    }
    /*bottom of recursion*/
    /*perform dft on n sub-arrays*/
    {
        if (size / n <= FFT_HARDCORD_SIZE) {
            fft_hardcord(array, size, n, sign);
        } else if (size / n <= FFT_PRIME_THRESHOLD) {
            dft(array, temp, omega, size, n);
        } else {
            fft_prime(array, size, n, sign);
        }
    }
    /*sum up with twiddle factors*/
    for (int h = np - 1; h >= 0; h--) {
        int m = size / n;
        int p = primes[h];
        int q = n / p;
        int r = size / q;

        for (int i = 0; i < size; i++) { temp[i] = 0; }
        for (int i = 0; i < q; i++) {
            for (int j = 0; j < p; j++) {
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < p; l++) {
                        temp[i * p * m + (j * m + k)] +=
                                array[i * p * m + (l * m + k)] * omega[(l * (j * m + k) % r) * q];
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) { array[i] = temp[i]; }
        n = q;
    }

    /*transpose*/
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            temp[j * column + i] = array[i * row + j];
        }
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

template<typename T>
void fft2d(T &array, int row, int column) { fft2d(array, row, column, -1); }

template<typename T>
void ifft2d(T &array, int row, int column) {
    fft2d(array, row, column, 1);
    for (int i = 0; i < row * column; i++) { array[i] /= (row * column); }
}

void ifft(std::vector <Complex> &array) { ifft(array, array.size()); }

void idft(std::vector <Complex> &array) { idft(array, array.size()); }

double fft_cos(int n, int m) {
    if (n == 0) { return 1; }
    if (n == m) {/*2 Pi*/return 1; }
    if (m % n == 0) {
        if (m / n == 2) {/*Pi*/return -1; }
        if (m / n == 4) {/*Pi/2*/return 0; }
    }
    if (m % (m - n) == 0) {
        if (m / (m - n) == 4) {/*3 Pi/2*/return 0; }
    }
    return cos(2 * M_PI * n / m);
}

double fft_sin(int n, int m) {
    if (n == 0) { return 0; }
    if (n == m) {/*2 Pi*/return 0; }
    if (m % n == 0) {
        if (m / n == 2) {/*Pi*/return 0; }
        if (m / n == 4) {/*Pi/2*/return 1; }
    }
    if (m % (m - n) == 0) {
        if (m / (m - n) == 4) {/*3 Pi/2*/return -1; }
    }
    return sin(2 * M_PI * n / m);
}

int eulerPhi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) { n /= i; }
            res -= res / i;
        }
    }
    if (n > 1) {
        res -= res / n;
    }
    return res;
}

int primitiveRoot(int n) {
    return primitiveRoot(n, eulerPhi(n));
}

int primitiveRoot(int n, int phi) {
    int i, t;
    std::vector<int> list;

    for (i = 2, t = phi; i * i <= t; i++) {
        if (t % i == 0) {
            list.push_back(i);
            do {
                t /= i;
            } while (t % i == 0);
        }
    }

    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
        *it = phi / (*it);
    }

    for (i = 2; i <= phi; i++) {
        for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
            if (powerMod(i, *it, phi) == 1) {
                goto loopend;
            }
        }
        break;
        loopend:;
    }
    return i;
}

int primePrimitiveRoot(int p) {
    int i, t;
    std::vector<int> list;

    for (i = 2, t = p - 1; i * i <= t; i++) {
        if (t % i == 0) {
            list.push_back(i);
            do {
                t /= i;
            } while (t % i == 0);
        }
    }

    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
        *it = (p - 1) / (*it);
    }
    for (i = 2; i <= p - 1; i++) {
        for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
            if (powerMod(i, *it, p) == 1) {
                goto loopend;
            }
        }
        break;
        loopend:;
    }
    return i;
}

int powerMod(int a, int b, int m) {
    int i;
    for (i = 1; b; b >>= 1) {
        if (b & 1) {
            i = (i * a) % m;
        }
        a = (a * a) % m;
    }
    return i;
}

template void ifft(std::vector <Complex> &array, int size);

template void fft2d(std::vector <Complex> &array, int row, int column);

template void ifft2d(std::vector <Complex> &array, int row, int column);

template void idft(std::vector <Complex> &array, int size);

template void fft2(
        std::vector <Complex> &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size
);

template void fft_prime(std::vector <Complex> &array, int size, int n, int sign);

template void fft2d(std::vector <Complex> &array, int row, int column, int sign);

template void ifft(Complex *&array, int size);

template void fft2d(Complex *&array, int row, int column);

template void ifft2d(Complex *&array, int row, int column);

template void idft(Complex *&array, int size);

template void fft2(
        Complex *&array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size
);

template void fft_prime(Complex *&array, int size, int n, int sign);

template void fft2d(Complex *&array, int row, int column, int sign);

std::vector <std::vector<int>> factorInteger(int size) {
    std::vector<int> primes;
    int n = 1;
    for (;;) {
        int m = size / n;
        int p = 2 + (m & 1);
        for (; p * p <= m; p += 2) {
            if (m % p == 0) {
                /*m is divisible by p*/
                primes.push_back(p);
                n *= p;
                goto next;
            }
        }
        break;
        next:;
    }
    primes.push_back(size / n);
    return tally(primes);
}

std::vector <std::vector<int>> tally(std::vector<int> list) {
    std::vector <std::vector<int>> res;
    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++) {
        for (std::vector < std::vector < int >> ::iterator it2 = res.begin(); it2 != res.end();
        it2++){
            if (it2->front() == *it) {
                it2->back() += 1;
                goto loopend;
            }
        }
        res.push_back(std::vector < int > {*it, 1});
        loopend:;
    }
    return res;
}

void print(std::vector <std::vector<int>> &list) {
    std::cout << "{";
    for (std::vector < std::vector < int >> ::iterator it = list.begin(); it != list.end();
    it++){
        std::cout << "{";
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++) {
            std::cout << *it2;
            if (std::next(it2) != it->end()) { std::cout << ","; }
        }
        std::cout << "}";
        if (std::next(it) != list.end()) { std::cout << ","; }
    }
    std::cout << "}\n";
}

int power(int a, int b) {
    int res = 1;
    for (int i = 0; i < b; i++) { res *= a; }
    return res;
}

void fft_pf(std::vector <Complex> &array) { fft_pf(array, array.size()); }

template<typename T>
void fft_pf(T &array, int size) { fft_pf(array, size, -1); }

template void fft_pf(std::vector <Complex> &array, int size);

template void fft_pf(Complex *&array, int size);

template void fft_pf(std::vector <Complex> &array, int size, int sign);

template void fft_pf(Complex *&array, int size, int sign);

template<typename T>
void fft_pf(T &array, int size, int sign) {
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, size));
        omega[i].imag(sign * fft_sin(i, size));
    }
    fft_pf(array, temp, omega, size, sign, factorInteger(size), 0);
}

template<typename T>
void fft_pf(
        T &array,
        std::vector <Complex> temp,
        std::vector <Complex> omega,
        int size,
        int sign,
        std::vector <std::vector<int>> list,
        int index
) {
    //print(list);
    if (index == list.size()) { return; }

    int nn = 1;
    for (int i = 0; i < index; i++) {
        nn *= power(list[i][0], list[i][1]);
    }
    int mm = size / nn;

    int n = power(list[index][0], list[index][1]);
    int m = mm / n;

    /*CRT mapping*/

    {
        for (int ii = 0; ii < nn; ii++) {
            int j = 0, k = 0;
            for (int i = 0; i < mm; i++, j++, k++) {
                if (j >= n) { j = 0; }
                if (k >= m) { k = 0; }
                temp[ii * mm + j + n * k] = array[ii * mm + i];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    /*===FFT2D===*/

    {
        //dft(array,temp,omega,size,size/n);
        fft_rec(array, temp, omega, size, size / n, sign);
    }

    /*transpose*/
    for (int ii = 0; ii < nn; ii++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[ii * mm + j + i * m] = array[ii * mm + i + j * n];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }

    {
        fft_pf(array, temp, omega, size, sign, list, index + 1);
    }

    /*===FFT2D end===*/

    /*good mapping*/

    {
        for (int ii = 0; ii < nn; ii++) {
            int i = 0;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++, i++) {
                    temp[ii * mm + (m * j + n * k) % mm] = array[ii * mm + i];
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

void fft_rec(std::vector <Complex> &array) { fft_rec(array, array.size()); }

template<typename T>
void fft_rec(T &array, int size) { fft_rec(array, size, -1); }

template void fft_rec(std::vector <Complex> &array, int size);

template void fft_rec(Complex *&array, int size);

template void fft_rec(std::vector <Complex> &array, int size, int sign);

template void fft_rec(Complex *&array, int size, int sign);

//template void fft_rec(std::vector<Complex> &array, int size, int sign);
//template void fft_rec(Complex* &array, int size, int sign);
template void fft_rec(
        std::vector <Complex> &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n,
        int sign
);

template void fft_rec(
        Complex *&array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n,
        int sign
);

template<typename T>
void fft_rec(T &array, int size, int sign) {
    std::vector <Complex> temp(size), omega(size);
    for (int i = 0; i < size; i++) {
        omega[i].real(fft_cos(i, size));
        omega[i].imag(sign * fft_sin(i, size));
    }
    fft_rec(array, temp, omega, size, 1, sign);
}

template<typename T>
void fft_rec(
        T &array,
        std::vector <Complex> &temp,
        std::vector <Complex> &omega,
        int size,
        int n,
        int sign
) {
    int m = size / n;
    int p = 2 + (m & 1);

    for (; p * p <= m; p += 2) {
        if (m % p == 0) {
            /*m is divisible by p*/
            int q = m / p;
            /*permutation*/
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                    for (int k = 0; k < q; k++) {
                        temp[i * m + q * j + k] = array[i * m + p * k + j];
                    }
                }
            }
            for (int i = 0; i < size; i++) {
                array[i] = temp[i];
            }
            n *= p;
            m /= p;
            fft_rec(array, temp, omega, size, n, sign);
            q = n / p;
            int r = size / q;

            for (int i = 0; i < size; i++) { temp[i] = 0; }
            for (int i = 0; i < q; i++) {
                for (int j = 0; j < p; j++) {
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < p; l++) {
                            temp[i * p * m + (j * m + k)] +=
                                    array[i * p * m + (l * m + k)] * omega[(l * (j * m + k) % r) * q];
                        }
                    }
                }
            }
            for (int i = 0; i < size; i++) { array[i] = temp[i]; }
            return;
        }
    }
    /*bottom of recursion*/
    /*perform dft on n sub-arrays*/
    if (size / n <= FFT_HARDCORD_SIZE) {
        fft_hardcord(array, size, n, sign);
    } else if (size / n <= FFT_PRIME_THRESHOLD) {
        dft(array, temp, omega, size, n);
    } else {
        fft_prime(array, size, n, sign);
    }
}