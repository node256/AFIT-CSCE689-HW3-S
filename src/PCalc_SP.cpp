#include "PCalc.h"
#include "PCalc_SP.h"


PCalc_SP::PCalc_SP(unsigned int count_to) : PCalc(count_to){
    
}

PCalc_SP::~PCalc_SP(){
    cleanup();
}

void PCalc_SP::markNonPrimes(){
    unsigned int max = array_size();
    unsigned int sqrtLimit = sqrt(max);
    for ( unsigned int i = 2; i < sqrtLimit; i++){
        if ( i % 2 == 0 ){
            at(i) = false;
        }
        else if ( at(i) == 1){
            for( unsigned int j = i * i; j < array_size(); j+=i){
                at(j) = 0;
            }
        }
    }
}