# Evolutionary Computer Course Projects
## Assignment 1
Hill Climber Algorithm:
The algorithm initiates with two vectors. One with the first value 0, rests are 1; other with the first value 1 and rests are 0. The eval() function then compares the two values and set the best value.
When the one value is better than other value, the vector associated with the lower value changes. It changes in a way, where instead of the first value, the first two values changes. At this point, the new vector, is compared with the earlier vector, if the value is same or better, the other vector changes. And, the iteration goes on unless we get the value equal to the max value.

Strength:

If the distribution of the data follows a bell curve, then it’s easily possible to get to the top. In the worst case, it have to iterate n/2 times.

Weakness:

In the worst case, it might have to iterate through n/2, which is sometimes big. Again, the algorithm does not work, if there is a static value for a long span of data. Also, the algorithm will fail to produce result, when there’ll be any sharp changes in values:

Hill Climber:

```C++
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
  if (fitness_v == 100) {
    printme(best_vec);
    return fitness_v;
  }
  
  fitness_bv = calc(best_vec, divider);
  cout << "**bv*" << fitness_bv << endl;
  if (fitness_bv == 100) {
    printme(best_vec);
    return fitness_bv;
  }
  
  while(fitness_bv >= fitness_v and divider < 100) {
    divider ++;
    fitness_v = calc(vec, divider);
    //cout << "****" << fitness_v << endl;
  }

  while(fitness_v > fitness_bv and divider < 100) {
    divider ++;
    fitness_bv = diff_calc(vec, divider);
    //cout << "####" << fitness_v << endl;
  }
}

double calc(int  arr[], int div) {
    for(int i = 0; i < div; i++) {
      arr[i] = 1;
    }
    for(int i = div; i < 100; i++) {
      arr[i] = 0;
    }
  return eval(arr);
}

double diff_calc(int  arr1[], int div1) {
    for(int i = 0; i < div1; i++){
      arr1[i] = 0;
    }
    for(int i = div1; i < 100; i++) {
      arr1[i] = 1;
    }
  return eval(arr1);
}

void printme(int vec[]) {
    for(int i=0; i < 100; i++) {
      cout << vec[i];
    }
    cout << '\n';
}
```
 


Eval function:
```C++
#include <iostream>

using namespace std;

string eval(int* x);

int main (){
	string result = eval(x);	
}

string eval(int* x){
	int sum = 0;
	for (int i = 0; i < 20; i++){
		if (i%2 == 0 and x[i] == 1){
			sum ++;
		}
	}
	for (int i = 20; i < 50; i++){
		if (i%2 == 1 and x[i] == 0){
			sum ++;
		}
	}
	if(x[23] and x [45] and x[78]){
		sum += 100;
	}

	if(sum > 100){
		
		return "Well done!";
	}
	else{
		return "Try again";
	}
}
```
