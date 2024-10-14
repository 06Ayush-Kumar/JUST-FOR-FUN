// This project simulates the characteristics of different animals based on user-defined inputs for life status, number of legs, and presence of a backbone.
//
// Theoretical Background:
//
// 1. **Animal Classification**:
//    Animals can be broadly classified into two main categories based on their life status:
//    - **Alive**: Indicates that the animal is currently living and functional.
//    - **Dead**: Indicates that the animal is no longer living.
//
// 2. **Legs**:
//    The number of legs is a key characteristic in classifying animals. Common classifications include:
//    - **Alegic**: Animals with no legs (e.g., some species of snakes).
//    - **Bipedal**: Animals with two legs (e.g., humans, birds).
//    - **Quadrupedal**: Animals with four legs (e.g., dogs, cats).
//    - **Hexapod**: Animals with six legs (e.g., insects).
//    - **Octopod**: Animals with eight legs (e.g., octopuses).
//    - **Decapod**: Animals with ten legs (e.g., certain crustaceans).
//
// 3. **Backbone**:
//    - **Vertebrate**: Animals that possess a backbone (e.g., mammals, birds, reptiles).
//    - **Invertebrate**: Animals that lack a backbone (e.g., insects, mollusks).
//
// 4. **Object-Oriented Programming (OOP) Concepts**:
//    - This project demonstrates basic OOP principles including encapsulation, where the attributes of the `Animal` class (life, legs, backbones) are kept private to maintain data integrity.
//    - The class provides setter functions to update these attributes and print information about the animal based on user input.
//    - Getter functions allow access to the attributes if needed in future expansions of the program.
//
// 5. **User Interaction**:
//    The program prompts the user to input the number of animals they wish to create, along with the characteristics of each animal. Each animal object is instantiated with the provided details, demonstrating the flexibility of the class to represent various animals.

#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    bool life;
    int legs;
    bool backbones;

public:
    // Constructor
    Animal(bool lyf = true, int le = 0, bool back = true) {
        setlife(lyf);
        setlegs(le);
        setbackbones(back);
    }

    // Setter functions with void return type
    void setlife(bool l) {
        life = l;
        cout << (life ? "The animal is alive\n" : "The animal is dead\n");
    }

    void setlegs(int x) {
        legs = x;
        switch (x) {
            case 0: cout << "The animal is Alegic\n"; break;
            case 2: cout << "The animal is Bipedal\n"; break;
            case 4: cout << "The animal is Quadrupedal\n"; break;
            case 6: cout << "The animal is Hexapod\n"; break;
            case 8: cout << "The animal is Octopod\n"; break;
            case 10: cout << "The animal is Decapod\n"; break;
            default: cout << "Wrong input\n"; break;
        }
    }

    void setbackbones(bool y) {
        backbones = y;
        cout << (backbones ? "The animal is Vertebrate\n" : "The animal is Invertebrate\n");
    }

    // Getter functions
    int getlegs() {
        return legs;
    }

    bool getlife() {
        return life;
    }

    bool getbackbones() {
        return backbones;
    }
};

int main() {
    int legs, n;
    bool backbones, life;
    string animalName;

    cout << "How many animals do you want to create?" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the name of the animal: ";
        cin >> animalName;  // This variable is for user input but not used in Animal creation
        cout << "Enter the number of legs: ";
        cin >> legs;
        cout << "Is the animal alive (1 for true, 0 for false)? ";
        cin >> life;
        cout << "Does the animal have a backbone (1 for true, 0 for false)? ";
        cin >> backbones;

        // Creating the animal object
        Animal a(life, legs, backbones);
    }

    return 0;
}
