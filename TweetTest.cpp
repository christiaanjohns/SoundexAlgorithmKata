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

TEST(ATweet, IsLessThanWhenUserAndMessageAre)
{
    Tweet a("msg", "@user1");
    Tweet b("msg", "@user2");
    ASSERT_THAT(a, Lt(b)); //Lt = less than
}

TEST(ATweet, IsLessThanWhenUserIsEqualAndMessageIsLessThan)
{
    Tweet a("msgA", "@user");
    Tweet b("msgB", "@user");
    ASSERT_THAT(a, Lt(b)); //Lt = less than
}

TEST(ATweet, CanCopyConstructed)
{
    Tweet a("msgA", "@user");
    Tweet b(a);
    ASSERT_THAT(a, Eq(b));
}