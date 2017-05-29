#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
   if(argc<2) { // if filename is not given as argument in command line,give error
       cout<<"Enter the filename as an argument(for e.g ./a.out file.txt)\n";
       return EXIT_FAILURE;
   }

   ifstream file(argv[1]);
   vector<string> names;
   string name;

   if(file.is_open()) { // getting the names from the file
       while(getline(file,name)) {
           names.push_back(name);
       }
   }

   sort(names.begin(),names.end()); // sorting the names in alphabetical order

   string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // for getting the integer value of a character
   map<char,int> val;
   for(int i=0;i<26;++i) {
       val[alphabets[i]] = i+1;
   }


   long sum = 0;
   for(unsigned int i=0;i<names.size();++i) {
       string temp = names[i];
       //cout<<temp<<" "; // you can uncomment the commented part for verification
       long temp_sum=0;
       for(unsigned int j=0;j<temp.size();++j) {
           temp_sum+=val[toupper(temp[j])];
           //cout<<temp_sum<<" ";
       }
       temp_sum*=(i+1);
       //cout<<temp_sum<<endl;
       sum+=temp_sum;
       //cout<<sum<<endl;
   }

   cout<<"Total sum of all the name-scores is "<<sum<<endl;
   return 0;
}
