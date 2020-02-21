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
    unsigned int stop = sqrt(end);
    std::thread thdArr[nThreads];

    for ( unsigned int i = 0; i < nThreads; i++){
        thdArr[i] = std::thread( [=] { tMark(end,stop); } );
    }
    for (auto &t : thdArr){
        t.join();
    }
}

void PCalc_T::tMark( unsigned int end, unsigned int stop ){

    unsigned int pos = 0;
    while ( pos <= stop){
        numLock.lock();
        pos = start;
        start+= 1;
        numLock.unlock();

        if ( at(pos) == true){
            for ( unsigned int j = pos * pos; j < end; j+=pos ){
                if (at(j) == 1 ) at(j) = false;
            }
        } 
    }
}