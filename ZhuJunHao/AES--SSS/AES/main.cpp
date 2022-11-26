#include <iostream>
#include <unistd.h>
#include "Block.hpp"
#include <fstream>

//AES-CTR

using namespace std;

void deAnden(){
    unsigned long long a = 5;
    unsigned long long q = 8;
    Block b(a, q);
    char * en = b.encrypt();
    //cout<<en<<endl;
    char * dn = b.decrypt();
    //cout<<dn<<endl;
}

int main() {
    //g++ main.cpp Block.hpp Block.cpp Config.hpp -std=c++14 -lzmq -ltomcrypt -lntl -lgmp
    
    ofstream fout;
    //char mn[5]={'h','e','l','l','o'};     
     clock_t first, second;
     fout.open("data.txt",ios::out);
     for(int i=1;i<1000;i++){
        first = clock();
        for(int j=0;j<i;j++){
            deAnden();
        }
        second = clock();
        fout << i << " " << second-first << endl;
         //cout<<" time="<<second-first<<endl;
     }
    fout.close();
   // cout<<" time="<<difftime(second,first)<<" "<<b->get_data()<<endl;
    return 0;
}
