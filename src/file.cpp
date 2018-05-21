#include "file.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
vector<feran> tup;
int finder(string s)
{int lk=0;
ifstream fi;
    string line; 
    fi.open("in.txt");
  do
{
getline(fi,line);
lk++;
size_t fid=line.find(s);
if(fid<15)
   {
       if(line.at(s.size())!=':')
         return lk;  
}
}
while(!fi.eof());
fi.close();
}
void hfind()
{
string s;
int lp=0;
ifstream gl;
gl.open("in.txt");
feran bep;
while(!gl.eof())
{getline(gl,s);
lp++;
size_t fid=s.find(":");
if(fid<15)
   {string sub3=s.substr(0,fid);
	bep.label=sub3;
	bep.branch=lp;
	bep.begin=finder(sub3);
	tup.push_back(bep);
}
}

}
map<string, int> map_opcode_values;
map<string, string> register_map;
map<string, string> hash_map;
map<string, string> LDRhash_map;
    void file::Initialize()
{
    map_opcode_values["ADD"]= 1;
    map_opcode_values["add"]= 1;
    map_opcode_values["SUB"]= 2;
    map_opcode_values["sub"]= 2;
    map_opcode_values["MUL"]= 3;
    map_opcode_values["mul"]= 3;

    map_opcode_values["LDR"]= 5;
    map_opcode_values["ldr"]= 5;
    map_opcode_values["STR"]= 4;
    map_opcode_values["str"]= 4;
    map_opcode_values["CMP"]= 6;
    map_opcode_values["cmp"]= 6;
    map_opcode_values["MOV"]= 7;
    map_opcode_values["mov"]= 7;
    map_opcode_values["BNE"]= 8;
    map_opcode_values["bne"]= 8;
    map_opcode_values["BGE"]= 9;
    map_opcode_values["bge"]= 9;
    map_opcode_values["BL"]= 10;
    map_opcode_values["bl"]= 10;
    map_opcode_values["B"]= 11;
    map_opcode_values["b"]= 11;
	map_opcode_values["LDR_pseudo"]=12;
	map_opcode_values["ldr_pseudo"]=12;
    for(int i=0;i<9;i++)
    {
        register_map["r"+to_string(i)]="0"+to_string(i+1);
        register_map["R"+to_string(i)]="0"+to_string(i+1);
    }
    for(int j=9;j<16;j++)
    {
     register_map["r"+to_string(j)]=to_string(j+1);
        register_map["R"+to_string(j)]=to_string(j+1);   
    }
    for(int y=16;y<100;y++)
    {
        hash_map["#"+to_string(y-16)]=to_string(y);
    }
	for(int y=0;y<10;y++)
    {
        LDRhash_map["="+to_string(y)]="0"+to_string(y);
    }
    for(int y=10;y<100;y++)
    {
        LDRhash_map["="+to_string(y)]=to_string(y);
    }

}
    void file::read()
    {
    int lined=1;
    string sub3="DUMMY";
    Initialize();
    ifstream file;
    ofstream fail;
    string line;
    hfind();
    fail.open ("out.txt");
    file.open("in.txt");
    if (!file.is_open() || !fail.is_open())
    {
        cout<<"Error in file handling."<<endl;
    }
    else
    {
        cout<<"File handling successful"<<endl;}
      do 
        {  
		 string sub1,sub2;
            stringstream ss;
            int cnt=0;
           getline(file,line,' ');
	if(!line.empty())
	{	 
            	size_t fid=line.find(":");
                if(fid<15)
                {   start=lined;
                    sub3=line.substr(0,fid);
                    line=line.substr(fid+1);
                }
	    fail<<map_opcode_values[line];
            int vew=map_opcode_values[line];
            getline(file, line);
            int append=0;
    for(int k=0;k<tup.size();k++)
   	{ if(line==tup[k].label)
		append=tup[k].branch;
	}
	if(append!=0)	
         {      if(append<10)
                    {
                        fail<<"00000"<<append;
                    }
                else
                    {
                        fail<<"0000"<<append;
                }
           append=0; }
       else
            {size_t fin=line.find("[");
            size_t fif=line.find("]");
            if((fin<15)&&(fif<15))
            {sub1=line.substr(fin+1,fif-(fin+1));
            sub2=line.substr(0,fin);
            ss<<sub2+sub1;
        }
            else
            {
            ss<<line;
            }
            while(getline(ss,line,','))
        {   cnt++;
            if((line.at(0)=='#'))
            {fail<<hash_map[line];
            }
	    else if((line.at(0)=='='))
            {fail<<LDRhash_map[line];
            }
            else if((line.at(0)=='r')||(line.at(0)='R'))
            {fail<<register_map[line];
            }
        }
    }

        if(cnt==2)
        {
            fail<<"00";
        }
        else if(cnt==1)
        {
            fail<<"0000";
        }
        if(!file.eof())
            fail<<endl;
        lined++;
       }
}
	 while(file.good()); 
        fail.close();
        file.close();
    }

