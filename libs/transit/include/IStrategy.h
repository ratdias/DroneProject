#ifndef ISTRATEGY_H_
#define ISTRATEGY_H_

#include <vector>
#include "graph.h"
#include "IEntity.h"

using namespace routing;

class IStrategy {
    public:
        virtual void Move(IEntity* entity, double dt) = 0;
        virtual bool IsCompleted() = 0;
        // virtual void SetCurrentIndex (int toSet) = 0;
        // virtual void SetMaxIndex (int toSet) = 0;
        // virtual int GetCurrentIndex()  = 0;
        // virtual int GetMaxIndex() = 0;
        // virtual void SetPosition(Vector3 toSet) = 0;
        // virtual void SetDestination(Vector3 toSet) = 0;
        // virtual Vector3 GetPosition() = 0;
        // virtual Vector3 GetDestination() = 0;

    protected:
        // IGraph object to be used in the simulation.
        const IGraph* graph;
        // int currentIndex;
        // int maxIndex;
}; //close class 

#endif // ISTRATEGY_H_