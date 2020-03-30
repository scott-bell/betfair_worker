//
// Created by scott on 29/03/2020.
//

#ifndef SX_CLIENT_SORTER_H
#define SX_CLIENT_SORTER_H


#include <jsoncpp/json/value.h>
#include "DataObject.h"

namespace Data {

    class DataObject;
    class Sorter {
    private:
        int id;
    public:
        explicit Sorter(Json::Value json);
        Sorter() = default;
        bool compare(const Data::DataObject &lhs, const Data::DataObject &rhs) const;
    };

}
#endif //SX_CLIENT_SORTER_H
