#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

void printMatrix(vector<vector<double>> a) {
	for (int i = 0; i < a[0].size(); i++) {
		for (int j = 0; j < a[0].size(); j++)
			printf("%4.0f ", a[i][j]);
		cout << endl;
	}
}

vector <vector<double>> reductionMatrix(vector <vector<double>> a) {
    double red_const, bottom_line = 0;
    for (int i = 1; i < a[0].size(); i++) {
        red_const = numeric_limits <double>::infinity();
        for (int j = 1; j < a[0].size(); j++)
            if (a[i][j] < red_const) red_const = a[i][j];
        for (int j = 1; j < a[0].size(); j++)
            a[i][j] -= red_const;
        bottom_line += red_const;
    }
    for (int i = 1; i < a[0].size(); i++) {
        red_const = numeric_limits <double>::infinity();
        for (int j = 1; j < a[0].size(); j++)
            if (a[j][i] < red_const) red_const = a[j][i];
        for (int j = 1; j < a[0].size(); j++)
            a[j][i] -= red_const;
        bottom_line += red_const;
    }
    return a;
}

void deleteRC(vector<vector<double>> &a, int i, int j) {
	int n = a[0].size();
    double b;
	for (int k = i; k < n - 1; k++)
		for (int q = 0; q < n; q++) {
			b = a[k][q];
			a[k][q] = a[k + 1][q];
			a[k + 1][q] = b;
		}
	a.resize(n - 1);
	for (int k = j; k < n - 1; k++)
		for (int q = 0; q < n - 1; q++) {
			b = a[q][k];
			a[q][k] = a[q][k + 1];
			a[q][k + 1] = b;
		}
	for (int i = 0; i < n - 1; i++)
		a[i].resize(n - 1);
}

vector<vector<double>> reduceMatrix(vector<vector<double>> a, int i, int j) {
    double red_const, bottom_line = 0;
    deleteRC(a, i, j);
    for (int i = 0; i < a[0].size(); i++) {
        red_const = numeric_limits <double>::infinity();
        for (int j = 0; j < a[0].size(); j++)
            if (a[i][j] < red_const) red_const = a[i][j];
        bottom_line += red_const;
    }
    for (int i = 0; i < a[0].size(); i++) {
        red_const = numeric_limits <double>::infinity();
        for (int j = 0; j < a[0].size(); j++)
            if (a[j][i] < red_const) red_const = a[j][i];
        bottom_line += red_const;
    }
    return a;
}

void bbmethod(vector<vector<double>> &a) {
    if (a[0].size() > 2) {
        a = reductionMatrix(a);
        int maxi, maxj;
        double branch_edge_column, branch_edge_row, max_b_l = -1;
        for (int i = 1; i < a[0].size(); i++)
            for (int j = 1; j < a[0].size(); j++)
                if (a[i][j] == 0) {
                    branch_edge_column = numeric_limits <double>::infinity();
                    branch_edge_row = numeric_limits <double>::infinity();
                    for (int k = 1; k < a[0].size(); k++) {
                        if (a[i][k] < branch_edge_row && k != j) branch_edge_row = a[i][k];
                        if (a[k][j] < branch_edge_column && k != i) branch_edge_column = a[k][j];
                    }
                    if (branch_edge_column + branch_edge_row > max_b_l) {
                        max_b_l = branch_edge_column + branch_edge_row;
                        maxi = i; maxj = j;
                    }
                }
        a[maxi][maxj] = numeric_limits <double>::infinity();
        for (int i = 1; i < a[0].size(); i++)
            for (int j = 1; j < a[0].size(); j++)
                if (a[maxi][0] == a[0][j] && a[0][maxj] == a[0][i])
                    a[i][j] = numeric_limits <double>::infinity();
        cout << a[maxi][0] << " " << a[0][maxj] << endl;
        a = reduceMatrix(a, maxi, maxj);
        bbmethod(a);
    } else {
        cout << a[1][0] << " " << a[0][1] << endl;
    }
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<vector<double>> a(66);
    int n, x;
    double bottom_line;
	cin >> n;
    for (int i = 0; i <= n; i++)
        a[0].push_back(i);
    for (int i = 1; i <= n; i++) {
        a[i].push_back(i);
        for (int j = 0; j < n; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    for (int i = 1; i < a[0].size(); i++)
        a[i][i] = numeric_limits <double>::infinity();
    bbmethod(a);
	system("pause");
	return 0;
}