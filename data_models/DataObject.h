//
// Created by scott on 18/01/2020.
//

#ifndef SXCLIENT_DATAOBJECT_H
#define SXCLIENT_DATAOBJECT_H


#include <string>
#include <jsoncpp/json/json.h>
#include "Sorter.h"

namespace Data {
    class Sorter;
    class DataObject {
    protected:
        friend class DataModels;

        std::string m_id;

        explicit DataObject(std::string id);

    public:
        DataObject() = delete;
        bool compare(const DataObject& rhs, const Data::Sorter& sorter) const;
        [[nodiscard]] virtual Json::Value json() const = 0;
        [[nodiscard]] const std::string &id() const;
    };
}

#endif //SXCLIENT_DATAOBJECT_H
