// pastNowAndFuture.cpp
#include <iostream>
#include <cstdio>

using namespace std;

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
// days[i-1] = i 月份的天數 

// 判斷是否為閏年
bool is29(int y) {
    return (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
}

// 判斷日期是否有效，1=合法, 0=不合法
int isDateValid(int y, int m, int d) {
    if (m < 1 || m > 12) return 0;
    int days_max = days[m - 1];
    if (is29(y) && m == 2) ++days_max;
    if (d > 0 && d <= days_max) return 1;
    return 0;
}

// 返回一年中之第幾日（0-based: Jan/01 -> 0）
int date_year(int y, int m, int d) {
    int sum = d - 1;                 // 先算當月前幾天
    for (int i = 1; i < m; ++i)      // 再加上之前所有整月
        sum += days[i - 1];
    if (m > 2 && is29(y)) ++sum;     // 閏年且超過 2 月，多一天
    return sum;                      // 範圍 0..(365/366-1)
}

// 將 0-based day-of-year 印成日期
void show_data(int y, int d) {
    int days_print[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is29(y)) days_print[1] = 29;

    int maxday = is29(y) ? 366 : 365;
    if (d < 0 || d >= maxday) {           // 注意這裡用 >=
        printf("Invalid date!\n");
        return;
    }

    int temp = d, temp_m = 0, i = 0;
    while (i < 12 && temp >= days_print[i]) {
        temp -= days_print[i];
        ++temp_m;
        ++i;
    }
    printf("%04d-%02d-%02d\n", y, temp_m + 1, temp + 1);
}

int main() {
    int year, month, day, move;

    while (scanf_s("%d-%d-%d %d", &year, &month, &day, &move) != EOF) {
        if (!isDateValid(year, month, day)) {
            cout << "Invalid date!\n";
            continue;
        }

        int d = date_year(year, month, day);  // 0-based 該年第幾天

        if (move >= 0) {
            // 正向移動
            while (move > 0) {
                int dd = is29(year) ? 366 : 365;
                int rem = dd - 1 - d;         // 本年還能往後走幾天（包含年底）

                if (move <= rem) {
                    d += move;
                    move = 0;
                }
                else {
                    move -= (rem + 1);       // 走到年底再往下一年一天
                    ++year;
                    d = 0;                   // 下一年從 0 開始
                }
            }
        }
        else {
            // 反向移動
            while (move < 0) {
                if (-move <= d) {
                    // 這一年之內就能往前移完
                    d += move;              // move 是負的
                    move = 0;
                }
                else {
                    // 先走回本年 1/1，再往前一年
                    move += (d + 1);        // 把今年剩下 (d+1) 天走完
                    --year;
                    int dd = is29(year) ? 366 : 365;
                    d = dd - 1;             // 前一年最後一天 (0-based)
                }
            }
        }

        show_data(year, d);  // 印出 year 年第 d 天
    }

    return 0;
}

