//
// Created by scott on 17/02/2020.
//

#ifndef SX_CLIENT_FILTER_H
#define SX_CLIENT_FILTER_H


#include "DataObject.h"

class Filter {
public:
    bool match(const Data::DataObject& item);
    Filter() = default;
    explicit Filter(Json::Value json);
};


#endif //SX_CLIENT_FILTER_H
