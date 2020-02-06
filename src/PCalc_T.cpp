#include "PCalc.h"
#include "PCalc_T.h"

PCalc_T::PCalc_T(unsigned int array_size, unsigned int num_threads): PCalc(array_size){
    nThreads = num_threads;
}

PCalc_T::~PCalc_T(){
    cleanup();
}

void PCalc_T::markNonPrimes(){

    unsigned int max = array_size();
    unsigned int sqrtLimit = sqrt(max);
    unsigned int chunk = sqrtLimit / nThreads;
    std::thread thdArr[nThreads];
    unsigned int start = 2;

    for ( unsigned int i = 0; i < nThreads; i++){

        unsigned int end = start + chunk;
        thdArr[i] = std::thread ( PCalc_T::tMark, start, end, max);
        start = end;
    }
    for (auto &t : thdArr){
        t.join();
    }
}

void PCalc_T::tMark( unsigned int start, unsigned int end, unsigned int max ){

    for ( unsigned int i = start; i <= end; i++){
        if ( at(i) == 1 ){
            for ( unsigned int j = i * i; j < max; j+=i ){
                numLock.lock();
                at(j) = false;
                numLock.unlock();
            }
        }
    }
}