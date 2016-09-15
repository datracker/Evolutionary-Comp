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