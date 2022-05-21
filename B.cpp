#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<algorithm>

std::tuple<std::string, std::vector<std::pair<int,int>>> Read() {
    std::string init_string;
    std::cin >> init_string;
    int num_queries;
    std::cin >> num_queries;

    std::vector<std::pair<int,int>> queries(num_queries);
    for (auto &query : queries) {
        std::cin >> query.first >> query.second;
        query.first--;
        query.second--;
    }
    return {init_string, queries};
}

void Solve(const  std::tuple<std::string, std::vector<std::pair<int,int>>>& complex) {
    std::string init_string = std::get<0>(complex);
    std::vector<std::pair<int,int>> queries = std::get<1>(complex);

    // store left points
    // first >= (at left)
    // first > (at right)
    // write index difference

    std::vector < int > left_points;
    for (size_t i = 0; i < init_string.size(); ) {
        left_points.push_back(i);
        int curr_letter = init_string[i];
        int nxt_ind = i + 1;
        while (nxt_ind < init_string.size() && init_string[nxt_ind - 1] <= init_string[nxt_ind]) {
            nxt_ind++;
        }
        i = nxt_ind;
    }

    //abcaabbaccccb -> 0 3 7 12
    //0123456789012 -> 1 7

    for (const auto &query : queries) {
        int left_ind = std::prev(std::upper_bound(left_points.begin(), left_points.end(),query.first)) - left_points.begin();
        int right_ind = std::upper_bound(left_points.begin(), left_points.end(), query.second) - left_points.begin();
        std::cout << right_ind - left_ind << "\n";
    }
}

void Run() {
    auto complex = Read();
    Solve(complex);
}