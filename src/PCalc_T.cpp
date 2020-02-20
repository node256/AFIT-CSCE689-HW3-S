#include "PCalc.h"
#include "PCalc_T.h"

PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads): PCalc(array_size){
    nThreads = num_threads;
}

PCalc_T::~PCalc_T(){
    cleanup();
}

void PCalc_T::markNonPrimes(){

    unsigned int end = array_size();
    std::thread thdArr[nThreads];
    unsigned int start = 2;

    for ( unsigned int i = 0; i < nThreads; i++){
        thdArr[i] = std::thread( [=] { tMark(start + i, end); } );
        start = end;
    }
    for (auto &t : thdArr){
        t.join();
    }
}

void PCalc_T::tMark( unsigned int start, unsigned int end ){

    for ( unsigned int i = start; i <= end; i++){
        if ( at(i) == 1 ){
            for ( unsigned int j = i * i; j < end; j+=i ){
                if (at(j) == 1 ) at(j) = 0;
            }
        }
    }
}