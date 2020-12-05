#include <Array2D.h>

Array2D::Array2D(){
    this->rows=0;
    this->columns=0;
    this->data=nullptr;
}

Array2D::Array2D(int rows, int columns){
    this->set(rows,columns);
}

Array2D::Array2D(const Array2D &array){
    this->set(array.rows,array.columns);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            data[i][j] = array.data[i][j];
        }
    }
}

Array2D::Array2D(Array2D &&array){
    rows = array.rows;
    columns = array.columns;
    data = array.data;
}

Array2D& Array2D::operator=(const Array2D &array){
    Array2D tmp(array);
    *this = std::move(tmp);
    tmp.data=nullptr;
    return *this;
}

Array2D& Array2D::operator=(Array2D &&array){
    if(this==&array){
        return *this;
    }
    rows = array.rows;
    columns = array.columns;
    data = array.data;
    return *this;
}

Array2D::~Array2D(){
    this->clear();
}

void Array2D::set(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    data = new double*[rows];
    data[0] = new double[rows*columns];
    for(int i=1;i<rows;i++){
        data[i] = &(data[0][i*columns]);
    }
}

void Array2D::clear(){
    if(data){
        delete[] data[0];
        delete[] data;
        data = nullptr;
    }
}

void Array2D::print(){
    std::ostream os(std::cout.rdbuf());
    print(os);
}

void Array2D::print(const char *fileName){
    std::ostream os(std::ofstream(fileName).rdbuf());
    print(os);
}

void Array2D::print(std::ostream &os){
    os.precision(17);
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            os << std::fixed << data[i][j] << "\t";
        }
        os << "\n";
    }
}

void Array2D::exportBMAT(const char *fileName, Array2D::precision p){
    FILE *fp = fopen(fileName,"wb");
    if(!fp){std::cout << "exportBMAT : unable to open file " << fileName << "\n"; return;}
    fwrite(&p,sizeof(precision),1,fp);
    fwrite(&rows,sizeof(int),1,fp);
    fwrite(&columns,sizeof(int),1,fp);
    int w1;
    float *f;
    switch(p){
        case p_double:
            if((w1=fwrite(data[0],sizeof(double),rows*columns,fp))!=rows*columns){
                std::cout << "exportBMAT : tried to write " <<
                          rows*columns*sizeof(double) << " bytes, but " <<
                          w1*sizeof(double) << " bytes were written\n";
            }
            break;
        case p_float:
            f = new float[rows*columns];
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    f[i*columns+j] = data[i][j];
                }
            }
            if((w1=fwrite(f,sizeof(float),rows*columns,fp))!=rows*columns){
                std::cout << "exportBMAT : tried to write " <<
                          rows*columns*sizeof(float) << " bytes, but " <<
                          w1*sizeof(float) << " bytes were written\n";
            }
            delete[] f;
            break;
    }
    fclose(fp);
}

Array2D::ReadOptions::ReadOptions() :
        lineSeparators({"\r\n","\n","\r"}),
        fieldSeparators({"\t"," "})
{
    rows = ReadOptions::automatic;
    columns = ReadOptions::automatic;
    rowOffset = 0;
    columnOffset = 0;
    repeatedSeparators = true;
    ignoreEmptyLines = false;
}

Array2D& Array2D::read(const char *fileName, ReadOptions &options){
    struct stat st;
    size_t size;
    if(stat(fileName,&st)==0){size = st.st_size+1;}
    FILE *fp = fopen(fileName,"r");
    if(!fp){
        std::cout << "unable to open " << fileName << "\n";
        return *this;
    }
    setbuf(fp,NULL);
    char *buffer = new char[size];
    fread(buffer,1,size,fp);
    buffer[size-1] = '\0';
    fclose(fp);

    Matcher lineMatcher(options.lineSeparators);
    Matcher fieldMatcher(options.fieldSeparators);

    std::list<char*> listRow;
    lineMatcher.tokenize(buffer,listRow,options.repeatedSeparators);

    for(std::list<char*>::iterator it=listRow.begin();it!=listRow.end();it++){
        if(fieldMatcher.count(*it,options.repeatedSeparators)==0){
            *it = NULL;
        }
    }
    listRow.remove(NULL);

    rows = listRow.size();
    int rowOffset = options.rowOffset < 0 ?
                    rows + options.rowOffset :
                    options.rowOffset;

    if(options.rows == ReadOptions::automatic){
        if(rows < rowOffset){
            std::cout << "row offset " << rowOffset << "exceeds the row size " << rows << "\n";
            return *this;
        }
        rows = rows - rowOffset;
    }else{
        if(rows < options.rows + rowOffset){
            std::cout << "row size "<< options.rows <<
                      " + rowOffset " << rowOffset << " exceeds the row size of input " << rows << "\n";
            return *this;
        }
        rows = options.rows;
    }

    std::list<char*>::iterator it = listRow.begin();
    for(int i=0;it != listRow.end() && i<rowOffset;it++,i++){}

    columns = fieldMatcher.count(*it,options.repeatedSeparators);
    int columnOffset = options.columnOffset < 0 ?
                       columns + options.columnOffset :
                       options.columnOffset;

    if(options.columns == ReadOptions::automatic){
        if(columns < columnOffset){
            std::cout << "column offset " << columnOffset << "exceeds the column size " << rows << "\n";
            return *this;
        }
        columns = columns - columnOffset;
    }else{
        if(columns < options.columns + columnOffset){
            std::cout << "column size "<< options.columns <<
                      " + columnOffset " << columnOffset << " exceeds the column size of input " << columns << "\n";
            return *this;
        }
        columns = options.columns;
    }
    //std::cout << "rows : " << rows << std::endl;
    //std::cout << "columns : " << columns << "\n";

    this->set(rows,columns);

    for(int i=0;it!=listRow.end() && i<rows;it++,i++){
        char *p = *it;
        for(int j=0;j<columnOffset;j++){
            fieldMatcher.clear();
            fieldMatcher.tokenize(&p,options.repeatedSeparators);
        }
        for(int j=0;j<columns;j++){
            fieldMatcher.clear();
            //fieldMatcher.tokenize(&p,options.repeatedSeparators);
            data[i][j] = atof(fieldMatcher.tokenize(&p,options.repeatedSeparators));
        }
    }
    return *this;
}

Array2D& Array2D::read(const char *fileName){
    ReadOptions options;
    return read(fileName,options);
}

double Array2D::interpolate(double x){
    // assumes x data are in 0th column, y data are in 1th column;
    // assumes x data are sorted in increasing order.

    if(x < data[0][0]){
        return (x - data[0][0])*(data[1][1]-data[0][1])/(data[1][0]-data[0][0]) + data[0][1];
    }
    if(x > data[rows-1][0]){
        return (x - data[rows-1][0])*(data[rows-1][1]-data[rows-2][1])/(data[rows-1][0]-data[rows-2][0]) + data[rows-1][1];
    }

    int i=0;
    for(;i<rows && x >= data[i][0];i++){}
    return (x-data[i][0])*(data[i][1]-data[i-1][1])/(data[i][0]-data[i-1][0]) + data[i][1];
}

double*& Array2D::operator[] (const int index){
    return data[index];
}

double Array2D::min(){
    double min = data[0][0];
    for(int i=0;i<rows*columns;i++){
        if(min > data[0][i]){min = data[0][i];}
    }
    return min;
}

double Array2D::minRow(int row){
    double min = data[row][0];
    for(int i=0;i<columns;i++){
        if(min > data[row][i]){min = data[row][i];}
    }
    return min;
}

double Array2D::minColumn(int column){
    double min = data[0][column];
    for(int i=0;i<rows;i++){
        if(min > data[i][column]){min = data[i][column];}
    }
    return min;
}

Array2D::Matcher::Matcher(std::list<std::string> &list){
    size = list.size();
    this->list[0] = new const char*[size];
    this->list[1] = new const char*[size];
    int i=0;
    for(std::list<std::string>::iterator it=list.begin();
        it != list.end();
        it++,i++
            ){
        this->list[0][i] = this->list[1][i] = it->c_str();
    }
}
Array2D::Matcher::~Matcher(){
    delete[] list[0];
    delete[] list[1];
}

void Array2D::Matcher::clear(){
    for(int i=0;i<size;i++){list[1][i] = list[0][i];}
}

char *Array2D::Matcher::match(char *p){
    for(int i=0;i<size;i++){
        if(*list[1][i]==*p){
            list[1][i]++;
            if(*list[1][i]=='\0'){
                for(int j=0;j<size;j++){list[1][j] = list[0][j];}
                int len = strlen(list[0][i]);
                return p-len+1;
            }
        }else{
            list[1][i] = list[0][i];
        }
    }
    return NULL;
}

char *Array2D::Matcher::replace(char *p, char c){
    for(int i=0;i<size;i++){
        if(*list[1][i]==*p){
            list[1][i]++;
            if(*list[1][i]=='\0'){
                for(int j=0;j<size;j++){list[1][j] = list[0][j];}
                int len = strlen(list[0][i]);
                char *pp = p;
                for(;p-pp < len;pp--){*pp=c;}
                return pp+1;
            }
        }else{
            list[1][i] = list[0][i];
        }
    }
    return NULL;
}

int Array2D::Matcher::count(char *str,bool repeatedSeparators){
    int counter=0;
    char *p,*ps,*pe,*pm,*tail;
    tail = pe = strchr(str,'\0');
    for(ps=p=str;*p;p++){
        pm = this->match(p);
        if(pm){
            pe = pm;
            if(!repeatedSeparators || ps!=pe){++counter;}
            ps = p+1;
        }
    }
    if(*ps && ps < tail){counter++;}
    return counter;
}

char *Array2D::Matcher::tokenize(char **str,bool repeatedSeparators){
    char *p,*ps,*pe,*pm;
    pe = strchr(*str,'\0');
    for(ps=p=*str;*p;p++){
        pm = this->replace(p,'\0');
        if(pm){
            pe = pm;
            if(!repeatedSeparators || ps!=pe){
                *str = p+1; return ps;
            }
            ps = p+1;
        }
    }
    return ps;
}

void Array2D::Matcher::tokenize(char *str, std::list<char*> &list, bool repeatedSeparators){
    char *p,*ps,*pe,*pm,*tail;

    tail = pe = strchr(str,'\0');
    for(ps=p=str;*p;p++){
        pm = this->replace(p,'\0');
        if(pm){
            pe = pm;
            if(!repeatedSeparators || ps != pe){
                list.push_back(ps);
            }
            ps = p+1;
        }
    }
    if(*ps && ps < tail){list.push_back(ps);}
}