/*Function that, given a sorted vector v of strings and a string s to search for,
finds the string s into v using binary-search*/

// obs. the computational complexty of such an algorithm is O(log(N))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin; using std::endl; using std::string;
using std::vector; 
using std::sort;

bool binary_search(vector<string>&,string&);

int main() {
    
    vector<string> v={"mario","luca","cane","pinocchio","giuliano","cavallo","gatto"};
    v.push_back("andreo");
    sort(v.begin(),v.end());
    string s="lucaj";
    bool exists=binary_search(v,s);

    exists? cout<<"Trovato!!":cout<<"Non trovato :( " << endl;
    
    return 0;
}


bool binary_search(vector<string>& v,string& s){
    /* note: the use of this algorithm makes sense only in case of an already
     SORTED vector*/
    vector<string>::const_iterator beg, mid, end;
    beg=v.begin();
    end=v.end();
    mid=beg + (end-beg)/2;

    while(mid!=end && *mid!=s){
        if(s<*mid)
            end=mid;        
        else
            beg=mid+1;
          
        
        mid=beg + (end-beg)/2;
    }
    return *mid==s ;
}
