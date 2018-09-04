#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<char,int>  mymap;
 // mymap['a']=1;
  mymap['b']=5;
 // mymap['c']=6;
  mymap['d'];
  cout<<"value of mymap[c] = "<<mymap['c']<<endl;
  mymap.insert(pair<char,int>('c',10));
   mymap.insert ( pair<char,int>('a',100) );
  mymap.insert ( pair<char,int>('z',200) );
  mymap.insert(make_pair('w',23));
   cout<<" value of mymap[w]  ="<<mymap['w']<<endl;
  mymap['w']=24;
   cout<<" value of mymap[w]  ="<<mymap['w']<<endl;
  mymap['w']=56;
  mymap['z']=207;
  cout<<" value of mymap[w]  ="<<mymap['w']<<endl;
  cout<<" value of mymap[z]  ="<<mymap['z']<<endl;
  mymap.insert(make_pair('w',302));
  mymap.insert(make_pair('z',222));
  cout<<" value of mymap[w]  ="<<mymap['w']<<endl;
  cout<<" value of mymap[z]  ="<<mymap['z']<<endl;

  mymap.insert((mymap.find('c'),pair<char,int>('c',12)));
  cout<<"value of mymap[c] = "<<mymap['a']<<endl;
  cout<<mymap.at('z')<<endl;
    return 0;
}
