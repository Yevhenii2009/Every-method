#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // -------- vector --------
    vector<int> v;
    int n;

    cout << "Enter integers (0 to stop): ";
    while (cin >> n && n != 0) {
        v.push_back(n);
        cout << "size=" << v.size()
            << " capacity=" << v.capacity() << "\n";
    }
    
    cout << "\nVector contents: ";
    auto vit_print = v.begin();
    while (vit_print != v.end()) {
        cout << *vit_print << " ";
        ++vit_print;
    }
    cout << "\n\n";

    // -------- find --------
    cout << "Enter value to find: ";
    cin >> n;

    auto it = find(v.begin(), v.end(), n);
    if (it != v.end())
        cout << "Found value: " << *it << "\n\n";
    else
        cout << "Value not found\n\n";

    // -------- erase from vector --------
    cout << "Removing even numbers from vector...\n";
    auto vit = v.begin();
    while (vit != v.end()) {
        if (*vit % 2 == 0)
            vit = v.erase(vit);
        else
            ++vit;
    }
  
    cout << "Vector after erase: ";
    vit_print = v.begin();
    while (vit_print != v.end()) {
        cout << *vit_print << " ";
        ++vit_print;
    }
    cout << "\n\n";
    
    // -------- list --------
    list<int> lst(v.begin(), v.end());
    cout << "Copied to list: ";

    auto lit_print = lst.begin();
    while (lit_print != lst.end()) {
        cout << *lit_print << " ";
        ++lit_print;
    }
    cout << "\n\n";

    cout << "Removing odd numbers from list...\n";
    auto lit = lst.begin();
    while (lit != lst.end()) {
        if (*lit % 2 != 0)
            lit = lst.erase(lit);
        else
            ++lit;
    }

    lit_print = lst.begin();
    while (lit_print != lst.end()) {
        cout << *lit_print << " ";
        ++lit_print;
    }
    cout << "\n\n";

    // -------- deque --------
    deque<int> dq;
    auto vit_dq = v.begin();
    while (vit_dq != v.end()) {
        dq.push_back(*vit_dq);
        dq.push_front(*vit_dq);
        ++vit_dq;
    }

    cout << "Deque contents: ";
    auto dqit = dq.begin();
    while (dqit != dq.end()) {
        cout << *dqit << " ";
        ++dqit;
    }
    cout << "\n\n";
    // -------- forward_list --------
    forward_list<int> fl = { 1, 2, 3, 4, 5, 6 };

    cout << "Forward_list before: ";
    auto fl_print = fl.begin();
    while (fl_print != fl.end()) {
        cout << *fl_print << " ";
        ++fl_print;
    }
    cout << "\n";
    auto prev = fl.before_begin();
    auto curr = fl.begin();

    while (curr != fl.end()) {
        if (*curr % 2 != 0)
            curr = fl.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }

    cout << "Forward_list after erase: ";
    fl_print = fl.begin();
    while (fl_print != fl.end()) {
        cout << *fl_print << " ";
        ++fl_print;
    }
    cout << "\n\n";

    // -------- string --------
    string text = "hello world";
    cout << "String before: " << text << "\n";

    auto pos = text.find("world");
    if (pos != string::npos)
        text.replace(pos, 5, "STL");

    cout << "String after: " << text << "\n\n";

    return 0;
}
 