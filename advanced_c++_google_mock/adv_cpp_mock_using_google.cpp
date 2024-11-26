

/**
 * @file adv_cpp_mock_using_google.cpp
 * @brief Advanced C++ Unit Testing Example using Google Mock Framework
 *
 * This file demonstrates advanced unit testing concepts using Google Mock framework:
 * 
 * Unit Testing:
 * - A software testing method where individual components are tested in isolation
 * - Helps verify that each unit of code performs as expected
 * - Improves code quality and helps catch bugs early in development
 *
 * Key Concepts Demonstrated:
 * 1. Mocking
 *    - Creating fake objects that simulate real object behavior
 *    - Useful for testing components in isolation
 *    - Allows control over test conditions
 *
 * 2. Test Fixtures (MovieAnalyzerTests)
 *    - Provides common setup and teardown for multiple tests
 *    - Helps maintain test code organization
 *    - Reduces code duplication across tests
 *
 * 3. Mock Objects
 *    - FakeStream: Mocks stream operations
 *    - fakeDataLayer: Mocks data layer operations
 *    - Allows testing without actual file/database operations
 *
 * 4. EXPECT_CALL
 *    - Defines expectations for mock method calls
 *    - Verifies number of calls and return values
 *    - Helps ensure correct interaction between components
 * 
 * 5. State Based Testing vs. Interaction Based Testing
 *   - State Based Testing: Tests based on object state changes
 *   - Interaction Based Testing: Tests based on object interactions
 *   - Google Mock supports both state and interaction based testing
 * 
 * 
 * Dependencies:
 * - Google Test (gtest)
 * - Google Mock (gmock)
 * 
 * @note This example focuses on testing movie data processing with mock objects
 *       to demonstrate isolation of components during testing.
 */

// Assert: A statement that verifies a condition is true
// Expect: A statement that verifies a condition is true, but does not stop the test if failed
// Mock: A fake object that simulates real object behavior

// ASSERT Types - Fatal assertions (stops the test if failed)
// ASSERT_TRUE(condition) - Verifies condition is true
// ASSERT_FALSE(condition) - Verifies condition is false
// ASSERT_EQ(val1, val2) - Verifies val1 equals val2
// ASSERT_NE(val1, val2) - Verifies val1 not equals val2
// ASSERT_LT(val1, val2) - Verifies val1 less than val2
// ASSERT_LE(val1, val2) - Verifies val1 less than or equal to val2
// ASSERT_GT(val1, val2) - Verifies val1 greater than val2
// ASSERT_GE(val1, val2) - Verifies val1 greater than or equal to val2

// EXPECT Types - Non-fatal assertions (continues test after failure)
// EXPECT_TRUE(condition) - Expects condition is true
// EXPECT_FALSE(condition) - Expects condition is false
// EXPECT_EQ(val1, val2) - Expects val1 equals val2
// EXPECT_NE(val1, val2) - Expects val1 not equals val2
// EXPECT_LT(val1, val2) - Expects val1 less than val2
// EXPECT_LE(val1, val2) - Expects val1 less than or equal to val2
// EXPECT_GT(val1, val2) - Expects val1 greater than val2
// EXPECT_GE(val1, val2) - Expects val1 greater than or equal to val2
// Advanced C++ Mocking Using Google Mock

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <string>
#include <cstring>

using namespace ::testing;

// Mocking a simple class
class FakeStream {
public:
    MOCK_METHOD1(open, void(std::string)); // MOCK_METHOD<number>: Define a mock method with <number> arguments
    MOCK_CONST_METHOD0(is_open, bool());
    MOCK_METHOD0(getstring, std::string());
    MOCK_METHOD0(close, void());
    MOCK_METHOD0(eof, bool());
    void getline(char *output, size_t size) {
        std::memcpy(output, getstring().c_str(), size);
    }
};

// Mocking a data layer
class MovieData {};
class DataLayer {
public:
    virtual bool MovieExist(const std::string& movieName) { // Use virtual methods to allow mocking
        return false;
    }
    virtual void Create(std::shared_ptr<MovieData> movie) {}
    virtual void Update(std::shared_ptr<MovieData> movie) {}
};

class fakeDataLayer : public DataLayer {
public:
    MOCK_METHOD1(MovieExist, bool(const std::string&));
    MOCK_METHOD1(Create, void(std::shared_ptr<MovieData>));
    MOCK_METHOD1(Update, void(std::shared_ptr<MovieData>));
};

// Example test case using Google Mock
class MovieAnalyzerTests : public Test {
protected:
    void SetUp() override {
        // Setup code here
    }

    void TearDown() override {
        // Cleanup code here
    }
};

TEST_F(MovieAnalyzerTests, ProcessFromFile_FileIsEmpty_DoNotCallDB) {
    fakeDataLayer fakeDataLayer;

    // Expectations
    EXPECT_CALL(fakeDataLayer, Create(_)).Times(0); // .WillOnce(Return()); // Expect Create to be called 0 times
    EXPECT_CALL(fakeDataLayer, Update(_)).Times(0);

    // Using WillOnce and WillRepeatedly to set return values
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillRepeatedly(Return(false)); // Returns false by default, can be int, double, etc.
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillOnce(Return(false)); // Returns false once));

    // Use WillOnce consecutive times to return different values
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillOnce(Return(false)).WillOnce(Return(true));

    // Throw exception
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillOnce(Throw(std::runtime_error("Database error")));

    // Uasing Invoke to call a custom function
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillOnce(Invoke([](const std::string& movieName) {
        return movieName == "existing movie";
    }));

    // Setting Expectations Using EXPECT_CALL
    // EXPECT_CALL(fakeDataLayer, MovieExist(_))
        // .With(Eq("existing movie")) // Check if the argument is equal to "existing movie"
        // .Times(1); // Expect the call to be made once
        // .InSequence(sequence1); // Define the sequence
        // .After(other_mock); // Expect the call to be made after another mock
        // .WillOnce(Return(true); // Set the return value
        // .WillRepeatedly(Return(false); // Set the return value to be repeated
        // .RetiresOnSaturation(); // Stop expecting calls after the expected number of calls

    // Generic Comparison Matchers
    // EXPECT_CALL(fakeDataLayer, MovieExist(_))
    //    .With(StrEq("existing movie")) // Check if the argument is a string equal to "existing movie"
    //    .With(StrNe("non-existing movie")) // Check if the argument is a string not equal to "non-existing movie"
    //    .With(StrCaseEq("EXISTING MOVIE")) // Check if the argument is a string case-insensitive equal to "EXISTING MOVIE"
    //    .With(StrCaseNe("NON-EXISTING MOVIE")) // Check if the argument is a string case-insensitive not equal to "NON-EXISTING MOVIE"
    //    .With(HasSubstr("movie")) // Check if the argument contains the substring "movie"
    //    .With(StartsWith("exist")) // Check if the argument starts with "exist"
    //    .With(EndsWith("movie")) // Check if the argument ends with "movie"
    //    .With(ContainsRegex(".*movie.*")) // Check if the argument contains a regex pattern
    //    .With(MatchesRegex(".*movie")) // Check if the argument matches a regex pattern
    //    .With(Count(2)) // Check if the argument is called 2 times
    //    .With(IsNull()) // Check if the argument is null
    //    .With(NotNull()) // Check if the argument is not null
    //    .With(IsTrue()) // Check if the argument is true
    //    .With(IsFalse()) // Check if the argument is false
    //    .With(Ge(5)) // Check if the argument is greater than or equal to 5
    //    .With(Gt(5)) // Check if the argument is greater than 5
    //    .With(Ref(variable)) // Check if the argument is a reference to a variable

    // Type Based Matchers
    //    .With(An<int>()) // Check if the argument is an integer
    //    .With(A<std::string>()) // Check if the argument is a string
    //    .With(TypedEq<int>(5)) // Check if the argument is an integer equal to 5
    //    .With(Matcher<int>(Gt(5))) // Check if the argument is an integer greater than 5

    // Combining Matchers
    //    .With(AllOf(Ge(5), Le(10))) // Check if the argument is greater than or equal to 5 and less than or equal to 10
    //    .With(AnyOf(Eq(5), Eq(10))) // Check if the argument is equal to 5 or equal to 10
    //    .With(Not(Eq(5))) // Check if the argument is not equal to 5

    // Member Matchers
    //    .With(Field(&MovieData::title, "Movie Title")) // Check if the title field of MovieData is "Movie Title"
    //    .With(Property(&MovieData::rating, Gt(4.0))) // Check if the rating field of MovieData is greater than 4.0
    //    .With(Pointee(5)) // Check if the argument points to the value 5
    //    .With(ElementsAre(1, 2, 3)) // Check if the argument contains elements 1, 2, and 3
    //    .With(UnorderedElementsAre(1, 2, 3)) // Check if the argument contains elements 1, 2, and 3 in any order
    //    .With(Contains(5)) // Check if the argument contains the value 5
    //    .With(Key("key")) // Check if the argument contains the key "key
    //    .With(Pair("key", 5)) // Check if the argument contains the pair "key" and 5ü

    // Container Matchers
    //    .With(IsEmpty()) // Check if the argument is empty
    //    .With(SizeIs(5)) // Check if the argument has a size of 5
    //    .With(WhenSorted(ElementsAre(1, 2, 3))) // Check if the argument contains elements 1, 2, and 3 when sorted
    //    .With(Pointwise(Eq(), {1, 2, 3})) // Check if the argument contains elements 1, 2, and 3 in the same order
    //    .With(Pairwise(Eq(), {1, 2, 3})) // Check if the argument contains pairs of elements 1, 2, and 3 in the same order
    //    .With(Contains(AllOf(Ge(5), Le(10)))) // Check if the argument contains elements greater than or equal to 5 and less than or equal to 10
    //    .With(Each(Ge(5))) // Check if each element in the argument is greater than or equal to 5
    //    .With(AllOf(SizeIs(3), Contains(5))) // Check if the argument has a size of 3 and contains the value 5

    // Multi-Argument Matchers
    //    .With(Args<0, 1>(Eq(5), Gt(10))) // Check if the first argument is equal to 5 and the second argument is greater than 10
    //    .With(Field(&MovieData::title, StrEq("Movie Title"))) // Check if the title field of MovieData is a string equal to "Movie Title"
    //    .With(AllOf(Args<0, 1>(Eq(5), Gt(10)), Field(&MovieData::title, StrEq("Movie Title")))) // Combine matchers for multiple arguments
        

    // Simulate file processing
    // MovieAnalyzer<FakeStream> analyzer(fakeRepository, fakeDataLayer);
    // NiceMock<FakeStream> fakeStream;
    // EXPECT_CALL(fakeStream, is_open()).WillRepeatedly(Return(true));
    // EXPECT_CALL(fakeStream, eof()).WillRepeatedly(Return(true));
    // analyzer.ProcessFromFile(fakeStream);
}

TEST_F(MovieAnalyzerTests, ProcessFromFile_FileHaveOneExistingMovie_LogWarning) {
    auto movieData = std::make_shared<MovieData>();
    fakeDataLayer fakeDataLayer;
    EXPECT_CALL(fakeDataLayer, MovieExist(_)).WillRepeatedly(Return(true));

    // Simulate file processing
    // MovieAnalyzerForTests analyzer(fakeRepository, fakeDataLayer);
    // auto fakeLogger = std::make_shared<FakeLogger>();
    // EXPECT_CALL(analyzer, CreateLogger()).WillOnce(Return(fakeLogger));
    // analyzer.ProcessFromFile(fakeStream);
}

// Creating new matchers
// 1. Using Truly() to define a custom matcher
MATCHER_P(IsEven, n, "") { return (n % 2) == 0; }

TEST_F(MovieAnalyzerTests, CustomMatcherUsingTruly) {
    EXPECT_THAT(4, Truly([](int n) { return (n % 2) == 0; }));
}

// 2. Using MATCHER macro to define a custom matcher
MATCHER(IsPositive, "") { return arg > 0; }

TEST_F(MovieAnalyzerTests, CustomMatcherUsingMacro) {
    EXPECT_THAT(5, IsPositive());
}

// 3. Using MatcherInterface to define a custom matcher
class IsDivisibleBy : public MatcherInterface<int> {
public:
    explicit IsDivisibleBy(int divisor) : divisor_(divisor) {}

    bool MatchAndExplain(int n, MatchResultListener* listener) const override {
        *listener << "which is " << (n % divisor_ == 0 ? "" : "not ") << "divisible by " << divisor_;
        return (n % divisor_) == 0;
    }

    void DescribeTo(::std::ostream* os) const override {
        *os << "is divisible by " << divisor_;
    }

    void DescribeNegationTo(::std::ostream* os) const override {
        *os << "is not divisible by " << divisor_;
    }

private:
    const int divisor_;
};

Matcher<int> IsDivisibleBy(int n) {
    // return MakeMatcher(new IsDivisibleBy(n));
}

TEST_F(MovieAnalyzerTests, CustomMatcherUsingMatcherInterface) {
    EXPECT_THAT(10, IsDivisibleBy(5));
}

// Main function to run all tests
// int main(int argc, char **argv) {
//     InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

// Hi-perf Dependency Injection
// Dependency Injection (DI) is a design pattern that allows the creation of objects with their dependencies supplied from the outside.
// It helps decouple components, making them easier to test and maintain.
// Hi-perf DI is a technique to optimize the performance of dependency injection in high-performance applications.
// It focuses on reducing the overhead of dependency injection while maintaining the benefits of DI.
// Key Concepts:
// 1. Manual Injection: Manually injecting dependencies into objects to avoid the overhead of DI frameworks.
// 2. Lazy Initialization: Delaying the creation of dependencies until they are needed to reduce startup time.
// 3. Object Pooling: Reusing objects to reduce memory allocation and deallocation overhead.
// 4. Custom Factories: Creating custom factories to manage object creation and reuse.
// 5. Inline Injection: Injecting dependencies directly into object constructors or methods to avoid virtual function calls.
// 6. Compile-Time Injection: Using compile-time techniques to inject dependencies without runtime overhead.
// 7. Minimalistic DI: Implementing a minimalistic DI framework tailored to the specific needs of the application.
// 8. Performance Profiling: Profiling the application to identify performance bottlenecks and optimize dependency injection.
// Example:
// Consider a high-performance application that processes large amounts of data.
// To optimize performance, we can use manual injection, lazy initialization, and object pooling to reduce overhead.
// We can create custom factories for managing object creation and reuse, and use inline injection to avoid virtual function calls.
// By profiling the application and optimizing the DI process, we can achieve high performance without sacrificing the benefits of DI.