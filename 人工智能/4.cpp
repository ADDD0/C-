#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<conio.h>
#include<time.h>

using namespace std;

#define PLAYER 0
#define COMPUTER 1

const char CHESS[3] = {'-', '@', '#'};

class Board {
    public:
        int a[3][3];

        void init() {
            memset(a, 0, sizeof(a));
        }

        void operator = (Board b) {
            for(int i=0; i < 3; ++i)
                for(int j=0; j < 3; ++j)
                    a[i][j] = b.a[i][j];
        }
};

int getInput(string s, int maxNum) {
    int t;
    char c;

    while(1) {
        cout << s;
        c = getch();
        t = c - '0';
        if (t >= 0 && t < maxNum)
            break;
        else
            cout << "输入错误,请重新输入!" << endl;
    }
    cout << endl;
    return t;
}

void outBoard(Board bod) {
    cout << "   ";
    for(int i=0; i < 3; ++i)
        printf("%2d", i);
    cout << endl << "   ======" << endl;
    for(int i=0; i < 3; ++i) {
        printf("%2d|",i);
        for(int j=0; j < 3; ++j)
            printf("%2c", CHESS[bod.a[i][j]]);
        cout << endl;
    }
}

void playerMove(Board &bod) {
    int x,y;
    outBoard(bod);
    while(true) {
        cout << "该你了,请输入你要下的横纵坐标(用空格隔开的两个数):";
        cin >> x >> y;
        if(!(x >= 0 && x <= 2 && y >= 0 && y <= 2)) {
            cout << "输入错误!请重新输入!横纵坐标都要是0或1或2" << endl;
            continue;
        }
        if(bod.a[x][y] != 0) {
            cout << "下错了,这个位置有棋!请选择其他位置" << endl;
            continue;
        }
        break;
    }
    bod.a[x][y] = 1;
    cout << "你下到了(" << x << "," << y << ")位置" << endl;
}

int evaluate(const Board &bod) {
    int cnt[3];
    int re=0;

    for (int i=0; i < 3; ++i) {
        memset(cnt, 0, sizeof(cnt));
        for (int j=0; j < 3; ++j)
            cnt[bod.a[i][j]]++;
        if (cnt[1] == 3)
            return 1000;
        if (cnt[2] == 3)
            return -1000;
        if (cnt[1] == 2 && cnt[0] == 1)
            re += 50;
        else if (cnt[1] == 1 && cnt[0] == 2)
            re += 10;
        if (cnt[2] == 2 && cnt[0] == 1)
            re -= 50;
        else if (cnt[2] == 1 && cnt[0] == 2)
            re -= 10;

        memset(cnt, 0, sizeof(cnt));
        for (int j=0; j < 3; ++j)
            cnt[bod.a[j][i]]++;
        if (cnt[1] == 3)
            return 1000;
        if (cnt[2] == 3)
            return -1000;
        if (cnt[1] == 2 && cnt[0] == 1)
            re += 50;
        else if (cnt[1] == 1 && cnt[0] == 2)
            re += 10;
        if (cnt[2] == 2 && cnt[0] == 1)
            re -= 50;
        else if (cnt[2] == 1 && cnt[0] == 2)
            re -= 10;
    }

    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i < 3; ++i)
        cnt[bod.a[i][i]]++;
    if (cnt[1] == 3)
        return 1000;
    if (cnt[2] == 3)
        return -1000;
    if (cnt[1] == 2 && cnt[0] == 1)
        re += 50;
    else if (cnt[1] == 1 && cnt[0] == 2)
        re += 10;
    if (cnt[2] == 2 && cnt[0] == 1)
        re -= 50;
    else if (cnt[2] == 1 && cnt[0] == 2)
        re -= 10;

    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i < 3; ++i)
        cnt[bod.a[i][2-i]]++;
    if (cnt[1] == 3)
        return 1000;
    if (cnt[2] == 3)
        return -1000;
    if (cnt[1] == 2 && cnt[0] == 1)
        re += 50;
    else if (cnt[1] == 1 && cnt[0] == 2)
        re += 10;
    if (cnt[2] == 2 && cnt[0] == 1)
        re -= 50;
    else if (cnt[2] == 1 && cnt[0] == 2)
        re -= 10;
    return re;
}

Board boa;

int dfs(const int &depth, const int &nowWho) {
    int t, ma=-100000, mi=100000, ok=0;
    int eva=evaluate(boa);

    if (depth == 0 || eva >= 1000 || eva <= -1000)
        return eva;

    for (int i=0; i < 3; ++i)
        for (int j=0; j < 3; ++j) {
            if (boa.a[i][j] != 0)
                continue;
            ok = 1;
            boa.a[i][j] = nowWho + 1;
            t = dfs(depth - 1, nowWho ^ 1);
            boa.a[i][j] = 0;
            ma = max(t, ma);
            mi = min(t, mi);
        }
    if (!ok)
        return eva;
    if (nowWho == 0)
        return ma;
    if (nowWho == 1)
        return mi;
}

void comake_pairuterMove(Board &bod) {
    int x,y,i,j;

    boa = bod;
    cout << "电脑:我的回合" << endl;
    vector<pair<int , pair<int, int> > > v;
    v.clear();
    for (int i=0; i < 3; ++i)
        for (int j=0; j < 3; ++j) {
            if(boa.a[i][j] != 0)
                continue;
            boa.a[i][j] = 2;
            v.push_back(make_pair(dfs(9, 0), make_pair(i, j)));
            boa.a[i][j] = 0;
    }
    sort(v.begin(), v.end());
    j = 1;
    while (j < v.size() && v[j].first == v[0].first)
        j++;
    if (j > 1)
        cout << "电脑:我有" << j << "种不同的效果差不多的棋可以走" << endl;
    else
        cout << "电脑:这步棋效果最佳" << endl;
    if (v.size() > j && v[j].first == 1000)
        cout << "电脑:要是我走除此之外的棋我就输了" << endl;
    if (v[0].first == -1000)
        cout << "电脑:你输定了" << endl;
    j = rand() % j;
    x = v[j].second.first;
    y = v[j].second.second;
    bod.a[x][y] = 2;
    cout << "电脑:经过我的精确思考,我下到了(" << x << "," << y << ")位置" << endl;
}

int result(Board bod) {
    int k=0;
    int t=evaluate(bod);

    if (t == 1000)
        return 1;
    if (t == -1000)
        return 2;
    for (int i=0; i < 3; ++i)
        for (int j=0; j < 3; ++j)
            if(bod.a[i][j] != 0)
                k++;
    if (k == 9)
        return 3;
    return 0;
}

void gameStart() {
    int playerFirst, nowMove, whoWin, continuegameStart=1;
    Board now;
    int t;
    int step;

    srand(time(NULL));
    while (continuegameStart) {
        system("cls");
        cout << "欢迎来到[人工智能博弈树井字棋游戏]!" << endl;
        playerFirst = getInput("请选择玩家先后手(0先手,1后手):", 2);
        now.init();
        cout << "(棋盘说明:" << CHESS[0] << "是空位," << CHESS[1] << "是你的棋子,";
        cout << CHESS[2] << "是电脑的棋子,上面是横坐标,左边是纵坐标)" << endl << endl;
        nowMove = playerFirst;
        whoWin = 0;
        step = 0;
        while (!whoWin) {
            cout << "[第" << ++step << "手]" << endl;
            if (nowMove == PLAYER)
                playerMove(now);
            else
                comake_pairuterMove(now);
            whoWin = result(now);
            if (whoWin != 0) {
                outBoard(now);
                if (whoWin == 1)
                    cout << "电脑:你获胜了" << endl;
                if (whoWin == 2)
                    cout << "电脑:你失败了" << endl;
                if (whoWin == 3)
                    cout << "电脑:平局" << endl;
            }
            nowMove = 1 - nowMove;
        }
        continuegameStart = getInput("是否继续游戏?(0结束游戏,1重新开始):", 2);
    }
}

int main() {
    gameStart();
    return 0;
}