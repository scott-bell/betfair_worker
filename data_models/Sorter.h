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
        Json::Value json;
    public:
        explicit Sorter(Json::Value json);
        Sorter() = default;
        virtual bool compare(const Data::DataObject &lhs, const Data::DataObject &rhs) const;
        template <typename T>
        bool compareProperty(const T &lhs, const T &rhs, bool desc) const;
        [[nodiscard]] bool compareProperties(const Data::DataObject* l, const Data::DataObject* r, bool& success, std::string& prop, bool desc) const;
    };

}
#endif //SX_CLIENT_SORTER_H
