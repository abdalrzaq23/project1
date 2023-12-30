 #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
set<string>dic={
    "class","int","intel","long","double","c++","java",
    "python","algorithms","string"};
cout<<"entre the number of strings you want to search about "<<endl;
int n;  cin>>n;
for (int i=0;i<n;i++){
    string t; cin>>t;
    if(dic.find(t)==dic.end()){
        cout<<"wrong "<<endl;
    }
}
cout<<"entre the number of strings you want to add "<<endl;

cin>>n;
for(int i=0;i<n;i++){
    string tmp; cin>>tmp;
    dic.insert(tmp);
}
cout<<"dictonary have "<<endl;
for(auto l:dic){
    cout<<l<<endl;
}
cout<<"auto complete "<<endl;
 string x; cin>>x;
for(auto l:dic){
   if(l.size()<x.size()) continue ;
   string tmp=l.substr(0,x.size());
   if(tmp==x){
cout<<l<<endl;
   }


}

}
