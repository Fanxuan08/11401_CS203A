# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: Peng-Syuan , Su  
Email: minna1008.su@gmail.com  

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  - [My C language coding implementation here]

    int myHashInt(int key, int m) {
      if (m <= 0) return -1; // invalid table size
      return key % m;  // division method example
    }

  - [My C++ language coding implementation here]

    int myHashInt(int key, int m) {
      if (m <= 0) return -1;// Simple integer hash (mod table size)
      return key % m;  // basic division method
    }

- Rationale: 
  - [My Design choice] 
      I chose the simple division method for hashing integers ( key % m ). Tt is simple and fast, suitable for basic hash tables.

  - [How they minimize collisions]
      1. Choose a prime number to reduce patterns in key distribution that may lead to clustering. For example, if many keys share common factors with m, using a non-prime table size may cause many keys to collide at the same index.
      2. The `% m` operation spreads keys across the table. Using a prime number for the table size helps the keys spread more evenly.
      3. Avoid table sizes m like 16, 32, or 64 because they can cause more collisions for certain patterns of keys.

### Non-integer Keys
- Formula / pseudocode:
  - [My C language coding implementation here]

    int myHashString(const char* str, int m) {
      unsigned long hash = 0;
      if (m <= 0) return -1; // invalid table size
      if (str == NULL) return -1; // null pointer check
      // Simple string hashing: sum ASCII values
      for (int i = 0; str[i] != '\0'; i++) {
          hash += (unsigned long)str[i];
      }
      return (int)(hash % m); // basic division method
    }
  
  - [My C++ language coding implementation here]

    int myHashString(const std::string& str, int m) {
      unsigned long hash = 0;
      if (m <= 0) return -1; //Return -1 if table size m is invalid (<=0)
      // Simple string hashing: sum the ASCII values of each character
      for (size_t i = 0; i < str.length(); i++) {
          hash += static_cast<unsigned long>(str[i]);
      }
      return static_cast<int>(hash % m);  // basic division method
    }

- Rationale:
  - [My Design choice] 
      I sum the ASCII values of all characters in the string to implement and works for basic hashing.

  - [How they minimize collisions]
      1. Using `% m` spreads hash values across the table.
      2. Choosing a prime number for m helps the values spread more evenly.
      3. For longer strings, more advanced hash methods may reduce collisions further, but this simple method is enough for small tables.

## Experimental Setup

- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation                                           |
|----------------|------------------------|-------------------------------------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10; keys wrap around frequently |
| 11             | 10, 0, 1, 2, ...       | More uniform distribution; fewer collisions observed  |
| 37             | 20, 21, 22, 23, ...    | Near-uniform; spread evenly across table              |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  .\makefile.bat all
  
  # Build only C version
  .\makefile.bat c
  
  # Build only C++ version
  .\makefile.bat cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  .\makefile.bat clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  C/hash_function.exe
  ```
  or
  ```bash
  CXX/hash_function_cpp.exe
  ```

### Result Snapshot
- Example output for integers:
  
  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_C%20(1).png)
  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_C%20(2).png)
  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_C%20(3).png)

  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_cpp%20(1).png)
  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_cpp%20(2).png)
  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_cpp%20(3).png)

- Example output for strings:

=== Hash Function Observation (C version) ===

  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_C%20(4).png)

  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_C%20(5).png)

=== Hash Function Observation (C++ version) ===

  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_cpp%20(4).png)

  ![image](https://github.com/Fanxuan08/11401_CS203A/blob/main/Assignment/AssignmentIV/OutputPicture/Output_cpp%20(5).png) 

- Observations: 
  1. The outputs confirm that prime table sizes (e.g., 11, 37) provide a more even key distribution and fewer collisions.
  2. Non-prime sizes like 10 show noticeable clustering, especially with sequential integer inputs.
  3. String hashing similarly benefits from larger primes, producing a more uniform spread.
  4. Overall, the C and C++ results match the expected behavior of the hash functions.

- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 14, 15, 16, 17, 18, 19, 20]
  ```
- Example output for strings:
  ```
  Hash table (m=10): [["bee","pig"], "bat", "cat", ["ant","fox"], "dog", "hen", null, null, "owl", "cow"]
  Hash table (m=11): [null, "pig", null, ["bat","bee","fox"], ["cat","ant"], null, "dog", "hen", "owl", null, "cow"]
  Hash table (m=37): [ "pig", null, null, ["bee","fox"], "ant", null, null, "hen", "owl", null, null, null, null, null, null, null, "cat", null, null, "dog", null, null, null, null, null, null, null, null, null, null, null, null, null, null, "cow", null, null ]
  ```
- Observations:
  1. The outputs confirm that prime table sizes (e.g., 11, 37) provide a more even key distribution and fewer collisions.
  2. Non-prime sizes like 10 show noticeable clustering, especially with sequential integer inputs.
  3. String hashing similarly benefits from larger primes, producing a more uniform spread.
  4. Overall, the C and C++ results match the expected behavior of the hash functions.

## Analysis
- Prime table sizes generally result in more uniform distribution and fewer collisions.
- Non-prime table sizes may create repeating patterns, leading to more collisions.
- Well-designed hash functions combined with prime table sizes improve distribution uniformity.
- Different key types (integers, strings) may affect collision rates.
- Collision handling methods (chaining, open addressing) impact performance and distribution.
- Table size selection should consider both prime strategy and load factor.

## Reflection
1. Designing hash functions requires balancing simplicity and minimizing collisions.
2. Table size significantly affects distribution uniformity, with prime sizes performing better.
3. Using a prime table size and a linear or simple transformation formula produces the most uniform index sequence.
4. Observing the effect of load factor on collision rates helps adjust table size or hashing strategy.
