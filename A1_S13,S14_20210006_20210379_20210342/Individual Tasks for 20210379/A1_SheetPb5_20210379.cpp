#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

class dominochain {
public:
    bool FormsDominoChain(vector<dominoT> &dominos, int l);
};

int main() {
    int n;
    cout<<"Enter number of dominos pieces: ";
    cin>>n;

    vector<dominoT>v(n);
    for(int i=0 ; i<n ; i++) {
        cin >> v[i].leftDots >> v[i].rightDots;
    }

    dominochain solution;
    bool exist = solution.FormsDominoChain(v,0);

    //print solution if exist
    if(exist) {
        for(int i=0 ; i<v.size()-1; i++)
            cout<<v[i].leftDots<<"|"<<v[i].rightDots<<" - ";
        cout<<v[v.size()-1].leftDots<<"|"<<v[v.size()-1].rightDots;
        cout << endl;
    }

    else{
        cout<<"there is no solution exist"<<'\n';
    }

    return 0;
}

bool dominochain::FormsDominoChain(vector<dominoT> & dominos,int l){
    if(l==dominos.size()){
      // check if this chain is valid
        bool ok = true;
        for(int i=0 ; i<dominos.size()-1; i++) {
            if (dominos[i].rightDots != dominos[i + 1].leftDots)
                ok =  false;
        }
        return ok;
     }

     else {
         //creat permutations and backtrack on it
         for (int i = l; i < dominos.size(); i++) {
             swap(dominos[l], dominos[i]);
             // if the chain is valid return true stop backtracking
             if (FormsDominoChain(dominos, l + 1))
                 return true;
             swap(dominos[l], dominos[i]);

         }

     }

}
