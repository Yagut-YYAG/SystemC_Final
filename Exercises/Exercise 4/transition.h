#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"

// Transition:
// TODO
// template <unsigned int N=1, unsigned int M=1>
template <unsigned int N=1, unsigned int M=1, unsigned int L=0> //adding inhibitors 
SC_MODULE(transition){
    sc_port < placeInterface, N, SC_ALL_BOUND> in;
    sc_port < placeInterface, M, SC_ALL_BOUND > out;
    sc_port < placeInterface, L, SC_ZERO_OR_MORE_BOUND > inhibitors;
    // sc_port < placeInterface, 0, SC_ZERO_OR_MORE_BOUND > out; //so that we dont have to specify the number beforehand as template in the main
    // sc_port < placeInterface, 0, SC_ZERO_OR_MORE_BOUND > in;
    unsigned int PlacesWithToken = 0;
    unsigned int InhibitorsWithoutToken = 0;

    SC_CTOR(transition){}

    // void fire(){
    //     PlacesWithToken = 0;
    //     for(int i=0; i<N;i++){
    //         if(in[i]->testTokens() >= 1)PlacesWithToken++;
    //     }
    //     if(PlacesWithToken == N){
    //         std::cout << this->name() <<": Fired"<< std::endl;
    //         for(int i=0; i<N;i++) in[i]->removeTokens(1);
    //         for(int i=0; i<M;i++) out[i]->addTokens(1);}
    //     else {std::cout<<this->name() <<": NOT Fired"<<std::endl;}
    // }
    void fire(){
        PlacesWithToken = 0;
        InhibitorsWithoutToken=0;
        for(int i=0; i<N;i++){
            if(in[i]->testTokens() == 1)PlacesWithToken++;
        }
        for(int i=0; i<L;i++){
            if(inhibitors[i]->testTokens() == 0)InhibitorsWithoutToken++;
        }
        if(PlacesWithToken == N && InhibitorsWithoutToken == L){
            std::cout << this->name() <<": Fired"<< std::endl;
            for(int i=0; i<N;i++) in[i]->removeTokens();
            for(int i=0; i<M;i++) out[i]->addTokens();}
        else {std::cout<<this->name() <<": NOT Fired"<<std::endl;}
    }
};

#endif // TRANSITION_H
