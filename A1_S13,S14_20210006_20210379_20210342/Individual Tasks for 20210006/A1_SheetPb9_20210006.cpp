//
// Created by AHMED on 10/13/2022.
//
#include<bits/stdc++.h>
using namespace std ;
bool file_comparison(string file1, string file2, int chosen);
int main(){
    string filename1, filename2 ;
    int choice ;
    cout<<"enter first file name: ";
    cin>>filename1 ;
    cout<<"enter second file name: ";
    cin>>filename2 ;
    filename1+= ".txt" ;
    filename2+= ".txt" ;
    cout<<"enter 1 for character by character comparison or enter 2 for word by word comparison: " ;
    cin>>choice ;
    file_comparison(filename1,filename2, choice);
}
bool file_comparison(string file1, string file2, int chosen){
    ifstream file_1, file_2 ;
    bool check= true ;
    file_1.open(file1,ios::in);
    if(file_1.is_open() ) {
        cout << "file1 opening successfully\n" ;
    }
    else {
        cout<<"couldn't find file1\n" ;
        check = false;
    }
    file_2.open(file2,ios::in);
    if(file_2.is_open() ) {
        cout << "file2 opening successfully\n";
    }
    else{
        cout<<"couldn't find file2\n" ;
        check = false ;
    }
    if(chosen == 1){
        vector<string> first_file ;
        vector<string> second_file ;
        string text;
        int larger ;
            while(!file_1.eof() &&check) {
                getline(file_1, text);
                first_file.push_back(text);
            }
            while(!file_2.eof() && check){
                getline(file_2,text) ;
                second_file.push_back(text) ;
            }
            int length1, length2, len ;
            length1 = first_file.size() ;
            length2 = second_file.size() ;
            if(length1==length2) {
                len = length2;
                larger = 0;
            }
            else if(length1>length2) {
                len = length2;
                larger = 1;
            }
            else {
                len = length1;
                larger = 2;
            }
                for(int i=0; i<len;i++){
                    if(first_file[i].length()== second_file[i].length()){
                        for(int j=0;j<first_file[i].length();j++){
                            if(first_file[i][j]!=second_file[i][j]){
                                cout<<i+1<<"th line differ"<<endl;
                                cout<<"first file: "<<first_file[i]<<endl ;
                                cout<<"second file: "<<second_file[i]<<endl ;
                                return false ;
                            }
                        }
                    }
                    else{
                        cout<<i+1<<"th line differ"<<endl;
                        cout<<"first file: "<<first_file[i]<<endl ;
                        cout<<"second file: "<<second_file[i]<<endl ;
                        return false ;
                    }
                }
                if(larger==1){
                cout<<"file1 is larger that file2 \n" ;
                cout<<"first additional line is: "<<first_file[length2] ;
                return false ;
            }
                else if(larger == 2){
                cout<<"file2 is larger that file2 \n" ;
                cout<<"first additional line is: "<<second_file[length1] ;
                return false ;
            }
                cout<<"files are characters identical\n" ;
                return true ;
    }
    else{
        int length1=0, length2=0, larger, line=0 ;
        vector<pair<string,int>> first_file ;
        vector<pair<string,int>> second_file ;
        pair<string,int> text ;
        string word,word2 ;

        while(!file_1.eof() &&check) {

            getline(file_1,word2) ;
            line ++ ;
            stringstream words(word2) ;
            while(words>>word) {
                length1++ ;
                text.first = word ;
                text.second = line ;
                first_file.push_back(text);
            }
            }
        line = 0 ;
        while(!file_2.eof() && check) {
            getline(file_2,word2) ;
            line++ ;
            stringstream words(word2) ;
            while (words >> word) {
            length2 ++ ;
                text.first = word ;
                text.second = line ;
                second_file.push_back(text) ;
        }
        }
        if(length1==length2){
            larger = 0 ;
        }
        else if(length1>length2){
            larger = 1 ;
        }
        else{
            larger = 2 ;
        }
        for(int i=0,j=0;i<first_file.size() &&j<second_file.size();i++,j++){
                if(first_file[i].first!=second_file[j].first){
                    cout<<first_file[i].second<<"th line diff in file one than "<<second_file[j].second<<"th line in file two"<<endl ;
                    cout<<"the word from the first file different is: "<<first_file[i].first<<endl ;
                    cout<<"the word from the second file different is: "<<second_file[j].first<<endl ;
                    return false ;
                }

        }
        if(larger==1){
            cout<<"first file is larger that second file \n" ;
            cout<<"first additional word is: "<<first_file[length2].first ;
            return false ;
        }
        else if(larger==2){
            cout<<"second file is larger that first file \n" ;
            cout<<"first additional word is: "<<second_file[length1].first ;
            return false ;
        }
        cout<<"files are words identical\n" ;
        return true ;
    }

}
