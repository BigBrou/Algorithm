#include <iostream>
#include <vector>

using namespace std;

// 1 <= N <= 1000 참가인원수
// 1 <= K <= 1000 한방 배정

// S 0, 1 여, 남 
// 1 - 6 학년

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N;
    cin >> K;

    vector<int> g_grade(7, 0);
    vector<int> m_grade(7, 0);
    for (int i = 0; i < N; i++) {
        int sex, grade;
        cin >> sex >> grade;

        if (sex == 0)
            g_grade[grade] += 1;
        else
            m_grade[grade] += 1;
    }

    int room_cnt = 0;
    for (int i = 1; i < g_grade.size(); i++) {
        int g_room = (g_grade[i] + K - 1) / K;
        int m_room = (m_grade[i] + K - 1) / K;

        room_cnt += (g_room + m_room);
    }

    cout << room_cnt;
}