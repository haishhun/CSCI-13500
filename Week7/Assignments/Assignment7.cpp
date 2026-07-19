#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  // Declare variables for input file name and output file name.
  std::string input_file_name = {};
  std::string output_file_name = {};

  // Declare variables for word search and replacement purposes.
  std::string word_to_search = {};
  std::string replacement_word = {};
  std::string line = "";

  // Declare variables for counting replaced words and total words in the text.
  int replaced_words_counter = 0;
  int total_word_counter = 0;

  // Ask user to input the file name to open.
  std::cout << "Enter the input file name: ";
  std::cin >> input_file_name;

  // Ask user to input the word to search.
  std::cout << "Enter the word to search for: ";
  std::cin >> word_to_search;

  // Ask user to input the word to replace the original one.
  std::cout << "Enter the replacement word: ";
  std::cin >> replacement_word;

  // Ask user to input the output file name.
  std::cout << "Enter the output file name: ";
  std::cin >> output_file_name;

  // Open the file and create the output file.
  std::ifstream FileReaderObject(input_file_name);
  std::ofstream FileOutputObject(output_file_name);

  // Check if it actually opened
  if (!FileReaderObject.is_open()) {
    std::cout << "File not found!" << std::endl;
    return 0;
  }

  // Iterate by one line in the text.
  while (getline(FileReaderObject, line)) {
    std::istringstream iss(line);
    std::string word = {};
    // Iterate by one word in the line.
    while (iss >> word) {
      // Check if the word is the one we search for.
      if (word == word_to_search) {
        // Replace the word and increment the counter.
        word = replacement_word;
        replaced_words_counter++;
      }
      // Write a space after each word and increment the total words counter.
      FileOutputObject << word << " ";
      total_word_counter++;
    }
    // End each line with "\n".
    FileOutputObject << "\n";
  }

  // Output results.
  std::cout << "------------------------------" << std::endl;
  std::cout << "            OUTPUT            " << std::endl;
  std::cout << "------------------------------" << std::endl;

  std::cout << "The word " << word_to_search << " was found "
            << replaced_words_counter << " times" << std::endl;
  std::cout << "The total amount of words in the " << input_file_name << " is "
            << total_word_counter << std::endl;
  if (total_word_counter > 0) {
    std::cout << "The percentage of replaced words is "
              << replaced_words_counter * 100 / total_word_counter << std::endl;
  } else {
    std::cout << "The percentage of replaced words is 0" << std::endl;
  }
  std::cout << "The modified text has been saved to " << output_file_name << "."
            << std::endl;

  // Close both files
  FileReaderObject.close();
  FileOutputObject.close();
}