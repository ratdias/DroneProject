#ifndef BEELINE_H_
#define BEELINE_H_

/**
 * include
 */
#include "math/vector3.h"
#include <vector>
#include "IStrategy.h"
#include "IEntity.h"
/**
 * @brief this class inhertis from the IStrategy class and is responsible for generating the beeline that the drone will take.
 */
class BeelineStrategy : public IStrategy {
public:
    BeelineStrategy(Vector3 position, Vector3 destination);
    ~BeelineStrategy();
    void Move(IEntity* entity, double dt);
    bool IsCompleted();
    // void SetPosition(Vector3 toSet) {position = toSet;};
    // void SetDestination(Vector3 toSet) {destination = toSet;};
    // Vector3 GetPosition() {return position;};
    // Vector3 GetDestination() {return destination;};
    // void SetCurrentIndex (int toSet) {currentIndex = toSet;};
    // void SetMaxIndex (int toSet){maxIndex = toSet;};
    // int GetCurrentIndex() {return currentIndex;};
    // int GetMaxIndex() {return currentIndex;};


private:
    Vector3 position;
    Vector3 destination;
    // int currentIndex;
    // int maxIndex;
}; //end class
#endif // BEELINE_H_