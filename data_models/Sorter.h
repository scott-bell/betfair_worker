//
// Created by scott on 29/03/2020.
//

#ifndef SX_CLIENT_SORTER_H
#define SX_CLIENT_SORTER_H


#include <jsoncpp/json/value.h>
#include "DataObject.h"

namespace Data {


    class Sorter {
    public:
        explicit Sorter(Json::Value json);
        Sorter();
        bool compare(DataObject &lhs, DataObject &rhs);
    };

}
#endif //SX_CLIENT_SORTER_H
