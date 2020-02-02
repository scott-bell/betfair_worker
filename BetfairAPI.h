//
// Created by scott on 22/01/2020.
//

#ifndef BETFAIR_WORKER_BETFAIRAPI_H
#define BETFAIR_WORKER_BETFAIRAPI_H

#include <3rd-party/SimpleWeb/client_https.hpp>
#include <betting_type/MarketCatalogue.h>
#include <betting_type/PlaceExecutionReport.h>
#include <betting_type/PlaceInstruction.h>
#include <betting_type/MarketVersion.h>
#include <betting_type/PriceProjection.h>
#include <betting_type/MarketBook.h>
#include <betting_type/TimeRange.h>
#include <betting_type/CurrentOrderSummaryReport.h>
#include <betting_type/CancelInstruction.h>
#include <betting_type/CancelExecutionReport.h>
#include <betting_type/UpdateInstruction.h>
#include <betting_type/UpdateExecutionReport.h>
#include <betting_type/ReplaceInstruction.h>
#include <betting_type/ReplaceExecutionReport.h>
#include <betting_type/MarketFilter.h>
#include <set>


class BetfairAPI {
    using HttpsClient = SimpleWeb::Client<SimpleWeb::HTTPS>;

    HttpsClient client;
    SimpleWeb::CaseInsensitiveMultimap header;
public:
    std::forward_list<MarketCatalogue>  listMarketCatalogue(const MarketFilter &filter, const std::set<std::string>& marketProjection, const std::string& sort,int maxResults, const std::string& locale);
    PlaceExecutionReport                placeOrders(const std::string& marketId, const std::vector<PlaceInstruction>& instructions, std::optional<std::string> customerRef,std::optional<MarketVersion> marketVersion, std::optional<std::string> customerStrategyRef, std::optional<bool> async);
    std::forward_list<MarketBook>       listMarketBook(const std::forward_list<std::string>& marketIds, std::optional<PriceProjection> priceProjection = std::nullopt, std::optional<std::string> orderProjection = std::nullopt, std::optional<std::string> matchProjection = std::nullopt, std::optional<bool> includeOverallPosition = std::nullopt, std::optional<bool> partitionMatchedByStrategyRef = std::nullopt, std::optional<std::vector<std::string>> customerStrategyRefs = std::nullopt, std::optional<std::string> currencyCode = std::nullopt, std::optional<std::string> locale = std::nullopt, std::optional<std::string> matchedSince = std::nullopt, std::optional<std::vector<std::string>> betIds = std::nullopt);
    CurrentOrderSummaryReport           listCurrentOrders(std::optional<std::set<std::string>> betIds, std::optional<std::set<std::string>> marketIds,
                                                            std::optional<std::string> orderProjection,
                                                            std::optional<std::set<std::string>> customerOrderRefs,
                                                            std::optional<std::set<std::string>> customerStrategyRefs, std::optional<TimeRange> dateRange,
                                                            std::optional<std::string> orderBy, std::optional<std::string> sortDir,
                                                            std::optional<int> fromRecord,
                                                            std::optional<int> recordCount);
    CancelExecutionReport               cancelOrders(std::optional<std::string> marketId, std::optional<std::forward_list<CancelInstruction>> instructions, std::optional<std::string> customerRef);
    UpdateExecutionReport               updateOrders(std::string marketId, std::forward_list<UpdateInstruction> instructions, std::optional<std::string> customerRef);
    ReplaceExecutionReport              replaceOrders(const std::string& marketId, std::forward_list<ReplaceInstruction> instructions, std::optional<std::string> customerRef, std::optional<MarketVersion> marketVersion, std::optional<bool> async);
    BetfairAPI();
};


#endif //BETFAIR_WORKER_BETFAIRAPI_H
