#include "PCalc.h"
#include "PCalc_SP.h"


PCalc_SP::PCalc_SP(unsigned int count_to) : PCalc(count_to){
    
}

PCalc_SP::~PCalc_SP(){
    cleanup();
}

void PCalc_SP::markNonPrimes(){
    unsigned int end = array_size();
    unsigned int stop = sqrt(end);
    for ( unsigned int i = 2; i < stop; i++){
        if ( at(i) == 1){
            for( unsigned int j = i * i; j < end; j+=i){
                if (at(j) == 1 ) at(j) = 0;
            }
        }
    }
}