#pragma once

#pragma warning(disable:4996)
#include <iostream>

using std::istream;
using std::ostream;
using std::cout;
using std::endl;
namespace jhx {


class string
{
public:
    typedef char* iterator;


    iterator begin()
    {
        return _str;


    }

    iterator end()
    {

        return _str + _size;

    }



    string(const char* str = "")
    {
        _str = new char[strlen(str) + 1];
        strcpy(_str, str);
        _size = strlen(str);
        _capacity = _size;
       
    }

    //   ~string();

    size_t size()const
    {
        return _size;

    
    }

    size_t capacity()const
    {
        return _capacity;
    
    }

    char& operator[](size_t i)
    {
        return _str[i];
    
    
    }
    const char& operator[](size_t i)const
    {
    
        return _str[i];
    
    }
    const char* c_str()
    {
        return _str;
    
    }

    void reserve(size_t n)
    {
        if (n > _size)
        {
            char *tmp=new char[n + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
            _size = n;
            _capacity = n;

        }
    
    
    }
    void push_back(const char ch)
    {
        if (_size + 1 >= _capacity)
        {
            char* tmp = new char[_size + 1];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
          _capacity = _size + 1;


        }
        strcat(_str+_size, &ch);

           _size++;
           _str[_size] = '\0';

    
    }

    void append(const char* str)
    {
        if (_size + strlen(str) >= _capacity)
        {
            char* tmp = new char[_size + strlen(str)+1];
            strcpy(tmp, _str);
           
            delete[] _str;
            _str = tmp;
            _capacity = _size + strlen(str);

        }
        strcat(_str + _size, str);
        
        _size= _size + strlen(str);
        _str[_size] = '\0';
    
    }
    string& operator+=(const char* str)
    {
        this->append(str);
        return *this;
    
    }
    string& operator+=(const char ch)
    {
        this->push_back(ch);

        return *this;
    }
    void insert(size_t pos, char ch)
    {
        if (this->_size == this->_capacity)
        {
            char* tmp = new char[this->_capacity ? 2 * (this->_capacity)+1:4 ];
           // char* tmp = new char[ 2 * (_capacity)+1];

           
            strcpy(tmp, this->_str);

            delete[] this->_str;
            this->_str = tmp;
           this->_capacity = this->_capacity ? 2 * (this->_capacity) + 1 : 4;


        }
        memmove(this->_str + pos + 1, this->_str + pos, this->_size - pos+1);
        this->_str[pos] = ch;
        _size++;
        
    }
    void insert(size_t pos, const char* str)
    {

        size_t len = strlen(str);
        if (this->_size == this->_capacity)
        {
            char* tmp = new char[this->_capacity ? 2 * (this->_capacity) + 1 : 4];
            // char* tmp = new char[ 2 * (_capacity)+1];


            strcpy(tmp, this->_str);

            delete[] this->_str;
            this->_str = tmp;
            this->_capacity = this->_capacity ? 2 * (this->_capacity) + 1 : 4;


        }
        memmove(this->_str + pos + len, this->_str + pos, len + 1);
        memmove(this->_str + pos ,str, len );
        _size+=len;
    
    
    }
    void erase(size_t pos, size_t len = npos)
    {
        if (len == npos)
            _str[pos] = '\0';

        memmove(_str + pos,_str+pos+len, _size-len-pos+1);
        _size -= len;
    
    }

    size_t find(char ch, size_t pos = 0)//从0这个位置开始查
    {
        char* now = _str + pos;
        size_t count = 0;
        while (*now != '\0')
        {
            if (*now == ch)
                return count+pos;
            else
            {
                count++;
                now++;
            }


        }
        return npos;
    
    
    }

        
        size_t find(const char* str, size_t pos = 0);

        bool operator<(const string& s)
        {
            return !strcmp(this->_str, s._str);
        
        }
    bool operator<=(const string& s);
    bool operator>(const string& s);
    bool operator>=(const string& s);
    bool operator==(const string& s);
    bool operator!=(const string& s);
    void test1()
    {
       
        string s("hello");

        string s2("hello");

       
      //  cout << s.size() << endl;
       // s.push_back('w');
        //s.append(" world");

       /* s+=" world";*/
        //s += 's';
       //cout << s.capacity()<<endl;
        s.insert(5, " world");
        //s.erase(5, 5);

       // cout << s.find('w', 5) << endl;
        cout << (s < s2) << endl;

            for (auto ch : s)
        {

            cout << ch ;

        }
    }



private:
    char* _str;
    size_t _size;
    size_t _capacity;
    static size_t npos;

};

     istream& operator<< (istream& cin,  string& s);
   ostream& operator<< (ostream& cout, const string &s);

size_t string::npos = -1;

}
