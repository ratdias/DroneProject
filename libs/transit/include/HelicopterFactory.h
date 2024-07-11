#ifndef HELICOPTER_FACTORY_H_
#define HELICOPTER_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Helicopter.h"

#include <vector>

class HelicopterFactory : public IEntityFactory {
  public:
      /**
     * @brief destructor of helicopter instances 
     **/
    virtual ~HelicopterFactory() {}

    /**
     * @brief create a Helicopter instance 
     * 
     * @param entity is the entity with details used to form a new helicopter     
     * @return pointer to new helicopter entity
     **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif 