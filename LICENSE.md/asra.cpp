#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
int CalculatedFinalScore = 0;
   //opens the file
std::ifstream infile("names.txt"); std::string line;
   int counter = 1;
   // does the processing of each name
while (std::getline(infile, line))
{
       
       int totalScore = 0; int TemporaryScore = 0;
std::istringstream iss(line);
string word;
       // processes each word in a given name 
if (!(iss >> word)) { break; } 
       // calculates the score of all names based on the criteria
       for(int i=0;i<word.length();i++){
           int _char = word[i];
           TemporaryScore += (_char-64);
       }
       //stores all namescore numerical values
totalScore = TemporaryScore*counter;
cout<<"The namescore For "<<word<<" is: "<<totalScore<<endl;
       CalculatedFinalScore += totalScore;
       //counter helps identity the position of all the names in file
       counter++;
}
   // outputs the final score
   cout<<"Final score of all names : "<<CalculatedFinalScore<<endl;
return 0;
}
