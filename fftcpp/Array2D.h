#ifndef ARRAY2D_H
#define ARRAY2D_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <string.h>
#include <sys/stat.h>

struct Array2D{
    struct ReadOptions{
        enum {automatic=-1};
        int rows;
        int columns;
        int rowOffset;
        int columnOffset;
        std::list<std::string> lineSeparators;
        std::list<std::string> fieldSeparators;
        bool repeatedSeparators;
        bool ignoreEmptyLines;

        ReadOptions();
    };
    enum precision{p_double,p_float};
    double **data;
    int rows;
    int columns;

    Array2D();
    Array2D(int,int);
    Array2D(const Array2D&);
    Array2D(Array2D&&);
    Array2D& operator=(const Array2D &array);
    Array2D& operator=(Array2D &&array);
    virtual ~Array2D();

    void set(int rows, int columns);
    void clear();
    void print();
    void print(const char *fileName);
    void print(std::ostream &os);
    void exportBMAT(const char *fileName,precision p);
    Array2D& read(const char *fileName, ReadOptions &options);
    Array2D& read(const char *fileName);
    double interpolate(double x);
    double min();
    double minRow(int row);
    double minColumn(int column);
    double*& operator[] (const int index);
private:
    struct Matcher{
        Matcher(std::list<std::string>&);
        ~Matcher();
        void clear();
        int count(char *str,bool repeatedSeparators);
        char *replace(char *p, char c);
        char *match(char *p);
        char *tokenize(char **str,bool repeatedSeparators);
        void tokenize(char *str,std::list<char*> &list,bool repeatedSeparators);
        size_t size;
        const char **list[2];
    };
};
#endif
