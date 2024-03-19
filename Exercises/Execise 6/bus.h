#ifndef BUS_H
#define BUS_H

#include <iostream>
#include <systemc.h>
#include <tlm.h>


// TODO: add your code here
template<unsigned int socket_size_i = 1, unsigned int socket_size_t = 1>
class bus : sc_module,
                            tlm::tlm_bw_transport_if<>,
                            tlm::tlm_fw_transport_if<>
{
    public:
    // tlm::tlm_initiator_socket<> iSocket[2];
    // tlm::tlm_target_socket<> tSocket[2];
    tlm::tlm_initiator_socket<> iSocket[socket_size_i];
    tlm::tlm_target_socket<> tSocket[socket_size_t];

    SC_CTOR(bus)
    {
        // tSocket[0].bind(*this);
        // tSocket[1].bind(*this);
        // iSocket[0].bind(*this);
        // iSocket[1].bind(*this);
        for(int i=0;i<socket_size_i;i++){
            iSocket[i].bind(*this);
            }
        for(int i=0;i<socket_size_t;i++){
            tSocket[i].bind(*this);
            }
    }

    void b_transport(tlm::tlm_generic_payload &trans, sc_time &delay)
    {
        // Annotate Bus Delay
        delay = delay + sc_time(40, SC_NS);

        if(trans.get_address() < 512)
        {
            iSocket[0]->b_transport(trans, delay);
        }
        else
        {
            // Correct Address:
            trans.set_address(trans.get_address() - 512);
            iSocket[1]->b_transport(trans, delay);
        }
    }

    // Dummy method
    virtual tlm::tlm_sync_enum nb_transport_fw(
            tlm::tlm_generic_payload& trans,
            tlm::tlm_phase& phase,
            sc_time& delay )
    {
        SC_REPORT_FATAL(this->name(),"nb_transport_fw is not implemented");
        return tlm::TLM_ACCEPTED;
    }

    // Dummy method
    bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans,
                            tlm::tlm_dmi& dmi_data)
    {
        SC_REPORT_FATAL(this->name(),"get_direct_mem_ptr is not implemented");
        return false;
    }

    // Dummy method
    unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
    {
        SC_REPORT_FATAL(this->name(),"transport_dbg is not implemented");
        return 0;
    }

    // Dummy method:
    void invalidate_direct_mem_ptr(sc_dt::uint64 start_range,
                                   sc_dt::uint64 end_range)
    {
        SC_REPORT_FATAL(this->name(),"invalidate_direct_mem_ptr not implement");
    }

    // Dummy method:
    tlm::tlm_sync_enum nb_transport_bw(
            tlm::tlm_generic_payload& trans,
            tlm::tlm_phase& phase,
            sc_time& delay)
    {
        SC_REPORT_FATAL(this->name(),"nb_transport_bw is not implemented");
        return tlm::TLM_ACCEPTED;
    }

};

#endif // BUS_H
