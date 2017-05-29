#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
int finalTotalScore = 0;
   //opening file
std::ifstream infile("names.txt");
std::string line;
   int counter = 1;
   // processing each name
while (std::getline(infile, line))
{
       //variables declared
       int totalScore = 0;
       int tempScore = 0;
std::istringstream iss(line);
string word;
       // processing each word
if (!(iss >> word)) { break; } // error
       // calculating each score
       for(int i=0;i<word.length();i++){
           int _char = word[i];
           tempScore += (_char-64);
       }
       //storing all score values
totalScore = tempScore*counter;
cout<<"For "<<word<<" the score is: "<<totalScore<<endl;
       finalTotalScore += totalScore;
       //counter is to locate position of word in file
       counter++;
}
   // printting resultant score
   cout<<"Final score of all names : "<<finalTotalScore<<endl;
return 0;
}
