#include <iostream>

#include <fstream>

#include <string>

#include <vector>

// Function to display the content of a file
void displayFileContent(const std::string & filename) {
  std::ifstream file(filename);
  std::string line;

  if (file.is_open()) {
    std::cout << "File content:" << std::endl;
    while (std::getline(file, line)) {
      std::cout << line << std::endl;
    }
    file.close();
  } else {
    std::cout << "Failed to open the file." << std::endl;
  }
}

int main() {
  // List of input files
  std::vector < std::string > inputFiles = {
    "test1.txt",
    "test2.txt",
    "test3.txt",
    "test4.txt"
  };
  // Output file
  std::cout << "Content of test1.txt, test2.txt, test3.txt, text4.txt: " << std::endl;

  displayFileContent("test1.txt");
  displayFileContent("test2.txt");
  displayFileContent("test3.txt");
  displayFileContent("test4.txt");

  std::string outputFile = "merged_test_file.txt";

  // Create or overwrite the output file
  std::ofstream mergedFile(outputFile);

  if (mergedFile.is_open()) {
    for (const auto & inputFile: inputFiles) {
      // Open each input file
      std::ifstream inputFileStream(inputFile);

      if (inputFileStream.is_open()) {
        std::string line;

        // Read each line from the input file and write it to the merged file
        while (std::getline(inputFileStream, line)) {
          mergedFile << line << "\n";
        }

        inputFileStream.close();
      } else {
        std::cout << "Failed to open input file: " << inputFile << std::endl;
      }
    }

    mergedFile.close();
    std::cout << "\nFiles merged successfully." << std::endl;
    std::cout << "\nContent of the merged file:" << std::endl;
    displayFileContent("merged_test_file.txt");
  } else {
    std::cout << "Failed to open the output file." << std::endl;
  }

  return 0;
}
