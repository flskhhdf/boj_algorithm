#include "iostream"
using namespace std;

class Car {
private:       
    int speed;	
    int gear;	
    string color;	
public:
    int getSpeed();
    void setSpeed(int s);
    void setSpeed(double s);
};

int Car::getSpeed() {
    return speed;
}

void Car::setSpeed(int s) {	
    speed = s;
}

void Car::setSpeed(double s) {	
    speed = (int)s;
}

int square(int i) {
	return i*i;
}

int main()
{
   Car myCar;
   myCar.setSpeed(80);
   myCar.setSpeed(100.0);
   cout << "차 속도: " << myCar.getSpeed() << endl;
   cout << square(10);
   return 0;
}


