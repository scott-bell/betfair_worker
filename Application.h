//
// Created by scott on 03/02/2020.
//

#ifndef SXCLIENT_APPLICATION_H
#define SXCLIENT_APPLICATION_H


struct Application {
    enum State { STARTING, READY, STOPPING };
    inline static State state = READY;

};


#endif //SXCLIENT_APPLICATION_H
