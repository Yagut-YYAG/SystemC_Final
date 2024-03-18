#include <iostream>
#include <systemc.h>

#include "kpn.h"
//-------------kpn is creating fibonacci sequence--------------
int sc_main(int, char**)
{
    kpn<unsigned int> kahn("kpn");
    sc_start();
    return 0;
}
