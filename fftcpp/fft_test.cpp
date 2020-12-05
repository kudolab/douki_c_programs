#include <fft.h>
#include <Array2D.h>
#include <vector>
int main(int argc, char *argv[]){
    Array2D a,b;
    if(argc > 1){
        a.read(argv[1]);
        b.set(a.rows,2*a.columns);
        if(a.columns >= 2){
            std::vector<Complex> array(a.rows);
            for(int i=0;i<a.rows;i++){
                array[i].real(a[i][0]);
                array[i].imag(a[i][1]);
            }
            fft(array);
            for(int i=0;i<b.rows;i++){
                b[i][0] = array[i].real();
                b[i][1] = array[i].imag();
            }
            for(int i=0;i<a.rows;i++){
                array[i].real(a[i][0]);
                array[i].imag(a[i][1]);
            }
            fft_pf(array);
            for(int i=0;i<b.rows;i++){
                b[i][2] = array[i].real();
                b[i][3] = array[i].imag();
            }

            std::streambuf *buf;
            if(argc > 2){
                buf = std::ofstream(argv[2]).rdbuf();
            }else{
                buf = std::cout.rdbuf();
            }
            std::ostream os(buf);
            b.print(os);
        }
    }else{
        std::cout << "usage : " << argv[0] << " [input file] [output file]\n";
    }
}