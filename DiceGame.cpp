/*-----------------------------------------------------------------------------------
1. The program asks for input until a valid choice (4-20) is given by the user
2. The program asks if the user wants to play again after each round (y/n)
3. if yes (y), the user is asked to choose a number of sides again
4. if no (n), the program gives a thank you message and instructs the user to press [RETURN] to exit (and waits for [RETURN] before exiting)

--------------------------------------------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int chooseSides(); 
void chooseNumbers(int num); 
char playagain();

int main()
{
    srand(time(0)); //seed random number generator 
    
    do {
        int sides = chooseSides(); //Call Function chooseSides() 
        chooseNumbers(sides); 
    } while ( playagain() == 'Y');

    return 0;
}
//function for choosing sides
int chooseSides()
{
    int num; // integer variable for number

    cout << "You are about to roll a single die" << endl;
    cout << "How many sided die would you like to roll (4-20)? ";
    cin >> num;
    cin.ignore(); // ignore newline in buffer

    while (num < 4 || num > 20) {
        cout << "Please enter a number between 4 and 20." <<endl;
        cin >> num;
        cin.ignore(); // ignore newline in buffer
    }
    
    return num;
}
//function for choosing numbers and makes number in roll random
void chooseNumbers(int num)
{
    int roll = 1 + rand() % num; //mods random number
    cout << "You rolled: " << roll << endl;
}
//Function to ask user if they want to play again. 
char playagain()
{
    char answer = ' ';
    while (answer != 'Y' && answer != 'N') {
        cout << "Play again (Y/N)? ";
        cin >> answer;
        cin.ignore(); // ignore newline in buffer
        answer = toupper(answer); // Makes it so Y and N can either be capitalized or not
    }
    // If answer equals Y the user can play again if user enters N game ends and exits.
    if (answer == 'Y') {
        cout << "Thank you! Please press RETURN to start again." << endl;
        cin.get();
        cout << "Starting again..." << endl;
    } else if (answer == 'N') {
        cout << "Thank you! Please press RETURN to exit." << endl;
        cin.get();
        cout << "Exiting..." << endl;
    }
    
    return answer;
}