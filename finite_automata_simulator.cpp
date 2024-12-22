// finite automata simulator:


// number of states eg q0,q1,q2
// end state and start state 
// number of alphabet eg 0,1,2,3
// condition for state to move  eg q0,0,q0;q0,1,q2

// blueprint:

//First, ask the user how many states the automaton will have and give each state a name. Then, figure out which state will be the starting one
// and which will be the ending one.
//Next, ask the user how many symbols (or characters) will be in the alphabet and store those symbols.
//For each combination of state and symbol, ask the user where the automaton should go next, and create a transition table to store these rules.
//Let the user test the automaton by providing an input string, and follow the transitions to see if it ends in the final state.
//Finally, show the user the states, the alphabet symbols, and the transition table so they can understand how the automaton works.

// updates:
// used 2 do while loop for continuous use of finite auotmata
// now user can enter new string for the old input



// code:
#include<iostream>
#include<vector>
#include<string>
using namespace std;
using str=string;

void state_input(vector<str>&state)
{
int n;   // for number of state and name of state
str name;
cout<<"enter the number of states";
cin>>n;
for (int i=0;i<n;i++){
cout<<"enter the state name";
cin>>name;
state.push_back(name);
}
};
void alphabet_input(vector<str>&alphabet){
int number;   // number of alphabet and value of alphabet
cout<<"enter the number of alphabet";
cin>>number;
str alp;
for (int j=0;j<number;j++){
cout<<"enter the alphabet";
cin>>alp;
alphabet.push_back(alp);
}
};

int start_state(vector<str>&state){
str start_state_value;
cout<<"enter the start state";
cin>>start_state_value;
/*
int count=0;
for (str x:state){
if (x==start_state){
return count;
break;
}

else{
  count++;
 }

}
return -1;
*/
for (int x=0;x<state.size();x++){
  if (state[x]==start_state_value){
return x;
break;

}
}
return -1;      // will return -1 when element not found so if element will found then x will return and fucntion will stop 
}
int end_state(vector<str>&state){
str end_state_value;
cout<<"enter the end state";
cin>>end_state_value;
for (int x=0;x<state.size();x++){
  if (state[x]==end_state_value){
return x;
break;
}
}
return -1;
}
void transition_input(vector<vector<int>>& transitions, const vector<str>& state, const vector<str>& alphabet) {
    int n;
    cout << "Enter the number of transitions: ";
    cin >> n;

    str current_state, input_symbol, next_state;
    int current_state_index, next_state_index, input_symbol_index;

    // Initialize transitions matrix with -1 (no transition)
    transitions.resize(state.size(), vector<int>(alphabet.size(), -1));

    for (int i = 0; i < n; i++) {
        cout << "Enter the transition (current state, input symbol, next state): ";
        cin >> current_state >> input_symbol >> next_state;

        current_state_index = -1;
        for (int j = 0; j < state.size(); j++) {
            if (state[j] == current_state) {
                current_state_index = j;
                break;
            }
        }

        next_state_index = -1;
        for (int j = 0; j < state.size(); j++) {
            if (state[j] == next_state) {
                next_state_index = j;
                break;
            }
        }

        input_symbol_index = -1;
        for (int j = 0; j < alphabet.size(); j++) {
            if (alphabet[j] == input_symbol) {
                input_symbol_index = j;
                break;
            }
        }

        if (current_state_index != -1 && next_state_index != -1 && input_symbol_index != -1) {
            transitions[current_state_index][input_symbol_index] = next_state_index;
        } else {
            cout << "Invalid transition. Please check the states and alphabet symbols." << endl;
        }
    }
}

bool check_input(const string& input, const vector<str>& state, const vector<str>& alphabet, const vector<vector<int>>& transitions, int start_state_index, int end_state_index) {
    int current_state_index = start_state_index; 
    for (char c : input) {
        string symbol(1, c); 

        
        int symbol_index = -1;
        for (int i = 0; i < alphabet.size(); i++) {
            if (alphabet[i] == symbol) {
                symbol_index = i;
                break;
            }
        }

        if (symbol_index == -1) {
            return false;  // No valid symbol found in alphabet
        }

        
        int next_state_index = transitions[current_state_index][symbol_index];
        if (next_state_index == -1) {
            return false;  
        }

        current_state_index = next_state_index; 
    }

    return current_state_index == end_state_index; // Check if the final state is the end state
}


int main(){

                         // using for continuous use of the fintie automata 
  vector<str> state;
    vector<vector<int>> transitions;
    vector<str> alphabet;
   // int case        // don't use case as it is reserved variable
    int ch;
    string input;
    // int start_state_index;  // declaring here so it can be access throught whole switch case
  //  int end_state_index;
   int choice;
do{
    state_input(state);
    alphabet_input(alphabet);

    int start_state_index = start_state(state);
    int end_state_index = end_state(state);

    cout << "The states are: ";
    for (str x : state) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "The alphabet symbols are: ";
    for (str x : alphabet) {
        cout << x << " ";
    }
    cout << "\n";

    cout << "Start state value: ";
    if (start_state_index == -1) {
        cout << "Start state not found.\n";
    } else {
        cout << state[start_state_index] << "\n";
    }

    cout << "End state value: ";
    if (end_state_index == -1) {
        cout << "End state not found.\n";
    } else {
        cout << state[end_state_index] << "\n";
    }

    
    transition_input(transitions, state, alphabet);
//int choice; it works for this do while loop but now i want it to work for the bigger while loop.thatswhy declaring it on top
 do{
  
  cout << "Enter a string to check: ";
    cin >> input;

    if (check_input(input, state, alphabet, transitions, start_state_index, end_state_index)) {
        cout << "The string is accepted by the automaton.\n";
    } else {
        cout << "The string is not accepted by the automaton.\n";
    }
  // int choice;   have to declare it outside of do loop as it is not accessed by while ()
   cout<<"if u want to enter a new string then enter  1\n";
cout<<"if u want to enter a  new automata then press 2\n";
cout<<"if u want to exit then press any integer rather than 1 and 2\n";
   cin>>choice;
   


}while(choice==1);

}while(choice==2); 
cout<<"than you for using my finite automata simulator .I hope u have enjoyed it\n";
    return 0;
}
