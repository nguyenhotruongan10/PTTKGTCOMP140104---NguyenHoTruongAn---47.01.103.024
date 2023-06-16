#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonSubstring(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    // Khởi tạo ma trận L với kích thước (m+1) x (n+1)
    vector<vector<int>> L(m + 1, vector<int>(n + 1));

    // Biến lưu độ dài của chuỗi chung dài nhất và chỉ số kết thúc của chuỗi đó trong X
    int len = 0, idx = 0;

    // Xử lí các phần tử trong ma trận L
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                if (L[i][j] > len) {
                    len = L[i][j];
                    idx = i;
                }
            }
            else {
                L[i][j] = 0;
            }
        }
    }

    // Nếu không có chuỗi chung, trả về chuỗi rỗng
    if (len == 0) {
        return "";
    }

    // Trả về chuỗi chung dài nhất
    return X.substr(idx - len, len);
}

int main()
{
    string X, Y;
    cout << "Nhap chuoi X: ";
    getline(cin, X);
    cout << "Nhap chuoi Y: ";
    getline(cin, Y);

    string result = longestCommonSubstring(X, Y);

    if (result.length() > 0) {
        cout << "Chuoi chung dai nhat la: " << result << endl;
    }
    else {
        cout << "Khong co chuoi chung." << endl;
    }

    return 0;
}