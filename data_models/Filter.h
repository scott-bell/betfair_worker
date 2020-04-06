//
// Created by scott on 17/02/2020.
//

#ifndef SX_CLIENT_FILTER_H
#define SX_CLIENT_FILTER_H


#include "DataObject.h"

namespace Data {
    class Filter {
    private:
        Json::Value _json;
    public:
        explicit Filter(Json::Value json);
        Filter() = default;
        [[nodiscard]] virtual bool matches(const Data::DataObject &item) const;
    protected:
        const Json::Value& json() const;

    };
}


#endif //SX_CLIENT_FILTER_H
