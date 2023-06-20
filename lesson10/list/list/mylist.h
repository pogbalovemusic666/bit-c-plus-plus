#pragma once



#include <assert.h>
namespace jhx
{
	//// 适配器 -- 复用
	//template<class Iterator, class Ref, class Ptr>
	//struct Reverse_iterator
	//{
	//	Iterator _it;
	//};
	//// vector和list反向迭代器实现






        // List的节点类
        template<class T>
        struct ListNode
        {
            ListNode(const T& val = T())
                :_data (val)
                ,_prev(nullptr)
                ,_next(nullptr)
            {}
            ListNode<T>* _prev;
            ListNode<T>* _next;
            T _data;
        };


        ////List的迭代器类
        template<class T, class Ref, class Ptr>
        class ListIterator
        {
            typedef ListNode<T>* PNode;
            typedef ListIterator<T, Ref, Ptr> Self;
        public:
            ListIterator(PNode pNode = nullptr)
                :_node(pNode)
            {
            }
            ListIterator(const Self& l)
            {
                this->_node = l._node;


            
            }
            T& operator*()
            {
                return _node->_data;
            }
            T* operator->()
            {
                //return &(_node->_data);
                return &(operator*());
            }
            Self& operator++()
            {
                _node = _node->_next;
                return *this;
            }
            Self operator++(int)
            {
                Self tmp(*this);
                _node = _node->_next;
                return tmp;
            }
            Self& operator--()
            {
                _node = _node->_prev;
                return *this;
            
            }
            Self& operator--(int)
            {
                Self tmp(*this);
                _node = _node->_prev;
                return tmp;
            }
            bool operator!=(const Self& l)
            {
                return _node != l._node;
            
            }
            bool operator==(const Self& l)
            {
            
                return _node == l._node;
            }
       // private:
            PNode _node;
        };


        //list类
        template<class T>
        class list
        {
            typedef ListNode<T> Node;
            typedef Node* PNode;
        public:
            typedef ListIterator<T, T&, T*> iterator;
            typedef ListIterator<T, const T&, const T&> const_iterator;
        public:
            ///////////////////////////////////////////////////////////////
            // List的构造
            list()
            {
                _phead = new Node;
                _phead->_next = _phead;
                _phead->_prev = _phead;
            }
            list(int n, const T& value = T())
            {
                _phead = new Node;
                _phead->_next = _phead;
                _phead->_prev = _phead;
                while (n--)
                    push_back(value);
            }


            //template <class Iterator>
            //list(Iterator first, Iterator last);
            list( list<T>& l)
            {

                _phead = new Node;
                _phead->_next = _phead;
                _phead->_prev = _phead;


                jhx::list<T>::iterator it = l.begin();
                while (it != l.end())
                {
                    push_back(*it);
                    it++;
                }

            
            }




            //list<T>& operator=(const list<T> l)
            //{
            //    _phead = new Node;
            //    _phead->_next = _phead;
            //    _phead->_prev = _phead;
            //
            //    jhx::list<int>::const_iterator it = l.begin();

            //    //cout << *it;
            //    //jhx::list<int>::iterator it1(it);
            //    while (it != l.end())
            //    {
            //       
            //        push_back(*it);
            //        ++it;

            //    }
            //    return *this;

            //}


            ~list()
            {

                delete _phead;
                
                _phead->_next= nullptr;
                _phead->_prev= nullptr;
                _phead = nullptr;
            }


         //   ///////////////////////////////////////////////////////////////
         //   // List Iterator
            iterator begin()
            {
                return iterator(_phead->_next);
            
            }
            iterator end()
            {
            return iterator(_phead);
            }

            const_iterator begin() const
            {
            
                return const_iterator(_phead->_next);
            }

            const_iterator end()const
            {
                return const_iterator(_phead);
            }


         //   ///////////////////////////////////////////////////////////////
            // List Capacity
            size_t size()const
            {
                jhx::list<T>::const_iterator it = this->begin();
                size_t ret = 0;
                    //cout << *it;
                    //jhx::list<int>::iterator it1(it);
                    while (it != this->end())
                    {
                       
                        ret++;
                        ++it;

                    }
                    return ret;
            
            }
            bool empty()const
            {
                if (_phead->_next == _phead)
                    return true;
                else
                    return false;
            
            }


            ////////////////////////////////////////////////////////////
            // List Access
            T& front()
            {
                return _phead->_next->_data;
            
            }
            const T& front()const
            {
            
                return _phead->_next->_data;
            }
            T& back()
            {
                return _phead->_prev->_data;
            }
            const T& back()const
            {
                return _phead->_prev->_data;
            
            }


         //   ////////////////////////////////////////////////////////////
         //   // List Modify

            //void push_back(const T& val)
            //{
            //

            //    PNode newnode = new Node;
            //    PNode tail = _phead->_prev;
            //    tail->_next = newnode;
            //    newnode->_prev = tail;
            //    _phead->_prev = newnode;
            //    newnode->_next = _phead;
            //    newnode->_data = val;
            //
            //
            //}
           //void pop_back()
           // {
           //    PNode newtail = _phead->_prev->_prev;
           //    PNode dele = _phead->_prev;

           //    newtail->_next = _phead;
           //    _phead->_prev = newtail;
           //    delete dele;
           //     
           // }
            void push_front(const T& val) 
            {
                insert(begin(), val);
            }
            void pop_front() 
            {
                erase(begin()); 
            }

            void push_back(const T& val) { insert(end(), val); }
            void pop_back() { erase(--end()); }
          
          
       
             //在pos位置前插入值为val的节点
           iterator insert(iterator pos, const T& val)
           {
               PNode newnode = new Node(val);
               PNode cur = pos._node;
             
               PNode prev = cur->_prev;


               prev->_next = newnode;
               newnode->_prev = prev;
               newnode->_next = cur;
               cur->_prev = newnode;
               return iterator(newnode);

             

           }
            // 删除pos位置的节点，返回该节点的下一个位置
           iterator erase(iterator pos)
           {
           
               assert(pos != end());
               PNode cur = pos._node;

               PNode prev = cur->_prev;
               PNode next = cur->_next;

               prev->_next = next;
               next->_prev = prev;
               delete cur;
               return iterator(next);


 
           }
           void clear()
           {

               while (!empty())
                   pop_back();
           
           }
           void swap(list<T>& l)
           {
               list<T> tmp(l);
               l.clear();

               jhx::list<T>::iterator it = this->begin();
               while (it != this->end())
               {
                    l.push_back(*it);
                    it++;
               }
               this->clear();

               jhx::list<T>::iterator it1 = tmp.begin();
               while (it1 != tmp.end())
               {
                   this->push_back(*it1);
                   it1++;
               }
           
           }
        private:
            //void CreateHead();
            PNode _phead;
        };
    


        void test1()
        {
            list<int> ls;
            ls.push_back(1);
            ls.push_back(2);
            ls.push_back(3);
            ls.push_back(4);
            ls.pop_back();
            
           // ls.clear();

            
                list<int> ls1;
                ls.swap(ls1);

                //cout << ls.front();
            //ls1 = ls;
        jhx::list<int>::iterator it = ls1.begin();
   
       /* ls.insert(it, 7);
        it++;
        it = ls.erase(it);*/
        //    //cout << *it;
        //    //jhx::list<int>::iterator it1(it);
            while (it != ls1.end())
            {
                cout <<*it;
                ++it;

            }
        //    /*cout << *it;
        //    it--;*/
        //    ls1.pop_back();

        }








}



