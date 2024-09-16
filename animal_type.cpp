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
