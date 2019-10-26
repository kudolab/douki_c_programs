/* --- icfft ---*/

void ifft(x, y, m)
        double x[], y[];
        int m;

{
    int i, n;
    double fn;
    n = 1 << m;
    fn = n;
    for (i = 0; i < n; i++) y[i] = -y[i];
    fft(x, y, m);
    for (i = 0; i < n; i++) {
        x[i] /= fn;
        y[i] = -y[i] / fn;
    }
}

void idft(double *x, double *y, int L) {
    int i;
    for (i = 0; i < L; i++) y[i] = -y[i];
    dft(x, y, L);
    for (i = 0; i < L; i++) {
        x[i] = x[i] / (double) L;
        y[i] = y[i] / (double) L;
    }
}
