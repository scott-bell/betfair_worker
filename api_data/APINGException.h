//
// Created by scott on 30/01/2020.
//

#ifndef SXCLIENT_APINGEXCEPTION_H
#define SXCLIENT_APINGEXCEPTION_H


#include <jsoncpp/json/json.h>
namespace API {

    class APINGException : public std::exception {
        std::string requestUUID;
        std::string errorCode;
        std::string errorDetails;
    public:
        explicit APINGException(Json::Value json);

        const char *what() const throw();
    };

}
#endif //SXCLIENT_APINGEXCEPTION_H
