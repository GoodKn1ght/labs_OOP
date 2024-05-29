#include "pch.h"
#include "C:\Users\sokal\source\repos\OOP_lab4\OOP_TEST_LAB$\lab4.h"
#include "C:\Users\sokal\source\repos\OOP_lab4\OOP_TEST_LAB$\Source.cpp"

TEST(TestCaseName, TestSet) {
    int d[3] = { 6,2,3 };
    int t[3] = { 6,5,2 };
    CMultiSet a(3);
    EXPECT_EQ(a.power(), 3);
    a.setA(d);
    EXPECT_EQ(a.max(), 6);
    EXPECT_EQ(a.min(), 2);

    EXPECT_EQ(a.findN(3), 1);

    a.add(10);
    EXPECT_EQ(a.max(), 10);
    a.dele();
    EXPECT_EQ(a.max(), 6);

    CMultiSet b;
    b.setA(t);
    EXPECT_EQ(b.power(), 0);
    b.set(3);
}


TEST(TestCaseName, TestARD) {
    int d[3] = { 6,2,3 };
    int t[3] = { 6,5,2 };
    CMultiSet a(3, d);
    CMultiSet b(3, t);
    CMultiSet c;
    c = a + b;
    EXPECT_EQ(c.max(), 6);
    EXPECT_EQ(c.findN(3), 1);

    c = a - b;
    EXPECT_EQ(c.min(), 3);
    EXPECT_EQ(c.max(), 5);

    EXPECT_EQ((b / a).min(), 2);
    EXPECT_EQ((b / a).max(), 6);
}