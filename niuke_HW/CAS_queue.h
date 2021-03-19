#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <atomic>
#include <thread>

using namespace std;

template<typename T>
class Queue{
    public:
        Queue(const int& size=16384);
        ~Queue(){delete[] m_data;}
        long Enqueue(const T &value);
        long Dequeue(T &value);
        void set_is_enqueue_done(const bool &is_enqueue_done){
            m_is_enqueue_done=is_enqueue_done;
        }
        bool get_is_enqueue_done const{ return m_is_enqueue_done;}
        bool get_is_dequeue_done const{ return m_is_dequeue_done;}
        void Clear();

    private: 
        int m_size;
        bool m_is_enqueue_done;
        bool m_is_dequeue_done;
        volatile atomic<long> m_enqueue_num;    // 所有线程可见变量
        volatile atomic<long> m_dequeue_num;    // 入队和出队的编号
        T *m_data;
        void set_size(const int& size);
};

template<typename T>
Queue<T>::Queue(const int& size){
    set_size(size);
    m_data = new T[m_size+1];
    m_is_enqueue_done=m_is_dequeue_done=false;
    m_enqueue_num=m_enqueue_num=0;
}
// 经典指数级扩容
template<typename T>
void Queue<T>::set_size(const int& size){
    if(size<=16384){
        m_size = 16384;
        return;
    }
    m_size = 16384;
    while(m_size<size){
        m_size <<= 1;
    }
    m_size>>=1;
}
// 生产者
template<typename T>
long Queue<T>::Enqueue(const T& value){
    while(m_enqueue_num-m_dequeue_num>=m_size){this_thread::sleep_for(1);}

    long old_num;
    do{
enqueue_loop:
    old_num = m_enqueue_num；
    if(m_enqueue_num==-1){
        this_thread::sleep_for(1);
        goto enqueue_loop;
    }
    }while(!atomic_compare_exchange_weak(&m_enqueue_num,&old_num,(long)-1));

    m_data[old_num&(m_size-1)] = value;
    m_enqueue_num = old_num+1;
    return m_enqueue_num;
}

template<typename T>
long Queue<T>::Dequeue(T &value){
    long old_num,new_num;
    do{
dequeue_loop:
        old_num_ = m_dequeue_num;
        new_num = old_num_+1;
        if(m_dequeue_num>=m_enqueue_num){
            if(m_is_enqueue_done){
                m_is_dequeue_done = true;
                return 0;
            }
            else
                this_thread::sleep_for(1);
            goto dequeue_loop;
        }
        value = m_data[m_dequeue_num&(m_size-1)];
    }while(!atomic_compare_exchange_weak(&m_dequeue_num,&old_num_,new_num))
    return m_dequeue_num;
}
/* 1. 循环队列采用线性表来进行实现，少一个节点用来区分空和满的情况，队列的头和尾等为空，(队尾+1)%size==队头作为满的情况*/
/* 2. 取余操作可以使用index&(size-1)代替index%size,但是这种计算方式的要求是size必须是2的整数次幂
   3. lockfree最关键的是要保障队头和队尾指针的atomic;
   4. CAS操作流程: 在CAS操作之前，需要先获取变量var的值并且储存在old_var中；之后执行CAS操作，检查var是否和old_var相等，
      如果相等将新值new_var赋值给var，如果不相等，则重新获取var的值保存在old_var当中，再次重复以上过程*/
#endif /*_QUEUE_H_*/