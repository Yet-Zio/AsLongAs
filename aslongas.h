#ifndef ASLONGAS_H
#define ASLONGAS_H

bool AS_LONG_AS_START = true;
unsigned long GLOBAL_ASLONGAS_COUNTER = 0;
unsigned long ASLONGAS_FSSIZE = 0;

void reset_while_this(){
    AS_LONG_AS_START = true;
    GLOBAL_ASLONGAS_COUNTER = 0;
    ASLONGAS_FSSIZE = 0;
}

void aslongas(bool &expression){

}

template<typename T, typename... ST>
void aslongas(bool &expression, T func, ST... fs){
    __aslong__as__:
    if(AS_LONG_AS_START){
        ASLONGAS_FSSIZE = sizeof...(fs)+1;
        AS_LONG_AS_START = false;
    }

    if(expression) {
        func();
    }

    if(sizeof...(fs) == 0){
        GLOBAL_ASLONGAS_COUNTER = ASLONGAS_FSSIZE;
    }

    if(GLOBAL_ASLONGAS_COUNTER > 1){
        GLOBAL_ASLONGAS_COUNTER--;
        return;
    }

    if(expression) {
        aslongas(expression, fs...);
    }

    if(GLOBAL_ASLONGAS_COUNTER > 1){
        GLOBAL_ASLONGAS_COUNTER--;
        return;
    }

    if(expression){
        reset_while_this();
        goto __aslong__as__;
    }

}

#endif //ASLONGAS_H
