#include <iostream>
#include <string>
using namespace std;

class Avto{
  string *Model;
	unsigned short *kol_mest;
	float *max_skor;
public:
	Avto();
	Avto(string,unsigned short,float);
	Avto(int);
	Avto(const Avto &);
	~Avto();
	void Output();
	void Input();
	void Equals(const Avto &);

	unsigned short getkol_mest() const{return *kol_mest;}
	void setkol_mest(unsigned short _kol_mest) {*kol_mest=_kol_mest;}
	string getModel()const {return *Model;}
	void setModel(string a) {*Model=a;}
	float getmax_skor() const {return *max_skor;}
	void setmax_skor(float _max_skor) {*max_skor=_max_skor;}

};

Avto::Avto(){
	
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*kol_mest=4;
	*max_skor=700;
	*Model="Mazda";

}

Avto::Avto(string a,unsigned short b,float c){
	
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*kol_mest=b;
	*max_skor=c;
	*Model=a;
}

Avto::Avto(int a){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	Input();
}

Avto::Avto(const Avto & Av){
	kol_mest=new unsigned short;
	max_skor=new float;
	Model=new string;
	*kol_mest=Av.getkol_mest();
	*max_skor=Av.getmax_skor();
	*Model=Av.getModel();
}

Avto::~Avto(){
	delete kol_mest;
	delete max_skor;
	delete Model;
	kol_mest=0;
	max_skor=0;	
	Model=0;
}

void Avto::Input(){
unsigned short int a1;float b1;string c1;
cout<<"Vv nazv modeli: ";
cin>>c1;
cout<<endl<<"Vv kol-vo mest: ";
cin>>a1;
cout<<endl<<"Vv max skorost': ";
cin>>b1;
cout<<endl;
*kol_mest=a1;
*max_skor=b1;
*Model=c1;
}

void Avto::Output(){
	cout<<"Model:"<<*Model<<endl;
	cout<<"Kol-vo mest: " <<*kol_mest<<endl;
	cout<<"Max skorost': "<<*max_skor<<endl;
}


void Avto::Equals(const Avto &b){
	int x;float z;
	cout <<"Nazvanie: ";
	if (getModel()<b.getModel())
		cout <<getModel()<<"<"<<b.getModel()<<endl;
	else if (getModel()==b.getModel())
		cout <<getModel()<<"="<<b.getModel()<<endl;
	else cout <<getModel()<<">"<<b.getModel()<<endl;
	
	cout<<"Kol-vo mest: ";
	x=(getkol_mest()-b.getkol_mest());
	if (x>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<x<<endl;
	else if (x<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<(x*(-1))<<endl;
	else cout<<"odinakovo = "<<getkol_mest()<<endl;
	
	cout<<"Max Skorost' : ";
	z=(getmax_skor()-b.getmax_skor());
	if (z>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<z<<endl;
	else if (z<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<(z*(-1))<<endl;
	else cout<<"odinakova = "<<getmax_skor()<<endl;
}
int main(){
 Avto m1;
 Avto m2("Honda",6,456.7);
 Avto m3(0);
 Avto m4(m3);

 m1.setModel("BMW");
 m1.setkol_mest(5);
 m1.setmax_skor(238.5);

 m4.Input();

 m1.Output();
 m2.Output();
 m3.Output();
 m4.Output();
 cin.get();

 m2.Equals(m3);
 cin.get();
 cin.get();
 return 0;
}
