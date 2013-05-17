#include <iostream>
using namespace std;
enum TYPE{SEDAN,LIMUZIN,KUPE,UNIVERSAL,FURGON};//перечень типов легковых машин

class Avto{
protected:
  char Model[35];
	unsigned short *kol_mest;
	float *max_skor;
public:
	Avto();
	Avto(char*,unsigned short,float);
	Avto(int);
	Avto(const Avto &);
	~Avto();
	void Output();
	void Input();
	void Equals(const Avto &);

	unsigned short getkol_mest() const{return *kol_mest;}
	void setkol_mest(unsigned short _kol_mest) {*kol_mest=_kol_mest;}
	const char* getModel()const {return Model;}
	void setModel(char *a) {strcpy(Model,a);}
	float getmax_skor() const {return *max_skor;}
	void setmax_skor(float _max_skor) {*max_skor=_max_skor;}

};

Avto::Avto(){
	strcpy(Model,"Mazda");
	kol_mest=new unsigned short;
	max_skor=new float;
	*kol_mest=4;
	*max_skor=700;
}

Avto::Avto(char*a,unsigned short b,float c){
	strcpy(Model,a);
	kol_mest=new unsigned short;
	max_skor=new float;
	*kol_mest=b;
	*max_skor=c;
}

Avto::Avto(int a){
	kol_mest=new unsigned short;
	max_skor=new float;
	Input();
}

Avto::Avto(const Avto & Av){
	kol_mest=new unsigned short;
	max_skor=new float;
	*kol_mest=Av.getkol_mest();
	*max_skor=Av.getmax_skor();
	strcpy(Model,Av.getModel());
}

Avto::~Avto(){
	delete kol_mest;
	delete max_skor;
	kol_mest=0;
	max_skor=0;	
} 
class LegkovieAvto :public Avto{
public:
	LegkovieAvto():mType(SEDAN){};
	~LegkovieAvto(){};
	TYPE getType() const {return mType;}
	void setType(TYPE Type) {mType=Type;}
private:
	TYPE mType;
};

class GruzovieAvto :public Avto{
public:
	GruzovieAvto():gruz(50){};
	~GruzovieAvto(){};
	float getgruz() const {return gruz;}
	void setgruz(float _gruz) {gruz=_gruz;}
private:
	float gruz;
};

void Avto::Input(){
unsigned short int a1;float b1;
cout<<"Vv nazv modeli: ";
cin>>Model;
cout<<endl<<"Vv kol-vo mest: ";
cin>>a1;
cout<<endl<<"Vv max skorost': ";
cin>>b1;
cout<<endl;
*kol_mest=a1;
*max_skor=b1;
}

void Avto::Output(){
	cout<<"Model:"<<Model<<endl;
	cout<<"Kol-vo mest: " <<*kol_mest<<endl;
	cout<<"Max skorost': "<<*max_skor<<endl;
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
LegkovieAvto m1;
m1.Output();
cout<<m1.getModel()<<" - "<<m1.getType()<<endl;
m1.setType(UNIVERSAL);
cout<<m1.getModel()<<" - "<<m1.getType()<<endl;
GruzovieAvto m2;
m2.Input();
m2.Output();
cout<<m2.getModel()<<" - "<<m2.getgruz()<<endl;
m2.setgruz(3700);
cout<<m2.getModel()<<" - "<<m2.getgruz()<<endl;

 cin.get();
 cin.get();
 return 0;
}
