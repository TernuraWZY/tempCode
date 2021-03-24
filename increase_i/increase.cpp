// ++i实现，返回自加后新值
int &int::operator++()
{
    *this += 1;
    return *this;
}



// i++实现，返回自加原值
const int int::operator(int)
{
    int oldValue = *this;
    ++(*this);
    return oldValue;
}