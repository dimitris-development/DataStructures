#include "gtest/gtest.h"
#include "LinkedList.h"
#include <string>

class LinkedListTest : public ::testing::Test {
private:
    const int Data_size = 100;
protected:
    void SetUp() override {
        //Create a dataset to test against
        for (int i = 0; i < this->Data_size; i++){
            if (i == 0) {
                Data->insert("HEAD", std::to_string(i));
                continue;
            }
            Data->insert(std::to_string(i-1), std::to_string(i));
        }
    }

    LinkedList * Data = new LinkedList();
    std::string randomDataFromNode = to_string(random() % this->Data_size);
};

TEST_F(LinkedListTest, TestInsertStatus) {
    ASSERT_EQ(Data->getStatus(), true);
}

TEST_F(LinkedListTest, TestExpectedDataset) {
    testing::internal::CaptureStdout();
    Data->printList();
    std::string PrintedDataset = testing::internal::GetCapturedStdout();

    ASSERT_EQ(PrintedDataset.find("HEAD"),std::string::npos);

    for (int i = 0; i < 100; i++) {
        ASSERT_NE(PrintedDataset.find(std::to_string(i)), std::string::npos);
    }
}

TEST_F(LinkedListTest, TestMemoization) {
    Data->find(randomDataFromNode);
    ASSERT_EQ(Data->currNode->data, randomDataFromNode);
}