#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


//int main() {
// int n, m;
// cin >> n >> m;
//
// vector <int> A(n), B(m);
// for (int i = 0; i < n; i++) cin >> A[i];
// for (int i = 0; i < m; i++) cin >> B[i];
//
// int min_val = 1e9, vala = -1, valb = -1;
// int inda = 0, indb = 0;
//
// while (inda < n && indb < m) {
//  if (min_val > abs(A[inda] - B[indb])) {
//   vala = A[inda];
//   valb = B[indb];
//   min_val = abs(A[inda] - B[indb]);
//  }
//
//  if (A[inda] > B[indb]) {
//   indb++;
//  }
//  else {
//   inda++;
//  }
// }
//
// cout << min_val << "\n" << vala << " " << valb;
//}

pair<double, double> NewPoint(double X, double Y) {
    pair<double, double> A;
    A.first = X;
    A.second = Y;
    return A;
}

pair<double, double> NewPoint(double radius, double angle, string mode) {
    pair<double, double> A;
    angle = angle * M_PI / 180;
    A.first = radius * cos(angle);
    A.second = radius * sin(angle);
    return A;
}

int main() {
    int N, M_i;
    double lenght = 0;
    pair<double, double> A;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M_i;
        vector <double> X(M_i);
        vector <double> Y(M_i);
        string input;
        for (int j = 0; j < M_i; j++) {
            cin >> input;
            if (input == "P") {
                cin >> X[j] >> Y[j];
                A = NewPoint(X[j], Y[j], "P");
            }
            else {
                X[j] = stoi(input);
                cin >> Y[j];
                A = NewPoint(X[j], Y[j]);
            }
            X[j] = A.first;
            Y[j] = A.second;
        }
        for (int j = 1; j < M_i; j++) {
            lenght += sqrt(pow((X[j] - X[j - 1]), 2) + pow((Y[j] - Y[j - 1]), 2));
        }
        cout << lenght << endl;
        lenght = 0;
    }
}