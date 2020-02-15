//
// Created by scott on 28/01/2020.
//

#ifndef SXCLIENT_TIMERANGE_H
#define SXCLIENT_TIMERANGE_H

#include <optional>
#include <string>
#include <jsoncpp/json/json.h>
namespace API {

    struct TimeRange {
        std::optional<std::string> from;
        std::optional<std::string> to;

        [[nodiscard]] Json::Value json() const;
    };

}
#endif //SXCLIENT_TIMERANGE_H
