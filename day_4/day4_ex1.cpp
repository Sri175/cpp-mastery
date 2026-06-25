#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int >
#define ll long long 
#define vvi vector<vector<int >>
#define pb push_back
#define vs vector<string >
template<typename T >
class stack{
private:

    vector< T> holder;
public :
    void push(T val){
        holder.push_back(val);
        return ;
    }
    T pop(){
        if(empty())
            throw underflow_error("Stack Empty");
        T temp=holder[holder.size()-1];
        holder.pop_back();
        return temp;
    }
    T top(){
        if(empty())
            throw underflow_error("Stack Empty");
        return holder[holder.size()-1];
    }
    bool empty(){
        if(holder.size()==0) return true;
        return false;
    }
    size_t size(){
        return holder.size();
    }
    
};

int main() {
	// your code goes here
	
} 
