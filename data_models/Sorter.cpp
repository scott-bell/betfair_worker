//
// Created by scott on 29/03/2020.
//

#include "Sorter.h"
#include <iostream>

namespace Data {

    Sorter::Sorter(Json::Value json) : json(std::move(json)){

    }

    bool Sorter::compare(const DataObject &lhs, const DataObject &rhs) const {
        for (const Json::Value &index : json) {
            bool desc = index["direction"] == "DESC";
            if (index["property"] == "idd") {
                if (desc)
                    return lhs.id() > rhs.id();
                else
                    return lhs.id() < rhs.id();
            }
        }
        return lhs.id() < rhs.id();
    }

}