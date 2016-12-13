#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    // DO STUFF HERE AND POPULATE result
    int m = A.size();
    int n = A[0].size();
    cout << "debug: " << "m = " << m << " n= " << n << endl;
        
    int nElems = m * n;
    int cnt = 0;
    int trow = 0, brow = m - 1, lcol = 0, rcol = n - 1;
    
    while (cnt != nElems) {
        // print left->right
        for (int i = lcol; i <= rcol; ++i) {
            //cout << A[trow][i] << "\t";
            result.push_back(A[trow][i]);
        }
        
        // print top->bot
        for (int i = trow + 1; i <= brow; ++i) {
            //cout << A[i][rcol] << "\t";
            result.push_back(A[i][rcol]);
        }
        
        // print bot right->bot left
        for (int i = rcol - 1; i >= lcol; --i) {
            //cout << A[brow][i] << "\t";
            result.push_back(A[brow][i]);
        }
        
        // print bot left->top
        for (int i = brow - 1; i > trow; --i) {
            //cout << A[i][lcol] << "\t";
            result.push_back(A[i][lcol]);
        }
        
        cnt += (rcol - lcol + 1) + (brow - trow) + (rcol - lcol) + (brow - trow - 1);
        
        cout << endl;
        cout << "debug: " << "trow=" << trow << " lcol=" << lcol << " brow=" << brow << " rcol=" << rcol;
        cout << "debug: " << "cnt=" << cnt << endl;
        
        ++trow;
        --brow;
        ++lcol;
        --rcol;
    }
    
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  
}

vector<vector<int> > getMatrix(int m, int n)
{
    vector<vector<int> > A;
    for (int i = 0; i < m; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            row.push_back(i*10+j);
        }
        
        A.push_back(row);
        
    }
    
    return A;
}

void printMatrix(vector<vector<int> >&A)
{
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }
}

void printVector(vector<int>& A)
{
    for (int i = 0; i < A.size(); ++i)
        cout << A[i] << "\t";
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<vector<int> > A = getMatrix(4,4);
    vector<int> result;
    
    printMatrix(A);
    result = spiralOrder(A);
    printVector(result);
    
    A = getMatrix(4,2);
    printMatrix(A);
    result = spiralOrder(A);
    printVector(result);
    
    A = getMatrix(2,4);
    printMatrix(A);
    result = spiralOrder(A);
    printVector(result);
    
    //A = getMatrix(1,1);
    //printMatrix(A);
    //result = spiralOrder(A);
    //printVector(result);
    
    return 0;
}

