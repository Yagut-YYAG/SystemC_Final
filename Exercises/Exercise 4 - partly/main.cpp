#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(Toplevel){
    placeChannel p1,p2;
    transition t1,t2;
    SC_CTOR(Toplevel):p1(1),p2(0),t1("t1"),t2("t2"){
    t1.in.bind(p1);
    t1.out.bind(p2);
    t2.in.bind(p2);
    t2.out.bind(p1);
    SC_THREAD(process);
    }
    void process()
        {
            while (true)
            {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
            sc_stop();
            }
        }
};

int sc_main(int, char**)
{
    // TODO
    Toplevel t("t");
    sc_start();
    return 0;
}
