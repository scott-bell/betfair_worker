//
// Created by scott on 30/01/2020.
//

#ifndef BETFAIR_WORKER_APINGEXCEPTION_H
#define BETFAIR_WORKER_APINGEXCEPTION_H


#include <jsoncpp/json/json.h>

class APINGException : public std::exception {
    std::string requestUUID;
    std::string errorCode;
    std::string errorDetails;
public:
    explicit APINGException(Json::Value json);
    const char * what () const throw();
};


#endif //BETFAIR_WORKER_APINGEXCEPTION_H
