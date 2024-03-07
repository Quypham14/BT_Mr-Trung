#include <bits/stdc++.h>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm ưu tiên của các toán tử
int get(char op)
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
    stack<char> op;
    string postfix = "";

    for (char &c : s)
    {
        if (isalnum(c))
        {
            postfix += c; // Nếu là toán hạng, thêm vào biểu thức hậu tố
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop(); // Loại bỏ '(' khỏi ngăn xếp
        }
        else if (isOp(c))
        {
            while (!op.empty() && get(op.top()) >= get(c))
            {
                postfix += op.top();
                op.pop();
            }
            op.push(c);
        }
    }

    // Đưa toàn bộ toán tử còn lại trong ngăn xếp vào biểu thức hậu tố
    while (!op.empty())
    {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}

int main()
{
    string s;
    getline(cin, s);

    string post = treatment(s);

    cout << post << endl;

    return 0;
}
