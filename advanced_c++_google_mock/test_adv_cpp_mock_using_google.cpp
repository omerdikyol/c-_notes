#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "adv_cpp_mock_using_google.cpp"

using namespace testing;

TEST(FakeStreamTests, GetString_ReturnsExpectedValue) {
    FakeStream stream;
    EXPECT_CALL(stream, getstring()) // Expect a call to getstring
        .WillOnce(Return("test string"));
    
    char buffer[20];
    stream.getline(buffer, sizeof(buffer)); // Call getline to get the value from getstring
    ASSERT_EQ(std::string(buffer), "test string"); // Check if the buffer contains the expected value
}

TEST(DataLayerTests, MovieExist_ReturnsFalse_ByDefault) {
    DataLayer dataLayer;
    ASSERT_EQ(dataLayer.MovieExist("any movie"), false);
}

TEST(FakeDataLayerTests, Create_CallsExpectedTimes) {
    fakeDataLayer dataLayer;
    auto movieData = std::make_shared<MovieData>();
    
    EXPECT_CALL(dataLayer, Create(movieData))
        .Times(1);
    
    dataLayer.Create(movieData);
}

TEST(FakeDataLayerTests, MovieExist_ReturnsConfiguredValue) {
    fakeDataLayer dataLayer;
    EXPECT_CALL(dataLayer, MovieExist("existing movie"))
        .WillOnce(Return(true));
    
    ASSERT_EQ(dataLayer.MovieExist("existing movie"), true);
}

TEST(FakeStreamTests, IsOpen_ReturnsConfiguredValue) {
    FakeStream stream;
    EXPECT_CALL(stream, is_open())
        .WillOnce(Return(true))
        .WillOnce(Return(false));
    
    ASSERT_EQ(stream.is_open(), true);
    ASSERT_EQ(stream.is_open(), false);
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}