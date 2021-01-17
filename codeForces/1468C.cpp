#include <bits/stdc++.h>

using namespace std;

struct Customer {
    int sequence;
    int weight;
    int valid;
};

struct cmp {
    bool operator()(const Customer *a, const Customer *b) {
        if (a->weight != b->weight)
            return a->weight < b->weight;
        else
            return a->sequence > b->sequence;
    }
};

// the main idea is clear. It just a simulation.
// The point of this question is speed. If just using vector, it will iterate each time, which is too slow.
// Therefore, for weight(money), using priority_queue to speed up is a good idea.
// To synchronizing 'sequence queue' and 'weight priority_queue', use pointers both of them.
int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<Customer *> order;
    priority_queue<Customer *, vector<Customer *>, cmp> weight;
    Customer *top = nullptr, *customer = nullptr;

    int q = 0, code, money, seq = 1;
    cin >> q;

    while (q--) {
        cin >> code;
        if (code == 1) {
            customer = new Customer;
        }

        switch (code) {
            case 1:
                cin >> money;
                customer->sequence = seq++;
                customer->weight = money;
                customer->valid = true;
                order.push(customer);
                weight.push(customer);
                break;

            case 2:
                while (!order.front()->valid) {
                    order.pop();
                }
                cout << order.front()->sequence << " ";
                order.front()->valid = false;
                order.pop();
                break;

            case 3:
                while (!weight.top()->valid) {
                    weight.pop();
                }
                top = weight.top();
                cout << top->sequence << " ";
                weight.pop();
                top->valid = false;
                break;
        }
    }

    return 0;
}