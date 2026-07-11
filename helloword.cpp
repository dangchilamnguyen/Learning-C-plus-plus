#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    system("chcp 65001 > nul"); // Thêm dòng này để sửa lỗi font tiếng Việt
    double a;
    double b;
    double c;

    std::cout << "cạnh 1: ";
    std::cin >> a; // Nhập xong cạnh 1 mới hỏi tiếp cạnh 2

    std::cout << "cạnh 2: ";
    std::cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));
    std::cout << "Cạnh huyền = " << c << '\n';

    system("pause"); // cho cái app exe k bị tắt
    return 0;
}
