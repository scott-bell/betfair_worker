//
// Created by scott on 22/01/2020.
//

#ifndef BETFAIR_WORKER_APILOADER_H
#define BETFAIR_WORKER_APILOADER_H

#include <3rd-party/SimpleWeb/client_https.hpp>
#include <betting_type/MarketCatalogue.h>
#include <betting_type/PlaceExecutionReport.h>
#include <betting_type/PlaceInstruction.h>
#include <betting_type/MarketVersion.h>


class APILoader {
    using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

    HttpsClient client;
    SimpleWeb::CaseInsensitiveMultimap header;
    inline static const std::string applicationId = ".";
    inline static const std::string token = ".";
public:
    std::vector<MarketCatalogue> listMarketCatalogue(const MarketFilter &filter, const std::set<std::string>& marketProjection, const std::string& sort,
                             int maxResults, const std::string& locale);

    PlaceExecutionReport placeOrders(const std::string& marketId, std::vector<PlaceInstruction> instructions, std::optional<std::string> customerRef,
                                     std::optional<MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async);
    APILoader();
};


#endif //BETFAIR_WORKER_APILOADER_H
