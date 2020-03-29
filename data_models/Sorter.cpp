//
// Created by scott on 29/03/2020.
//

#include "Sorter.h"

namespace Data {

    Sorter::Sorter(Json::Value json) {
    }

    bool Sorter::compare(DataObject &lhs, DataObject &rhs) {
        return lhs.id() > rhs.id();
    }

    Sorter::Sorter() {

    }

}