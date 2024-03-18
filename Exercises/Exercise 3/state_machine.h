#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

// TODO
SC_MODULE (stateMachine){
    private:
    enum base{Start, G, GA, GAA, GAAG};
    void process();

    public:
    sc_in<char> input;
    sc_in<bool> clk;
    base current_state = base::Start;
    SC_CTOR(stateMachine) : input("input"), clk("clk") {
		SC_METHOD(process);
		sensitive << clk.pos();
		dont_initialize();
	}
};
#endif // STATE_MACHINE_H


