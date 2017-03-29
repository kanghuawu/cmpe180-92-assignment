#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

void simulate(int sequence, int& win1, int& win2);    // run simulation
Door randomDoor();    // return 1, 2 or 3 randomly
Door hideCar();    // return the door number with a car
Door FirstChoice();    // return player's first choice
Door MontyDoor(Door firstChoiceDoor, Door carBehindDoor);    // return the door number Monty opened
Door SecondChoice(Door firstChoiceDoor, Door openedDoor);    // return the door number after switching
void printHeader();    // print header

/**
 * Main
 */
int main()
{
    int win1 = 0, win2 = 0;
    
    srand(time(NULL));  // seed the random number generator
    printHeader();
    
    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);
    
    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    
    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}

/***** Complete this program. ****/

void simulate(int sequence, int& win1, int& win2){
    Door CarDoor = hideCar();
    Door FirstDoor = FirstChoice();
    Door OpenedDoor = MontyDoor(FirstDoor, CarDoor);
    Door SecondDoor = SecondChoice(FirstDoor, OpenedDoor);
    
    // print out each simulation result
    cout << setw(4) << sequence;
    cout << setw(8) << CarDoor;
    cout << setw(8) << FirstDoor;
    cout << setw(8) << OpenedDoor;
    cout << setw(8) << SecondDoor;
    
    
    if(FirstDoor == CarDoor){
        win1++;
        cout << setw(8) << "yes";    // the first door win
    }else{
        win2++;
        cout << setw(16) << "yes";   // the second (switching) door win
    }
    cout << endl;
}

Door randomDoor(){
    return rand()%3+1;
}

Door hideCar(){
    return randomDoor();
}

Door FirstChoice(){
    return randomDoor();
}

Door MontyDoor(Door firstChoiceDoor, Door carBehindDoor){
    Door DoortoOpen;
    do {
        DoortoOpen = randomDoor();
    } while (DoortoOpen == firstChoiceDoor || DoortoOpen == carBehindDoor);
    return DoortoOpen;
}

Door SecondChoice(Door firstChoiceDoor, Door openedDoor){
    if(firstChoiceDoor != 1 && openedDoor !=1){
        return 1;
    }else if (firstChoiceDoor != 2 && openedDoor !=2){
        return 2;
    }else{
        return 3;
    }
}


void printHeader(){
    // first line
    cout << setw(4) << "#";
    cout << setw(8) << "Car";
    cout << setw(8) << "First";
    cout << setw(8) << "Opened";
    cout << setw(8) << "Second";
    cout << setw(8) << "Win";
    cout << setw(8) << "Win" << endl;
    
    // second line
    cout << setw(12) << "here";
    cout << setw(8) << "choice";
    cout << setw(8) << "door";
    cout << setw(8) << "choice";
    cout << setw(8) << "first";
    cout << setw(8) << "second" << endl;
    cout << endl;
}