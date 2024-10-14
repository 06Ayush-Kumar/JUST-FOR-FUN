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
    
    Leaf(float ws, float m, float a, float af) {
        check_wind_speed(ws);
        check_mass(m);
        check_area(a);
        check_attach_force(af);
    }

    
    void check_wind_speed(float ws) {
        if (ws >= 0) {
            wind_speed = ws;
        } else {
            cout << "Wind speed can't be negative. Setting to 0." << endl;
            wind_speed = 0;
        }
    }

    // Method to check mass
    void check_mass(float m) {
        if (m >= 0) {
            mass = m;
        } else {
            cout << "Mass can't be negative. Setting to 0." << endl;
            mass = 0;
        }
    }

    
    void check_area(float a) {
        if (a >= 0) {
            area = a;
        } else {
            cout << "Area can't be negative. Setting to 0." << endl;
            area = 0;
        }
    }

   
    void check_attach_force(float af) {
        if (af >= 0) {
            attach_force = af;
        } else {
            cout << "Attach force can't be negative. Setting to 0." << endl;
            attach_force = 0;
        }
    }

   
    float calculateDragForce() const {
        return 0.5 * Cd * density * area * wind_speed * wind_speed;
    }

   
    void checkDetachment() const {
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
    float mass, area, wind_speed, attach_force;
    
    cout << "Please enter the mass of the leaf: ";
    cin >> mass;
    cout << "Please enter the area of the leaf: ";
    cin >> area;
    cout << "Tell the wind speed: ";
    cin >> wind_speed;
    cout << "Write the attach force: ";
    cin >> attach_force;
    
    
    Leaf leaf(wind_speed, mass, area, attach_force);
    
  
    leaf.checkDetachment();

    return 0;
}




