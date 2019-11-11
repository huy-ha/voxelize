#include <gtest/gtest.h>
#include <Voxelize.hpp>
#include <vector>
#include <tuple>
#include <string>
#include <functional>

using namespace std;
struct Foo
{
    int bar1;
    int bar2;
    int bar3;
};

TEST(BasicTest, Constructor)
{
    // vector<tuple<string, function<float(Foo)>>> fitnessMaps;
    // fitnessMaps.push_back(make_tuple("Bar1", [](const Foo &f) {
    //     return f.bar1;
    // }));
    // fitnessMaps.push_back(make_tuple("Bar2", [](const Foo &f) {
    //     return f.bar2;
    // }));
    // fitnessMaps.push_back(make_tuple("Bar3", [](const Foo &f) {
    //     return f.bar3;
    // }));
    // vector<Foo> foos;

    // Pareto<Foo> pareto(fitnessMaps);
    // int val = pareto.FindFront(foos);
    int val = 0;
    ASSERT_EQ(val, 0);
}

TEST(BasicTest, StandardInput2)
{
    EXPECT_TRUE(true);
}

TEST(BasicTest, StandardInput3)
{
    ASSERT_TRUE(true);
}

TEST(BasicTest, StandardInput4)
{
    ASSERT_TRUE(true);
}
