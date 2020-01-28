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
#include <betting_type/PriceProjection.h>
#include <betting_type/MarketBook.h>


class APILoader {
    using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

    HttpsClient client;
    SimpleWeb::CaseInsensitiveMultimap header;
    inline static const std::string applicationId = ".";
    inline static const std::string token = ".";
public:
    std::vector<MarketCatalogue> listMarketCatalogue(const MarketFilter &filter, const std::set<std::string>& marketProjection, const std::string& sort,
                             int maxResults, const std::string& locale);
    PlaceExecutionReport placeOrders(const std::string& marketId, const std::vector<PlaceInstruction>& instructions, std::optional<std::string> customerRef,
                                     std::optional<MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async);
    std::vector<MarketBook> listMarketBook(const std::vector<std::string>& marketIds, std::optional<PriceProjection> priceProjection, std::optional<std::string> orderProjection, std::optional<std::string> matchProjection, std::optional<bool> includeOverallPosition, std::optional<bool> partitionMatchedByStrategyRef, std::optional<std::vector<std::string>> customerStrategyRefs, std::optional<std::string> currencyCode, std::optional<std::string> locale, std::optional<std::string> matchedSince, std::optional<std::vector<std::string>> betIds);
    APILoader();
};


#endif //BETFAIR_WORKER_APILOADER_H
