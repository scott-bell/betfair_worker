//
// Created by scott on 17/02/2020.
//

#ifndef SX_CLIENT_MARKETFILTER_H
#define SX_CLIENT_MARKETFILTER_H


#include <string>
#include "Filter.h"
#include "Market.h"



class MarketFilter : public Filter {
    std::optional<std::string> m_marketType;
public:
    MarketFilter() = default;
    explicit MarketFilter(Json::Value json);
    bool match(const Data::Market& item);
};


#endif //SX_CLIENT_MARKETFILTER_H
