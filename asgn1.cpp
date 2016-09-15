#include <iostream>

using namespace std;

double eval(int *pj);
void printme(int vec[]);
double calc(int  arr[], int div);
double diff_calc(int  arr1[], int div1);

int main(){
  int vec[100];
  int best_vec[100];

  double fitness_v, fitness_bv;
  int divider = 50;
  
  fitness_v = diff_calc(vec, divider);
  cout << "***v" << fitness_v << endl;
  if (fitness_v == 100){
    printme(best_vec);
    return fitness_v;
  }
  fitness_bv = calc(best_vec, divider);
  cout << "**bv*" << fitness_bv << endl;
  if (fitness_bv == 100){
    printme(best_vec);
    return fitness_bv;
  }
  
  while(fitness_bv >= fitness_v and divider < 100){
    divider ++;
    fitness_v = calc(vec, divider);
    //cout << "****" << fitness_v << endl;
  }
  while(fitness_v > fitness_bv and divider < 100){
    divider ++;
    fitness_bv = diff_calc(vec, divider);
    //cout << "####" << fitness_v << endl;
  }
}

double calc(int  arr[], int div){{
    for(int i = 0; i < div; i++){
      arr[i] = 1;
    }
    for(int i = div; i < 100; i++){
      arr[i] = 0;
    }
  }
  return eval(arr);
}

double diff_calc(int  arr1[], int div1){{
    for(int i = 0; i < div1; i++){
      arr1[i] = 0;
    }
    for(int i = div1; i < 100; i++){
      arr1[i] = 1;
    }
  }
  return eval(arr1);
}

void printme(int vec[]){
    for(int i=0; i < 100; i++){
      cout << vec[i];
    }
    cout << '\n';
}
