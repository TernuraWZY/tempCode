#include <unordered_map>
#include <utility>
#include <string>

template <class abstractProduct>
class runTimeMap
{
public:
    void addObj(const string &name, abstractProduct* obj)
    {
        Map[name] = obj;
    }

private:
    unordered_map<string, abstractProduct*> Map;
};