#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO
class placeInterface : public sc_interface{
    public:
    virtual void addTokens(unsigned int n)=0;
    virtual void removeTokens(unsigned int n)=0;
    virtual unsigned int testTokens()=0;
};

// Place Channel:
// TODO
class placeChannel : public placeInterface{
    private:
    unsigned int tokens;

    public:
    placeChannel(){this->tokens = 0;}
    placeChannel(unsigned int initokens){
        this->tokens = initokens;
    }
    void addTokens(unsigned int n){
        tokens = tokens + n;
    }
    void removeTokens(unsigned int n){
        tokens = tokens - n;
    }
    unsigned int testTokens(){
        return tokens;
    }
};

#endif // PLACE_H
