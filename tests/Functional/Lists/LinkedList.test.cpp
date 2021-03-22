#include "gtest/gtest.h"
#include "Lists/LinkedList.h"

class LinkedListTest : public ::testing::Test {
private:
    const int Data_size = 100;
protected:
    void SetUp() override {
        //Create a dataset to test against
        for (int i = 0; i < this->Data_size; i++){
            if (i == 0) {
                Data->insert(-1,i);
                continue;
            }
            Data->insert(i-1, i);
        }
    }

    LinkedList<int> * Data = new LinkedList<int>(-1);
    int randomDataFromNode = (int)random() % this->Data_size;
};

TEST_F(LinkedListTest, TestInsertStatus) {
    ASSERT_EQ(Data->getStatus(), true);
}

TEST_F(LinkedListTest, TestExpectedDataset) {
    testing::internal::CaptureStdout();
    Data->printList();
    std::string PrintedDataset = testing::internal::GetCapturedStdout();

    for (int i = 0; i < 100; i++) {
        ASSERT_NE(PrintedDataset.find(std::to_string(i)), std::string::npos);
    }
}

TEST_F(LinkedListTest, TestMemoization) {
    Data->find(randomDataFromNode);
    ASSERT_EQ(Data->currNode->Data, randomDataFromNode);

}