#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int n, s;
    std::cout << "So menh gia la: ";
    std::cin >> n;
    std::cout << "So tien can doi la: ";
    std::cin >> s;

    std::vector<int> c(n);
    std::cout << "Nhap cac menh gia: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    c.insert(c.begin(), 0);

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(s + 1, 0));
    for (int i = 1; i <= s; i++)
    {
        f[0][i] = INT_MAX; //tra ve vo cung neu khong co menh gia de doi
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= c[i])
            {
                    f[i][j] = std::min(f[i - 1][j], f[i][j - c[i]] + 1);
            }
        }
    }
    std::cout <<"So to da doi: ";
    std::cout << f[n][s] << std::endl;

    int i = n, j = s;
    std::vector<int> k;
    while (i > 0 && j > 0)
    {
        if (f[i][j] != f[i - 1][j])
        {
            k.push_back(i);
            j -= c[i];
        }
        else
        {
            i--;
        }
    }

    std::cout << "Cac dong xu can su dung la: ";
    for (int i = k.size() - 1; i >= 0; i--)
    {
        std::cout << c[k[i]] << " ";
    }

    return 0;
}