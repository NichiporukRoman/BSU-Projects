#include <vector>
#include "gtest/gtest.h"
#include "../LABA4.cpp"

TEST(HasInVector, Sample) {
    vector<char> v = {1, 5, 3, 999, 5};
    ASSERT_EQ(HasInVector(v, 5), true);
    ASSERT_EQ(HasInVector(v, 6), false);
}

TEST(Capitalize, Sample) {
    vector<char> v = {' ', 't', 'e', 's', 't', ' ', 'T', 'E', 's', 't', ' '}
    ASSERT_EQ(HasInVector(v, 5), true);
    ASSERT_EQ(HasInVector(v, 6), false);
}

TEST(strcspn, Sample) {
    vector<char> v = {' ', 't', 'e', 's', 't', ' ', 'T', 'E', 's', 't', ' '}
    vector<char> forbidden1 = {'T', 'E'};
    vector<char> forbidden2 = {' ', ' '};
    ASSERT_EQ(strcspn(v, forbidden1), 6);
    ASSERT_EQ(strcspn(v, forbidden2), 0
    );
}
