#include <iostream>

using namespace std;

class Alb{
public:

  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool full();
  int DarSobresComprados();
  int darenalb();
  int total();
  Alb(int n);
  
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  
  int *album;
  int *repetidas;
};

void Alb::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Alb::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
 n_sobres_comprados = n_sobres_comprados + 1;
}

Alb::Alb(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

bool Alb::full(){
	if(n_en_album == n_total){
		return true;
	}
	else{
		return false;
	}
}


int Alb::DarSobresComprados(){
	return n_sobres_comprados;
}

int Alb::darenalb(){
	return n_en_album;
}

int Alb::total(){
	return n_total;
}

int main(){
  srand(time(0));
  Alb A(660);
  for(int i=0;i<160;i++){
    A.CompraSobre(5);
    A.Status();
  }
}
