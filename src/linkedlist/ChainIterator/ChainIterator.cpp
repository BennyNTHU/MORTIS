//More functions
ChainIterator begin() const
{
    return ChainIterator(first);
}
ChainIterator end() const
{
    return ChainIterator(0);
}