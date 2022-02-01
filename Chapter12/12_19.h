#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加和删除元素
    void push_back(const string& t) { data->push_back(t); }
    void pop_back();
    //元素访问
    string& front();
    string& front() const;
    string& back();
    string& back() const;
    //返回指向首元素和尾后元素的StrBlobPtr
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    shared_ptr<vector<string>> data;
    // 如果data[i]不合法，抛出一个异常
    void check(size_type i, const string& msg) const;
};

class StrBlobPtr{
public:
    StrBlobPtr(): curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string& deref() const;
    StrBlobPtr& incr();     // 前缀递增
private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>> check(size_t, const string&) const;
    // 保存一个weak_ptr，意味着底层vector可能会被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;    //在数组中的当前位置
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

StrBlobPtr StrBlob::begin() { 
        return StrBlobPtr(*this); 
    }
    StrBlobPtr StrBlob::end() { 
        auto ret = StrBlobPtr(*this, data->size()); 
        return ret;
    }


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock(); //vector还存在吗？
    if(!ret)
        throw runtime_error("unbound StrBlobPtr");
    if(i >= ret->size())
        throw out_of_range(msg);
    return ret; //否则，返回指向vector的shared_ptr
}

string& StrBlobPtr::deref() const{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  //(*p)是对象所指向的vector
}

//前缀递增，返回递增后的对象的引用
StrBlobPtr& StrBlobPtr::incr(){
    //如果curr已经指向容器的尾后位置，就不能递增它
    check(curr, "increment past end of StrBlobPtr");
    ++curr; //推进当前位置
    return *this;
}

#endif
