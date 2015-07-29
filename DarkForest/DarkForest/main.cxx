#ifdef WIN32
#include <windows>
#endif

#ifndef __MAIN__
#define __MAIN__

#include <iostream>
#include "SolarSystem.h"
#include "SpaceMap.h"

int main(){
  
  bool is_player(true);
  SolarSystem sun("Sun",is_player);
  SolarSystem three_body("ThreeBody");

  SpaceMap::SpaceMap space_map;
  SpaceMap::joinSpace(sun,space_map);
  SpaceMap::joinSpace(three_body,space_map);

  while(true){
    std::cout<<"-------New Report-------"<<std::endl;
    sun.takeAction(three_body);
    three_body.takeAction(sun);

    //Can choose explore, develop, hide, do nothing etc. Comsuming diff resources respectively
    //When exploring, have chance to find resources(higher tech, higher possibility)

    //TODO:Use absolute position rather than 2D position? random generate distance
    //TODO:static map/set to save all solar objects

    std::cout<<"------------------------"<<std::endl;

    if(sun.dead() || three_body.dead())
      break;
  }

  system("PAUSE");
}

#endif /* __MAIN__ */