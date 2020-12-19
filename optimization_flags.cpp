#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

vector<vector<int>> mm_multiplikation(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> result;
	vector<int> temp_;
	int temp = 0.0;
	
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < A[0].size(); j++)
		{
			for(int k = 0; k < A[0].size(); k++)
			{
				temp = temp + A[i][k] * B[k][j];
			}
			temp_.push_back(temp);
			temp = 0.0;
		}
		result.push_back(temp_);
		temp_.clear();
	}
	return result;
}

int main()
{
	vector<vector<int>> matrixA;
	vector<vector<int>> matrixB;
	vector<vector<int>> matrixC;
	vector<int> temp;
	
	for(int i = 1; i<1301; i++){ //fill matA with A_ij = (i * j)
		for(int j = 1; j < 1301; j++){
			temp.push_back(i*j);
		}
		matrixA.push_back(temp);
		temp.clear();
	}
	
	for(int i = 1; i<1301; i++){ //fill matB with B_ij = (i + 2) ∗ (j + 1)
		for(int j = 1; j < 1301; j++){
			temp.push_back((i+2)*(j+1));
		}
		matrixB.push_back(temp);
		temp.clear();
	}
	
	struct timespec start, end; 
  
    // start timer
    clock_gettime(CLOCK_MONOTONIC, &start); 
  
    // unsync the I/O of C++
    ios_base::sync_with_stdio(false); 
    
	// time intense calculation
	matrixC = mm_multiplikation(matrixA, matrixB);
	
	// stop timer
    clock_gettime(CLOCK_MONOTONIC, &end); 
    
    // Calculating total time taken by the program. 
    double time_taken; 
    time_taken = (end.tv_sec - start.tv_sec) * 1e9; 
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(9); 
    cout << " sec" << endl; 
}
