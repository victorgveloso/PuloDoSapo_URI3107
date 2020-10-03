//
// Created by victor on 02/10/2020.
//
#include "gtest/gtest.h"
#include "jumper.h"

/*
 * 8 16
 * 2 3 4 7 11 12 13 15
 * 2 4
 */
TEST(JumperTest, TestCatarina) {
    int path[100000] = {1,2,3,4,7,11,12,13,15,16};
    Jumper j(path, 4, 2, 8);
    ASSERT_EQ(j.jump(),-1);
}
/*
 * 8 16
 * 2 3 4 7 8 12 13 15
 * 2 4
 */
TEST(JumperTest, TestCatarinaFixed) {
    int path[100000] = {1,2,3,4,7,8,12,13,15,16};
    Jumper j(path, 4, 2, 8);
    ASSERT_EQ(j.jump(), 6);
}
/*
 * 7 15
 * 2 3 6 7 11 12 14
 * 2 4
 */
TEST(JumperTest, TestCatarinaSpooky) {
    int path[100000] = {1,2,3,6,7,11,12};
    Jumper j(path, 4, 2, 5);
    ASSERT_EQ(j.jump(), 5);
}
/*
 * 8 16
 * 2 3 4 6 11 12 13 15
 * 2 4
 */
TEST(JumperTest, TestCatarinaModified) {
    int path[100000] = {1,2,3,4,6,11,12,13,15,16};
    Jumper j(path, 4, 2, 8);
    ASSERT_EQ(j.jump(),-1);
}
/*
 * 3 6
 * 2 4 5
 * 1 2
 */
TEST(JumperTest, TestBoard) {
    int path[100000] = {1,2,4,5,6};
    Jumper j(path, 2, 1, 3);
    ASSERT_EQ(j.jump(), 4);
}
/*
 * 3 6
 * 3 4 5
 * 1 3
 */
TEST(JumperTest, TestDemo) {
    int path[100000] = {1,3,4,5,6};
    Jumper j(path, 3, 1, 3);
    ASSERT_EQ(j.jump(), 3);
}
/*
 * 4 8
 * 2 4 5 6
 * 1 3
 */
TEST(JumperTest, MySmallTest) {
    int path[100000] = {1,2,4,5,6,8};
    Jumper j(path, 3, 1, 4);
    ASSERT_EQ(j.jump(), 3);
}
/*
 * 3 10
 * 4 6 7
 * 2 4
 */
TEST(JumperTest, MyBigSparseTest) {
    int path[100000] = {1,4,6,7,10};
    Jumper j(path, 4, 2, 3);
    ASSERT_EQ(j.jump(), 3);
}

void testFromFile(std::string fileName, int expectedOutput) {
    std::ifstream inFile;
    inFile.open(fileName);
    ASSERT_TRUE(inFile);
    int lastStone, END, sJ, bJ;
    int *path = {new int[1000002]};
    inFile >> lastStone >> END;
    path[0] = 1;
    path[lastStone + 1] = END;
    for (int stone = 1; stone <= lastStone; ++stone) {
        int dist;
        inFile >> dist;
        path[stone] = dist;
    }
    inFile >> sJ >> bJ;
    Jumper j(path, bJ, sJ, lastStone);

    ASSERT_EQ(j.jump(),expectedOutput);
}

TEST(JumperTest, TestFullPathWithBigDistance) {
    testFromFile("../../input.txt",-1);
}

TEST(JumperTest, TestCompleteFullPath) {
    testFromFile("../../inputSuccess.txt",500001);
}

TEST(JumperTest, TestTooFarMargin) {
    testFromFile("../../inputTooFarMargin.txt",-1);
}
