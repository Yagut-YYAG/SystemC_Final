#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO

//--------------------------Commented lines corresponds to the same solution but with additional ports of subnet-------------------
//template<unsigned int N=1, unsigned int M=1>
SC_MODULE (subnet){
    //sc_port<placeInterface, N, SC_ZERO_OR_MORE_BOUND> subnet_in;
    //sc_port<placeInterface, M, SC_ZERO_OR_MORE_BOUND> subnet_out;
    public:
    placeChannel<1,1> ACTIVE;
    transition<1,1> RD,PRE,WR;
    transition<1,1,1> ACT;
    SC_CTOR(subnet):ACTIVE(0),RD("RD"),PRE("PRE"),WR("WR"),ACT("ACT"){

       // ACT.in.bind(subnet_in);
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);

        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);

        PRE.in.bind(ACTIVE);
       // PRE.out.bind(subnet_out);
        
    }
};
#endif // SUBNET_H
