#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int lat[15];
int * helper(){

    static int lat[15];  
	int countwords=0;
    ifstream file;
    ofstream fail;
    string line; 
    string word;
    fail.open ("out.txt");
    file.open("latency.txt");
		while(!file.eof())
		 {
		 	string sub1,sub2;
            stringstream ss;
            int cnt=0;
            getline(file,line);
            size_t fid=line.find("add");
            
            size_t sub=line.find("sub");
            size_t ldr=line.find("ldr");
           
            size_t str=line.find("str");
            //size_t str_pseudo=line.find("str_pseudo");
            size_t cmp=line.find("cmp");
            size_t mul=line.find("mul");
            size_t bne=line.find("bne");
            size_t bge=line.find("bge");
            size_t b=line.find("b");
            size_t bl=line.find("bl");
            size_t mov=line.find("mov");



           // cout<<fid;
            if(fid<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(fid+6,fis-(fid+6));
            	//cout<<sub3;
        		lat[0]=stoi(sub3);
            }
            else if(sub<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(sub+6,fis-(sub+6));
            	//cout<<sub3;
            	lat[1]=stoi(sub3);
            }
            else if(ldr<16){
            	 //size_t ldr_pseudo=line.find("ldr_pseudo");
 				string sub3;
 				
 				if(line.at(ldr+4)=='p'){
 								//	cout<<3<<endl;
 				size_t fis=line.find(";");
 					sub3=line.substr(ldr+13,fis-(ldr+13));
 				lat[2]=stoi(sub3);
 				}

 					else {
 					//	cout<<4<<endl;
 						size_t fis=line.find(";");
 				sub3=line.substr(ldr+6,fis-(ldr+6));
            	lat[3]=stoi(sub3);
            	}//cout<<sub3;
            }
            
     //        if(ldr_pseudo<16){
 				// string sub3;
 				// sub3=line.substr(ldr_pseudo+6,fis-(ldr_pseudo+6));
     //        	//cout<<sub3;
     //        	list.push_back( (sub3));
     //        }
            
            else if(str<16){
            	 //size_t ldr_pseudo=line.find("ldr_pseudo");
 				string sub3;
 				
 				if(line.at(str+4)=='p'){
 									//cout<<3<<endl;
 				size_t fis=line.find(";");
 					sub3=line.substr(str+13,fis-(str+13));
 				lat[4]=stoi(sub3);
 				}

 					else {
 					//	cout<<4<<endl;
 						size_t fis=line.find(";");
 				sub3=line.substr(str+6,fis-(str+6));
            	lat[5]=stoi(sub3);
            	}//cout<<sub3;
            }
     //        if(str_pseudo<16){
 				// string sub3;
 				// size_t fis=line.find(";");
 				// sub3=line.substr(str_pseudo+6,fis-(str_pseudo+6));
     //        	//cout<<sub3;
     //        	list.push_back( (sub3));
     //        }
            else if(cmp<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(cmp+6,fis-(cmp+6));
            lat[6]=stoi(sub3);
            }
            else if(bne<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(bne+6,fis-(bne+6));
            	//cout<<sub3;
            	lat[7]=stoi(sub3);
            }
            else if(bge<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(bge+6,fis-(bge+6));
            	//cout<<sub3;
            lat[8]=stoi(sub3);
            }
            else if(mov<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(mov+6,fis-(mov+6));
            	//cout<<sub3;
            lat[9]=stoi(sub3);
            }
            else if(b<16){
 				string sub3;
 					if(line.at(b+1)=='l'){
 									//cout<<3<<endl;
 				size_t fis=line.find(";");
 					sub3=line.substr(b+5,fis-(b+5));
 					lat[10]=stoi(sub3);
 				}
 				else {	
 				size_t fis=line.find(";");	
 				sub3=line.substr(b+4,fis-(b+4));
        		    	lat[11]=stoi(sub3);}
			}
           	 	else if(mul<16){
 				string sub3;
 				size_t fis=line.find(";");
 				sub3=line.substr(mul+6,fis-(mul+6));
            			lat[12]=stoi(sub3);
           			 }
		}
		file.close();
	 
	   return lat;
           }


