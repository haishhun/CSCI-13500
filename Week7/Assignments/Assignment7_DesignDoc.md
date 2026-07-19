# Program Design Document

## Program Name

Word Search and Replace Using File I/O

## Purpose

This program searches for a word in a text file, counts how many times it appears, and creates a new file where every occurrence of that word is replaced with another word chosen by the user.

---

## Inputs

* input_file_name
* word_to_search 
* replacement_word
* output_file_name

---

## Outputs

Example:

* replaced_words_counter
* total_word_counter
* output_file_name
* input_file_name

---

## Variables

| Variable               | Type     | Purpose                                      |
| ---------------------- | -------- | -------------------------------------------- |
| input_file_name        | string   | Stores the name of the input file            |
| output_file_name       | string   | Stores the name of the output file           |
| word_to_search         | string   | The word to search for                       |
| replacement_word       | string   | The word that replaces each match            |
| line                   | string   | Holds one line of the text file              |
| word                   | string   | Holds one word of the current line           |
| replaced_words_counter | int      | Counts how many replacements were made       |
| total_word_counter     | int      | Counts the total number of words in the text |
| FileReaderObject       | ifstream | Object for reading the source file           |
| FileOutputObject       | ofstream | Object for writing the modified text         |

---

## Key Design Choices

* I used two while loops: one by line, the other by word. Otherwise we can't save the structure of lines and it would be a plain text.
* I check if the input file opened right after asking for its name, so the program exits early on failure without asking for the other inputs.

---

## Program Steps (Algorithm)

1. Ask the user for the input file name.
2. Open the input file and validate if the file was opened.
3. Ask for word_to_search, replacement_word and output_file_name input.
4. Create the output file.
5. Read the input file one line at a time.
6. For each line, read one word at a time.
7. Compare each word to the word we search for. If matches, replace the word and increment the replaced word counter.
8. Write each word to the output file and increment the total word counter.
9. Write new line after each line
10. Output results.
11. Close both files.

---

## Functions

No separate functions were used in the program.

---

## Sample Input/Output

Input:
Enter the input file name: story.txt
Enter the word to search for: cat
Enter the replacement word: tiger
Enter the output file name: output.txt

Output:
------------------------------
            OUTPUT            
------------------------------
The word cat was found 2 times
The total amount of words in the story.txt is 14
The percentage of replaced words is 14
The modified text has been saved to output.txt.

---

## Testing

### Test Case 1

Input:
Enter the input file name: story.txt
Enter the word to search for: cat
Enter the replacement word: tiger
Enter the output file name: output.txt

Expected Result: 
```
------------------------------
            OUTPUT            
------------------------------
The word cat was found 2 times
The total amount of words in the story.txt is 14
The percentage of replaced words is 14
The modified text has been saved to output.txt.
```

### Test Case 2

Input: 
Enter the input file name: asdasd.txt 

Expected Result:
File not found!

### Test Case 3 

Input:
Enter the input file name: text.txt (Empty file)
Enter the word to search for: cat
Enter the replacement word: dog
Enter the output file name: o.txt

Expected Result:
```
------------------------------
            OUTPUT            
------------------------------
The word cat was found 0 times
The total amount of words in the text.txt is 0
The percentage of replaced words is 0
The modified text has been saved to o.txt.
```