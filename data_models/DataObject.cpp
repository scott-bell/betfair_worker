//
// Created by scott on 18/01/2020.
//

#include "DataObject.h"


namespace Data {

    DataObject::DataObject(std::string id) : m_id(id) {

    }

    const std::string &DataObject::id() const {
        return m_id;
    }

}