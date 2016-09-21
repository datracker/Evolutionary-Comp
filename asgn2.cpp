#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double eval(int *pj);
int randomNum();
void printVec(bool *vec);
double fitLevel(bool *vec);
void printFitness(int *array);

int main(){
  bool vec[150];
  int alist[100];
  int i;
  srand((unsigned)time(0));
  double fitness;
  
  for (int i = 0; i < 100; i++){
    for(int j = 0; j < 150; j++){
      *(vec+j) = randomNum();
    }
    //printVec(vec);
    fitness = fitLevel(vec);
    *(alist + i) = fitness;
    //cout <<"Index: " << i <<" fitness = " << fitness << endl;
    printFitness(alist);
  }
  
}

int randomNum(){
    return (rand()%2);
}

void printVec(bool *vec){
  for(int i = 0; i < 150; i++){
    cout << *(vec + i);
  }
  cout << "\n";
}

double fitLevel(bool *vec){
  double fit = eval((int*)vec);; //typecasted from bool to int
  return fit;
}

void printFitness(int *array){
  for(int i = 0; i < (sizeof(array)/sizeof(int)); i++){
    cout << *(array + i) << " ";
  }
  cout << "\n";
}