#include <iostream>

// 这里实现的是叫做策略模式
// 策略模式定义了算法族，分别进行了封装，
class QuackBehavior{
public:
    // 纯虚函数要加=0进行提示
    virtual void quack() = 0;
};

class FlyBehavior{
public:
    virtual void fly() = 0;
};

// 超类
class Duck{
public:
    // 行为类
    QuackBehavior* quackbehavior;
    FlyBehavior* flybehavior;

    Duck(){}
    // 将具体的行为委托给行为类
    void performQuack(){
        quackbehavior->quack();
    }

    void performFly(){
        flybehavior->fly();
    }

    void setQuack(QuackBehavior* qb){
        quackbehavior = qb;
    }

    void setFly(FlyBehavior* fb){
        flybehavior = fb;
    }

    void swim(){
        std::cout << "鸭子类！"<< std::endl;
    }
};

// 呱呱叫的接口类
class Quack: public QuackBehavior{
public:
    void quack() override{
        std::cout << "quack!" << std::endl;
    }
};

class MuteQuack: public QuackBehavior{
public:
    void quack() override{
        std::cout << "<<silence>>" << std::endl;
    }
};

class SqueakQuack: public QuackBehavior{
public:
    void quack() override{
        std::cout << "<<squeak>>" << std::endl;
    }
};

// 飞行的行为类
class FlyWithWings: public FlyBehavior{
public:
    void fly() override{
        std::cout << "fly with wings!" << std::endl;
    }
};

class FlyNoWay: public FlyBehavior{
public:
    void fly() override{
        std::cout << "can't fly!" << std::endl;
    }
};

class FlyRocketPower: public FlyBehavior{
public:
    void fly() override{
        std::cout << "I can fly with rocket!" << std::endl;
    }
};

class MallardDuck:public Duck{
public:
    // 这里只是使用构造器来进行动态绑定
    MallardDuck(){
        quackbehavior = new Quack();
        flybehavior = new FlyWithWings();
    }
    void display(){
        std::cout << "I'm a real Mallard duck!" << std::endl;
    }
};

class ModelDuck:public Duck{
public:
    // 这里只是使用构造器来进行动态绑定
    ModelDuck(){
        quackbehavior = new Quack();
        flybehavior = new FlyNoWay();
    }
    void display(){
        std::cout << "I'm a model duck!" << std::endl;
    }
};

int main(){
    Duck* d = new MallardDuck();
    d->performQuack();
    d->performFly();
    Duck* d2 = new ModelDuck();
    d2->performFly();
    d2->setFly(new FlyRocketPower());
    d2->performFly();

    return 0;
}

