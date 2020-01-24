//
// Created by scott on 23/01/2020.
//

#include "MarketLineRangeInfo.h"

MarketLineRangeInfo::MarketLineRangeInfo(Json::Value json) {
    maxUnitValue = json["maxUnitValue"].asDouble();
    minUnitValue = json["minUnitValue"].asDouble();
    interval = json["interval"].asDouble();
    marketUnit = json["marketUnit"].asString();
}
