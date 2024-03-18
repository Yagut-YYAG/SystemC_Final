#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
SC_MODULE (transition){
    sc_port<placeInterface> in;
    sc_port<placeInterface> out;
    SC_CTOR(transition){}
    void fire(){
        if(in->testTokens()>0){
            in->removeTokens(1);
            out->addTokens(1);
            std::cout << this->name() << ": Fired" << std::endl;
            }
        else std::cout << this->name() << ": NOT Fired" << std::endl;
    }
};

#endif // TRANSITION_H
