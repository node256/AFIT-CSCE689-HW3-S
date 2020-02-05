#include "PCalc.h"
#include "PCalc_SP.h"


PCalc_SP::PCalc_SP(unsigned int count_to) : PCalc(count_to){
    
}

PCalc_SP::~PCalc_SP(){
    cleanup();
}

void PCalc_SP::markNonPrimes(){
    for ( unsigned int i = 2; i < sqrt(array_size()); i++){
        if ( at(i) == true){
            for( unsigned int j = i * i; i < array_size(); j+=i){
                at(j) = false;
            }
        }
    }
}