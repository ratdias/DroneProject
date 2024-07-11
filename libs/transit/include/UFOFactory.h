#ifndef UFO_FACTORY_H_
#define UFO_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "UFO.h"

#include <vector>

class UFOFactory : public IEntityFactory {
  public:
    /**
     * @brief destructor of UFO instances 
     **/
    virtual ~UFOFactory() {}

    /**
     * @brief create a UFO instance 
     * 
     * @param entity is the entity with details used to form a new UFO  
     * @return pointer to new UFO entity
     **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif