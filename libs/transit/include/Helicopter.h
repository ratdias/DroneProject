#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <vector>

#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"
#include "IStrategy.h"
#include "BeelineStrategy.h"

class Helicopter : public IEntity {
 public:
  /**
  * @brief Constructor of the Helicopter class
  * 
  * @param obj json object to initilize the instace of the class with
  **/
  Helicopter (JsonObject& obj);

  /**
   * @brief copy constructor 
  **/
  ~Helicopter () override = default;
  
  /**
   * @brief gets the internal variable position 
   * @return internal variable position
   **/

  Vector3 GetPosition() const { return position; }

  /**
   * @brief gets the internal variable direction 
   * @return internal variable direction
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief gets the internal variable destination 
   * @return internal variable destination
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief gets the internal variable availability
   * @return internal variable availability
   **/
  bool GetAvailability() const { return available; }

   /**
   * @brief method to return the details of the class
   * @return details private variable
   **/
  JsonObject GetDetails() const override;

  /**
   * @brief method to return the speed of the class
   * @return speed private variable
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief method to return the strategyname of the class
   * @return strategyName private variable
   **/
  std::string GetStrategyName() {return strategyName;}

  /**
   * @brief method to set the private varibale availability
   * @param choice is our choice of value for the variable
  **/
  void SetAvailability(bool choice);

  /** 
   * @brief method to set the private varibale position
   * @param pos_ is our choice of value for the variable
  **/
  void SetPosition(Vector3 pos_) { position = pos_; }


  /** 
   * @brief method to set the private varibale direction
   * @param dir_ is our choice of value for the variable
  **/
  void SetDirection(Vector3 dir_) { direction = dir_; }


  /** 
   * @brief method to set the private varibale destination
   * @param des_ is our choice of value for the variable
  **/
  void SetDestination(Vector3 des_) { destination = des_; }

    /** 
   * @brief method to set the private varibale strategyName
   * @param strategyName_ is our choice of value for the variable
  **/
  void SetStrategyName(std::string strategyName_) {strategyName = strategyName_;}

  /**
   * @brief method to rotate an Helicopter instance 
   * @param angle determines the angle of rotation 
  **/
  void Rotate(double angle);

  /**
   *@brief method to move the car instance according to the strategy
   *@param dt sets he maginitude of the move 
   *@param scheduler is a vector of all enitities being simulated  
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  bool available;
  std::string strategyName;
  IStrategy* toTargetDesStrategy = NULL;
};

#endif  // HELICOPTER_H