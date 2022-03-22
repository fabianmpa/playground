#include <boost/program_options.hpp>
#include <boost/any.hpp>
#include <boost/array.hpp>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

namespace opt = boost::program_options;
using namespace std;
typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val) {
    // C++11 lambda function
    const auto inc = [](char& c){ ++c; };

    // boost::array has begin(), cbegin(), end(), cend(),
    // rbegin(), size(), empty() and other functions that are
    // common for standard library containers.
    std::for_each(val.begin(), val.end(), inc);
    return val;
}

int main(int argc, char *argv[])
{
  /*
    // Constructing an options describing variable and giving
    // it a textual description "All options".
    opt::options_description desc("All options");
    // When we are adding options, first parameter is a name
    // to be used in command line. Second parameter is a type
    // of that option, wrapped in value<> class. Third parameter
    // must be a short description of that option.
    desc.add_options()
        ("apples", opt::value<int>()-> default_value(10), "how many apples do you have")
        ("oranges", opt::value<int>()-> default_value(20), "how many oranges do you have")
        ("help", "produce help message");
        // Variable to store our command line arguments.
    opt::variables_map vm;
    // Parsing and storing arguments.
    opt::store(opt::parse_command_line(argc, argv, desc), vm);
    // Must be called after all the parsing and storing.
    opt::notify(vm);
        if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }
        std::cout << "Fruits count: "
        << vm["apples"].as<int>() + vm["oranges"].as<int>()
        << std::endl;
  */

/*
std::vector<boost::any> some_values;
some_values.push_back(10);
some_values.push_back("HelloThere");
some_values.push_back(std::string("Wow"));

string& s   = boost::any_cast<string&>(some_values.back());
int&    sum = boost::any_cast<int&>(some_values.front());

s += " That is great!";
sum += 20;
cout << s   << endl;
cout << sum << endl;
*/

    // We can initialize boost::array just like an array in C++11:
    // array4_t val = {0, 1, 2, 3};
    // but in C++03 additional pair of curly brackets is required.
    array4_t val = {'a', 'b', 'c', 'd'};

    array4_t val_res;               // it is default constructible
    val_res = vector_advance(val);  // it is assignable

    assert(val.size() == 4);
    assert(val[0] == 'b');
    assert(val_res.size() == 4);
    assert(val_res[0] == 'b');
    /*val[4];*/ // Will trigger an assert because max index is 3
    cout << val[0] << endl;
    cout << val_res.front() << endl;
    // We can make this assert work at compile-time.
    // Interested? See recipe 'Check sizes at compile-time'
    assert(sizeof(val) == sizeof(char) * array4_t::static_size);
}