#ifndef CAR_FACTORY_H_
#define CAR_FACTORY_H_

#include "IEntity.h"
#include "IEntityFactory.h"
#include "Car.h"

#include <vector>

class CarFactory : public IEntityFactory {
  public:
    /**
     * @brief destructor of car instances 
     **/
    virtual ~CarFactory() {}
    /**
     * @brief create a car instance 
     * 
     * @param entity is the entity with details used to form a new car
     * 
     * @return pointer to new car entity
     **/
    IEntity* CreateEntity(JsonObject& entity);
};

#endif 