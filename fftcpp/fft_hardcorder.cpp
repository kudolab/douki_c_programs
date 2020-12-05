#include <iostream>
#include <cmath>

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

int main(int argc, char *argv[]) {
    FILE *fp;
    char *fileout;
    int i, j, k;
    int n, p, q;
    int flag = 0;
    if (argc < 3) {
        printf("usage : %s [outputfile] [number]\n", argv[0]);
        return -1;
    }
    n = atoi(argv[2]);

    fp = fopen(argv[1], "w");
    fprintf(fp, "#ifndef FFT_HARDCORD_H\n");
    fprintf(fp, "#define FFT_HARDCORD_H\n");
    fprintf(fp, "#include <vector>\n");
    fprintf(fp, "using Complex = std::complex<double>;\n");

    fprintf(fp, "#define FFT_HARDCORD_SIZE %d\n", n);
    fprintf(fp, "inline void fft_hardcord(T &array,int size,int n,int sign){\n\n");
    fprintf(fp, "int m = size/n;");
    fprintf(fp, "switch(m){\n");
    fprintf(fp, "\t  case 1:\n");
    fprintf(fp, "\t\t break;\n");
    for (i = 2; i <= n; i++) {
        fprintf(fp, "\t  case %d:\n", i);
        fprintf(fp, "\t\tfor(int i=0;i<n;i++){\n");
        for (j = 0; j < i; j++) {
            fprintf(fp, "\t\t\tdouble r%d = ", j);
            flag = 0;
            for (k = 0; k < i; k++) {
                p = (k * j) % i;
                q = i;
                if (p == 0) {
                    if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                    fprintf(fp, "array[i*%d+%d].real()", i, k);
                    continue;
                }
                if (q % p == 0) {
                    if (q / p == 2) {
                        if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                        fprintf(fp, "(-array[i*%d+%d].real())", i, k);
                        continue;
                    }
                    if (q / p == 4) {
                        continue;
                    }
                }
                if (q % (q - p) == 0) {
                    if (q / (q - p) == 4) {
                        continue;
                    }
                }
                if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                fprintf(fp, "(%.14e)*(array[i*%d+%d].real())", cos(2 * M_PI * p / q), i, k);
            }
            fprintf(fp, "\n\t\t\t");
            flag = 0;
            for (k = 0; k < i; k++) {
                p = (k * j) % i;
                q = i;
                if (p == 0) {
                    continue;
                }
                if (q % p == 0) {
                    if (q / p == 2) {
                        continue;
                    }
                    if (q / p == 4) {
                        if (!flag) {
                            flag = 1;
                            fprintf(fp, " + ");
                        }
                        else { fprintf(fp, " + "); }
                        fprintf(fp, "(-sign)*(array[i*%d+%d].imag())", i, k);
                        continue;
                    }
                }
                if (q % (q - p) == 0) {
                    if (q / (q - p) == 4) {
                        if (!flag) {
                            flag = 1;
                            fprintf(fp, " + ");
                        }
                        else { fprintf(fp, " + "); }
                        fprintf(fp, "sign*(array[i*%d+%d].imag())", i, k);
                        continue;
                    }
                }
                if (!flag) {
                    flag = 1;
                    fprintf(fp, " + ");
                }
                else { fprintf(fp, " + "); }
                fprintf(fp, "(-sign)*(%.14e)*(array[i*%d+%d].imag())", sin(2 * M_PI * p / q), i, k);
            }
            fprintf(fp, ";\n");
        }
        for (j = 0; j < i; j++) {
            fprintf(fp, "\t\t\tdouble i%d = ", j);
            flag = 0;
            for (k = 0; k < i; k++) {
                p = (k * j) % i;
                q = i;
                if (p == 0) {
                    continue;
                }
                if (q % p == 0) {
                    if (q / p == 2) {
                        continue;
                    }
                    if (q / p == 4) {
                        if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                        fprintf(fp, "sign*(array[i*%d+%d].real())", i, k);
                        continue;
                    }
                }
                if (q % (q - p) == 0) {
                    if (q / (q - p) == 4) {
                        if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                        fprintf(fp, "(-sign)*(array[i*%d+%d].real())", i, k);
                        continue;
                    }
                }
                if (!flag) { flag = 1; } else { fprintf(fp, " + "); }
                fprintf(fp, "sign*(%.14e)*(array[i*%d+%d].real())", sin(2 * M_PI * p / q), i, k);
            }
            fprintf(fp, "\n\t\t\t");
            flag = 0;
            for (k = 0; k < i; k++) {
                p = (k * j) % i;
                q = i;
                if (p == 0) {
                    if (!flag) {
                        flag = 1;
                        fprintf(fp, " + ");
                    }
                    else { fprintf(fp, " + "); }
                    fprintf(fp, "(array[i*%d+%d].imag())", i, k);
                    continue;
                }
                if (q % p == 0) {
                    if (q / p == 2) {
                        if (!flag) {
                            flag = 1;
                            fprintf(fp, " + ");
                        }
                        else { fprintf(fp, " + "); }
                        fprintf(fp, "(-array[i*%d+%d].imag())", i, k);
                        continue;
                    }
                    if (q / p == 4) {
                        continue;
                    }
                }
                if (q % (q - p) == 0) {
                    if (q / (q - p) == 4) {
                        continue;
                    }
                }
                if (!flag) {
                    flag = 1;
                    fprintf(fp, " + ");
                }
                else { fprintf(fp, " + "); }
                fprintf(fp, "(%.14e)*(array[i*%d+%d].imag())", cos(2 * M_PI * p / q), i, k);
            }
            fprintf(fp, ";\n");
        }
        for (int j = 0; j < i; j++) {
            fprintf(fp, "\t\t\tarray[i*%d+%d].real(r%d);\n", i, j, j);
            fprintf(fp, "\t\t\tarray[i*%d+%d].imag(i%d);\n", i, j, j);
        }
        fprintf(fp, "\t\t}\n");
        fprintf(fp, "\t\tbreak;\n");
    }
    fprintf(fp, "}\n");
    fprintf(fp, "\n};\n");
    fprintf(fp, "#endif\n");
    fclose(fp);
    return 0;
}