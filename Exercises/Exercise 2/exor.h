#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

SC_MODULE(exor){
    sc_in <bool> A,B;
    sc_out <bool> Z;
    sc_signal<bool> h1, h2, h3;
    nand nand_a, nand_b, nand_c, nand_d;

    SC_CTOR(exor):A("A"),B("B"),Z("Z"),nand_a("nand a"), nand_b("nand b"), nand_c("nand c"), nand_d("nand d"), h1("h1"), h2("h2"), h3("h3"){
        nand_a.A.bind(A);
        nand_a.B.bind(B);
        nand_a.Z.bind(h1);

        nand_b.A.bind(h1);
        nand_b.B.bind(B);
        nand_b.Z.bind(h3);

        nand_c.A.bind(A);
        nand_c.B.bind(h1);
        nand_c.Z.bind(h2);
        
        nand_d.A.bind(h2);
        nand_d.B.bind(h3);
        nand_d.Z.bind(Z);
    }
};


#endif // EXOR_H
