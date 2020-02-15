//
// Created by scott on 24/01/2020.
//

#ifndef SXCLIENT_MARKETTYPERESULT_H
#define SXCLIENT_MARKETTYPERESULT_H


#include <string>
#include <optional>
namespace API {

    struct MarketTypeResult {
        std::optional<std::string> marketType;
        std::optional<int> marketCount;
    };
}

#endif //SXCLIENT_MARKETTYPERESULT_H
