//
// Created by AHMED on 10/13/2022.
//
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,string>> scores(10) ;

void menu();
void add_player(string name, int score);
void display_scores() ;
void search_name(string name) ;
int main(){
    menu() ;
    return 0 ;
}
void add_player(string name, int score){
    if(score> scores[0].first) {
        pair player(score,name) ;
        scores.push_back(player) ;
        sort(scores.begin(),scores.end()) ;
        scores.erase(scores.begin()) ;

    }
}
void display_scores(){
    for(int i=scores.size()-1;i>=0 ;i--){
        cout<<scores[i].second<<": "<<scores[i].first<<endl ;
    }
}
void search_name(string name){
    string player ;
    int his_score ;
    bool found = false ;
    for(int i=0;i<scores.size();i++){
        if(scores[i].second == name){
            found = true ;
            player = scores[i].second ;
            his_score = scores[i].first ;

        }
    }
    if(found){
        cout<<player<<": "<<his_score<<endl ;
    }
    else{
        cout<<"this player is not on the list "<<endl ;
    }
}
void menu(){
    bool check= true ;
    while(check){
        int num ;
        cout<<" enter 1 for adding player or 2 to display scores or 3 to search name or 4 to end program " ;
        cin>>num ;
        switch(num) {
            case 1: {

                string your_name;
                int your_score;
                cout << "enter your name: ";
                cin >> your_name;
                cout << "enter your score: ";
                cin >> your_score;
                add_player(your_name, your_score);
                break;
            }
            case 2: {

                display_scores();
                break;
        }
            case 3: {
                string your_name2;
                cout << "enter your name: ";
                cin >> your_name2;
                search_name(your_name2);
                break ;
            }
            case 4:{
                check = false ;
                break ;
            }
            default:{
                cout<<"wrong input\n" ;
                break ;
            }
        }
    }
}