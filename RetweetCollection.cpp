#include "RetweetCollection.h"

RetweetCollection::RetweetCollection()
{
    size_ = 0;
}

bool RetweetCollection::isEmpty() const
{
    return 0 == size();
}

unsigned int RetweetCollection::size() const
{
    return isEmpty() ? 0 : 1;
}

void RetweetCollection::add(const Tweet &tweet)
{
    tweets.insert(tweet);
    size_ += 1;
}

