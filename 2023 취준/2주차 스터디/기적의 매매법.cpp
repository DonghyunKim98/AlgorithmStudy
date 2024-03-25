#include <bits/stdc++.h>

#define endl '\n'
#define MAX_DAYS 14

using namespace std;

int BNP_budget, TIMING_budget;
int BNP_stocks = 0, TIMING_stocks = 0;
int stock_price[MAX_DAYS];

void calculateBNP()
{
    for (int i = 0; i < MAX_DAYS; i++)
    {
        if (BNP_budget / stock_price[i])
        {
            BNP_stocks += BNP_budget / stock_price[i];
            BNP_budget %= stock_price[i];
        }
    }

    // 최종 자산
    BNP_budget += BNP_stocks * stock_price[MAX_DAYS - 1];
}

void calculateTiming()
{
    int increase_cnt = 0, decrease_cnt = 0;

    for (int i = 1; i < MAX_DAYS; i++)
    {
        if (stock_price[i] > stock_price[i - 1])
        {
            increase_cnt++;
            decrease_cnt = 0;
            // 전량 매도
            if (increase_cnt == 3 && TIMING_stocks > 0)
            {
                TIMING_budget = TIMING_stocks * stock_price[i];
                TIMING_stocks = 0;
                increase_cnt = 0;
            }
        }
        else if (stock_price[i] < stock_price[i - 1])
        {
            increase_cnt = 0;
            decrease_cnt++;
            // 전량 매수
            if (decrease_cnt == 3 && TIMING_budget / stock_price[i])
            {
                TIMING_stocks += TIMING_budget / stock_price[i];
                TIMING_budget %= stock_price[i];
                decrease_cnt = 0;
            }
        }
    }

    // 최종 자산
    TIMING_budget += TIMING_stocks * stock_price[MAX_DAYS - 1];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> BNP_budget;
    TIMING_budget = BNP_budget;

    for (int i = 0; i < MAX_DAYS; i++)
    {
        cin >> stock_price[i];
    }

    calculateBNP();
    calculateTiming();

    // cout << BNP_budget << ' ' << TIMING_budget << endl;

    if (BNP_budget > TIMING_budget)
    {
        cout << "BNP";
    }
    else if (BNP_budget < TIMING_budget)
    {
        cout << "TIMING";
    }
    else
    {
        cout << "SAMESAME";
    }

    return 0;
}

/*
    Tip 1 : 배열의 마지막 원소에 대해서 -1 여부 잘 체크하기
    Tip 2 : 연산의 순서에 대해서 잘 생각하기
*/