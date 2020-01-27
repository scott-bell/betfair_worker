//
// Created by scott on 26/01/2020.
//

#include "KeyLineSelection.h"

KeyLineSelection::KeyLineSelection(Json::Value json) {
    if (json.isMember("selectionId"))
        selectionId = json["status"].asInt();
    if (json.isMember("handicap"))
        handicap = json["handicap"].asDouble();

}
