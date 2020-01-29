//
// Created by scott on 16/01/2020.
//

#include <betting_type/MarketFilter.h>
#include "NavigationLoader.h"
#include "BetfairData.h"
#include "APILoader.h"
#include <betting_type/MarketCatalogue.h>

int main() {

    BetfairData bd;
    NavigationLoader nl(bd);
    APILoader api;
    
    std::cout << "Finished" << std::endl;


    return 0;
}