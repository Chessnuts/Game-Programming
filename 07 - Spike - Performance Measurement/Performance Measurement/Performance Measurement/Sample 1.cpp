#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;


// - count char using slow repeated string::find_first_of
int count_char_using_find_first_of(string s, char delim)
{
    int count = 0;
    // note: string::size_type pos = s.find_first_of(delim);
    auto pos = s.find_first_of(delim);
    while ((pos = s.find_first_of(delim, pos)) != string::npos)
    {
        count++;
        pos++;
    }
    return count;
}

// - count char using fast std::count
int count_char_using_count(string s, char delim)
{
    return count(s.begin(), s.end(), delim);
}


void exponential_rampup_test()
{
    cout << " << Exponential Ramp-up Test >> " << endl;
    int total;
    // ull (suffix) == "unsigned long long" in c
    for (auto size = 1ull; size < 100000000ull; size *= 10)
    {
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / size << "s/int" << endl;

        // TIP: time in nanoseconds? Cast result of chrono::duration.count() ...
        // auto _dur = duration_cast<nanoseconds>( end - start ).count();
        // cout << _dur << endl;
    }
    cout << "done." << endl;
}

void linear_rampup_test()
{
    cout << " << Linear Ramp-up Test >> " << endl;
    int total;
    for (auto size = 1; size <= 8; size += 1)
    {
        int vec_size = size * 10000;
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(vec_size, 42);
        // std::accumulate (from <numeric>) collects from begin, to end
        // - in this case (default) it is the sum total of all the values in v
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << vec_size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / vec_size << "s/int" << endl;
    }
    cout << "done." << endl;
}

void exponential_rampdown_test()
{
    cout << " << Exponential Ramp-down Test >> " << endl;
    int total;
    // ull (suffix) == "unsigned long long" in c
    for (auto size = 10000000ull; size >= 1ull; size /= 10)
    {
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(size, 42);
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / size << "s/int" << endl;

        // TIP: time in nanoseconds? Cast result of chrono::duration.count() ...
        // auto _dur = duration_cast<nanoseconds>( end - start ).count();
        // cout << _dur << endl;
    }
    cout << "done." << endl;
}

void linear_rampdown_test()
{
    cout << " << Linear Ramp-down Test >> " << endl;
    int total;
    for (auto size = 8; size >= 1; size -= 1)
    {
        int vec_size = size * 10000;
        // 1. get start time
        auto start = steady_clock::now();
        // 2. do some work (create, fill, find sum)
        vector<int> v(vec_size, 42);
        // std::accumulate (from <numeric>) collects from begin, to end
        // - in this case (default) it is the sum total of all the values in v
        total = accumulate(v.begin(), v.end(), 0u);
        // 3. show duration time
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << " - size: " << vec_size << ", time: " << diff.count() << " s";
        cout << ", time/int: " << diff.count() / vec_size << "s/int" << endl;
    }
    cout << "done." << endl;
}

int main()
{
    for (auto size = 3; size >= 1; size -= 1)
    {
        // Simple wrapper around a linaer set of time tests
        linear_rampup_test();

        // Simple wrapper around an exponential set of time tests
        exponential_rampup_test();

        linear_rampdown_test();

        exponential_rampdown_test();
    }
    // Compare the two different methods of counting in a string
    // - show result in nanoseconds?
    string s1 = "This is a really simple string but it will do for testing.";
    string s2 = "This is a really simple string but it will do for testing. This is a really simple string but it will do for testing.";
    string s3 = "This is a really simple string but it will do for testing. This is a really simple string but it will do for testing. This is a really simple string but it will do for testing. This is a really simple string but it will do for testing.";
    int result;
    //auto start = steady_clock::now();
    //auto end = steady_clock::now();
    //duration<double> diff = end - start;
    for (auto size = 10; size >= 1; size -= 1)
    {
        cout << "dataset first of" << endl;
        auto start = steady_clock::now();
        result = count_char_using_find_first_of(s1, 's');
        cout << s1.size() << " result: " << result << endl;
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;

        start = steady_clock::now();
        result = count_char_using_find_first_of(s2, 's');
        cout << s2.size() << " result: " << result << endl;
        end = steady_clock::now();
        diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;

        start = steady_clock::now();
        result = count_char_using_find_first_of(s3, 's');
        cout << s3.size() << " result: " << result << endl;
        end = steady_clock::now();
        diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;
    }

    for (auto size = 10; size >= 1; size -= 1)
    {
        cout << "dataset count" << endl;
        auto start = steady_clock::now();
        result = count_char_using_count(s1, 's');
        cout << s1.size() << " result: " << result << endl;
        auto end = steady_clock::now();
        duration<double> diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;

        start = steady_clock::now();
        result = count_char_using_count(s2, 's');
        cout << s2.size() << " result: " << result << endl;
        end = steady_clock::now();
        diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;

        start = steady_clock::now();
        result = count_char_using_count(s3, 's');
        cout << s3.size() << " result: " << result << endl;
        end = steady_clock::now();
        diff = end - start;
        cout << "time: " << diff.count() << " s" << endl;

    }

    return 0;
}

