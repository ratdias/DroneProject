#include "Car.h"
#include "AstarStrategy.h"
#include <cstdlib>
Car::Car(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

JsonObject Car::GetDetails() const { return details; }

void Car::SetAvailability(bool choice) { available = choice; }

void Car::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void Car::Update(double dt, std::vector<IEntity*> scheduler){

  if (toTargetDesStrategy == NULL){
    Vector3 desty = {(rand()%1500)-1400, 240+ rand(), (rand()%800)-800};
    SetDestination(desty);
    toTargetDesStrategy = new AstarStrategy(GetPosition(), GetDestination(), graph);
  } else {
    if (toTargetDesStrategy->IsCompleted()){
    Vector3 desty = {(rand()%1500)-1400, 240+ rand(), (rand()%800)-800};
    SetDestination(desty);
    toTargetDesStrategy = new AstarStrategy(GetPosition(), GetDestination(), graph);
    } else {
      toTargetDesStrategy->Move(this, dt);
    }
  }
}


