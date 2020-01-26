//
// Created by scott on 24/01/2020.
//

#include "PlaceInstructionReport.h"

PlaceInstructionReport::PlaceInstructionReport(Json::Value json) : instruction(PlaceInstruction(json["instruction"])) {
    status = json["status"].asString();
    if (json.isMember("errorCode"))
        errorCode = json["errorCode"].asString();
    if (json.isMember("orderStatus"))
        orderStatus = json["orderStatus"].asString();
    //instruction = PlaceInstruction(json["instruction"]);
    if (json.isMember("betId"))
        betId = json["betId"].asString();
    if (json.isMember("placedDate"))
        placedDate = json["placedDate"].asString();
    if (json.isMember("averagePriceMatched"))
        averagePriceMatched = json["averagePriceMatched"].asDouble();
    if (json.isMember("sizeMatched"))
        sizeMatched = json["sizeMatched"].asDouble();

}
