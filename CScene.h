#include <iostream>
#include <vector>
#include "CObject.h"
#include "CCollidingPair.h"
#include "CShape.h"
#include "CSection.h"

using namespace std;

class CScene
{
private:
    vector<CObject*> objects;
    vector<CCollidingPair*> objectPair;
public:
    CScene();
    void addObject(CObject *obOther);
    void rotate(int i, double degrees);
    void shift(int i, double x, double y);
    vector<CCollidingPair*> detectCollision();
    void show(int number);


};
