//
// Created by U203872 on 12/20/17.
// http://www.cplusplus.com/forum/beginner/134128/

#include "HttpTest.h"


#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "HttpFetchMock.h"
#include "HtmlParser.h"


int suma(const int a, const int b) {
    return a + b;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

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


TEST(suma, TestName) {
    ASSERT_EQ(10, suma(7, 3));
}
