#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là toán tử hay không
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Hàm tính giá trị của biểu thức hậu tố
double evaluatePostfix(string postfix)
{
    stack<double> operands;

    for (char &c : postfix)
    {
        if (isalnum(c))
        {
            // Nếu là toán hạng, chuyển từ ký tự sang số và thêm vào ngăn xếp
            operands.push(static_cast<double>(c - '0'));
        }
        else if (isOperator(c))
        {
            // Nếu là toán tử, lấy hai toán hạng từ ngăn xếp và thực hiện phép toán
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            switch (c)
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            }
        }
    }

    // Kết quả cuối cùng sẽ nằm trong ngăn xếp
    return operands.top();
}

int main()
{
    string postfixExpression;

    cout << "Nhap bieu thuc hau to: ";
    getline(cin, postfixExpression);

    double result = evaluatePostfix(postfixExpression);

    cout << "Gia tri cua bieu thuc hau to: " << result << endl;

    return 0;
}
