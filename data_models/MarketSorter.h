//
// Created by scott on 30/03/2020.
//

#ifndef SX_CLIENT_MARKETSORTER_H
#define SX_CLIENT_MARKETSORTER_H

#include "Sorter.h"
#include "Market.h"

namespace Data {

    class MarketSorter : public Sorter {
        Json::Value json;
    public:
        explicit MarketSorter(Json::Value json);
        MarketSorter() = default;
        [[nodiscard]] bool compare(const Data::DataObject &lhs, const Data::DataObject &rhs) const override;
        [[nodiscard]] bool compareProperties(const Data::Market* l, const Data::Market* r, bool& success, std::string& prop, bool desc) const;
    };


}
#endif //SX_CLIENT_MARKETSORTER_H
