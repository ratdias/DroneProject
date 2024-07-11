#ifndef STATION_FACTORY_H_
#define STATION_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Station.h"

#include <vector>

class StationFactory : public IEntityFactory {
  public:
      /**
     * @brief destructor of station instances 
     **/
    virtual ~StationFactory() {}

    /**
     * @brief create a Station instance 
     * 
     * @param entity is the entity with details used to form a new station    
     * @return pointer to newstation entity
     **/
    IEntity* CreateEntity(JsonObject& entity);
};      // STATION_FACTORY_H_

#endif 
