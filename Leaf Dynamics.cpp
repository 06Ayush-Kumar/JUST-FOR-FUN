// This project simulates the conditions under which a leaf will detach from a tree based on user-defined inputs for mass, area, wind speed, and attachment force.

#include <iostream>
#include <cmath>
using namespace std;

class Leaf {
private:
    float wind_speed;    
    float mass;          
    float area;          
    float attach_force;  
    
    const float g = 9.8;        
    const float density = 1.225; 
    const float Cd = 1.2;      

public:
    
    Leaf(float ws, float m, float a, float af) 
        : wind_speed(ws), mass(m), area(a), attach_force(af) {}

    
    float calculateDragForce() {
        return 0.5 * Cd * density * area * wind_speed * wind_speed;
    }

    
    void checkDetachment() {
        float drag_force = calculateDragForce();
        float total_force = sqrt((drag_force * drag_force) + (mass * g) * (mass * g));

        if (wind_speed == 0) {
            float attach_force_calc = mass * g;
            cout << "The leaf will not detach. Attach force: " << attach_force_calc << endl;
        } else if (attach_force > total_force) {
            cout << "The leaf will stay attached." << endl;
        } else {
            cout << "The leaf will detach." << endl;
        }
    }
};

int main() {
float mass,area,wind_speed,attach_force;
    cout<<"please enter the mass of the leaf\n";
    cin>>mass;
    cout<<"please enter the area of the leaf\n";
    cin>>area;
    cout<<"tell the wind speed\n";
    cin>>wind_speed;
    cout<<"write the attach force\n";
    cin>>attach_force;
    
    Leaf leaf(wind_speed, mass, area, attach_force);

    
    leaf.checkDetachment();

    return 0;
}





