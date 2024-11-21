#include "ShipTypes.h"

using namespace std;
// Define the ship types

const ShipType ShipTypes::BATTLESHIP = {"Battleship", 5};
const ShipType ShipTypes::CRUISER = {"Cruiser", 4};
const ShipType ShipTypes::DESTROYER = {"Destroyer", 3};
const ShipType ShipTypes::SUBMARINE_1 = {"Submarine 1", 2};
const ShipType ShipTypes::SUBMARINE_2 = {"Submarine 2", 2};
const ShipType ShipTypes::FISHING_1 = {"Fishing 1", 1};
const ShipType ShipTypes::FISHING_2 = {"Fishing 2", 1};

const ShipType ShipTypes::SHIP_TYPES[7] = {BATTLESHIP, CRUISER, DESTROYER, SUBMARINE_1, SUBMARINE_2, FISHING_1, FISHING_2};
