#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
#include<map>
void findMostFrequentWord(const std::vector<std::string>& words) {
	std::map<std::string, int> wordCount;


	for (const auto& word : words) {
		wordCount[word]++;
	}


	std::string mostFrequentWord;
	int maxCount = 0;
	for (const auto& pair : wordCount) {
		if (pair.second > maxCount) {
			mostFrequentWord = pair.first;
			maxCount = pair.second;
		}
	}

	std::cout << "Vital popular word :  " << mostFrequentWord << std::endl;
}
void isbiggest(std::vector<int>wcich) {
	int max(0);
	int lettern_(0);
	for (int i = 0; i < wcich.size(); i++) {
		if (wcich[i] > max) {
			max = wcich[i];
			lettern_ = i;
		}
	}
	std::cout << "The biggest letter int this chapter number :" << lettern_<<"\n";
}
int main() {
	int chapterCount(1), wordCount(0),wcil(0),lettern(1);
	std::vector<std::string> text;
	std::vector<int>wcich;
	std::vector<int>bigestword;
	std::string line;
	std::string bword;
	std::fstream io;
	std::fstream io_2;
	std::fstream io_3;
	io.open("Text.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (io.is_open()) {
		std::cout << "File is Open\n"<<std::endl;
	}
	else {
		std::cout << "File didnt open\n" << std::endl;
	}
	while (std::getline(io, line)) {
		if (line.find("Chapter") != std::string::npos) {
			std::cout << "Chapter " << chapterCount << ": ";
		}
			int charCount = 0;
			std::istringstream iss(line);
			while (std::getline(io, line) && line.find("Chapter") == std::string::npos) {
				charCount += line.length();
				while (iss >> line) {
						wordCount++;
						wcil++;
						
						if (line.find(" .")) {
							wcich.push_back(wcil);
					}
				}
			}
			std::cout << "Quantity of symbols - " << charCount << std::endl;
			chapterCount++;
			std::cout << "Quantity of words - " << wordCount << std::endl;
			wordCount = 0;
			isbiggest(wcich);
			
		}
	io_2.open("Text.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (io_2.is_open()) {
		std::cout << "File is Open\n" << std::endl;
	}
	else {
		std::cout << "File didnt open\n" << std::endl;
	}
	while (std::getline(io_2, line)) {
				std::istringstream iss(line);
				std::string word;
				while (iss >> word) {
					text.push_back(word);
				}
			}
			findMostFrequentWord(text);
	io_2.close();
	return 0;
	}
		