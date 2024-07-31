// Section 11
// Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.
    
    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.
    
    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.
    
        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth
        
    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!
    
    Finally,  don't forget to use function prototypes!
    
    Good luck -- I know you can do it!
*/

// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

void start_program();
char prompt_user();
void select_action(const char &prompt,std::vector<int> &list);

int main() {
    
    start_program();
    
    std::cout << std::endl;
    return 0;
}

void start_program() {

    std::vector<int> list {};
    char prompt {};
    do {
        prompt = prompt_user();
        select_action(prompt,list);
    } while (prompt != 'q' and prompt != 'Q');

}

char prompt_user(){

    char prompt {};
    std::cout << "---------------------" << std::endl
            << "Command list: " << std::endl
            << "P - Print numbers" << std::endl
            << "A - Add a number" << std::endl
            << "M - Display mean of the numbers" << std::endl
            << "S - Display the smallest number" << std::endl
            << "L - Display the largest number" << std::endl
            << "Q - Quit" << std::endl
            << "\nSelect a command: ";
    std::cin >> prompt;

    return prompt;
}

void select_action(const char &prompt,std::vector<int> &list){

    switch (prompt){
        case 'p': //intentional to achieve p OR P
        case 'P':
            // case p or P - print
            if (!list.empty()){
                std::cout << "[ ";
                for (auto element: list)
                    std::cout << element << " ";
                std::cout << "]" << std::endl;
            } else
                std::cout << "[] - the list is empty" << std::endl;
            break;
        case 'a': 
        case 'A':{ //brackets needed to declare the scope for the number variable    
            // case a or A - add
            std::cout << "Provide a number: ";
            int number {};
            std::cin >> number;
            list.push_back(number);
            std::cout << number << " added" << std::endl;
            break;
        } 
        case 'm': 
        case 'M':{
            // case m or M - mean
            if (!list.empty()){
                int running_sum {};
                for (auto element: list)
                    running_sum += element;
                // std::cout << std::fixed << std::setprecision(2); //Optional to set the precion of the output
                std::cout << static_cast<double>(running_sum) / list.size() << std::endl; // (double) / (int) = (double)
            } else
                std::cout << "Unable to calculate the mean - no data" << std::endl;
            break;
        }
        case 's': 
        case 'S':{
            // case s or S - smallest
            if (!list.empty()){
                int smallest {INT_MAX};
                int index {};
                int i {};
                for (auto element: list){
                    index = (element < smallest)?i:index; // if element is smaller then assign new index else keep the old one
                    smallest = (element < smallest)?element:smallest;
                    ++i;
                }
                std::cout << smallest << " at [" << index << "]" << std::endl;
            } else
                std::cout << "Unable to determine the smallest number - list is empty" << std::endl;
            break;
        }
        case 'l': 
        case 'L':
            // case l or L - largest
            if (!list.empty()){
                int largest {}, index {}, i{};
                for (auto element: list){
                    index = (element > largest)?i:index;
                    largest = (element > largest)?element:largest;
                    ++i;
                }
                std::cout << largest << " at [" << index << "]" << std::endl;
            } else
                std::cout << "Unable to determine the largest number - list is empty" << std::endl;
            break;
        case 'q': 
        case 'Q':
            // case q or Q - quit
            std::cout << "Goodbye" << std::endl;
            break;
        default:
            std::cout << "Unknown selection, please try again" << std::endl;
    }

}