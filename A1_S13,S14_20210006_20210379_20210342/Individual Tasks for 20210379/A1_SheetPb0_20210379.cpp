#include <iostream>
#include <vector>
using namespace std;

class correct{
private:
    string sentence;
    vector<string>sentences;

public:
    void input();
    void fixeSentence();
    void print();
};

int main() {

    correct t;
    t.input();
    t.fixeSentence();
    t.print();

    return 0;
}

void correct::input() {
    while(true){
        cin>>sentence;
        sentences.push_back(sentence);
        if(sentences[sentences.size()-1][sentence.size()-1]=='.')
            break;
    }
}

void correct::fixeSentence() {
    sentences[0][0] = toupper(sentences[0][0]);

    for(int i=0 ; i<sentences.size(); i++) {
        for (int j = 0; j < sentences[i].size(); j++) {

            if(!i && !j)
                continue;

            if (isalpha(sentences[i][j]))
               sentences[i][j] = tolower(sentences[i][j]);
        }
    }
}

void correct::print() {
    for(const string& i:sentences)
        cout<<i<<" ";
}