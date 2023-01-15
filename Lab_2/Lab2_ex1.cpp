#include <iostream>

using namespace std;

int numberOfSolutions(int coefficients[], int startingIndex, int endingIndex, int constant) {
    if (constant == 0) {
        return 1;
    }

    int result = 0;

    for (int i = startingIndex; i <= endingIndex; i++) {
        if (coefficients[i] <= constant  ) {
            result += numberOfSolutions(coefficients, i, endingIndex, constant - coefficients[i]);
        }
    }

    return result;
}

int main (void) {
    int n;
	int coefficients[100];
	int constant;
    cin >> n;
    cin >> constant;
    
    
	for (int i = 0; i < n; i++) {
        cin >> coefficients[i];
    }
    
    int noOfSolutions = numberOfSolutions(coefficients, 0, n - 1, constant);
    cout << noOfSolutions << "\n";
    return 0;
}
