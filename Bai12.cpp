#include <bits/stdc++.h>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm ưu tiên của các toán tử
int getPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string treatment(string s)
{
    stack<char> operators;
    string postfix = "";

    for (char &c : s)
    {
        if (isalnum(c))
        {
            postfix += c; // Nếu là toán hạng, thêm vào biểu thức hậu tố
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Loại bỏ '(' khỏi ngăn xếp
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Đưa toàn bộ toán tử còn lại trong ngăn xếp vào biểu thức hậu tố
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main()
{
    string s;

    cout << "Nhap bieu thuc trung to: ";
    getline(cin, s);

    string post = treatment(s);

    cout << "Bieu thuc hau to tuong ung: " << post << endl;

    return 0;
}
