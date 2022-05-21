#include<iostream>
#include<vector>

std::vector < int > Read() {
    int len;
    std::cin >> len;
    std::vector < int > vec(len);
    for (auto &el : vec) {
        std::cin >> el;
    }
    return vec;
}

void Solve(const std::vector<int> &vec) {
    long long score = 0;
    int shift = 0;
    for (int ind = (int)vec.size() - 1; ind >= 0;) {
        int curr_pos = vec[ind] - shift;
        if (curr_pos <= 0) {
            break;
        }

        int num = 0;
        while (ind - num >= 0 && vec[ind] == vec[ind - num]) {
            num++;
        }

        score += (long long)curr_pos * num;
        shift += num;

        ind -= num;
    }

    std::cout << score << "\n";
}

void Run() {
    std::vector < int > vec = Read();
    Solve(vec);
}