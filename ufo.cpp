#include <iostream>
#include "ufo_functions.hpp"

int main() {

/* STANDARD PROCEDURE */

  greet();

  //Data Structures
  std::string codeword="peekaboo"; //word to guess
  std::string answer="__________"; //placeholder for input
  int misses = 0; //num of misses
  std::vector<char> incorrect;//array of incorrect answers
  bool guess=false; //guess status
  char letter; //user input

/* GAME ITERATION */
  while(answer!=codeword && misses<7) {
    
    /* Game Animation */
    display_misses(misses);
    display_status(incorrect, answer); //display's status

    /*--------------------------*/
    //real logic starts here
    std::cout << "Please enter your guess: ";
    std::cin >> letter;

    for(int i=0; i<codeword.length(); i++) {
      if(codeword[i]==letter) {
        answer[i]=letter;
        guess=true;
      }
    }

    if(guess==true) {
      std::cout << "Correct!";
    } else { 
      std::cout << "Incorrect! The tractor beam pulls the person in further.";
      incorrect.push_back(letter);
      misses++;
    }
    // misses++;
    guess=false;
  }
  
  end_game(answer, codeword); 
}
