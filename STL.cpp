#include<bits/stdc++.h>
using namespace std;

void learnPair() {
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << "\n";

    pair<int, pair <int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << "\n";

    pair <int, int> p3[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << p3[1].first; 
}

void learnVector() {
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);
    //Both does the same thing but emplace is faster than push back =

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(1, 2);
    // Does the same thing

    vector<int> v(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v(5); // {0, 0, 0, 0, 0}
    vector<int> v1(v);

    vector<int>::iterator it = v.begin(); //adress

    it++; //next memory location
    cout << *(it) << " " << "\n"; // prints the value
    vector<int>::iterator it = v.end(); //pointing to next location to end
    cout << v[0] << " " << v.at(0) << "\n";
    cout << v.back() << " "; //pointing to last location of the vector

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto value : v) {
        cout << value << " ";
    }

    // {10, 20, 30, 40}
    v.erase(v.begin() + 1); // {10, 30, 40}

    //{10, 20, 30, 40, 50}
    v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 50}

    vector<int> v(2, 100); // {100, 100}
    v.insert(v.begin(), 300); // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);
    v.insert(v.begin(), copy.begin(), copy.end());

    cout << v.size(); // size of the vector

    v.pop_back(); //delete last element
    v.clear(); // trims all the element in a vector
    v.empty(); //returns true if its empty
}

void learnList() {
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(5);

    ls.push_front(5);
    ls.emplace_front(2);

    //rest all the function  are same as vector
    //insertion takes more time in vector, it is faster in  List
    //internally it is implemented as doubly linked list
}

void learnDeque() {
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(4);
    dq.emplace_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();
    //rest all the function are same as Vector
}

void learnStack() {
    //LIFO Last in first out
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // 5
    st.pop(); // {3, 3, 2, 1}
    cout << st.size(); //4
    cout << st.empty();
    // All the operation are TC o(n) 
}

void learnQueue() {
    //FIFO First in first out
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(3); // {1, 2, 3}

    q.back() += 5;
    cout << q.back(); // prints 9
    cout << q.front(); // prins 1

    q.pop(); // {2, 9}

    cout << q.front(); // print 2
    // Rest all the function works same as queue
}

void learnPQ() {
    //Priority queue store max element at the top, this is max heap
    priority_queue<int> pq;
    pq.push(5); //{5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // print 10
    pq.pop(); // {8. 5, 2}
    cout << pq.top(); // prints 8

    //Minimum heap, saves in reverse order min up
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // prints 2
}

void learnSet() {
    //Set stores elements unique and sorted order
    set<int> st;
    st.insert(1); // {1}
    st.insert(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    auto it = st.find(2); // returns iterator of the element if found else return st.end()
    st.erase(3); // erase 3 in log n time
    int count = st.count(1);

    auto it = st.find(3);
    st.erase(it);

    auto it1 = st.find(2);
    auto it2 = st.find(6);
    st.erase(it1, it2);
    //rest function are same as a vector 
}

void learnMultiSet() {
    //MultiSet stores elements in sorted but not unique
    multiset<int> ms;
    ms.insert(1); //{1}
    ms.insert(1); // {1, 1}
    ms.insert(2); // {1, 1, 2}

    ms.erase(1); // erases all the occurances of 1
    //if we want to delete one occurance 
    ms.erase(ms.find(1)); // provide the address of that element
    ms.erase(ms.find(1), ms.find(1) + 4); // erase the range
}

void learnUSet() {
    unordered_set<int> st;
    // unique but not sorted
    // All the operations are same as set but works in o(1) tc
    // upper_bound and lower_bound does not work on this
}

void learnMap() {
    //key -> value pair
    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace({3, 1});
    mpp.insert({2, 1});
    mpp[{2, 1}] = 10;
    // map stores unique key in sorted order of key

    for (auto it: mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5]; // if not exist key return 0

    auto it = mpp.find(2); //finds the key and returns the address
    cout << *(it).second;

    auto it = mpp.upper_bound(2);
    auto it = mpp.lower_bound(21);

    // rest all the function are same
}

void learnMultiMap() {
    // everythings is same as map except stores duplicate keys
    // mpp[key] does not work here
}

void learnUnorderedMap() {
    //not store in sorted but unique
    // all cases works in constant time
}

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    if (p1.first > p2.first) return true;
    return false;
}

void leanrAlgos() {
    int a[] = {1, 2, 3};
    sort(a, a+a.size()); //sort it in ascending order
    sort(a, a+a.size(), greater<int>) // sort in decending order

    // sort in my way
    pair<int, int> a[] = {{1, 2,}, {2, 1}, {4, 3}};
    //sort according to second element
    //if second element is same then sort by first element in decending

    sort(a, a+n, comp);

    string s = "321";
    sort(s.begin(), s.end());
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    //all the permusion iteration

    int maxi = *max_element(a, a.size());
}

int main() {
    learnPair();
}