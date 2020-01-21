//
// Created by scott on 16/01/2020.
//

#include "NavigationLoader.h"
#include "BetfairData.h"


int main() {
    BetfairData bd;
    NavigationLoader nl(bd);
    std::cout << "Initializing...." << std::endl;
    nl.init();
    int countRecursive = bd.nodeCountRecursive();
    int nodeCount = bd.nodeCount();
    std::cout << "Recursive count: " << countRecursive << ", unique nodes: " << nodeCount << std::endl;
    std::cout << "Goodbye." << std::endl;

    return 0;
}
