//
// Created by scott on 29/03/2020.
//

#include "Sorter.h"

namespace Data {

    Sorter::Sorter(Json::Value json) {
        id = 0;
        for (const Json::Value &index : json) {
            if (index["property"] == "id") {
                if (index["direction"] == "DESC")
                    id = -1;
                else
                    id = 1;
            }
        }
     }

    bool Sorter::compare(const DataObject &lhs, const DataObject &rhs) const {
        if (id > 0)
            return lhs.id() > rhs.id();
        else if (id < 0)
            return lhs.id() < rhs.id();
        return lhs.id() < rhs.id();
    }

}