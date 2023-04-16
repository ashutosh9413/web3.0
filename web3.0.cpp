#include <iostream>
#include <math.h>
using namespace std;

class car
{
public:
    string make;
    string model;
    int year;
    double speed_x, speed_y;
    double x;
    double y;
    double speed_increment, speed_decrement;
    void accelerate_x(double speed_increment)
    {
        if(speed_x>0)
        {
            speed_x += speed_increment;
        }
        else
        {
            speed_x = speed_x - speed_increment;
        }
    }
    void brake_x(double speed_decrement)
    {
        if(speed_x>0)
        {
            speed_x =speed_x - speed_decrement;
        }
        else
        {
            speed_x = speed_x + speed_decrement;
        }
    }
    void move(double rate)
    {
        x += speed_x * rate;
        y += speed_y * rate;
        accelerate_x(speed_increment);
    }
    
        };
int main()
{
    double c1x, c2x, c1y, c2y;
    double c1sx, c1sy, c1a, c2sx, c2sy, c2a;
    cout << "Enter Car 1 Position, Speed, Acc\n";
    cin >> c1x >> c1y >> c1sx >> c1sy >> c1a;
    cout << "Enter Car 2 Position, Speed, Acc\n";
    cin >> c2x >> c2y >> c2sx >> c2sy >> c2a;
    
    car car1;
    car1.make ="Scorpio";
    car1.model = "SUV";
    car1.year = 2022;
    car1.speed_x = c1sx;
    car1.speed_y = c1sy;
    car1.x = c1x;
    car1.y = c1y;

    
    
    car car2;
    car2.make = "Honda";
    car2.model = "city";
    car2.year = 2020;
    car2.speed_x = c2sx;
    car2.speed_y = c2sy;
    car2.x = c2x;
    car2.y = c2y;

    
    int f = 1;
    double time = 0;
    double rate = 0.0001;
while(!(fabs(car1.x - car2.x)<0.0001 || fabs(car1.y - car2.y)<0.0001)){
        time += rate;
        car1.move(rate);
        car2.move(rate);
        cout << "( " << car1.x << ", " << car1.y << ") (" << car2.x << ", " << car2.y << ") \n";
        if(fabs(car1.x - car2.x)> 50000 || fabs(car1.y - car2.y) > 50000) {f = 0; break;}
    }
    cout << "time : " <<time << "\n";
    
    (f)? cout << "Collision\n" : cout << "Noccccc\n";
    cout << car1.x << " " << car2.x << "\n";
    
    
    cout<<car2.x<<endl;
return 0;
}