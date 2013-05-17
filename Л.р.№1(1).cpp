#include <iostream>
using namespace std;

class Avto{
  char Model[35];
	unsigned short kol_mest;
	float max_skor;
public:
	Avto();
	Avto(char*,unsigned short,float);
	Avto(int);
	~Avto();
	void Output();
	void Input();
	void Equals(const Avto &);

	unsigned short getkol_mest() const{return kol_mest;}
	void setkol_mest(unsigned short _kol_mest) {kol_mest=_kol_mest;}
	const char* getModel()const {return Model;}
	void setModel(char *a) {strcpy(Model,a);}
	float getmax_skor() const {return max_skor;}
	void setmax_skor(float _max_skor) {max_skor=_max_skor;}

};

Avto::Avto(){
	strcpy(Model,"Mazda");
	kol_mest=4;
	max_skor=700;
}

Avto::Avto(char*a,unsigned short b,float c){
	strcpy(Model,a);
	kol_mest=b;
	max_skor=c;
}

Avto::Avto(int a){
	Input();
}

Avto::~Avto(){
}

void Avto::Input(){
cout<<"Vv nazv modeli: ";
cin>>Model;
cout<<endl<<"Vv kol-vo mest: ";
cin>>kol_mest;
cout<<endl<<"Vv max skorost': ";
cin>>max_skor;
cout<<endl;
}

void Avto::Output(){
	cout<<"Model:"<<Model<<endl;
	cout<<"Kol-vo mest: " <<kol_mest<<endl;
	cout<<"Max skorost': "<<max_skor<<endl;
}


void Avto::Equals(const Avto &b){
	int x;float z;
	cout <<"Nazvanie: ";
	if (strcmp(getModel(),b.getModel())<0)
		cout <<getModel()<<"<"<<b.getModel()<<endl;
	else if (strcmp(getModel(),b.getModel())==0)
		cout <<getModel()<<"="<<b.getModel()<<endl;
	else cout <<getModel()<<">"<<b.getModel()<<endl;
	
	cout<<"Kol-vo mest: ";
	x=(getkol_mest()-b.getkol_mest());
	if (x>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<x<<endl;
	else if (x<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<abs(x)<<endl;
	else cout<<"odinakovo = "<<getkol_mest()<<endl;
	
	cout<<"Max Skorost' : ";
	z=(getmax_skor()-b.getmax_skor());
	if (z>0) 
		cout<<getModel()<<" bolshe "<<b.getModel()<<" na "<<z<<endl;
	else if (z<0) 
		cout<<b.getModel()<<" bolshe "<<getModel()<<" na "<<abs(z)<<endl;
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
