//Write a Buffer class owning a raw heap array — implement Rule of Five correctly
#include <bits/stdc++.h>
using namespace std;

class buffer{
private:
    size_t m_size{};
    int * m_data;
public:
    //constructor
    buffer(size_t m_size){
        m_size=m_size;
        m_data=(new int[m_size]);
        cout<<"constructor called\n";
        
    }
    ~buffer(){
        delete []m_data;
    }
    buffer(const buffer& other){ // copy constructor
        m_size=other.m_size;
        m_data= new int[m_size];
        for(size_t=0;i<m_size;i==){
            m_data[i]=other.m_data[i];
        }
        cout<<"copy constructore called\n";
    }
    //cpoy assignemnt operator
    buffer& operator=(const buffer & other){
        if(this==& other) return *this;
        delete []m_data;
        m_size=other.size;
        m_data= new int[m_size];
        for(size_t i=0;i<m_size;i++){
            m_data[i]=other.m_data[i];
        }
        return *this ;
    }
    // move constructor
    buffer( buffer && other){
        
        m_size=move(other.m_size);
        other.m_size=0;
        m_data=move(other.m_data);
        other.m_data=nullptr;
        cout<<" move constructor called/n";
    }
    // move assignemnt operator
    buffer& operator=(buffer && other){
        if(this==& other) return *this;
        delete []m_data;
        m_size=move(other.m_size);
        m_data=new int [m_size];
        m_data=other.m_data;
        other.m_size=0;
        other.m_data=nullptr;
        return *this;
    }
    
}
int main() {
	// your code goes here
	
} 
