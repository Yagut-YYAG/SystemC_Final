#ifndef NAND_H
#define NAND_H

#include <systemc.h>


SC_MODULE(nand){
   sc_in<bool> A, B;
   sc_out<bool> Z;

   SC_CTOR(nand): A("A"), B("B"), Z("Z"){
    SC_METHOD(process);
    sensitive <<  A << B;
   } 
    void process(){
        Z.write(!(A.read() && B.read()));
    }
};

#endif
