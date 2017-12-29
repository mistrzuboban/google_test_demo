//
// Created by U203872 on 12/20/17.
// http://www.cplusplus.com/forum/beginner/134128/



#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "HttpFetchMock.h"
#include "HtmlParser.h"
#include "DummyArray.h"
#include "DummyArrayIterator.h"

int suma(const int a, const int b) {
    return a + b;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// function
TEST(suma, TestName) {
    ASSERT_EQ(10, suma(7, 3));
}

// mock
TEST(HtmlParser, NoData) {
    using ::testing::Return;

    char *html;
    HttpFetchMock mock;
    HtmlParser parser(mock);

    //ON_CALL(mock, getUrlAsString("http://example2.net")).WillByDefault(Return(""));
    EXPECT_CALL(mock, getUrlContentAsString("http://example.net"))
            .WillOnce(Return(std::string(html)));

    std::vector<std::string> links = parser.getAllLinks("http://example.net");
    EXPECT_EQ(1, links.size());
}

// exception
TEST(CustomArrayIterator, ShouldThrowOutOfArray) {
    DummyArray<int, 2> arr;
    arr.setAt(1, 1);
    EXPECT_THROW(arr.getAt(6), std::out_of_range);
}

// string equality
TEST(CustomArrayIterator, SetterGetterStringEqual) {
    DummyArray<char *, 5> arr;
    char *r = "GDN";
    arr.setAt(4, r); // this is wrong
    char *p = arr.getAt(4);
    EXPECT_STRCASEEQ(p, r);
}

// fixtures as reusable component
class DummyArrayFixture : public ::testing::Test {
protected:

    static constexpr unsigned int size = 5;
    static constexpr float sum = 17.45;

    DummyArrayFixture() {
        arr.setAt(0, 1.3);
        arr.setAt(1, 2.17);
        arr.setAt(2, 3.14);
        arr.setAt(3, 4.85);
        arr.setAt(4, 5.99);
    }

    using _DummyArray = DummyArray<float, size>;
    _DummyArray arr;


};

// test fixture / float comparison
TEST_F(DummyArrayFixture, FloatComparison) {

    float aggr = 0;
    int div = 131;
    for (auto&& d : arr) {
        aggr += (d / div);
    }
    aggr *= div;

    EXPECT_FLOAT_EQ(aggr, sum);
    EXPECT_NEAR(aggr, sum, 0.00001);
}

// test fixture / true/false
TEST_F(DummyArrayFixture, IteratorScopeEnd) {

    _DummyArrayIterator<float, size>  itr = begin(arr);
    ++itr;
    EXPECT_TRUE(itr != end(arr));
    ++itr;
    EXPECT_TRUE(itr != end(arr));
    ++itr;
    EXPECT_TRUE(itr != end(arr));
    ++itr;
    EXPECT_TRUE(itr != end(arr));
    ++itr;
    EXPECT_FALSE(itr != end(arr));
}