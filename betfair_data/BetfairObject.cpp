//
// Created by scott on 18/01/2020.
//

#include "BetfairObject.h"

BetfairObject::BetfairObject(std::string id) : m_id(id) {

}

const std::string &BetfairObject::get_id() const {
    return m_id;
}
