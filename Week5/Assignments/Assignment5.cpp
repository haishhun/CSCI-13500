#include <iostream>
#include <random>
#include <string>

/*This function prints the welcome message for the game.*/
void PrintWelcomeMessage();

/*This function prompts the user to enter the number of rounds they want to play
 * and returns the value.*/
int GetRounds();

/*This function prompts the user to enter their move and returns the value.*/
std::string GetPlayerMove();

/*This function generates the bot's move and returns the value.*/
std::string GetBotMove();

/*This function prints the score for a single round.
@player_score: The player's score.
@bot_score: The bot's score.
*/
void PrintRoundScore(int player_score, int bot_score);

/*This function determines the winner of a round and updates the scores.
@player_move: The player's move.
@bot_move: The bot's move.
@player_score: The player's score.
@bot_score: The bot's score.
*/
bool DetermineRoundWinner(const std::string& player_move,
                          const std::string& bot_move, int& player_score,
                          int& bot_score);

/*This function prints the final score of the game.
@player_score: The player's score.
@bot_score: The bot's score.
*/
void PrintFinalScore(int player_score, int bot_score);

/*This function asks the user if they want to play again and returns a boolean
 * value.*/
bool AskPlayAgain();

/*This function plays the game for the specified number of rounds.
@rounds: The number of rounds to play.
@player_score: The player's score.
@bot_score: The bot's score.
*/
void PlayGame(int rounds, int& player_score, int& bot_score);

int main() {
  PrintWelcomeMessage();
  while (true) {
    int player_score = 0;
    int bot_score = 0;
    int rounds = GetRounds();

    PlayGame(rounds, player_score, bot_score);
    PrintFinalScore(player_score, bot_score);

    if (!AskPlayAgain()) {
      break;
    }
  }
}

void PrintWelcomeMessage() {
  std::cout << "Welcome to the Rock, Paper, Scissor game." << std::endl;
}

int GetRounds() {
  int rounds = 0;
  // Asking user for rounds input and validating the input.
  while (true) {
    std::cout << "Please enter the amount of rounds you want to play: ";

    if (!(std::cin >> rounds) || rounds <= 0) {
      std::cout << "Error: Invalid amount of rounds. Please enter again.\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    } else {
      std::cin.ignore(10000,
                      '\n');  // Handling float inputs into rounds variable.
      break;
    }
  }
  return rounds;
}

std::string GetPlayerMove() {
  std::string player_move = "";
  while (true) {
    std::cout << "Please choose your move (Rock, Paper or Scissor): ";
    std::cin >> player_move;

    // Handling uppercase and lowercase inputs.
    for (int j = 0; j < player_move.size(); j++) {
      if (player_move[j] >= 'a' && player_move[j] <= 'z')
        player_move[j] = player_move[j] - 'a' + 'A';
    }

    // Validating user's input.
    if (player_move != "ROCK" && player_move != "PAPER" &&
        player_move != "SCISSOR") {
      std::cout << "Error: Invalid move. Please enter again.\n";
      continue;  // Running the loop again to get a valid move from the user.
    }

    break;  // Valid move, exit and return it
  }
  return player_move;
}

std::string GetBotMove() {
  int bot_move = 0;
  std::string bot_pick = "";

  // Generate bot input
  bot_move = rand() % 3;

  if (bot_move == 0) {
    bot_pick = "Rock";
  } else if (bot_move == 1) {
    bot_pick = "Paper";
  } else {
    bot_pick = "Scissor";
  }

  std::cout << "Bot picked: " << bot_pick << std::endl;

  // Transforming bot's choice into uppercase to match user's input uppercase
  for (int k = 0; k < bot_pick.size(); k++) {
    if (bot_pick[k] >= 'a' && bot_pick[k] <= 'z')
      bot_pick[k] = bot_pick[k] - 'a' + 'A';
  }

  return bot_pick;
}

void PrintRoundScore(int player_score, int bot_score) {
  std::cout << "Player " << player_score << ":" << bot_score << " Bot"
            << std::endl;
}

bool DetermineRoundWinner(const std::string& player_move,
                          const std::string& bot_move, int& player_score,
                          int& bot_score) {
  if (player_move == bot_move) {
    std::cout << "Tie! Both picked the same move!" << std::endl;
    return true;
  } else if ((player_move == "ROCK" && bot_move == "SCISSOR") ||
             (player_move == "PAPER" && bot_move == "ROCK") ||
             (player_move == "SCISSOR" && bot_move == "PAPER")) {
    player_score++;
  } else {
    bot_score++;
  }

  // Returning score each round for better experience for the user.
  PrintRoundScore(player_score, bot_score);
  return false;
}

void PrintFinalScore(int player_score, int bot_score) {
  // Returning the score table in the end.
  std::cout << std::endl;
  std::cout << "------------------" << std::endl;
  std::cout << "| Player " << player_score << ":" << bot_score << " Bot |"
            << std::endl;
  std::cout << "------------------" << std::endl;

  // Declare winner or tie.
  if (player_score > bot_score) {
    std::cout << "   Player wins!" << std::endl << std::endl;
  } else if (bot_score > player_score) {
    std::cout << "    Bot wins!" << std::endl << std::endl;
  } else {
    std::cout << "       Tie!" << std::endl << std::endl;
  }
}

bool AskPlayAgain() {
  char continue_option = ' ';

  // Asking user if he wants to play again.
  std::cout << "Enter Y to play again. Any other key to exit.\n";
  std::cin >> continue_option;
  std::cin.ignore(10000, '\n');  // Handling inputs like "y3A+" etc.

  if (continue_option != 'y' && continue_option != 'Y') {
    return false;
  }
  return true;
}

void PlayGame(int rounds, int& player_score, int& bot_score) {
  // Running the game for the amount of rounds chosen until someone wins or tie
  // for even amount of rounds.
  for (int i = 0; i < rounds; i++) {
    if (player_score - bot_score > rounds - i ||
        bot_score - player_score > rounds - i) {
      break;
    }

    std::string player_move = GetPlayerMove();
    std::string bot_move = GetBotMove();

    if (DetermineRoundWinner(player_move, bot_move, player_score, bot_score)) {
      i--;
    }
  }
}
