#include <iostream>
#include<systemc.h>
#include "state_machine.h"

// TODO
void stateMachine :: process(){
    switch(current_state)
    {
        case Start:
            if(input.read() == 'G')current_state = G;
            else current_state = Start;
            break;
        case G:
            if(input.read() == 'A') current_state = GA;
            else if(input.read()=='G') current_state = G;
            else current_state = Start;
            break;
        case GA:
            if(input.read()=='A') current_state = GAA;
            else if(input.read()=='G') current_state = G;
            else current_state = Start;
            break;
        case GAA:
            if(input.read()=='G'){
                current_state = GAAG;
                std::cout <<"@"<<sc_time_stamp()<<" GAAG is part of a DNA sequence"<<std::endl;
            } else current_state = Start;
            break;
        case GAAG:
            if(input.read()=='G') current_state = G;
            else current_state = Start;
            break;
        default:
            std::cout << "Invalid Input!!"<<std::endl;
            break;
    }    
};