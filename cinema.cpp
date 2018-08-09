#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
using namespace std;

char place[10][15][5];
float zone[10][15];
int seans=0;
float price_today;
float z1=30;
float z2=40;
float z3=50;


// place[ряд][место]


void color (int color_fone, int color_text){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((color_fone << 4) | color_text));
}

void hall(){
 system("cls");
 color(0,11);

 cout<<"    __________________Screen___________________   Seans: "<<seans+1<<"\n";
 cout<<"    ";
 for (int a=1; a<16; a++) {if (a<10) {cout<<a<<"  ";} else {cout<<a<<" ";};};

 cout<<"\n";

 color(0,15);
 for (int i=0;i<10; i++) {
        cout<<i+1<<"  ";
        if (i!=9) cout<<" ";
  for (int j=0;j<15;j++) {
        if (zone[i][j]==z2) color(0,13);
        if (zone[i][j]==z3) color(0,12);
        if (zone[i][j]==z1) color(0,10);
        cout<<place[i][j][seans]<<"  ";
       }
  cout<<"\n";
 };
   color(0,15);
}

void init(){
 for (int s=0;s<5;s++)
 for (int i=0;i<10; i++)
  for (int j=0;j<15;j++) place[i][j][s]='F';

 for (int i=0;i<10; i++)
   for (int j=0;j<15;j++) zone[i][j]=z1;
  for (int i=3;i<8; i++)
   for (int j=4;j<11;j++) zone[i][j]=z2;
 for (int j=0;j<15;j++) zone[9][j]=z3;
}

void helper(){
  int l,p;

  do {
   cout<<"line: ";
   cin>>l;
   cout<<"place: ";
   cin>>p;
   l--;p--;
   if (place[l][p][seans]!='F') cout<<"Taken!\n";
  } while (place[l][p][seans]!='F');
   place[l][p][seans]=char(219);
   hall();
}

float prise(){
  float summa;
  summa=0;
  for (int s=0;s<5;s++)
  for (int i=0;i<10; i++)
   for (int j=0;j<15;j++)
      if (place[i][j][s]!='F') {summa+=price_today*zone[i][j]/100;}
  return summa;
}

int main()
{
    init();
    hall();
    char q;
    cout<<"Price today: ";
    cin>>price_today;
    do {
    cout<<"Seans (1-5):";
    cin>>seans;
    seans--;
    hall();
    if (seans>=0) {

     do {
       helper();
       cout<<"Quit seans (y/n)";
       cin>>q;
      } while(q=='n');
    };
    } while (seans>=0);
    cout<<"Summa= "<<prise();


    ifstream fin("cinema.dat");

     for (int s=0;s<5;s++)
      for (int i=0;i<10; i++)
       for (int j=0;j<15;j++) fin<<place[i][j][s]<<" ";
    fin.close();




    return 0;
}
