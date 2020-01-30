//
// Created by scott on 30/01/2020.
//

#include "APINGException.h"

APINGException::APINGException(Json::Value json) {
    requestUUID = json["requestUUID"].asString();
    errorCode = json["errorCode"].asString();
    errorDetails = json["errorDetails"].asString();

}

const char *APINGException::what() const throw() {
    return errorCode.c_str();
}
