#ifndef CONDITION_DECORATOR_H_
#define CONDITION_DECORATOR_H_

#include <vector>
#include "Drone.h"
#include "IStrategy.h"

class ConditionDecorator : public IStrategy {
 public:
  ConditionDecorator(IStrategy *strategy_) {
    strategy = strategy_;
    time = 0;
    stratToRepairStation  = NULL;
  }
  void Move(IEntity*entity, double dt);
  bool IsCompleted();
  int accidentProbability(); 
  void StopMoving(IEntity *entity);


 protected:
  bool operational; 
  IStrategy *strategy;
  IStrategy *stratToRepairStation;
  float time;
  Vector3 RepairStation = Vector3(600, 280, -240);
};  // close class

#endif  // CONDITION_DECORATOR_H_
