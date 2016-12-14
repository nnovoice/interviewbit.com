#include <vector>
#include <iostream>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    // DO STUFF HERE AND POPULATE result
    int m = A.size();
    int n = A[0].size();
    //cout << "debug: " << "m = " << m << " n= " << n << endl;
        
    int nElems = m * n;
    //int cnt = 0;
    int trow = 0, brow = m - 1, lcol = 0, rcol = n - 1;
    
    //while (cnt != nElems) {
    while (trow <= brow && lcol <= rcol) {

        //cout << "debug: " << " before " << "trow=" << trow << " lcol=" << lcol << " brow=" << brow << " rcol=" << rcol << endl;

        // print left->right
        for (int i = lcol; i <= rcol; ++i) {
            //cout << A[trow][i] << "\t";
            result.push_back(A[trow][i]);
        }
        
        ++trow;
        
        // print top->bot
        for (int i = trow; i <= brow; ++i) {
            //cout << A[i][rcol] << "\t";
            result.push_back(A[i][rcol]);
        }
        
        --rcol;
        
        // print bot right->bot left
        for (int i = rcol; i >= lcol && m > 1; --i) {
            //cout << A[brow][i] << "\t";
            result.push_back(A[brow][i]);
        }
        
        --brow;
        
        // print bot left->top
        for (int i = brow; i >= trow && n > 1; --i) {
            //cout << A[i][lcol] << "\t";
            result.push_back(A[i][lcol]);
        }
        
        ++lcol;
        
        //cout << "debug: " << " after " << "trow=" << trow << " lcol=" << lcol << " brow=" << brow << " rcol=" << rcol << endl;
    }
    
    return result;
}

vector<vector<int> > getMatrix(int m, int n)
{
    vector<vector<int> > A;
    for (int i = 0; i < m; ++i) {
        vector<int> row;
        for (int j = 0; j < n; ++j) {
            row.push_back(i*10 + j*10 + j);
        }
        
        A.push_back(row);
        
    }
    
    return A;
}

void printMatrix(vector<vector<int> >&A)
{
    cout << endl << "Matrix m= " << A.size() << " n=" << A[0].size() << endl;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

void printVector(vector<int>& A)
{
    cout << "debug: " << "num elements in the vector=" << A.size() << endl;
    for (int i = 0; i < A.size(); ++i)
        cout << A[i] << "\t";
    cout << endl;
}

int main(int argc, char *argv[])
{
    int m[] = {4, 4, 2, 3, 1, 10, 3, 10, 1};
    int n[] = {4, 2, 4, 2, 1, 2, 1, 1, 5};
    
    vector<vector<int> > A;
    vector<int> result;
    
    int len = (int)(sizeof(m)/sizeof(int));
    
    for (int i = 0; i < len; ++i) {
        A = getMatrix(m[i], n[i]);
        printMatrix(A);
        result = spiralOrder(A);
        printVector(result);
    }
    
    return 0;
}

