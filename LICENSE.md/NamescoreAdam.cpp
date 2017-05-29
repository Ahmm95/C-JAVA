#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void alphabetList(fstream &infile) {
	const int size = 6000;
	string nameList[size];
	string line;
	int i = 0;
	infile.open("names.txt");
	while (!infile.eof()) {				//make array of names
		getline(infile, line);
		nameList[i] = line;
		i++;
		}
	infile.close();
	
	sort(begin(nameList), end(nameList));	//sort names in alphabetical in array
	
	fstream outfile("names.txt");

	for (int k = 0; k < size; k++) {			//write new alphabetical list to names.txt file
		if (!nameList[k].empty()) {
			outfile << nameList[k] << endl;
		}
	}
}


int main()
{	
	fstream infile;
	alphabetList(infile);

	
	int CalculatedFinalScore = 0;
	//opens the file
	std::ifstream newfile("names.txt"); std::string line;
	int counter = 1;
	// does the processing of each name
	while (std::getline(newfile, line))
	{

		int totalScore = 0; int TemporaryScore = 0;
		std::istringstream iss(line);
		string word;
		// processes each word in a given name 
		if (!(iss >> word)) { break; }
		// calculates the score of all names based on the criteria
		for (int i = 0; i<word.length(); i++) {
			int _char = word[i];
			TemporaryScore += (_char - 64);
		}
		//stores all namescore numerical values
		totalScore = TemporaryScore*counter;
		cout << "The namescore for " << word << " is: " << totalScore << endl;

		CalculatedFinalScore += totalScore;
		//counter helps simplify things by making it easier to manage & identity the position of all the names in a given file
		counter++;
	}
	// outputs the final score
	cout << "Total sum of all name-scores is : " << CalculatedFinalScore << endl;
	system("PAUSE");
	return 0;
}
