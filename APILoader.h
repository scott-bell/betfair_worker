//
// Created by scott on 22/01/2020.
//

#ifndef BETFAIR_WORKER_APILOADER_H
#define BETFAIR_WORKER_APILOADER_H

#include <3rd-party/SimpleWeb/client_https.hpp>
#include <betting_type/MarketCatalogue.h>

class APILoader {
public:
    std::vector<MarketCatalogue> listMarketCatalogue(const MarketFilter &filter, const std::set<std::string>& marketProjection, const std::string& sort,
                             int maxResults, const std::string& locale);
};


#endif //BETFAIR_WORKER_APILOADER_H
