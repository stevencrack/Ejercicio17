#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

using namespace std;

void cambio(Alb 1, Alb 2);

class Alb{

public:

  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool full();
  int DarSobresComprados();
  int darenalb();
  int total();
  bool dar(int n);
  bool recibir(int n);
  void rm(int n);
  void add(int n);
  Alb(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

Alb::Alb(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_sobres_comprados = 0;
  n_repetidas = 0;
  n_en_album = 0 ;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

void Alb::Status(void){
  cout << n_en_album << " " <<n_repetidas << endl;
}

void Alb::CompraSobre(int n_en_sobre){
  int lamina;
  
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;

    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }
    else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
  n_sobres_comprados = n_sobres_comprados + 1;
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

bool dar(int n){
  if(repetidas[n] != 0){
    return true;
  }
  else{
    return false;
  }
}

bool recibir(int n){
  if(album[n]==0){
    return true;
  }
  else{
    return false;
  }
}
void rm(int n){
  repetidas[n] = repetidas[n] - 1; 
}
void add(int n){
  album[n] = 1;
}




int main(){
  srand(time(0));
  Alb A(660);
  Alb B(660);
  int count = 0; 
  while(A.full() == false){
  	A.CompraSobre(5);
    B.CompraSobre(5);
    cambio(A,B);
  	count++;
  }
  cout << A.DarSobresComprados() << endl;
}

void cambio(Alb A, Alb B){
  int N = A.total();
  int c_A = 0;
  int c_B = 0;

  for(int i=1 ; i<=N ; i++){
    if(A.dar(i) && B.recibir(i)){
      c_A++;
    }
    else if(A.recibir(i) && B.dar(i)){
      c_B++;
    }
  }
  int camb = ((c_A > c_B) ? c_A : c_B );
  int n = 0;

  for(int i=1 ; i<=N ; i++){
    int cA = 0;
    int cB = 0;

    while(cA < camb){
      if(A.dar(i) && B.recibir(i)){
        A.rm(i);
        B.Addi);
        cA ++;
      }
    }




    while(cB < camb){
      if(A.recibir(i) && B.dar(i)){
        A.Add(i);
        B.rm(i);
        cB ++;
      }
    }

  }

}

