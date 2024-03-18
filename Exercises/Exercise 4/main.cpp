#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE (Toplevel){
    // placeChannel<1,1> channel1, channel2, channel3, channel4;

    // transition<1,2> t1;// with SC_ZERO_OR_MORE_BOUND we can do dynamic binding without having to specify it in the template
    // transition<2,1> t2;
    // transition<1,1> t3;
   
    // t1.in.bind(channel1);
    // t1.out.bind(channel2);
    // t2.in.bind(channel2);
    // t2.out(channel1);

    // Building Hierarchial PNs
    subnet s1, s2;
    //subnet<1,1> s1,s2;
    placeChannel<1,1> IDLE;
    SC_CTOR(Toplevel):s1("s1"),s2("s2"),IDLE(2){
        s1.ACT.in.bind(IDLE);
        s1.PRE.out.bind(IDLE);
        s2.ACT.in.bind(IDLE);
        s2.PRE.out.bind(IDLE);
        //-------solution but with additional ports of subnet------
        // s1.subnet_in.bind(IDLE);
        // s1.subnet_out.bind(IDLE);
        // s2.subnet_in.bind(IDLE);
        // s2.subnet_out.bind(IDLE);
        
        SC_THREAD(process);
    }



    //----------- Modelling a single memory bank --------------
    // placeChannel<1,1> IDLE, ACTIVE;
    // transition<1,1> ACT, RD, PRE, WR;
    // SC_CTOR(Toplevel):ACT("ACT"),RD("RD"),PRE("PRE"),WR("WR"),IDLE(0),ACTIVE(0){
    //     ACT.in.bind(IDLE);
    //     ACT.out.bind(ACTIVE);
    //     RD.in.bind(ACTIVE);
    //     RD.out.bind(ACTIVE);
    //     PRE.in.bind(ACTIVE);
    //     PRE.out(IDLE);// why worked inside the constructor?
    //     WR.in.bind(ACTIVE);
    //     WR.out.bind(ACTIVE);
    //     SC_THREAD(process);
    // }




    // SC_CTOR(Toplevel):t1("t1"),t2("t2"),t3("t3"),channel1(1),channel2(0),channel3(0),channel4(0){
    //     t1.in.bind(channel1);
    //     t1.out.bind(channel2);
    //     t1.out.bind(channel3);
    //     t2.in.bind(channel2);
    //     t2.in.bind(channel4);
    //     t2.out(channel1);// why worked inside the constructor?
    //     t3.in.bind(channel3);
    //     t3.out.bind(channel4);
    //     SC_THREAD(process);
    // }
    void process(){
        
        //----------- Modelling a single Memory bank ---------------
        while(true){
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s1.RD.fire();
            wait(10, SC_NS);
            s1.WR.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s1.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s2.ACT.fire();
            wait(10, SC_NS);
            s1.PRE.fire();
            wait(10, SC_NS);
            s2.PRE.fire();
            wait(10, SC_NS);
            sc_stop();
        }
        //----------------------------------------------------------
        // while(true){
        //     wait(10, SC_NS);
        //     t1.fire();
        //     wait(10, SC_NS);
        //     t2.fire();
        //     wait(10, SC_NS);
        //     t3.fire();
        //     wait(10, SC_NS);
        //     t2.fire();
        //     sc_stop();
        // }
    }
};

int sc_main(int, char**)
{
    Toplevel t("t");
    sc_start();
    return 0;
}
