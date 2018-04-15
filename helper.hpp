#import <iostream>
#import <string>
#import <vector>

template<class K, typename V>
struct TestFuncType {
    using type = std::function<V(K)>;
};

template<class K, typename V>
struct DebugFuncType {
    using type = std::function<void(K input, V target, V result)>;
};

template<typename K, typename V>
void runUnitTest(string title, vector <pair<K, V>> tests, const typename TestFuncType<K, V>::type &func,
                 const typename DebugFuncType<K, V>::type &debugFunc = nullptr) {
    cout << title << " : " << endl;
    for (int i = 0; i < tests.size(); ++i) {
        auto item = tests[i];
        K key = item.first;
        V value = item.second;
        V result = func(key);

        bool passed = result == value;
        string sign = passed ? "✅" : "❌";

        cout << "\t";
        cout << sign;
        if (!passed) {
            cout << " (case " << i << " failed)";
            if (debugFunc) {
                debugFunc(key, value, result);
            }
        } else {
            cout << " (case " << i << " passed)";
        }
        cout << endl;
    }
}
