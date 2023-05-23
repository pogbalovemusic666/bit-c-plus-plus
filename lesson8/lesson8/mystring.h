#pragma once

#pragma warning(disable:4996)
#include <iostream>

//using std::istream;
//using std::ostream;
//using std::cout;

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
        :_str(new char[strlen(str) + 1])
    {
       
        strcpy(_str, str);
        _size = strlen(str);
        _capacity = _size;
       
    }


    string(const string &s2)
        :_str(new char[strlen(s2._str) + 1])
    {
        strcpy(_str, s2._str);
        this->_size = strlen(s2._str);
        this->_capacity = this->_size;
    
    }
    string& operator=(const string& s);


    
    ~string()
    {
        delete[]_str;
        _size = 0;
        _capacity = 0;

    
    
    }

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
            
            _capacity = n;
            _str[n] = '\0';
        }
    
    
    }

    void resize(size_t n,char ch)
    {
        if (n < _size)
        {
            _str[n] = '\0';

        }
        else
        {
            if (n >= _capacity)
            {
                this->reserve(n);
                while (this->_size != n)
                {
                    _str[_size] = ch;
                    _size++;


                }
                _str[_size] = '\0';
                _capacity = n;
            }


        }
    
    
    }

    void push_back(const char ch)
    {
        if (_size == _capacity)
        {
            char* tmp = new char[_size + 2];
            strcpy(tmp, _str);
            delete[] _str;
            _str = tmp;
          _capacity = _size + 1;


        }
        _str[_size] = ch;

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
        if (len >= _size - pos)
        {

            _str[pos] = '\0';
            _size = pos;

        }
            

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

        
    size_t find(const char* str, size_t pos = 0)
    {
        char*p=strstr(_str, str);
        if (p == nullptr)
            return npos;
        else
        {
            return (p - _str);

        }
    
    }

        bool operator<(const string& s)
        {
            return strcmp(this->_str, s._str)<0;
        
        }
        bool operator<=(const string& s)
        {
            return *this < s || *this == s;
        
        }
        bool operator>(const string& s)
        {
            return !(*this < s) && !(*this == s);
        }
        bool operator>=(const string& s)
        {
            return (*this > s) || (*this == s);
        }
    bool operator==(const string& s)
    {
        return strcmp(this->_str, s._str) == 0;
    
    }
    bool operator!=(const string& s)
    {
    
        return  !(*this == s);
    
    }
    void test1()
    {
       
        string s("hello");

        string s2("hello");
        s.resize(10, 'y');
        //s.reserve(10);
      //  cout << s.size() << endl;
       // s.push_back('w');
        //s.append(" world");

       /* s+=" world";*/
        //s += 's';
       //cout << s.capacity()<<endl;
        //s.insert(5, " world");
        //s.erase(5, 5);

       // cout << s.find('w', 5) << endl;
        cout << (s >= s2) << endl;
        cout<<s.find("ll", 0)<<endl;
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

istream& operator<< (istream& cin, string& s)
{

    while (1)
    {
        char ch;
        ch=cin.get();
        if (ch == ' ' || ch == '\n')
        {
            break;
        }
        else
        {
            s += ch;
        }
        return cin;
    }

}
     ostream& operator<< (ostream& cout, const string& s)
     {

         for (int i = 0; i < s.size(); i++)
         {

             cout << s[i];
         }
         
         return cout;
     
     }

size_t string::npos = -1;

}
