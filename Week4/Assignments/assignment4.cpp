#include <cctype>
#include <iostream>
#include <vector>

// Time complexity - O(n)
// Space complexity - O(1), two integers and no new memory added.
void removeCopies(std::vector<int>& data) {
  // The vector is sorted in non-decreasing order.
  // Remove all duplicate values in-place so that
  // each value appears exactly once.
  //
  // Do not create another vector.
  // Modify the vector named "data" directly.
  //
  // Maybe two-pointer method? Hmm?
  // Hint: resize() function

  // Validating if data is empty.
  if (data.size() == 0) {
    return;
  }

  // Declaring first pointer
  int first_pointer = 1;

  // Move second pointer and check if the value is different from the previous
  // one and rewriting the value of first pointer if it is. Time complexity -
  // O(n) - one loop through data vector.
  for (int second_pointer = 1; second_pointer < data.size(); second_pointer++) {
    if (data[second_pointer] != data[second_pointer - 1]) {
      data[first_pointer] = data[second_pointer];
      first_pointer++;
    }
  }

  // Resizing the vector to remove extra elements.
  data.resize(first_pointer);
}

// Time complexity - O(n)
// Space complexity - O(1), working with fixed size objects.
void isAnagram(std::string officer_name, std::string spy_name) {
  // Write code to see if the spy name is an anagram of the officer name
  // Maybe a vector of size 26? Hmm?

  // Declaring alphabet vector.
  std::vector<int> letters(26);

  // Early check, if the size of strings is not the same then they are not
  // anagrams.
  if (officer_name.size() != spy_name.size()) {
    std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
    return;
  }

  // Adding each letter from officer_name into alphabet vector.
  // Time complexity - O(n) - one loop through officer_name string.
  for (char letter : officer_name) {
    letters[std::tolower(letter) - 'a']++;
  }

  // Subtracting each letter from spy_name from alphabet vector.
  // Time complexity - O(n) - one loop through spy_name string.
  for (char letter : spy_name) {
    letters[std::tolower(letter) - 'a']--;
  }

  // Checking if count is not 0 for each letters then it's an imposter.
  // Time complexity - O(26), so its O(1) - one loop through alphabet vector
  // that has 26 elements.
  for (int count : letters) {
    if (count != 0) {
      std::cout << "IMPOSTER! IMPOSTER!" << std::endl;
      return;
    }
  }

  std::cout << "No imposter detected!" << std::endl;
}

int main() {
  /*Use other test cases to make sure you program works*/
  std::vector<int> server = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6};

  /*Print out the original server vector before function called*/
  std::cout << "---------- Data before removing duplicates ----------"
            << std::endl;
  for (auto data : server) {
    std::cout << data << " ";  // 1,1,2,2,2,3,3,4,5,6,6,6
  }

  removeCopies(server);

  /*Print out the modification of the server vector after function called*/
  std::cout << "\n---------- Data after removing duplicates ----------"
            << std::endl;
  for (auto data : server) {
    std::cout << data << " ";
  }

  std::cout << std::endl;

  /****************************TEST
   * ANAGRAM*************************************/
  std::cout << "\n---------- isAnagram tests ----------" << std::endl;
  isAnagram("syeda", "aysed");      // No imposter detected!
  isAnagram("angelo", "annabeth");  // IMPOSTER! IMPOSTER!

  return 0;
}
