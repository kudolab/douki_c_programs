//
// Created by Tetsu Takizawa on 2019/11/16.
//

#ifndef DOUKI_C_PROGRAMS_FILELIB_OSX_H
#define DOUKI_C_PROGRAMS_FILELIB_OSX_H

int AnyFile_error(int n);;

int style(char *name);;

int lenfile(char *name);

int read_DSAfile(char *name, double *data, int len);

int read_DFAfile(char *name, double *data, int len);

int read_DDAfile(char *name, double *data, int len);

int read_DSBfile(char *name, double *data, int len);

int read_DFBfile(char *name, double *data, int len);

int read_DDBfile(char *name, double *data, int len);

int AnyFileRead(char *name, double *data, int len);

int write_DSAfile(char *name, double *data, int len);

int write_DSBfile(char *name, double *data, int len);

int write_DFBfile(char *name, double *data, int len);

int write_DDBfile(char *name, double *data, int len);

int AnyFileWrite(char *name, double *data, int len);

#endif //DOUKI_C_PROGRAMS_FILELIB_OSX_H
