# Program Design Document

## Program Name

Assignment 4 - Pro Hacker Training

## Purpose

The program implements two operations on data as two separate functions: removing duplicate values from a sorted vector, and checking whether one string is an anagram of another.

---

## Inputs

The program does not take the input from the user. Test data stored in `main()`:

* `server`
* `officer_name`
* `spy_name`

---

## Outputs

* The `server` vector printed before and after duplicates are removed
* A result message for each `isAnagram` call: `No imposter detected!` or `IMPOSTER! IMPOSTER!`

---

## Variables

| Variable       | Type          | Purpose                                                          |
| -------------- | ------------- | ---------------------------------------------------------------- |
| data           | vector<int>   | Input data in `removeCopies`                                     |
| first_pointer  | int           | First pointer that stays in place                                |
| second_pointer | int           | Second pointer that moves in the loop                            |
| officer_name   | std::string   | First input string in `isAnagram`                                |
| spy_name       | std::string   | Second input string in `isAnagram`                               |
| letters        | vector<int>   | Size 26 vector used as alphabet                                  |
| letter         | char          | Loop variable used to loop through input string                  |
| count          | int           | Loop variable to check each letter for a nonzero value           |

---

## Key Design Choices

* I declared `first_pointer` = 1, not 0. Index 0 is always unique by definition, so there's nothing to compare it against.*
* I used * `std::tolower()` to every letter before indexing so the comparison is case-insensitive.
* I did early check for data size in `removeCopies` to prevent empty input.
* I did early comparison of sizes of two input strings in `isAnagram`, because if the size is different then they won't be anagrams.

---

## Program Steps (Algorithm)

### removeCopies(data)
 
1. Return early if `data` is empty.
2. Set `first_pointer` to 1.
3. Loop `second_pointer` from 1 to the last index of `data`:
4. If `data[second_pointer]` differs from `data[second_pointer - 1]`, write `data[second_pointer]` into `data[first_pointer]` and increment `first_pointer`.
5. Resize `data` to `first_pointer` elements.

### isAnagram(officer_name, spy_name)
 
1. Return early with the imposter message if `officer_name.size()` differs from `spy_name.size()`.
2. Create `letters`, a 26-element vector initialized to 0.
3. Loop through `officer_name`, incrementing `letters[tolower(letter) - 'a']` for each character.
4. Loop through `spy_name`, decrementing `letters[tolower(letter) - 'a']` for each character.
5. Loop through `letters`; if any count is nonzero, print the imposter message and return.
6. If every count is 0, print the match message.

---

## Functions

### Function: removeCopies(data)
 
Purpose: Removes duplicate values from a sorted vector then resizes the vector to drop the leftover slots. Time complexity O(n). Space complexity O(1) — no new container is allocated.

### Function: isAnagram(officer_name, spy_name)
 
Purpose: Determines whether `spy_name` is an anagram of `officer_name`.
Time complexity O(n). Space complexity O(1) — the 26-element vector is a fixed size regardless of input length.

---

## Sample Input/Output

Input (test values in `main()`):
```
    std::vector<int> server = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6};
 
    isAnagram("syeda", "aysed");
    isAnagram("angelo", "annabeth");
```

Output:
```
---------- Data before removing duplicates ----------
1 1 2 2 2 3 3 4 5 6 6 6 
---------- Data after removing duplicates ----------
1 2 3 4 5 6 

---------- isAnagram tests ----------
No imposter detected!
IMPOSTER! IMPOSTER!
```

---

## Testing

### Test Case 1

Input: 
std::vector<int> server = {1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 6}; in `removeCopies`

Output: 
---------- Data before removing duplicates ----------
1 1 2 2 2 3 3 4 5 6 6 6 
---------- Data after removing duplicates ----------
1 2 3 4 5 6 

### Test Case 2

Input: An empty vector passed to `removeCopies`.

Expected Result: The function returns immediately with no changes made and no crash.

### Test Case 3

Input:
()"syeda", "aysed") in `isAnagram`
("angelo", "annabeth") in `isAnagram`

Output:
No imposter detected!
IMPOSTER! IMPOSTER!
