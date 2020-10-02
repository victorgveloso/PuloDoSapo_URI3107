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
    Jumper j(path,16,4,2,8);
    ASSERT_THROW(j.jump(),std::exception);
}
/*
 * 8 16
 * 2 3 4 7 8 12 13 15
 * 2 4
 */
TEST(JumperTest, TestCatarinaFixed) {
    int path[100000] = {1,2,3,4,7,8,12,13,15,16};
    Jumper j(path,16,4,2,8);
    try {
        ASSERT_EQ(j.jump(), 6);
    }catch (std::exception &e) {
        FAIL() << "Test throws unexpected exception";
    }
}
/*
 * 8 16
 * 2 3 4 6 11 12 13 15
 * 2 4
 */
TEST(JumperTest, TestCatarinaModified) {
    int path[100000] = {1,2,3,4,6,11,12,13,15,16};
    Jumper j(path,16,4,2,8);
    ASSERT_THROW(j.jump(),std::exception);
}
/*
 * 3 6
 * 2 4 5
 * 1 2
 */
TEST(JumperTest, TestBoard) {
    int path[100000] = {1,2,4,5,6};
    Jumper j(path,6,2,1,3);
    try {
        ASSERT_EQ(j.jump(), 4);
    }catch (std::exception &e) {
        FAIL() << "Test throws unexpected exception";
    }
}
/*
 * 3 6
 * 3 4 5
 * 1 3
 */
TEST(JumperTest, TestDemo) {
    int path[100000] = {1,3,4,5,6};
    Jumper j(path,6,3,1,3);
    try {
        ASSERT_EQ(j.jump(), 3);
    }catch (std::exception &e) {
        FAIL() << "Test throws unexpected exception";
    }
}
/*
 * 4 8
 * 2 4 5 6
 * 1 3
 */
TEST(JumperTest, MySmallTest) {
    int path[100000] = {1,2,4,5,6,8};
    Jumper j(path,8,3,1,4);
    try {
        ASSERT_EQ(j.jump(), 3);
    }catch (std::exception &e) {
        FAIL() << "Test throws unexpected exception";
    }
}
/*
 * 3 10
 * 4 6 7
 * 2 4
 */
TEST(JumperTest, MyBigSparseTest) {
    int path[100000] = {1,4,6,7,10};
    Jumper j(path,10,4,2,3);
    try {
        ASSERT_EQ(j.jump(), 3);
    }catch (std::exception &e) {
        FAIL() << "Test throws unexpected exception";
    }
}