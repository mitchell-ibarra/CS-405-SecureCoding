//Mitchell Ibarra
// CS 405 Secure Coding
// Module Four Milestone 
// SNHU
// 3/27/2021
// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    // if empty, the size must be 0
    ASSERT_TRUE(collection->empty());
    // Add entry and compare to expected size of collection 1 to confirm a single value was added - Mitchell
    add_entries(1);
    ASSERT_EQ(collection->size(), 1);
    // is the collection still empty?
    // if not empty, what must the size be?
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // if empty, the size must be 0
    ASSERT_TRUE(collection->empty());
    add_entries(5);
    // Add entry and compare to expected size of collection 5 to confirm five values were added - Mitchell
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, IsColectionSizeGreaterThanOrEqualSize01510)
{
    //Check if Collection is empty
    ASSERT_TRUE(collection->empty());

    //If empty, the size must be 0 
    //Assert that each size of list is greater than or equal to expected by adding values to collection - Mitchell
    ASSERT_GE(collection->size(), 0);
    add_entries(1);
    ASSERT_GE(collection->size(), 1);
    add_entries(4);
    ASSERT_GE(collection->size(), 5);
    add_entries(5);
    ASSERT_GE(collection->size(), 10);
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, IsColectionCapacityGreaterThanOrEqualSize01510)
{
    //Check if Collection is empty
    ASSERT_TRUE(collection->empty());

    //If empty, the size must be 0 
    //Assert that each size of list is as expected by adding values to collection - Mitchell
    ASSERT_GE(collection->capacity(), 0);
    add_entries(1);
    ASSERT_GE(collection->capacity(), 1);
    add_entries(4);
    ASSERT_GE(collection->capacity(), 5);
    add_entries(5);
    ASSERT_GE(collection->capacity(), 10);
}

// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, IsCollectionLargerWhenResized)
{
    //Get the inital size of the collection to compare against the collection after it has been resized - Mitchell
    int collection_size = collection->size();
    collection->resize(1);
    ASSERT_GT(collection->size(), collection_size);
    collection_size = collection->size();
    collection->resize(3);
    ASSERT_GT(collection->size(), collection_size);
}

// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, IsCollectionSmallerWhenResized)
{
    // Add entries to collection in order to resize to smaller - Mitchell
    add_entries(10);
    //Get the inital size of the collection to compare against the collection after it has been resized - Mitchell
    int collection_size = collection->size();
    collection->resize(8);
    ASSERT_LT(collection->size(), collection_size);
    collection_size = collection->size();
    collection->resize(5);
    ASSERT_LT(collection->size(), collection_size);
}

// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, IsCollectionZeroWhenResized)
{
    // Add entries to collection in order to resize to zero - Mitchell
    add_entries(10);
    //After values have been added, we resize the collection to zero and confirm with the assert equals - Mitchell
    collection->resize(0);
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, IsCollectionEmptyAfterClear)
{
    // Add entries to collection in order to clear - Mitchell
    add_entries(10);
    //After values have been added, we clear the collection and confirm it is empty with assert true - Mitchell
    collection->clear();
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, IsCollectionErasedFromBeginToEnd)
{
    // Add entries to collection in order to erase from beginning to end - Mitchell
    add_entries(10);
    //After values have been added, we erase the collection from beginning to end 
    //and confirm it is empty with assert true - Mitchell
    collection->erase(collection->begin(), collection->end());
    ASSERT_TRUE(collection->empty());
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, CollectionReserveIncreasesCapacityNotSize)
{
    // Add entries to collection in order to erase from beginning to end - Mitchell
    add_entries(10);
    // store the size value to compare with capacity later - Mitchell
    int size = collection->size();
    // Call the reserve function to increase the capacity - Mitchell
    collection->reserve(15);
    // And store the capacity value to compare with size - Mitchell
    int capacity = collection->capacity();
    // Assert that the capacity is greater than size after the reserve call - Mitchell
    ASSERT_GT(capacity, size);
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, CollectionOutOfRangeException)
{
    // Assert that the out_of_range exceptions has been thrown when accesing an element out of 
    // bounds with the at() function - Mitchell 
    ASSERT_THROW(collection->at(1), std::out_of_range);
    // Add entries and confirm exception is thrown - Mitchell
    add_entries(3);
    ASSERT_THROW(collection->at(4), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

// Create a test that uses the assign function to add multiple of the same value - positive test - Mitchell
TEST_F(CollectionTest, CollectionAssignFunction)
{
    // Use the assign funtion to add 10 ints with the value of 100 - Mitchell 
    collection->assign(10, 100);
    // Assert that the size of the collection is now 10 - Mitchell
    ASSERT_EQ(collection->size(), 10);
    // Loop through and check that each element in the collection is 100 - Mitchell
    for (int i = 0; i < collection->size(); i++)
    {
        ASSERT_EQ(collection->at(i), 100);
    }
}

// Create a test that uses the at function with a negative index - Mitchell
TEST_F(CollectionTest, CollectionOutOfBoundsNegative)
{
    // Assert that looking for element at a negative index throws out_of_range exception - Mitchell
    ASSERT_THROW(collection->at(-1), std::out_of_range);
}