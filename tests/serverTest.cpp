
#include <string>
#include <vector>
#include <gtest/gtest.h>
#include "SearchServer.h"
#include "InvertedIndex.h"

TEST(TestCaseSearchServer, TestSimple) {
    const std::vector<std::string> docs = {"milk milk milk milk water water water",
                                           "milk water water",
                                           "milk milk milk milk milk water water water water water",
                                           "americano cappuccino"};
    const std::vector<std::string> request = {"milk water", "sugar"};
    const std::vector<std::vector<std::pair<int, float>>> expected = {{{2, 1}, {0, 0.7}, {1, 0.3}}, {{0,0}}};
    auto* idx = new InvertedIndex;
    idx->UpdateDocumentBase(docs);
    auto* srv = new SearchServer(idx);
    std::vector<std::vector<std::pair<int, float>>> result;
    calculateRelRelative(srv, request, result);
    delete idx;
    delete srv;
    ASSERT_EQ(result, expected);
}//тест класса SearchServer
TEST(TestCaseSearchServer, TestTop5) {
    const std::vector<std::string> docs = {"london is the capital of great britain",
                                           "paris is the capital of france",
                                           "berlin is the capital of germany",
                                           "rome is the capital of italy",
                                           "madrid is the capital of spain",
                                           "lisboa is the capital of portugal",
                                           "bern is the capital of switzerland",
                                           "moscow is the capital of russia",
                                           "kiev is the capital of ukraine",
                                           "minsk is the capital of belarus",
                                           "astana is the capital of kazakhstan",
                                           "beijing is the capital of china",
                                           "tokyo is the capital of japan",
                                           "bangkok is the capital of thailand",
                                           "welcome to moscow the capital of russia the third rome",
                                           "amsterdam is the capital of netherlands",
                                           "helsinki is the capital of finland",
                                           "oslo is the capital of norway",
                                           "stockholm is the capital of sweden",
                                           "riga is the capital of latvia",
                                           "tallinn is the capital of estonia",
                                           "warsaw is the capital of poland"};
    const std::vector<std::string> request = {"moscow is the capital of russia"};
    const std::vector<std::vector<std::pair<int, float>>> expected = {{{7, 1.0f}, {14, 1.0f}, {0, 0.666666686535}, {1, 0.666666686535},
                                                                       {2, 0.666666686535}, {3, 0.666666686535}, {4, 0.666666686535},
                                                                       {5, 0.666666686535}, {6, 0.666666686535}, {8, 0.666666686535},
                                                                       {9, 0.666666686535}, {10, 0.666666686535}, {11, 0.666666686535},
                                                                       {12, 0.666666686535}, {13, 0.666666686535}, {15, 0.666666686535},
                                                                       {16, 0.666666686535}, {17, 0.666666686535}, {18, 0.666666686535},
                                                                       {19, 0.666666686535}, {20, 0.666666686535}, {21, 0.666666686535}}};

    auto* idx = new InvertedIndex;
    idx->UpdateDocumentBase(docs);
    auto* srv = new SearchServer(idx);
    std::vector<std::vector<std::pair<int, float>>> result;
    calculateRelRelative(srv, request, result);
    delete idx;
    delete srv;
    ASSERT_EQ(result, expected);

}//тест класса SearchServer
