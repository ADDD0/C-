#include <iostream>
#include <cstring>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

//一些函数的定义
void init_string(string &ini);         //初始化
string del_include(string temp);       //消去蕴涵符号
string dec_neg_rand(string temp);      //减少否定符号的辖域
string standard_var(string temp);      //对变量标准化
string del_exists(string temp);        //消去存在量词
string convert_to_front(string temp);  //化为前束形
string convert_to_and(string temp);    //把母式化为合取范式
string del_all(string temp);           //消去全称量词
string del_and(string temp);           //消去连接符号合取^
string change_name(string temp);       //更换变量名称

//辅助函数定义
string del_null_bracket(string temp);  //删除多余的括号
string del_blank(string temp);         //删除多余的空格
void check_legal(string temp);         //检查合法性
char num_to_char(int temp);            //数字显示为字符

//主函数
int main() {
    cout << "------------------求子句集九步法演示-----------------------" << endl;
    string origin, temp;
    char command0, command1, command2, command3, command4, command5,
    command6, command7, command8, command9;
    //=========================================================================
    cout << "0.(准备工作)输入初始化谓词公式(y/n):";
    cin >> command0;
    if (tolower(command0) == 'y')
        init_string(origin);
    else
        exit(0);
    //=========================================================================
    cout << "1.消去蕴涵符号(y/n):";
    cin >> command1;
    if (tolower(command1) == 'y') {
        origin = del_include(origin);
        cout << "消去蕴涵符号后是:" << endl << origin << endl;
    } else
        exit(0);
    //=========================================================================
    cout << "2.减否定符辖域(y/n):";
    cin >> command2;
    if (tolower(command2) == 'y') {
        do {
            temp = origin;
            origin = dec_neg_rand(origin);
        } while (temp != origin);
        cout << "减否定符辖域后是:" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "3.对变量标准化(y/n):";
    cin >> command3;
    if (tolower(command3) == 'y') {
        origin = standard_var(origin);
        cout << "对变量标准化后是:" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "4.消去存在量词(y/n):";
    cin >> command4;
    if (tolower(command4) == 'y') {
        origin = del_exists(origin);
        cout << "消去存在量词后是(w=g(x)是一个Skolem函数):" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "5.化为前束形(y/n):";
    cin >> command5;
    if (tolower(command5) == 'y') {
        origin = convert_to_front(origin);
        cout << "化为前束形后是:" << endl << origin << endl;
    } else
    exit(0);
    //=============================================================================
    cout << "6.化为合取范式(y/n):";
    cin >> command6;
    if (tolower(command6) == 'y') {
        origin = convert_to_and(origin);
        cout << "化为合取范式后是:" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "7.消去全称量词(y/n):";
    cin >> command7;
    if (tolower(command7) == 'y') {
        origin= del_all(origin);
        cout << "消去全称量词后是:" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "8.消去合取符(y/n):";
    cin >> command8;
    if (tolower(command8) == 'y') {
        origin = del_and(origin);
        cout << "消去合取符后是:" << endl << origin << endl;
    } else
        exit(0);
    //=============================================================================
    cout << "9.更换变量名(y/n):";
    cin >> command9;
    if (tolower(command9) == 'y') {
        origin = change_name(origin);
        cout << "更换变量名后是(x1, x2, x3代替变量x):" << endl << origin << endl;
    } else
    exit(0);
    //============================================================================
    cout << "-------------------------完毕-----------------------------------" << endl;
}

void init_string(string &ini) {
    char commanda, commandb;

    cout << "请输入您要转换的谓词公式:" << endl;
    cout << "是否需要查看输入帮助(y/n):";
    cin >> commanda;
    if (tolower(commanda == 'y'))
        cout << "本例程规定输入时蕴涵符号为>, 全称量词为@, 存在量词为#, " << endl << "取反为~, 析取为V, 合取为^, 左右括号分别为(和), 函数名用一个字母代替" << endl;
    cout << "是否由用户自定义(y/n):";
    cin >> commandb;
    if (tolower(commandb == 'y'))
        cin >> ini;
    else
        ini = "(@x)(P(x)>((@y)(P(y)>P(f(x,y)))^~(@y)(Q(x,y)>P(y))))";
    cout << "原始命题是" << endl << ini << endl;
}

string del_include(string temp) {      //消去>蕴涵项
    //a>b变为~aVb
    char ctemp[100]={""};
    string output;
    int length = temp.length();
    int i=0, right_bracket=0, flag=0;
    stack<char> stack1, stack2, stack3;

    strcpy_s(ctemp, temp.c_str());
    while (ctemp[i] != '\0' && i <= length-1) {
        stack1.push(ctemp[i]);
        if ('>' == ctemp[i+1]) {       //如果是a>b则用~aVb替代
            flag = 1;
            if (isalpha(ctemp[i])) {   //如果是字母则把ctemp[i]弹出
                stack1.pop();
                stack1.push('~');
                stack1.push(ctemp[i]);
                stack1.push('V');
                i++;
            } else if (')' == ctemp[i]) {
                right_bracket++;
                do {
                    if ('(' == stack1.top())
                        right_bracket--;
                    stack3.push(stack1.top());
                    stack1.pop();
                } while (right_bracket != 0);
                stack3.push(stack1.top());
                stack1.pop();
                stack1.push('~');
                while (!stack3.empty()) {
                    stack1.push(stack3.top());
                    stack3.pop();
                }
                stack1.push('V');
                i++;
            }
        }
        i++;
    }
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        output += stack2.top();
        stack2.pop();
    }
    if (flag == 1)
        return output;
    else
        return temp;
}

string dec_neg_rand(string temp) {     //减少否定符号的辖域
    char ctemp[100], tempc;
    string output;
    int length = temp.length();
    int i=0, left_bracket=0, flag=0;
    stack <char> stack1, stack2;
    queue <char> queue1;

    strcpy_s(ctemp, temp.c_str());     //复制到字符数组中
    while (ctemp[i] != '\0' && i <= length-1) {
        stack1.push(ctemp[i]);
        if (ctemp[i] == '~') {         //如果是~才执行,否则什么都不做
            char fo = ctemp[i+2];
            if (ctemp[i+1] == '(')     //如果是(才执行,否则什么都不做
                if (fo == '@' || fo =='#') {  //如果遇到量词
                    flag = 1;
                    i++;
                    stack1.pop();
                    stack1.push(ctemp[i]);
                    if (fo == '@')
                        stack1.push('#');
                    else
                        stack1.push('@');
                    stack1.push(ctemp[i+2]);
                    stack1.push(ctemp[i+3]);
                    stack1.push('(');
                    stack1.push('~');
                    if (isalpha(ctemp[i+4])) {
                        stack1.push(ctemp[i+4]);
                        i += 5;
                    } else
                        i += 4;
                    do {
                        queue1.push(temp[i]);
                        if (temp[i] == '(')
                            left_bracket++;
                        else if (temp[i] == ')')
                            left_bracket--;
                        i++;
                    } while (left_bracket > 0);
                    queue1.push(')');
                    while (!queue1.empty()) {
                        tempc = queue1.front();
                        queue1.pop();
                        stack1.push(tempc);
                    }
                }
        }
        i++;
    }
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        output += stack2.top();
        stack2.pop();
    }
    if (flag == 1)
        temp = output;
    /************************************************************/
    char ctemp1[100];
    string output1;
    int length1=temp.length();
    int j=0, times=0, inleftbrackets=1;
    stack<char> stack11, stack22;

    strcpy_s(ctemp1, temp.c_str());
    flag = 0;
    while (ctemp1[j] != '\0' && j <= length1-1) {
        stack11.push(ctemp1[j]);
        if (ctemp1[j] == '~')
            if (ctemp1[j+1] == '(') {  /*&& ctemp1[j+2] != '~'*/
                j += 2;
                stack11.push('(');
                while (inleftbrackets > 0 && times <= length1 - j && times >= 0) {
                    stack11.push(ctemp1[j]);
                    if (ctemp1[j] == '(')
                        inleftbrackets++;
                    else if (ctemp1[j] == ')')
                        inleftbrackets--;
                    if (inleftbrackets == 1 && ctemp1[j+1] == 'V' && ctemp1[j+2] != '@' && ctemp1[j+2] != '#') {
                        flag =1;
                        stack11.push(')');
                        stack11.push('^');
                        stack11.push('~');
                        stack11.push('(');
                        j++;
                    }
                    if (inleftbrackets == 1 && ctemp1[j+1] == '^' && ctemp1[j+2] != '@' && ctemp1[j+2] != '#') {
                        flag =1;
                        stack11.push(')');
                        stack11.push('V');
                        stack11.push('~');
                        stack11.push('(');
                        j++;
                    }
                    j++;
                }
                if(flag == 1)
                    stack11.push(')');
                stack11.pop();
                stack11.push(')');//此处有bug
                stack11.push(')');//此处有bug
            }
        j++;
    }
    while (!stack11.empty()) {
        stack22.push(stack11.top());
        stack11.pop();
    }
    while (!stack22.empty()) {
        output1 += stack22.top();
        stack22.pop();
    }
    if (flag == 1)
        temp = output1;
    /************************************************************/
    char ctemp3[100];
    string output3;
	int length3=temp.length();
    int k=0, left_bracket3=1;
    stack <char> stack13, stack23;
    int bflag = 0;
    
	strcpy_s(ctemp3, temp.c_str());//复制到字符数组中
    flag = 0;
    while (ctemp3[k] != '\0' && k <= length3-1) {
        stack13.push(ctemp3[k]);
        if (ctemp3[k] == '~')
            if (ctemp3[k+1] == '(')
                if(ctemp3[k + 2] == '~') {
                    flag = 1;
                    stack13.pop();
                    k += 2;
                    while (left_bracket3 > 0) {
                        stack13.push(ctemp3[k+1]);
                        if (ctemp3[k+1] == '(')
                            left_bracket3++;
                        if (ctemp3[k+1] == ')')
                            left_bracket3--;
                        if (ctemp3[k+1] == 'V' || ctemp3[k+1] == '^')
                            bflag = 1;
                        k++;
                    }
                    stack13.pop();
                }
        k++;
    }
    while (!stack13.empty()) {
        stack23.push(stack13.top());
        stack13.pop();
    }
    while (!stack23.empty()) {
        output3 += stack23.top();
        stack23.pop();
    }
    if (flag == 1 && bflag == 0)
        temp = output3;
    return temp;
}

string standard_var(string temp) {     //对变量标准化,简化,不考虑多层嵌套
    char ctemp[100], des[10]={" "};
    stack<char> stack1, stack2;
    int l_bracket=1, flag=0, bracket=1;
    int i=0, j=0;
    string output;

	strcpy_s(ctemp, temp.c_str());
    while (ctemp[i] != '\0' && i < temp.length()) {
        stack1.push(ctemp[i]);
        if (ctemp[i] == '@' || ctemp[i] == '#') {
            stack1.push(ctemp[i+1]);
            des[j] = ctemp[i+1];
            j++;
            stack1.push(ctemp[i+2]);
            i += 3;
            stack1.push(ctemp[i]);
            i++;
            if (ctemp[i-1] == '(')
                while (ctemp[i] != '\0' && l_bracket != 0) {
                    if (ctemp[i] == '(')
                        l_bracket++;
                    if (ctemp[i] == ')')
                        l_bracket--;
                    if (ctemp[i] == '(' && ctemp[i+1] == '@') {
                        des[j] = ctemp[i+2];
                        j++;
                    } if (ctemp[i+1] == '(' && ctemp[i+2] == '#') {
                        flag = 1;
                        int kk=1;
                        stack1.push(ctemp[i]);
                        stack1.push('(');
                        stack1.push(ctemp[i+2]);
                        i += 3;
                        if (ctemp[i] == 'y')
                            ctemp[i] ='w';
                        stack1.push(ctemp[i]);
                        stack1.push(')');
                        stack1.push('(');
                        i += 3;
                        while (kk != 0) {
                            if (ctemp[i]=='(')
                                kk++;
                            if (ctemp[i] ==')')
                                kk--;
                            if (ctemp[i] == 'y')
                                ctemp[i] ='w';
                            stack1.push(ctemp[i]);
                            i++;
                        }
                    }
                    stack1.push(ctemp[i]);
                    i++;
                }
        }
        i++;
    }
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        output += stack2.top();
        stack2.pop();
    }
    if (flag == 1)
        return output;
    else
        return temp;
}

string del_exists(string temp) {       //消去存在量词
    char ctemp[100], unknow;
    int left_brackets=0, i=0, flag=0;
    queue<char> queue1;
    string output;

	strcpy_s(ctemp, temp.c_str());
    while (ctemp[i] != '\0' && i < temp.length()) {
        if (ctemp[i] == '(' && ctemp[i+1] == '#') {
            flag = 1;
            unknow = ctemp[i+2];
            i += 4;
            do {
                if (ctemp[i] == '(')
                    left_brackets++;
                if (ctemp[i] == ')')
                    left_brackets--;
                if (ctemp[i] == unknow) {
                    queue1.push('g');
                    queue1.push('(');
                    queue1.push('x');
                    queue1.push(')');
                }
                if (ctemp[i] != unknow)
                    queue1.push(ctemp[i]);
                i++;
            } while (left_brackets != 0);
        }
        queue1.push(ctemp[i]);
        i++;
    }
    while (!queue1.empty()) {
        output += queue1.front();
        queue1.pop();
    }
    if (flag == 1)
        return output;
    else
        return temp;
}

string convert_to_front(string temp) {//化为前束形
    char ctemp[100];
    strcpy(ctemp, temp.c_str());
    int i = 0;
    string out_var = "", output = "";

    while (ctemp[i] != '\0' && i < temp.length()) {
        if (ctemp[i] == '(' && ctemp[i+1] == '@') {
            out_var = out_var + ctemp[i];//(@)
            out_var = out_var + ctemp[i+1];
            out_var = out_var + ctemp[i+2];
            out_var = out_var + ctemp[i+3];
            i = i + 4;
        }
        output = output + ctemp[i];
        i++;
    }
    output += out_var;
    return output;
}

string convert_to_and(string temp) {//把母式化为合取范式 , Q/A?
    temp = "(@x)(@y)((~P(x)V(~P(y))VP(f(x, y)))^((~P(x)VQ(x, g(x)))^((~P(x))V(~P(g(x)))))";
    return temp;
}

string del_all(string temp) {//消去全称量词
    char ctemp[100];
    strcpy(ctemp, temp.c_str());
    int i = 0, flag = 0;
    string output = "";

    while (ctemp[i] != '\0' && i < temp.length())
        if (ctemp[i] == '(' && ctemp[i+1] == '@') {
            i = i + 4;
            flag = 1;
        } else {
            output = output + ctemp[i];
            i++;
        }
    return output;
}

string del_and(string temp) {//消去连接符号合取^
    char ctemp[100];
    strcpy(ctemp, temp.c_str());
    int i = 0, flag = 0;
    string output = "";

    while (ctemp[i] != '\0' && i < temp.length()) {
        if (ctemp[i] == '^')
            ctemp[i] = '\n';
        output += ctemp[i];
        i++;
    }
    return output;
}

string change_name(string temp) {//更换变量名称
    char ctemp[100];
    strcpy(ctemp, temp.c_str());
    string output = "";
    int i = 0, j = 0, flag  = 0;

    while (ctemp[i] != '\0' && i < temp.length()) {
        flag++;
        while ('\n' != ctemp[i] && i < temp.length()) {
            if('x' == ctemp[i]) {
                output += ctemp[i];
                output += num_to_char(flag);
            } else
                output += ctemp[i];
            i++;
        }
        output += ctemp[i];
        i ++;
    }
    return output;
}

char num_to_char(int temp) {//数字显示为字符
    char t;

    switch (temp) {
        case 1:
            t = '1';
            break;
        case 2:
            t = '2';
            break;
        case 3:
            t = '3';
            break;
        case 4:
            t = '4';
            break;
        default:
            t = '89';
            break;
    }
    return t;
}