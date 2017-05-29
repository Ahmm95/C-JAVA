#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
void sortNames(string names[], int count)
{
    for(int i = 0; i < count - 1; i++)
    for(int j = 0; j < count - i - 1; j++)
       if(names[j].compare(names[j+1]) > 0)
       {
          string temp = names[j];
          names[j] = names[j+1];
          names[j+1] = temp;
       }
}
int main()
{
int CalculatedFinalScore  = 0;

std::ifstream infile("names.txt");   //Opens the file 'names.txt'. 
std::string line;  
int counter = 1;
// does the processing of each name in the input file .txt
string names[11000];
int count = 0;   
while (std::getline(infile, line))   //For each line read.
{
   names[count] = line;
   count++;
}
sortNames(names, count);  //sorting function
for(int j = 0; j < count; j++)
{
       line = names[j];
//variables declared
int totalScore = 0;  
int tempScore = 0;
std::istringstream iss(line);
string word;
// processes each word
if (!(iss >> word)) { break; } 
// calculating each score
for(int i=0;i<word.length();i++){
int _char = word[i];
tempScore += (_char-64);
}
//stores all score values
totalScore = tempScore*counter;
cout<<"The name-score for "<<word<<" is: "<<totalScore<<endl;
CalculatedFinalScore  += totalScore;
//counter helps simplify things by making it easier to manage & identity the position of all the names in a given file
counter++;
}
// outputs the final score 
cout<<"Total sum of all name-scores is : "<<CalculatedFinalScore <<endl;
return 0;
}
