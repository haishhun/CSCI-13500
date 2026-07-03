# Program Design Document

## Program Name

Rock, Paper, Scissor Game (Modified)

## Purpose

A Rock, Paper, Scissor game in a terminal where user plays vs. bot.
The user choses amount of rounds for the game and after all rounds the program announces the winner.

---

## Inputs

* Number of rounds.
* Player's move.
* Play again choice.

---

## Outputs

* Bot's move each round.
* Score after each round.
* Score table in the end of the game.
* Winner announcement.
* Play again option.
* Error messages.

---

## Variables

| Variable        | Type   | Purpose                                               |
| --------------- | ------ | ----------------------------------------------------- |
| player_score    | int    | Counter for player's win rounds                       |
| bot_score       | int    | Counter for bot's win rounds                          |
| player_move     | string | Stores player's input move                            |
| bot_move        | int    | Stores random number (0–2) for bot's move             |
| bot_pick        | string | Stores bot's move choice based on the bot_move number |
| rounds          | int    | Stores number of rounds                               |
| continue_option | char   | Stores user's choice to replay or exit                |

---

## Key Design Choices

* I used a `while(true)` loop in `main()` for the whole program so the user can play as many games as they want until they choose to exit.
* I added input validation for the `rounds` variable inside `GetRounds()` so the value must be a whole number greater than 0.
* I added uppercase conversion so the user can type their move in any capitalization without causing comparison issues.
* I used `i--` in `PlayGame()` for rounds where both the player and bot chose the same move, so the tied round is not counted and the game continues.
* I removed `player_score++` and `bot_score++` from the tie condition but kept the condition itself, because without it the code would fall into the `else` branch and incorrectly give the bot a point.
* `DetermineRoundWinner()` return a `bool` indicating whether the round was a tie, so `PlayGame()` knows when to decrement `i`.
* I added a score table at the end of each game to improve the UI.
---

## Program Steps (Algorithm)

### 1. `PrintWelcomeMessage()`
   1. Display welcome message.

### 2. `GetRounds()`
   1. Ask user for number of rounds.
   2. Validate the input.
   3. Return the validated number of rounds.

### 3. `GetPlayerMove()`
   1. Ask user for their move.
   2. Convert the input to uppercase.
   3. Validate the input.
   4. Return the validated move.

### 4. `GetBotMove()`
   1. Generate a random number from 0 to 2.
   2. Convert the number into a move string.
   3. Display the bot's picked move.
   4. Convert the move string to uppercase.
   5. Return the bot's move.

### 5. `DetermineRoundWinner()`
   1. Compare player's move and bot's move.
   2. If they match, display a tie message and return `true`.
   3. If the player's move beats the bot's move, increment `player_score`, if not - increment `bot_score`.
   4. Display the current round score.
   5. Return `false` if the round was not a tie.

### 6. `PrintRoundScore()`
   1. Display the current player and bot score.

### 7. `PlayGame()`
   1. Loop for the number of rounds chosen.
   2. Check for an early exit before each round.
   3. Call `GetPlayerMove()` and `GetBotMove()` to get both moves.
   4. Call `DetermineRoundWinner()` to score the round and check for a tie.
   5. If the round was a tie, decrement the loop counter so the round is replayed.

### 8. `PrintFinalScore()`
   1. Display the final score table.
   2. Announce the winner or a tie.

### 9. `AskPlayAgain()`
   1. Ask the user if they want to play again.
   2. Return `true` if the user enters "Y" or "y", if not - return `false`.

### 10. `main()`
   1. Call `PrintWelcomeMessage()`.
   2. Loop until the user chooses to exit:
      1. Reset `player_score` and `bot_score` to 0.
      2. Call `GetRounds()` to get the number of rounds.
      3. Call `PlayGame()` to run the rounds and update scores.
      4. Call `PrintFinalScore()` to display results.
      5. Call `AskPlayAgain()`; exit the loop if the user declines.

---

## Functions

### 1. `main()`
Main function to manage the game flow.
### 2. `PrintWelcomeMessage()`
This function prints the welcome message for the game.
### 3. `GetRounds()`
This function prompts the user to enter the number of rounds they want to play and returns the value.
### 4. `GetPlayerMove()`
This function prompts the user to enter their move and returns the value.
### 5. `GetBotMove()`
This function generates the bot's move and returns the value.
### 6. `PrintRoundScore()`
This function prints the score for a single round.
### 7. `DetermineRoundWinner()`
This function determines the winner of a round and updates the scores.
### 8. `PrintFinalScore()`
This function prints the final score of the game.
### 9. `AskPlayAgain()`
This function asks the user if they want to play again and returns a boolean value.
### 10. `PlayGame()`
This function plays the game for the specified number of rounds.

---

## Sample Input/Output

Input:
```
Please enter the amount of rounds you want to play: 1
Please choose your move (Rock, Paper or Scissor): Rock
N
```
Output:
```
Welcome to the Rock, Paper, Scissor game.
Please choose your move (Rock, Paper or Scissor):
Bot picked: Paper
Player 0:1 Bot

.-----------------
| Player 0:1 Bot |
.------------------
    Bot wins!
```    
---

## Testing

### Test Case 1

Input: 3, rock, paper, scissor, N

Expected Result: Score table and winner announcement.

### Test Case 2

Input: -1

Expected Result: Error: Invalid amount of rounds. Please enter again.

### Test Case 3

Input: 1, xyz

Expected Result: Error: Invalid move. Please enter again.

### Test Case 4

Input: 1, Rock (bot picks Rock)

Expected Result:
```
Bot picked: Rock
Tie! Both picked the same move!
Player 0:0 Bot
```