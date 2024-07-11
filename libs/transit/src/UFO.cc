#include "UFO.h"
#include <cstdlib>


UFO::UFO(JsonObject &obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
}

JsonObject UFO::GetDetails() const { return details; }

void UFO::SetAvailability(bool choice) { available = choice; }

void UFO::Rotate(double angle) {
  direction.x = direction.x * std::cos(angle) - direction.z * std::sin(angle);
  direction.z = direction.x * std::sin(angle) + direction.z * std::cos(angle);
}

void UFO::Update(double dt, std::vector<IEntity*> scheduler){
  if (toTargetDesStrategy == NULL){
    Vector3 desty = {(rand()%1500)-1400, position.y, (rand()%800)-800};
    SetDestination(desty);
    toTargetDesStrategy = new BeelineStrategy(GetPosition(), GetDestination());
  } else {
    if (toTargetDesStrategy->IsCompleted()){
      Vector3 desty = {(rand()%1500)-1400, position.y, (rand()%800)-800};
      SetDestination(desty);
      toTargetDesStrategy = new BeelineStrategy(GetPosition(), GetDestination());
    } else {
      toTargetDesStrategy->Move(this, dt);
    }
  }
}


