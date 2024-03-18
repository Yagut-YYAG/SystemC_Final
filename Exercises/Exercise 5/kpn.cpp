#include <unistd.h>
#include <systemc.h>

#include "kpn.h"
template<class T> void kpn<T>::Split(){
    while(count<10){
        T val = b.read();
		d.write(val);
		a.write(val);// WHY a.write(b.read()); IS NOT CORRECT?
		e.write(val);
        std::cout <<"e: "<< e.read()<< std::endl;
        count++;
    }
    sc_stop;
}
template void kpn<unsigned int>::Split();

template<class T> void kpn<T>::Add(){
    while(true){
        b.write(a.read() + c.read());
    }
}
template void kpn<unsigned int>::Add();

template<class T> void kpn<T>::Delay(){
    while(true){
        c.write(d.read());
    }
}
template void kpn<unsigned int>::Delay();
