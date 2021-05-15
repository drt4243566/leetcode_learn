// 单例模式demo

class single{
private:
    single(){}
    ~single(){}

public:
    static single* getinstance();
};

single* single::getinstance(){
    static single obj;
    return &obj;
}