#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include <vector>
#include "pipe.h"
using namespace std;
//extern int reg[16];
extern vector <int> st1;
extern vector <int> st2;
extern vector <int> st3;
extern vector <int> st4;
extern vector <int> st5;
extern vector<feran> tup;
extern vector <int> GC;
extern vector <float>IPC;
bool goa=true;
bool reverse=false;
bool ward4=true;
int ck=0;
int WindowHeight = 1000;
int WindowWidth = 1000;
int  k=75; int l=775;int i5 =0;int i4 =0;int i3 =0;int i2 = 0; int i1=0; int pause; int check=0;
int refresh = 1000;
std::vector<char*> v1;
std::vector<char*> v2;
std::vector<char*> v3;
std::vector<char*> v4;
std::vector<char*> v5;
std::vector<char*> ipcChar;
std::vector<char*> CLCK;
void Timer(int value){
  glutPostRedisplay();
  glutTimerFunc(refresh,Timer,10);


}
void printtext(int x, int y, string String)
{
//(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void display(void)
{
 // for(int i =0;i<5;i++){
 glClear( GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 0.0);
 //stage 1
 glBegin(GL_POLYGON);
  glVertex3f(0.5, 9.0, 0.0);
  glVertex3f(1.5, 9, 0.0);
  glVertex3f(1.5, 8, 0.0);
  glVertex3f(0.5, 8, 0.0);
 glEnd();

 // reges1er 1
 glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex3f(1.9, 9.5, 0.0);
  glVertex3f(2.1, 9.5, 0.0);
  glVertex3f(2.1, 7.5, 0.0);
  glVertex3f(1.9, 7.5, 0.0);
 glEnd();
 glColor3f(0.0, 1.0, 0.0);

 //stage 2
 glBegin(GL_POLYGON);
  glVertex3f(2.5, 9.0, 0.0);
  glVertex3f(3.5, 9, 0.0);
  glVertex3f(3.5, 8, 0.0);
  glVertex3f(2.5, 8, 0.0);
 glEnd();

 // regester 2
 glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex3f(3.9, 9.5, 0.0);
  glVertex3f(4.1, 9.5, 0.0);
  glVertex3f(4.1, 7.5, 0.0);
  glVertex3f(3.9, 7.5, 0.0);
 glEnd();
 //stage 3
 glColor3f(0.0, 1.0, 0.0);

 glBegin(GL_POLYGON);
  glVertex3f(4.5, 9.0, 0.0);
  glVertex3f(5.5, 9, 0.0);
  glVertex3f(5.5, 8, 0.0);
  glVertex3f(4.5, 8, 0.0);
 glEnd();

 // regester 3
 glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex3f(5.9, 9.5, 0.0);
  glVertex3f(6.1, 9.5, 0.0);
  glVertex3f(6.1, 7.5, 0.0);
  glVertex3f(5.9, 7.5, 0.0);
 glEnd();
 //stage 4
 glColor3f(0.0, 1.0, 0.0);

 glBegin(GL_POLYGON);
  glVertex3f(6.5, 9.0, 0.0);
  glVertex3f(7.5, 9, 0.0);
  glVertex3f(7.5, 8, 0.0);
  glVertex3f(6.5, 8, 0.0);
 glEnd();

 // regester 4
 glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POLYGON);
  glVertex3f(7.9, 9.5, 0.0);
  glVertex3f(8.1, 9.5, 0.0);
  glVertex3f(8.1, 7.5, 0.0);
  glVertex3f(7.9, 7.5, 0.0);
 glEnd();
//stage 5
 glColor3f(0.0, 1.0, 0.0);

 glBegin(GL_POLYGON);
  glVertex3f(8.5, 9.0, 0.0);
  glVertex3f(9.5, 9, 0.0);
  glVertex3f(9.5, 8, 0.0);
  glVertex3f(8.5, 8, 0.0);
 glEnd();

// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//  glEnable(GL_DEPTH_TEST);
  glColor3f(0.0, 0.0, 0.0);

    char string[1024];
    sprintf(string, "ID");
    printtext(75,850,string);
  // char string[64];
    sprintf(string, "IF");
    printtext(275,850,string);

sprintf(string, "EX");
    printtext(475,850,string);

sprintf(string, "MEM");
    printtext(675,850,string);

sprintf(string, "WB");
    printtext(875,850,string);


  glColor3f(0.0, 0.0, 1.0);
sprintf(string, "IF/ID");
    printtext(175,700,string);


sprintf(string, "ID/EX");
    printtext(375,700,string);


sprintf(string, "EX/MEM");
    printtext(575,700,string);


sprintf(string, "MEM/WB");
    printtext(775,700,string);
    char str[1024];


sprintf(string, "Instruction Per Cycle => ");
    printtext(650,200,string);


sprintf(string, "Clock Cycle => ");
    printtext(100,200,string);
    //char str[1024];

sprintf(string, "Buttons := ");
    printtext(300,600,string);

sprintf(string, "Press P =>To pause and resume the Instructions ");
    printtext(350,550,string);

sprintf(string, "Press R => To reverse the execution of Instructions ");
    printtext(350,500,string);

sprintf(string, "Press M => To increase the speed by 2 times ");
    printtext(350,450,string);


sprintf(string, "Press N => To decrease the speed by 2 times ");
    printtext(350,400,string);

     if(i1<ipcChar.size()){

      sprintf(str,ipcChar[i1]);
     printtext(900,200,str);
      }

      if(i1<CLCK.size()){

      sprintf(str,CLCK[i1]);
     printtext(250,200,str);
      }
     if(i1<v1.size()){

      sprintf(str,v1[i1]);
     printtext(50,l,str);
      }//k=k+200;
      if(i1<v2.size()){
           sprintf(str,v2[i1]);
      printtext(250,l,str);
       }//p=p+200;
      if(i1< v3.size()){
     sprintf(str,v3[i1]);
          printtext(450,l,str);   }
 //          //z2=z2+200;
     if(i1< v4.size()){
     sprintf(str,v4[i1]);
     printtext(650,l,str);
  } //z2=z2+200;
     if(i1< v5.size()){
     sprintf(str,v5[i1]);
     printtext(850,l,str);
 }

    if(goa==true&&ward4==true)
    i1=i1+1;
    else if(goa==true&&reverse==true)
    i1=i1-1;
   // i2=i2+1;
   // i3=i3+1;
   //   i4=i4+1;
   // i5=i5+1;

   // }

    glutSwapBuffers();
    glFlush();
}


void handleKeypress (unsigned char key, int x, int y)
{
 switch (key)
{
case 27:
  exit (0); break;
case 'p':

  {
      if(check ==0){
        goa=false;
    check=1;
      //cout<<check<<endl<<pause<<endl;
   }
   else if(check==1){
     goa=true;
    check=0;
    //cout<<check<<endl<<refresh;
   }

break;
 }
   case 'n':
  { refresh = refresh*2;
   }break;
   case 'm':
  { refresh = refresh/2;
   }break;
   case 'r':
  {
    if(ck==0)
    {reverse=true;
    ward4=false;
    ck=1;}
    else if(ck==1)
    {
      reverse=false;
      ward4=true;
      ck=0;
    }
   }break;

}
}
int main(int argc, char **argv)
{ pipeline();

    for(int i =0;i<IPC.size();i++){
      string ipc = to_string(IPC[i]);
          char * fi = (char *)alloca(ipc.size() + 1);
    memcpy(fi, ipc.c_str(), ipc.size() + 1);
     ipcChar.push_back(fi);
    }

        for(int i =0;i<GC.size();i++){
      string gc = to_string(GC[i]);
          char * clk = (char *)alloca(gc.size() + 1);
    memcpy(clk, gc.c_str(), gc.size() + 1);
     CLCK.push_back(clk);
    }


    for (int i = 0; i < st1.size(); i++)
   {  int inst;
   inst = (st1[i]-st1[i]%1000000)/1000000;
   //cout<<st1[i]<<endl;
   int s2=(st1[i] % 100);

   int s1=((st1[i]%10000-s2)/100);


   int des=((st1[i]%1000000-(st1[i]%10000))/10000)-1;
   string so1 = to_string(s1);

   string des1 = to_string(des);
   string result;
   if(inst ==0){
    v1.push_back("NOP");
   }
     if(inst==1){
  //    cout<<"ef";
      if(s2<16){
        s2=s2-1;
        string so2 = to_string(s2);
      result= "Add  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {
          s2=s2-16;
        string so2 = to_string(s2);

        result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==2){

      if(s2<=16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "SUB  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "SUB R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==3){

      if(s2<16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "MUL  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "MUL  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==4){
       s2=s2-16;
        string so2 = to_string(s2);
      //if(s2<16){
      result= "STR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==5){
       s2=s2-16;
        string so2 = to_string(s2);
      result= "LDR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==6){
     if(s1<16){

      s1=s1-1;
        string so1 = to_string(s1);
      result= "CMP  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
        s1=s1-16;
        string so1 = to_string(s1);
        result= "CMP R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==7){
    if(s1<16){
     s1=s1-1;
        string so1 = to_string(s1);
      result= "MOV  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
         s1=s1-16;
        string so1 = to_string(s1);
        result= "MOV R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v1.push_back(final);
    }
  if(inst==8){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BNE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v1.push_back(final);
    }
  if(inst==9){
  int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BGE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v1.push_back(final);//v1.push_back("BGE");
    }
  if(inst==10){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BL "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v1.push_back(final);
      //v1.push_back("BL");
    }
  if(inst==11){
      int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "B "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v1.push_back(final);
      //v1.push_back("B");
    }
  if(inst==12){
      v1.push_back("LDR_pseudo");
    }

}
// for(int i =0;i<v1.size();i++){
//   cout<<v1[i]<<endl;
// }
//gandu();
// for(int i =0;i<16;i++){
//   cout<<reg[i]<<endl;
// }

// for(int i=0;i<st5.size();i++){
//   cout<<st5[i]<<endl;
// }

for (int i = 0; i < st2.size(); i++)
   {  int inst;
   inst = (st2[i]-st2[i]%1000000)/1000000;
  // cout<<st2[i]<<endl;
   int s2=(st2[i] % 100);

   int s1=((st2[i]%10000-s2)/100);


   int des=((st2[i]%1000000-(st2[i]%10000))/10000)-1;
   string so1 = to_string(s1);

   string des1 = to_string(des);
   // const char *dest = des1.c_str();
   // const char *source1 = so1.c_str();
   // const char *source2 = so2.c_str();
   string result;
   if(inst ==0){
    v2.push_back("NOP");
   }
     if(inst==1){
     // cout<<"ef";
      if(s2<16){
        s2=s2-1;
        string so2 = to_string(s2);
      result= "Add  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {
          s2=s2-16;
        string so2 = to_string(s2);

        result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==2){

      if(s2<=16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "SUB  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "SUB R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==3){

      if(s2<16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "MUL  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "MUL  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==4){
       s2=s2-16;
        string so2 = to_string(s2);
      //if(s2<16){
      result= "STR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==5){
       s2=s2-16;
        string so2 = to_string(s2);
      result= "LDR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==6){
     if(s1<16){

      s1=s1-1;
        string so1 = to_string(s1);
      result= "CMP  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
        s1=s1-16;
        string so1 = to_string(s1);
        result= "CMP R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==7){
    if(s1<16){
     s1=s1-1;
        string so1 = to_string(s1);
      result= "MOV  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
         s1=s1-16;
        string so1 = to_string(s1);
        result= "MOV R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v2.push_back(final);
    }
  if(inst==8){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BNE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v2.push_back(final);
    }
  if(inst==9){
  int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BGE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v2.push_back(final);//v1.push_back("BGE");
    }
  if(inst==10){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BL "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v2.push_back(final);
      //v1.push_back("BL");
    }
  if(inst==11){
      int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "B "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v2.push_back(final);
      //v1.push_back("B");
    }
  if(inst==12){
      v2.push_back("LDR_pseudo");
    }

}


for (int i = 0; i < st3.size(); i++)
   {  int inst;
   inst = (st3[i]-st3[i]%1000000)/1000000;
 //  cout<<st3[i]<<endl;
   int s2=(st3[i] % 100);

   int s1=((st3[i]%10000-s2)/100);


   int des=((st3[i]%1000000-(st3[i]%10000))/10000)-1;
   string so1 = to_string(s1);

   string des1 = to_string(des);
   // const char *dest = des1.c_str();
   // const char *source1 = so1.c_str();
   // const char *source2 = so2.c_str();
   string result;
   if(inst ==0){
    v3.push_back("NOP");
   }
     if(inst==1){
     // cout<<"ef";
      if(s2<16){
        s2=s2-1;
        string so2 = to_string(s2);
      result= "Add  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {
          s2=s2-16;
        string so2 = to_string(s2);

        result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==2){

      if(s2<=16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "SUB  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "SUB R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==3){

      if(s2<16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "MUL  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "MUL  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==4){
       s2=s2-16;
        string so2 = to_string(s2);
      //if(s2<16){
      result= "STR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==5){
       s2=s2-16;
        string so2 = to_string(s2);
      result= "LDR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==6){
     if(s1<16){

      s1=s1-1;
        string so1 = to_string(s1);
      result= "CMP  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
        s1=s1-16;
        string so1 = to_string(s1);
        result= "CMP R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==7){
    if(s1<16){
     s1=s1-1;
        string so1 = to_string(s1);
      result= "MOV  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
         s1=s1-16;
        string so1 = to_string(s1);
        result= "MOV R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v3.push_back(final);
    }
  if(inst==8){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BNE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v3.push_back(final);
    }
  if(inst==9){
  int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BGE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v3.push_back(final);//v1.push_back("BGE");
    }
  if(inst==10){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BL "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v3.push_back(final);
      //v1.push_back("BL");
    }
  if(inst==11){
      int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "B "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v3.push_back(final);
      //v1.push_back("B");
    }
  if(inst==12){
      v3.push_back("LDR_pseudo");
    }

}

for (int i = 0; i < st4.size(); i++)
   {  int inst;
   inst = (st4[i]-st4[i]%1000000)/1000000;
   //cout<<st4[i]<<endl;
   int s2=(st4[i] % 100);

   int s1=((st4[i]%10000-s2)/100);


   int des=((st4[i]%1000000-(st4[i]%10000))/10000)-1;
   string so1 = to_string(s1);

   string des1 = to_string(des);
   // const char *dest = des1.c_str();
   // const char *source1 = so1.c_str();
   // const char *source2 = so2.c_str();
   string result;
   if(inst ==0){
    v4.push_back("NOP");
   }
     if(inst==1){
      //cout<<"ef";
      if(s2<16){
        s2=s2-1;
        string so2 = to_string(s2);
      result= "Add  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {
          s2=s2-16;
        string so2 = to_string(s2);

        result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==2){

      if(s2<=16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "SUB  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "SUB R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==3){

      if(s2<16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "MUL  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "MUL  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==4){
       s2=s2-16;
        string so2 = to_string(s2);
      //if(s2<16){
      result= "STR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==5){
       s2=s2-16;
        string so2 = to_string(s2);
      result= "LDR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==6){
     if(s1<16){

      s1=s1-1;
        string so1 = to_string(s1);
      result= "CMP  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
        s1=s1-16;
        string so1 = to_string(s1);
        result= "CMP R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }
  if(inst==7){
    if(s1<16){
     s1=s1-1;
        string so1 = to_string(s1);
      result= "MOV  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
         s1=s1-16;
        string so1 = to_string(s1);
        result= "MOV R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v4.push_back(final);
    }if(inst==8){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BNE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v4.push_back(final);
    }
  if(inst==9){
  int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BGE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v4.push_back(final);//v1.push_back("BGE");
    }
  if(inst==10){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BL "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v4.push_back(final);
      //v1.push_back("BL");
    }
  if(inst==11){
      int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "B "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v4.push_back(final);
      //v1.push_back("B");
    }
  if(inst==12){
      v4.push_back("LDR_pseudo");
    }

}



for (int i = 0; i < st5.size(); i++)
   {  int inst;
   inst = (st5[i]-st5[i]%1000000)/1000000;
  // cout<<st5[i]<<endl;
   int s2=(st5[i] % 100);

   int s1=((st5[i]%10000-s2)/100);


   int des=((st5[i]%1000000-(st5[i]%10000))/10000)-1;
   string so1 = to_string(s1);

   string des1 = to_string(des);
   // const char *dest = des1.c_str();
   // const char *source1 = so1.c_str();
   // const char *source2 = so2.c_str();
   string result;
   if(inst ==0){
    v5.push_back("NOP");
   }
     if(inst==1){
      //cout<<"ef";
      if(s2<16){
        s2=s2-1;
        string so2 = to_string(s2);
      result= "Add  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {
          s2=s2-16;
        string so2 = to_string(s2);

        result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==2){

      if(s2<=16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "SUB  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "SUB R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==3){

      if(s2<16){
          s2=s2-1;
        string so2 = to_string(s2);

      result= "MUL  R"+ des1 +" R"+ so1 +" R"+ so2 + ".";
     }//const char *final = result.c_str();
      else {

          s2=s2-16;
        string so2 = to_string(s2);

        result= "MUL  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==4){
       s2=s2-16;
        string so2 = to_string(s2);
      //if(s2<16){
      result= "STR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==5){
       s2=s2-16;
        string so2 = to_string(s2);
      result= "LDR  R"+ des1 +" [R"+ so1 +" #"+ so2 + "].";
     //}//const char *final = result.c_str();
     // else {result= "Add  R"+ des1 +" R"+ so1 +" #"+ so2 + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==6){
     if(s1<16){

      s1=s1-1;
        string so1 = to_string(s1);
      result= "CMP  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
        s1=s1-16;
        string so1 = to_string(s1);
        result= "CMP R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
  if(inst==7){
    if(s1<16){
     s1=s1-1;
        string so1 = to_string(s1);
      result= "MOV  R"+ des1 +" R"+ so1 + ".";
     }//const char *final = result.c_str();
      else {
         s1=s1-16;
        string so1 = to_string(s1);
        result= "MOV R"+ des1 +" #"+ so1  + ".";}
      char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);

      v5.push_back(final);
    }
 if(inst==8){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BNE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v5.push_back(final);
    }
  if(inst==9){
  int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BGE "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v5.push_back(final);//v1.push_back("BGE");
    }
  if(inst==10){
    int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "BL "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v5.push_back(final);
      //v1.push_back("BL");
    }
  if(inst==11){
      int ff=0;
    while(s2!=tup[ff].branch)
    {
      ff++;
    }
    result= "B "+tup[ff].label;
      //v1.push_back("BNE");
    char * final = (char *)alloca(result.size() + 1);
    memcpy(final, result.c_str(), result.size() + 1);
      v5.push_back(final);
      //v1.push_back("B");
    }
  if(inst==12){
      v5.push_back("LDR_pseudo");
    }

}
 glutInit(&argc, argv);
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100);

 glutInitWindowSize(1000,1000);
 glutCreateWindow ("Pipeline");

 glClearColor(0.0, 0.0, 0.0, 0.0);         // black background
 glMatrixMode(GL_PROJECTION);              // setup viewing projection
 glLoadIdentity();                           // start with identity matrix
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
glutKeyboardFunc(handleKeypress);
 glutDisplayFunc(display);
 glutTimerFunc(0,Timer, 0);

 glutMainLoop();

 return 0;
}
