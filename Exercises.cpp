#include <iostream>
#include <string>
#include <iomanip> // For std::setw
#include <cmath>
#include <vector>

void  F_to_C() {
    float fahrenheit{};
    float celsius{};

    std::cout << "Enter fahrenheits\n";
    std::cin >> fahrenheit;
    celsius = static_cast<float>((fahrenheit - 32) * 0.5556);

    std::cout << "Celsius - " << celsius;

}


int pos_Neg_check() {
    signed long number;
    std::cout << "Enter a Number\n";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Number is negative";
    }

    if (number > 0) {
        std::cout << "Number is positive";
    }

    return 0;
}



int first_five_dividers() {
    int userinput;
    std::vector<int> numbers;
    std::cout << "Enter a Number";
    std::cin >> userinput;
    int i = 1;

    while (true) {

        int remainder = userinput % i;

        //if no remainder, then it's divisible
        if (remainder == 0) {
            numbers.push_back(i);
        }

        //break when we have 5 numbers. or equal to user input. 
        if (numbers.size() == 5 || i == (userinput-1)){
            break;
        }

        i += 1;
    }

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << "\n";
    }

    return 0;
}



/*
You work in a toy car workshop, and your job is to build toy cars from a collection of parts.
Each toy car needs 4 wheels, 1 car body, and 2 figures of people to be placed inside.
Given the total number of wheels, car bodiesand figures available, how many complete toy cars can you make ?
*/
void toyCarFactory() {

    int wheels{};
    int bodies{};
    int engins{};

    std::cout << "How many wheels?\n";
    std::cin >> wheels;

    std::cout << "How many bodies?\n";
    std::cin >> bodies;

    std::cout << "How many engins?\n";
    std::cin >> engins;

    bool finished{ false };

    int max{0};

    //checking how many cars can made from wheels
    max = (wheels / 4);
    
    //checking how many cars can made from bodies
    if (max > bodies) {
        max = bodies;
    }  

    //checking how many cars can made from engines
    if (max > engins) {
        max = engins;
    }

    std::cout << max << " car(s) can be made\n";

    
}




void letters_shared_between_words() {

    std::string longWord{};
    std::string shortWord{};

    std::cout << "Enter a word\n";
    std::cin >> longWord;

    std::cout << "Enter another word\n";
    std::cin >> shortWord;

    std::vector<char> matchingLetters;

    //set the long word correctly
    if (shortWord.length() > longWord.length()) {
        std::string tmp_longWord = longWord;
        longWord = shortWord;
        shortWord = tmp_longWord;
    }


    for (int i = 0; i < longWord.length(); i++) {
        for (int t = 0; t < shortWord.length(); t++) {
            if (longWord[i] == shortWord[t] && (std::find(matchingLetters.begin(), matchingLetters.end(), longWord[i]) == matchingLetters.end())) { //return end of vect if nothing found. so if statement is true when nothing found.
                matchingLetters.push_back(longWord[i]);
                std::cout << longWord[i] << " match" << std::endl;
            }
        }
    }
    std::cout << "\n" << matchingLetters.size() << " matching letters found!!" << std::endl;

}



int main() {

    //first_five_dividers();
    //pos_Neg_check();
    //F_to_C();
    //toyCarFactory();
    //letters_shared_between_words();

}

