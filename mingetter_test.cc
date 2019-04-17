#include <gtest/gtest.h>
#include "MinGetter1.h"
#include "MinGetter2.h"
#include "MinGetter3.h"
#include "MinGetterBase.h"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;

#define RAND_MAX INT_MAX

class MinGetterTest : public testing::Test {

public:
  static void SetUpTestCase() {
    targets.push_back(make_shared<MinGetter1>());
    targets.push_back(make_shared<MinGetter2>());
    targets.push_back(make_shared<MinGetter3>());

    X_axis.push_back(1000);
    X_axis.push_back(2000);
    X_axis.push_back(3000);
    X_axis.push_back(4000);
    X_axis.push_back(5000);
    X_axis.push_back(6000);
    X_axis.push_back(7000);
    X_axis.push_back(8000);
    X_axis.push_back(9000);
    X_axis.push_back(10000);
    srand(time(nullptr));
  }

  static void TearDownTestCase() {
    targets.clear();
    X_axis.clear();
    record.close();
  }
protected:
  static vector<shared_ptr<MinGetterBase>> targets;
  static vector<int> X_axis;
  static int NOI;
  static fstream record;

};

vector<shared_ptr<MinGetterBase>> MinGetterTest::targets;
vector<int> MinGetterTest::X_axis;
int MinGetterTest::NOI = 100;
fstream MinGetterTest::record = fstream("data.txt", ios::out | ios::binary | ios::app);


TEST_F(MinGetterTest, FunctionalTest) {

  for (auto minGetter : targets) {
    std::cout << minGetter->describe() << "\n";
    ASSERT_TRUE(minGetter->put(10));
    ASSERT_TRUE(minGetter->put(12));
    ASSERT_TRUE(minGetter->put(3));
    ASSERT_TRUE(minGetter->put(60));
    ASSERT_TRUE(minGetter->put(7));
    ASSERT_EQ(5, minGetter->size());

    ASSERT_TRUE(minGetter->put(7));
    ASSERT_TRUE(minGetter->put(60));
    ASSERT_EQ(5, minGetter->size());

    ASSERT_EQ(3, minGetter->get_min_value());
    ASSERT_EQ(7, minGetter->get_min_value());
    ASSERT_EQ(3, minGetter->size());

    ASSERT_EQ(10, minGetter->get_min_value());
    ASSERT_EQ(12, minGetter->get_min_value());
    ASSERT_EQ(60, minGetter->get_min_value());
    ASSERT_EQ(0, minGetter->size());

    ASSERT_EQ(-1, minGetter->get_min_value());
  }

}

TEST_F(MinGetterTest, PutTest) {
  ASSERT_TRUE(record.is_open());
  record << "PutTest-" << static_cast<unsigned>(time(0)) << ":\n";

  for (auto minGetter : targets) {
    std::cout << minGetter->describe() << "\n";
    record <<  minGetter->describe() << " : ";
    for (auto times : X_axis) {
      double sum = 0.0;
      for (int i = 0; i < NOI; i++) {
        auto start = std::chrono::system_clock::now();
        for (int j = 0; j < times; ++j) {
          ASSERT_TRUE(minGetter->put(rand()));
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end-start;
        sum += diff.count();
        minGetter->clear();
      }
      record << (sum / NOI) * 1000 << " ";
    }
    record << "\n";
  }
}

TEST_F(MinGetterTest, WorkerTest) {
  ASSERT_TRUE(record.is_open());
  record << "WorkerTest-" << static_cast<unsigned>(time(0)) << ":\n";

  for (auto minGetter : targets) {
    cout << minGetter->describe() << "\n";
    record << minGetter->describe() << " : ";
    for (auto times : X_axis) {
      double sum = 0.0;
      for (int i = 0; i < NOI; i++) {
        minGetter->clear();
        auto start = chrono::system_clock::now();

        for (int j = 0; j < times; ++j) {
          if ((rand() & ((1 << 3) - 1)) < 3) { // get
            auto temp = minGetter->get_min_value();
          }else {                 // put
            ASSERT_TRUE(minGetter->put(rand()));
          }
        }

        auto end = chrono::system_clock::now();
        chrono::duration<double> diff = end - start;
        sum += diff.count();
        minGetter->clear();
      }
      record << (sum / NOI) * 1000 << " ";
    }
    record << "\n";
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
