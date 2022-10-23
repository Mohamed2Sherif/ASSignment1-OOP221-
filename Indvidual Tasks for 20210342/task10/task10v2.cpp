#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void check(string , string , int );

ifstream myFile;
//creating two vectors one for keywords and other for points
vector<string> keyWords{"Invoice","Missing Invoice","RE:INVOICE","New","New Invoice","Message","Required","<Blank Subject>","File","Request","Action","Document","Verification","efax from ID","eFax® message from","VM from","VMAIL RECEIVED","A vulnerability has been identified in.","To perform verification click the link","Here is the new invoice for this week’s activities","Please click here to install the latest","Your account has been locked for security reasons click here to unlock your account","Urgent","Verification required!","Need urgent help!","Suspicious Outlook activity","Important! Your password is about to expire","Action required…","Slots!","Get 100% sale on","Remove any ransomware with this app!","check your device from virsus now!","the best antivirus get it now!"};
vector<int> points{2,3,2,1,2,1,1,3,2,2,2,2,2,3,3,3,3,3,3,3,3,3,2,2,3,3,3,3,2,3,3,3,3};
//creating variables used along to project to extract lines from the file or to fill the vectors from custom words or file 
string line, temptex,stemppnt,name ;
// variable used to extract text from the file 
string filetext ;
// variable used to calculate the total points of occurences inside a message
static int totalpoints;

 int main()
 {
    // prompt the user to enter an option
    int option;
    cout<<"1-use the program words"<<endl<<"2-use custom keywords"<<endl<<"Option : ";
    cin>>option;
    
    int i=0;
    // if the user entered option 2 , the next lines make him choose a file to import the keywords from 
    // it should be donated  on format ("keyword" ',' "point") like this bank,3
    if(option==2)
    {
    myFile.open("Phishing_Words_and_phrases.txt");
    while(getline (myFile,line))
    {
        
        stringstream l(line);
        getline(l,temptex,',');
        getline(l,stemppnt,'\n');
        
           keyWords[i]= temptex;
            points[i]=stoi(stemppnt);
           i++;
    }
    myFile.close();
    }
    //make the user enter a name of the email file (one will be checked)
    string fname;
    cout<<"enter the email file name : ";
    cin>>fname;
    myFile.open(fname);
    // looping through the email file to extract the lines into one string 
while(getline(myFile,line))
{
    filetext += line;
    filetext += ' ';
}
for (int i =0; i < filetext.size(); i++ )
{
    filetext[i] = (char) tolower(filetext[i]);
}
   for(string& j : keyWords)
        {
            for(char& c : j)
            {
                c = tolower(c);
            }
        }       
   //looping through the vectors and apply the check function below to count hte number of occurences of the word inside the file text 
   
    for(int i=0; i <keyWords.size();i++)
    {
        
        check(filetext,keyWords[i],points[i]);
      
    
    }
    // printing how many times a danger keyword found 
    cout<<"message total points are : "<<totalpoints<<endl;
}
  
void check(string s1,string s2,int point)
{
    //coutner to count the word occurences 
    int counter =0;
    int word_Size = s2.size();
    // looping  only if a keyword position found, 
    //and terminating the loop after no more duplicates of the same keyword founds
for (int i =0; i < s1.size();i++)
if(s1.find(s2) != string::npos)
{
    int pos = s1.find(s2) ;
    counter +=1;
    s1.erase(0,s1.find(s2)+word_Size);

}
//printing the word occurences inside the file and the total points of the word in the vector 
if(counter != 0)
{
cout<<"the Word is :"<<s2<<'\t'<<"occurences = "<<counter<<'\t'<<"word points = "<<point<<endl;
totalpoints += counter * point;
}
}


