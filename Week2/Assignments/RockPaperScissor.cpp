#include <iostream>
#include <random>
#include <string>

int main()
{
    // Declare variables for scores.
    int player_score = 0;
    int bot_score = 0;

    // Declare variables for player's and bot's moves.
    std::string player_move = "";
    int bot_move = 0;
    std::string bot_pick = "";

    // Declare variables for settings.
    int rounds = 0;
    char continue_option = ' ';

    std::cout
        << "Welcome to the Rock, Paper, Scissor game." << std::endl;

    // Infinitely run the program until user wants to exit.
    while (true)
    {
        // Clearing variables after each game.
        player_score = 0;
        bot_score = 0;

        // Asking user for rounds input and validating the input.
        while (true)
        {
            std::cout << "Please enter the amount of rounds you want to play: ";

            if (!(std::cin >> rounds) || rounds <= 0)
            {
                std::cout << "Error: Invalid amount of rounds. Please enter again.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            else
            {
                std::cin.ignore(10000, '\n'); // Handling float inputs into rounds variable.
                break;
            }
        }

        // Running the game for the amount of rounds chosen until someone wins or tie for even amount of rounds.
        for (int i = 0; i < rounds; i++)
        {

            // check for early winner
            if (player_score - bot_score > rounds - i || bot_score - player_score > rounds - i)
            {
                break;
            }

            // Asking user to input his move
            std::cout << "Please choose your move (Rock, Paper or Scissor): ";
            std::cin >> player_move;

            // Handling uppercase and lowercase inputs.
            for (int j = 0; j < player_move.size(); j++)
            {
                if (player_move[j] >= 'a' && player_move[j] <= 'z')
                    player_move[j] = player_move[j] - 'a' + 'A';
            }

            // Validating user's input.
            if ((player_move != "ROCK") && (player_move != "PAPER") && (player_move != "SCISSOR"))
            {
                std::cout << "Error: Invalid move. Please enter again.\n";
                i--; // Don't count the round if input is incorrect.
                continue;
            }

            // Generate bot input
            bot_move = rand() % 3;

            if (bot_move == 0)
            {
                bot_pick = "Rock";
            }
            else if (bot_move == 1)
            {
                bot_pick = "Paper";
            }
            else
            {
                bot_pick = "Scissor";
            }

            std::cout << "Bot picked: " << bot_pick << std::endl;

            // Transforming bot's choice into uppercase to match user's input uppercase
            for (int k = 0; k < bot_pick.size(); k++)
            {
                if (bot_pick[k] >= 'a' && bot_pick[k] <= 'z')
                    bot_pick[k] = bot_pick[k] - 'a' + 'A';
            }

            // Figure out the winner of the round.
            if (player_move == bot_pick)
            {
                std::cout << "Tie! Both picked the same move!" << std::endl;
                i--;
            }
            else if (player_move == "ROCK" && bot_pick == "SCISSOR")
            {
                player_score++;
            }
            else if (player_move == "PAPER" && bot_pick == "ROCK")
            {
                player_score++;
            }
            else if (player_move == "SCISSOR" && bot_pick == "PAPER")
            {
                player_score++;
            }
            else
            {
                bot_score++;
            }

            // Returning score each round for better experience for the user.
            std::cout << "Player " << player_score << ":" << bot_score << " Bot" << std::endl;
        }

        // Returning the score table in the end.
        std::cout << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "| Player " << player_score << ":" << bot_score << " Bot |" << std::endl;
        std::cout << "------------------" << std::endl;

        // Declare winner or tie.
        if (player_score > bot_score)
        {
            std::cout << "   Player wins!" << std::endl
                      << std::endl;
        }
        else if (bot_score > player_score)
        {
            std::cout << "    Bot wins!" << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "       Tie!" << std::endl
                      << std::endl;
        }

        // Asking user if he wants to play again.
        std::cout << "Enter Y to play again. Any other key to exit.\n";
        std::cin >> continue_option;
        std::cin.ignore(10000, '\n'); // Handling inputs like "y3A+" etc.

        if (continue_option != 'y' && continue_option != 'Y')
        {
            break;
        }
    }
}
