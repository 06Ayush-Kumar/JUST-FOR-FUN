// This project simulates the conditions under which a leaf will detach from a tree based on user-defined inputs for mass, area, wind speed, and tensile strength of the leaf material.
//
// Theoretical Background:
//
// 1. **Forces Acting on the Leaf**:
//    - **Gravitational Force (Weight)**: The force due to gravity acting on the leaf, calculated as:
//      F_gravity = mass * g
//      where g is the acceleration due to gravity (approximately 9.8 m/s^2).
//
//    - **Drag Force**: The aerodynamic force acting against the wind. This force is influenced by the wind speed, the cross-sectional area of the leaf, and the drag coefficient (Cd). The drag force can be calculated using the formula:
//      F_drag = 0.5 * Cd * density * area * wind_speed^2
//      where:
//        - Cd is the drag coefficient (depends on the shape of the object, typically around 1.2 for flat plates).
//        - density is the air density (approximately 1.225 kg/m^3 at sea level).
//
// 2. **Tensile Strength**: This is the maximum amount of tensile (pulling) stress that a material can withstand before failure. The attachment force of the leaf can be calculated based on its tensile strength and area:
//    F_attachment = tensile_strength * area
//
// 3. **Detachment Condition**:
//    - The leaf will remain attached to the tree if the attachment force is greater than the total force acting on it (which includes both gravitational and drag forces). The total force is calculated as:
//      total_force = sqrt(F_drag^2 + F_gravity^2)
//    - If the drag force exceeds the attachment force, the leaf will detach from the tree.
//
// This simulation allows users to input various parameters (mass, area, wind speed, tensile strength) and observe how they affect the stability of a leaf on a tree under wind conditions.


#include <iostream>
#include <cmath>
using namespace std;

class Leaf {
private:
    float wind_speed;    
    float mass;          
    float area;          
    float attach_force;  
    float tensile_strength;
    
    const float g = 9.8;        
    const float density = 1.225; 
    const float Cd = 1.2;      

public:
    
    Leaf(float ws, float m, float a, float ts) {
        check_wind_speed(ws);
        check_mass(m);
        check_area(a);
        check_tensile_strength(ts);
    }

    void check_wind_speed(float ws) {
        if (ws >= 0) {
            wind_speed = ws;
        } else {
            cout << "Wind speed can't be negative. Setting to 0." << endl;
            wind_speed = 0;
        }
    }

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

    void check_tensile_strength(float ts) {
        if (ts >= 0) {
            tensile_strength = ts;
        } else {
            cout << "Tensile strength can't be negative. Setting to 0." << endl;
            tensile_strength = 0;
        }
    }

    float calculateDragForce() const {
        return 0.5 * Cd * density * area * wind_speed * wind_speed;
    }

    float calculateAttachForce() {
        attach_force = tensile_strength * area;
        return attach_force;
    }

    void displayDragForce() {
        cout << "Drag Force: " << calculateDragForce() << " N" << endl;
    }

    void displayAttachForce() {
        cout << "Attachment Force: " << calculateAttachForce() << " N" << endl;
    }

    void checkDetachment() const {
        float drag_force = calculateDragForce();
        float attachment_force = calculateAttachForce();
        float total_force = sqrt((drag_force * drag_force) + (mass * g) * (mass * g));

        if (wind_speed == 0) {
            float attach_force_calc = mass * g;
            cout << "The leaf will not detach. Attach force: " << attach_force_calc << " N" << endl;
        } else if (attachment_force > total_force) {
            cout << "The leaf will stay attached." << endl;
        } else {
            cout << "The leaf will detach." << endl;
        }
    }
};

int main() {
    float mass, area, wind_speed, tensile_strength;  
    
    cout << "Please enter the mass of the leaf (kg): ";
    cin >> mass;
    cout << "Please enter the area of the leaf (m²): ";
    cin >> area;
    cout << "Tell the wind speed (m/s): ";
    cin >> wind_speed;
    cout << "Write the tensile strength (N/m²): ";  
    cin >> tensile_strength;
    
    Leaf leaf(wind_speed, mass, area, tensile_strength);
    
    leaf.displayDragForce();
    leaf.displayAttachForce(); 
    leaf.checkDetachment();

    return 0;
}





