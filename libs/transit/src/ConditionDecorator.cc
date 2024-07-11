#include  "ConditionDecorator.h"
#include    <cstdlib>
#include    <iostream>
#include    "BeelineStrategy.h"

int ConditionDecorator::accidentProbability(){
  return 30;
}

bool ConditionDecorator::IsCompleted() { 
  if (strategy->IsCompleted()){
    if (stratToRepairStation != NULL) {
      return stratToRepairStation->IsCompleted();
    }
    else {
      return true;
    }
  }
  else {return false;}

}

void ConditionDecorator::Move(IEntity* entity, double dt) {
  std::cout<<"Drone moving" << std::endl;
  int x = accidentProbability();
  if (!strategy->IsCompleted()) {
    if (x  < 20) {
      ConditionDecorator::StopMoving(entity);
      entity->SetRepair(true);
    }
    else if( x < 40){
      entity->SetRepair(true);
      strategy -> Move(entity, dt);
    }
    else {
      strategy->Move(entity, dt);
    } 
  }
  // else {
  //   std::cout<<"condition finished"<<std::endl;
  //   if (x  < 40 && x > 20 && !entity->GetRepairStatus()) {
  //     std::cout<<"needs repair"<<std::endl;
  //     entity->SetAvailability(false);
  //     entity->SetRepair(true);
  //     stratToRepairStation = new BeelineStrategy(entity->GetPosition(), RepairStation);
  //     entity->SetTargetStrat(stratToRepairStation);
  //   }
  // }      

}

void ConditionDecorator::StopMoving (IEntity* entity) {
  Vector3 dir = (entity->GetPosition()- entity->GetPosition()).Unit();
  float speed = 0.0; 
  entity->SetPosition(entity->GetPosition());
  entity->SetDirection(dir);
}


