//
// Created by scott on 03/02/2020.
//

#ifndef BETFAIR_WORKER_APPLICATION_H
#define BETFAIR_WORKER_APPLICATION_H


struct Application {
    enum State { STARTING, READY, STOPPING };
    inline static State state = READY;

};


#endif //BETFAIR_WORKER_APPLICATION_H
