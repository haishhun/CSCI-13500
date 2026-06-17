# Program Design Document

## Program Name

Rock, Paper, Scissor Game

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

* I used a `while(true)` loop for the whole program so the user can play as many games as they want until they choose to exit.
* I added input validation for the `rounds` variable so the value must be a whole number greater than 0.
* I added uppercase conversion so the user can type their move in any capitalization without causing comparison issues.
* I used `i--` for rounds where both the player and bot chose the same move so the tied round is not counted and the game continues.
* I removed `player_score++` and `bot_score++` from the tie condition but kept the condition itself, because without it the code would fall into the `else` branch and incorrectly give the bot a point.
* I added a score table at the end of each game to improve the UI.

---

## Program Steps (Algorithm)

1. Display welcome message.
2. Reset scores to 0.
3. Ask user for number of rounds.
4. Validate the input.
5. Create a loop for the amount of rounds chosen.
6. Check for early exit before the start of each round.
7. Ask user for their move and convert it to uppercase.
8. Validate the input.
9. Generate a number from 0 to 2 for the bot's move.
10. Convert the bot's move number into a string.
11. Convert the bot's move string into uppercase.
12. Determine the winner of the round and display the current score.
13. After all rounds, display a score table and winner announcement.
14. Ask the user if they want to play again.

---

## Functions

No separate functions were used in the program.

---

## Sample Input/Output

Input:

Please enter the amount of rounds you want to play: 1
Please choose your move (Rock, Paper or Scissor): Rock
N

Output:
Welcome to the Rock, Paper, Scissor game.
Please choose your move (Rock, Paper or Scissor):
Bot picked: Paper
Player 0:1 Bot

.-----------------
| Player 0:1 Bot |
.------------------
    Bot wins!
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
Bot picked: Rock
Tie! Both picked the same move!
Player 0:0 Bot