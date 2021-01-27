#ifndef NO
#define NO

#include <iostream>

using namespace std;

class No {

  private:

     int _dado;
     int _prioridade;

  public:

    No(int prioridade, int dado);
	
     int getDado();
     void setDado(int dado);

	  int getPrioridade();
	  void setPrioridade(int prioridade);
};

#endif