#include <gmock/gmock.h>
#include "Tweet.h"

using namespace std;
using namespace ::testing;

TEST(ATweet, DefaultUserNotNullWhenNotProvided)
{
    Tweet tweet("msg");
    ASSERT_THAT(tweet.getUser_(), Eq("@null"));
}

TEST(ATweet, IsEqualToAnotherWhenMessageAndUserAreEqual)
{
    Tweet a("msg A", "@user1");
    Tweet b("msg A", "@user1");
    ASSERT_TRUE(a == b);
}

TEST(ATweet, IsNotEqualToAnotherWhenMessageAndUserAreEqual)
{
    Tweet a("msg A", "@user1");
    Tweet b("msg B", "@user2");
    ASSERT_TRUE(a != b);
}