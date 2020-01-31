//
// Created by scott on 16/01/2020.
//

#include <betting_type/MarketFilter.h>
#include "NavigationLoader.h"
#include "BetfairData.h"
#include "BetfairAPI.h"
#include "WebServer.h"
#include <betting_type/MarketCatalogue.h>

int main() {

    BetfairData bd;
    NavigationLoader nl(bd);
    BetfairAPI api;
    nl.init();

    WebServer ws(bd);
    ws.init();

    return 0;
}