对于不同模型的基类有共有的方法 
static shoes *New  
static initMap
static insertMap
static unordered_map<string, shoes*>

派生类
static string typeName

共有加入静态哈希表类
class addConstructorToMap
{
public:
    static concreteType *productNew()
    {
        return new concreteType;
    }
    addConstructorToMap(const string &lookup = concreteType::typeName)
    {
        abstractType::initMap();
        abstractType::insertMap(lookup, productNew());
    }
};