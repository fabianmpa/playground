#include "../GraphValidTree/validtree.h"
#include "disjoint_set_testdata.h"
#include "gtest/gtest.h"

TEST(UnionFind, validTree) {
  int n=4;
  EXPECT_EQ(true,validTree(n,edges_t1));
}
int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
