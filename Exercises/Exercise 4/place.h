#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO
//template<class T>

// class placeInterface : public sc_interface{
    
//     public:
//     virtual void addTokens(unsigned int n)=0;
//     virtual void removeTokens(unsigned int n)=0;
//     virtual unsigned int testTokens()=0;
// };
// Templated channels
class placeInterface : public sc_interface{
    
    public:
    virtual void addTokens()=0;
    virtual void removeTokens()=0;
    virtual bool testTokens()=0;
};
// Place Channel:
// TODO
//template<class T>
//template <unsigned int N=1, unsigned int M=1>
template<unsigned int Win=1,unsigned int Wout=1>
class placeChannel: public placeInterface{
    private:
    unsigned int tokens;

    public:
    placeChannel(unsigned int current_tokens):tokens(current_tokens){}
    void addTokens(){
        tokens = tokens + Win;
    }
    void removeTokens(){
        tokens = tokens - Wout;
    }
    bool testTokens(){
        return tokens>=Wout;
    }
};
#endif // PLACE_H
