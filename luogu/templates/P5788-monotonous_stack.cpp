#include <iostream>
#include <stack>
#include <vector>

// 栈底到栈顶依次减小
// 从右向左扫描
/*
 */
class MonotonousStack {
public:
    std::vector<int> solution(std::vector<int> arr) {
        std::stack<int> s;
        std::vector<int> res(arr.size());
        for (int i = arr.size() - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] < arr[i]) s.pop();
            res[i] = s.empty() ? 0 : s.top();
            s.push(i);
        }
        return res;
    }
};

int main(int argc, char** argv) {
    std::vector<int> arr = {1, 4, 2, 3, 5};
    MonotonousStack s;
    auto res = s.solution(arr);
    for (auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}