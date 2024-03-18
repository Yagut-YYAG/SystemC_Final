#ifndef STIMULUS_H
#define STIMULUS_H

#include <systemc.h>

SC_MODULE(stim)
{
public:
    sc_out<bool> A, B;
    sc_in<bool> Clk;
    SC_CTOR(stim)
    {
        SC_THREAD(StimGen);
        sensitive << Clk.pos();
    }

private:
    void StimGen()
    {
        wait(SC_ZERO_TIME);
        A.write(false);
        B.write(false);
        wait();
        A.write(false);
        B.write(true);
        wait(15, SC_NS);
        A.write(true);
        B.write(false);
        wait();
        A.write(true);
        B.write(true);
        wait();
        A.write(false);
        B.write(false);
        wait();
        sc_stop();
    }
};

#endif
