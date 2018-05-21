#include <fstream>
#include <string>
#include <vector>
#include "pipe.h"
using namespace std;
int *p = helper();
int g;
int memory[1024];
int compare;
float instr_cnt=0;
vector <int> st1;
vector <int> st2;
vector <int> st3;
vector <int> st4;
vector <int> st5;
vector <int> cache,GC;
vector <float>IPC;
int ard=0;
int ward=0;
int loc2,loc3;
int fourwardd=0;
int forwarddd=0;
int stop=0;
int brunch;
int regi[16];
int global_clock=1;
class decode{
	public: int s2=0;
	int s1=0;
	int des=0;
	int opcode=0;
	//int forward=0;
};
class alu{
	public: int result=0;
	int dest=0;
	int mux=9;
	int mov=0;
	int write=9;
	//int forwardd=0;
};
class meq{
	public:
	int wb=0;
	int destiny=0;
	int mov=0;
	int data=0;
	//int forwarddd=0;
};
void opener(){
fstream fi;
    string line;
    fi.open("out.txt");
     int i=0;
     do
{
getline(fi,line);

//int s=stoi(line,nullptr,10);
if(!line.empty())
cache.push_back(stoi(line));
// for(int i=0;i<10;i++){
// 	cout<<memory[i];
// }
}
while(!fi.eof());

fi.close();
}

void stage1(int address){
	if(address<cache.size())
regi[15] =  cache[address];
else
	regi[15] = 0;
}

decode stage2(int test){
 decode po;
ward=test;
 po.s2=test % 100;
po.s1=(test%10000-po.s2)/100;
po.des=(test%1000000-(test%10000))/10000;
po.opcode=(test-test%1000000)/1000000;

	if (po.opcode==9)
	{
		//cout<<compare<<"\t"<<reg[3]<<endl;
		int fi=0;
		int fii=0;
		int local_clock=global_clock;
			for(int i=0;i<loc2+p[8]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi<p[8]-1)
		{st5.push_back(forwarddd);
		forwarddd=fourwardd;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		if(fii==0)
		{
			st4.push_back(fourwardd);
 			fourwardd=0;
 			fii++;
		}
		else
			st4.push_back(0);
		st3.push_back(0);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
		if(compare!=-1)
		{
			stop=1;
	 		brunch=po.s2;
			regi[15]=0;
		}
	}
else if (po.opcode==10)
	{
		int fi=0;
		int fii=0;
		int local_clock=global_clock;
			for(int i=0;i<loc2+p[10]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi<p[10]-1)
		{st5.push_back(forwarddd);
		forwarddd=fourwardd;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		if(fii==0)
		{
			st4.push_back(fourwardd);
 			fourwardd=0;
 			fii++;
		}
		else
			st4.push_back(0);
		st3.push_back(0);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
		regi[14]=cache[g];
		stop=1;
		brunch=po.s2;
		regi[15]=0;
	}
else if (po.opcode==11)
	{	int fi=0;
		int fii=0;
		int local_clock=global_clock;
			for(int i=0;i<loc2+p[11]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi<p[11]-1)
		{st5.push_back(forwarddd);
		forwarddd=fourwardd;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		if(fii==0)
		{
			st4.push_back(fourwardd);
 			fourwardd=0;
 			fii++;
		}
		else
			st4.push_back(0);
		st3.push_back(0);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
		stop=1;
		brunch=po.s2;
		regi[15]=0;

	}
	else if (po.opcode==8)
	{
		int fi=0;
		int fii=0;
		int local_clock=global_clock;
			for(int i=0;i<loc2+p[7]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi<p[7]-1)
		{st5.push_back(forwarddd);
		forwarddd=fourwardd;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		if(fii==0)
		{
			st4.push_back(fourwardd);
 			fourwardd=0;
 			fii++;
		}
		else
			st4.push_back(0);
		st3.push_back(0);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
		if(compare!=0)
		{
			stop=1;
	 		brunch=po.s2;
			regi[15]=0;
		}
	}
return po;
}
alu stage3(decode fetch){
	alu res;
	fourwardd=ward;
	if(fetch.opcode==1){
		int fi=0;
	int local_clock=global_clock;
	//cout<<loc3<<"\t"<<global_clock<<"\t"<<p[0]<<endl;
	for(int i=0;i<loc3+p[0]-local_clock-1;i++)
		{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
	//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
	global_clock++;
	if(fi==0)
	{st5.push_back(forwarddd);
	forwarddd=0;
	//cout<<"for--> "<<forwarddd<<endl;
	fi++;}
	else
	{st5.push_back(0);}
	st4.push_back(0);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);	}
		if(fetch.s2>15)
		{res.result=regi[fetch.s1-1]+fetch.s2-16;
			 res.dest=fetch.des;
			res.mux=0;}
		else
		{res.result=regi[fetch.s1-1]+regi[fetch.s2-1];
			 res.dest=fetch.des;
			res.mux=0;}
	}


	else if (fetch.opcode==2){
	int fi=0;
	int local_clock=global_clock;
		for(int i=0;i<loc3+p[1]-local_clock-1;i++)
		{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
	//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
	global_clock++;
	if(fi==0)
	{st5.push_back(forwarddd);
	forwarddd=0;
	//cout<<"for--> "<<forwarddd<<endl;
	fi++;}
	else
	{st5.push_back(0);}
	st4.push_back(0);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);
	}
	if(fetch.s2>15)
		{res.result=regi[fetch.s1-1]-fetch.s2+16;
			 res.dest=fetch.des;
			res.mux=0;}
		else
		{res.result=regi[fetch.s1-1]-regi[fetch.s2-1];
			 res.dest=fetch.des;
			res.mux=0;}
	}

	else if (fetch.opcode==3){
		int fi=0;
	int local_clock=global_clock;
		for(int i=0;i<loc3+p[12]-local_clock-1;i++)
		{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
	//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
	global_clock++;
	if(fi==0)
	{st5.push_back(forwarddd);
	forwarddd=0;
	//cout<<"for--> "<<forwarddd<<endl;
	fi++;}
	else
	{st5.push_back(0);}
	st4.push_back(0);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);
	}
			if(fetch.s2>15)
		{res.result=regi[fetch.s1-1]*(fetch.s2-16);
			 res.dest=fetch.des;
			res.mux=0;}
		else
		{res.result=regi[fetch.s1-1]*regi[fetch.s2-1];
			 res.dest=fetch.des;
			res.mux=0;}

	}

	else if (fetch.opcode==4)
	{int fi=0;
	int local_clock=global_clock;
		for(int i=0;i<loc3+p[0]-local_clock-1;i++)
		{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
	//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
	global_clock++;
	if(fi==0)
	{st5.push_back(forwarddd);
	forwarddd=0;
	//cout<<"for--> "<<forwarddd<<endl;
	fi++;}
	else
	{st5.push_back(0);}
	st4.push_back(0);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);
	}
res.result=regi[fetch.s1-1]+(fetch.s2-16)/4;
			res.dest=fetch.des;
			res.mux=1;
			res.write= 1;
		}


	else if (fetch.opcode==5)
	{int fi=0;
	int local_clock=global_clock;
		for(int i=0;i<loc3+p[0]-local_clock-1;i++)
		{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
	//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
	global_clock++;
	if(fi==0)
	{st5.push_back(forwarddd);
	forwarddd=0;
	//cout<<"for--> "<<forwarddd<<endl;
	fi++;}
	else
	{st5.push_back(0);}
	st4.push_back(0);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);
	}
			//cout<<"chlra h 3";
			res.result=regi[fetch.s1-1]+(fetch.s2-16)/4;
			res.dest=fetch.des;
			res.mux=1;
			res.write= 0;
	}
	else if (fetch.opcode==6)
	{
		int fi=0;
		int local_clock=global_clock;
			for(int i=0;i<loc3+p[6]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi==0)
		{st5.push_back(forwarddd);
		forwarddd=0;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		st4.push_back(0);
		st3.push_back(ward);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
	if(fetch.s1>15)
		{
		if(regi[fetch.des-1]>fetch.s1-16)
			compare=1;
		else if(regi[fetch.des-1]<fetch.s1-16)
			compare=-1;
		else if(regi[fetch.des-1]==fetch.s1-16)
			compare=0;
		}
	else
		{if(regi[fetch.des-1]>regi[fetch.s1-1])
			compare=1;
		else if(regi[fetch.des-1]<regi[fetch.s1-1])
			compare=-1;
		else if(regi[fetch.des-1]==regi[fetch.s1-1])
			compare=0;}


	}
	else if (fetch.opcode==7){
		int fi=0;
		int local_clock=global_clock;
			for(int i=0;i<loc3+p[9]-local_clock-1;i++)
			{GC.push_back(global_clock);
IPC.push_back(instr_cnt/global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi==0)
		{st5.push_back(forwarddd);
		forwarddd=0;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		st4.push_back(0);
		st3.push_back(ward);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
		 if(fetch.s1>15)

 		{		res.result=fetch.s1-16;
 			 	res.dest=fetch.des;
 			res.mux=0;}
 		else
 		{res.result=fetch.s1;
 		res.dest=fetch.des;
 		res.mov=1;
		res.mux=0;}
	}
	else if (fetch.opcode==12){
		int fi=0;
		int local_clock=global_clock;
			for(int i=0;i<loc3+p[2]-local_clock-1;i++)
			{IPC.push_back(instr_cnt/global_clock);
				GC.push_back(global_clock);
		//cout<<"counter--> "<<i<<"\t"<<loc3+p[0]-global_clock<<endl;
		global_clock++;
		if(fi==0)
		{st5.push_back(forwarddd);
		forwarddd=0;
		//cout<<"for--> "<<forwarddd<<endl;
		fi++;}
		else
		{st5.push_back(0);}
		st4.push_back(0);
		st3.push_back(ward);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);
		}
 		res.result=fetch.s1;
 		res.dest=fetch.des;
		res.mux=0;
	}
return res;
}
meq stage4(alu ff)
{meq qelica;
forwarddd=fourwardd;
if(ff.mux==0)
{//global_clock++;
qelica.destiny=ff.dest;
qelica.data=ff.result;
qelica.mov=ff.mov;
qelica.wb=1;
}
else if(ff.mux==1)
{int check=0;
	//cout<<"GC"<<global_clock<<endl;
	if(ff.write==1)
	{for(int i=0;i<p[5]-1;i++)
	{IPC.push_back(instr_cnt/global_clock);
		GC.push_back(global_clock);
		global_clock++;
	// check++;
	// cout<<check<<endl;
	st5.push_back(0);
	st4.push_back(fourwardd);
	st3.push_back(ward);
	st2.push_back(regi[15]);
	if(g<cache.size())
	st1.push_back(cache[g]);
	else
	st1.push_back(0);		}
	memory[ff.result]=regi[ff.dest-1];
	qelica.wb=0;
	qelica.destiny=0;
	qelica.data=0;
	}
	else if(ff.write==0)
	{for(int i=0;i<p[3]-1;i++)
		{GC.push_back(global_clock);
			IPC.push_back(instr_cnt/global_clock);
			global_clock++;
		// check++;
		// cout<<check<<endl;
		st5.push_back(0);
		st4.push_back(fourwardd);
		st3.push_back(ward);
		st2.push_back(regi[15]);
		if(g<cache.size())
		st1.push_back(cache[g]);
		else
		st1.push_back(0);			}
		qelica.data=memory[ff.result];
		qelica.wb=1;
		qelica.destiny=ff.dest;
		}
	}
return qelica;
}
void stage5(meq dae)
{	//global_clock++;
st5.push_back(forwarddd);
st4.push_back(fourwardd);
st3.push_back(ward);
st2.push_back(regi[15]);
if(g<cache.size())
st1.push_back(cache[g]);
else
st1.push_back(0);
if(dae.wb==1&&dae.mov==1&&dae.destiny!=0)
	{
		regi[dae.destiny-1]=regi[dae.data-1];
		//mov=0;
		//cout<<"chala "<<reg[dae.data-1]<<endl;
		//cout<<reg[dae.destiny]<<endl;
	}
	else if(dae.wb==1&&dae.mov==0&&dae.destiny!=0)
		regi[dae.destiny-1]=dae.data;
}
int check(alu fat,meq mac,decode ded)
{
	if(ded.s1==fat.dest&&fat.dest!=0)
		return 11;//source 1 matches destiny
	else if(ded.s2==fat.dest&&fat.dest!=0)
		return 12;//source 2 matches destiny
	else if(ded.s1==mac.destiny&&mac.destiny!=0&&mac.wb==1)
		return 21;//source 1 matches destiny and WB is to be done
	else if(ded.s2==mac.destiny&&mac.destiny!=0&&mac.wb==1)
		return 22;//source 2 matches destiny and WB is to be done
	else
		return 0;//No forwarding
}
void pipeline(){
regi[15]=0;
	int until;
	file f;
	f.read();
decode q;
alu w;
meq r;
string inp;
opener();
cout<<"Type  'end'  to run the pipeline till end."<<endl;
cout<<"Enter the number of cycles: ";
cin>>inp;
if(inp=="end")
	until=cache.size()+4;
else
	until=stoi(inp);
for(g=0;g<until;g++)
{	if(g<cache.size()&&regi[15]!=0)
	{	instr_cnt++;
		//IC.push_back(instr_cnt);
	}
	GC.push_back(global_clock);
	IPC.push_back(instr_cnt/global_clock);
	global_clock++;
	stage5(r);
loc3=global_clock;
if(check(w,r,q)==0)
{
r = stage4(w);
loc2=global_clock;
w = stage3(q);
}
else if(check(w,r,q)==11)
{
r = stage4(w);
loc2=global_clock;
regi[q.s1-1]=w.result;
w = stage3(q);
}
else if(check(w,r,q)==12)
{
r = stage4(w);
loc2=global_clock;
regi[q.s2-1]=w.result;
w = stage3(q);
}
else if(check(w,r,q)==21)
{
regi[q.s1-1]=r.data;
r = stage4(w);
loc2=global_clock;
w = stage3(q);
}
else if(check(w,r,q)==22)
{
regi[q.s2-1]=r.data;
r = stage4(w);
loc2=global_clock;
w = stage3(q);
}

q = stage2(regi[15]);
if(stop==0)
	{stage1(g);}
else
{
g=brunch-2;
stop=0;
}
//ard=regi[15];
//cout<<reg[15]<<"\t";
}
//cout<<reg[4]<<endl;
//cout<<global_clock<<endl;
//cout<<compare<<endl;
//cout<< q.s2<<endl<<q.s1<<endl<<q.des
 for(int i=0;i<16;i++)
	{
  	cout<<"R"<<i<<"--> "<<regi[i]<<endl;
	}
for(int j=0;j<st1.size();j++)
cout<<st1[j]<<"\t\t"<<st2[j]<<"\t\t"<<st3[j]<<"\t\t"<<st4[j]<<"\t\t"<<st5[j]<<endl;
}
// int main()
// {
// 	pipeline();
// 	for(int i=0;i<GC.size();i++)
// 	{
//   	cout<<"GC"<<i+1<<"--> "<<GC[i]<<endl;
// 	}
// 	return 0;
// }
