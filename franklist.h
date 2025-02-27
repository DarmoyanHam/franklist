#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

#include <iostream>

namespace vhuk {

template <typename T>
class FrankList;

template <typename T>
std::ostream& operator<<(std::ostream& out, const FrankList<T>& rhv);

template <typename T>
class FrankList
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using size_type = std::size_t;
    using pointer = value_type*;
    using const_pointer = const value_type*;
private:
    struct Node
    {
        T val;
        Node* next;
        Node* prev;
        Node* asc;
        Node* desc;
        Node();
        Node(T val);
    };
private:
    class base_iterator
    {
        friend FrankList<value_type>;
    public:
        ~base_iterator();
        bool operator==(const base_iterator& rhv) const; 
        bool operator!=(const base_iterator& rhv) const; 
    protected:
        explicit base_iterator(Node* ptr); 
    protected:
        Node* ptr = nullptr;
    };
public:
    class const_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_iterator(const base_iterator& rhv); 
        const_iterator(base_iterator&& rhv); 
        
        const const_iterator& operator=(const base_iterator& rhv); 
        const const_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_iterator& operator++(); 
        const const_iterator operator++(value_type); 
        const const_iterator& operator--(); 
        const const_iterator operator--(value_type); 

    protected:
        explicit const_iterator(Node* ptr); 
    };

public:
    class iterator : public const_iterator
    {
        friend FrankList<value_type>;
    public:
        iterator(const base_iterator& rhv); 
        iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->();

        const iterator& operator=(const base_iterator& rhv); 
        const iterator& operator=(base_iterator&& rhv); 
    protected:
        explicit iterator(Node* ptr); 
    };

public:
    class const_reverse_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_reverse_iterator(const base_iterator& rhv); 
        const_reverse_iterator(base_iterator&& rhv); 
        
        const const_reverse_iterator& operator=(const base_iterator& rhv); 
        const const_reverse_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_reverse_iterator& operator++(); 
        const const_reverse_iterator operator++(value_type); 
        const const_reverse_iterator& operator--(); 
        const const_reverse_iterator operator--(value_type); 

    protected:
        explicit const_reverse_iterator(Node* ptr); 
    };
    
public:
    class reverse_iterator : public const_reverse_iterator
    {
        friend FrankList<value_type>;
    public:
        reverse_iterator(const base_iterator& rhv); 
        reverse_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const reverse_iterator& operator=(const base_iterator& rhv); 
        const reverse_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit reverse_iterator(Node* ptr); 
    };

public:
    class const_asc_iterator :public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_asc_iterator(const base_iterator& rhv); 
        const_asc_iterator(base_iterator&& rhv); 
        
        const const_asc_iterator& operator=(const base_iterator& rhv); 
        const const_asc_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_asc_iterator& operator++(); 
        const const_asc_iterator operator++(value_type); 
        const const_asc_iterator& operator--(); 
        const const_asc_iterator operator--(value_type); 

    protected:
        explicit const_asc_iterator(Node* ptr); 
    };
public:
    class asc_iterator : public const_asc_iterator
    {
        friend FrankList<value_type>;
    public:
        asc_iterator(const base_iterator& rhv); 
        asc_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const asc_iterator& operator=(const base_iterator& rhv); 
        const asc_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit asc_iterator(Node* ptr); 
    };

public:
    class const_desc_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_desc_iterator(const base_iterator& rhv); 
        const_desc_iterator(base_iterator&& rhv); 
        
        const const_desc_iterator& operator=(const base_iterator& rhv); 
        const const_desc_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_desc_iterator& operator++(); 
        const const_desc_iterator operator++(value_type); 
        const const_desc_iterator& operator--(); 
        const const_desc_iterator operator--(value_type); 

    protected:
        explicit const_desc_iterator(Node* ptr); 
    };
public:
    class desc_iterator : public const_desc_iterator
    {
        friend FrankList<value_type>;
    public:
        desc_iterator(const base_iterator& rhv); 
        desc_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const desc_iterator& operator=(const base_iterator& rhv); 
        const desc_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit desc_iterator(Node* ptr); 
    };

public:
    class const_multi_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_multi_iterator(const base_iterator& rhv); 
        const_multi_iterator(base_iterator&& rhv); 
        
        const const_multi_iterator& operator=(const base_iterator& rhv); 
        const const_multi_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_multi_iterator& operator++(); 
        const const_multi_iterator operator++(value_type); 
        const const_multi_iterator& operator--(); 
        const const_multi_iterator operator--(value_type); 

        void chmod(); 
    protected:
        explicit const_multi_iterator(Node* ptr); 
        bool mode = true;
    };
public:
    class multi_iterator : public const_multi_iterator
    {
        friend FrankList<value_type>;
    public:
        multi_iterator(const base_iterator& rhv); 
        multi_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const multi_iterator& operator=(const base_iterator& rhv); 
        const multi_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit multi_iterator(Node* ptr); 
    };

public:
    class const_multi_reverse_iterator : public base_iterator
    {
        friend FrankList<value_type>;
    public:
        const_multi_reverse_iterator(const base_iterator& rhv); 
        const_multi_reverse_iterator(base_iterator&& rhv); 
        
        const const_multi_reverse_iterator& operator=(const base_iterator& rhv); 
        const const_multi_reverse_iterator& operator=(base_iterator&& rhv); 
        const_reference operator*() const; 
        const_pointer operator->() const; 

        const const_multi_reverse_iterator& operator++(); 
        const const_multi_reverse_iterator operator++(value_type); 
        const const_multi_reverse_iterator& operator--(); 
        const const_multi_reverse_iterator operator--(value_type); 


        void chmod(); 
    protected:
        explicit const_multi_reverse_iterator(Node* ptr);
        bool mode = true;
    };
public:
    class multi_reverse_iterator : public const_multi_reverse_iterator
    {
        friend FrankList<value_type>;
    public:
        multi_reverse_iterator(const base_iterator& rhv); 
        multi_reverse_iterator(base_iterator&& rhv); 

        reference operator*(); 
        pointer operator->(); 

        const multi_reverse_iterator& operator=(const base_iterator& rhv); 
        const multi_reverse_iterator& operator=(base_iterator&& rhv); 
        
    protected:
        explicit multi_reverse_iterator(Node* ptr); 
    };

public:
    FrankList(); 
    FrankList(size_type size); 
    FrankList(size_type size, const_reference init); 
    FrankList(const FrankList<value_type>& rhv); 
    FrankList(FrankList<value_type>&& rhv); 
    FrankList(std::initializer_list<value_type> init); 
    template <typename input_iterator>
    FrankList(input_iterator f, input_iterator l); 
    ~FrankList();
public:
    void swap(FrankList<value_type>& rhv); 

    size_type size() const; 

    bool empty() const; 
    void resize(size_type s, const_reference init = value_type()); 
    void clear() noexcept; 

    void push_front(const_reference elem); 
    void pop_front(); 
    void push_back(const_reference elem); 
    void pop_back(); 

    const_reference front() const; 
    reference front(); 
    const_reference back() const; 
    reference back(); 
    const_reference min() const; 
    reference min(); 
    const_reference max() const; 
    reference max();

    const FrankList<value_type>& operator=(const FrankList<value_type>& rhv); 
    const FrankList<value_type>& operator=(FrankList<value_type>&& rhv); 
    const FrankList<value_type>& operator=(std::initializer_list<value_type> init); 

    bool operator==(const FrankList<value_type>& rhv) const; 
    bool operator!=(const FrankList<value_type>& rhv) const; 
    bool operator<(const FrankList<value_type>& rhv) const; 
    bool operator<=(const FrankList<value_type>& rhv) const; 
    bool operator>(const FrankList<value_type>& rhv) const; 
    bool operator>=(const FrankList<value_type>& rhv) const; 

public:
    const_iterator cbegin() const; 
    const_iterator cend() const; 
    const_reverse_iterator crbegin() const; 
    const_reverse_iterator crend() const; 
    const_asc_iterator cabegin() const; 
    const_asc_iterator caend() const; 
    const_desc_iterator cdbegin() const; 
    const_desc_iterator cdend() const; 
    const_multi_iterator cmbegin() const; 
    const_multi_iterator cmend() const; 
    const_multi_iterator cmabegin() const; 
    const_multi_iterator cmaend() const; 
    const_multi_reverse_iterator cmrbegin() const; 
    const_multi_reverse_iterator cmrend() const; 
    const_multi_reverse_iterator cmrdbegin() const; 
    const_multi_reverse_iterator cmrdend() const; 

    iterator begin(); 
    iterator end(); 
    reverse_iterator rbegin(); 
    reverse_iterator rend(); 
    asc_iterator abegin(); 
    asc_iterator aend(); 
    desc_iterator dbegin(); 
    desc_iterator dend(); 
    multi_iterator mbegin(); 
    multi_iterator mend();
    multi_iterator mabegin(); 
    multi_iterator maend(); 
    multi_reverse_iterator mrbegin(); 
    multi_reverse_iterator mrend(); 
    multi_reverse_iterator mrdbegin(); 
    multi_reverse_iterator mrdend(); 

public:
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_iterator, iter>::value ||
                              std::is_base_of<const_asc_iterator, iter>::value ||
                              std::is_base_of<const_multi_iterator, iter>::value, 
             iter>::type
    insert(iter pos, const_reference val) { 
        return insert_def(pos, val);
    }
    
    template <typename iter>
    typename std::enable_if<std::is_base_of<const_reverse_iterator, iter>::value ||
                              std::is_base_of<const_desc_iterator, iter>::value ||
                              std::is_base_of<const_multi_reverse_iterator, iter>::value,
             iter>::type
    insert(iter pos, const_reference val) { 
        return insert_rev(pos, val);
    }

    template <typename iter>
    iter insert(iter pos, size_type size, const_reference val); 
    template <typename iter>
    iter insert(iter pos, std::initializer_list<value_type> init); 
    template <typename iter, typename input_iterator>
    iter insert(iter pos, input_iterator f, input_iterator l);

    template <typename iter>
    iter erase(iter pos); 
    template <typename iter>
    iter erase(iter f, iter l); 

    size_type remove(const_reference val); 
    template <typename unary_predicate>
    size_type remove_if(unary_predicate func); 

    void reverse(); 
    void sort(bool reversed = false); 

    iterator find(const_reference elem); 
    iterator rfind(const_reference elem); 

    template <typename unary_predicate>
    void traverse(unary_predicate func, bool sorted = false, bool reversed = false); 

    void print(bool sorted = false, bool reversed = false); 

protected:
    void put_in_sorted_order(Node* ptr); 
    void organize_left(Node* ptr); 
    void organize_right(Node* ptr); 
private:
    template <typename iter>
    iter insert_def(iter pos, const_reference val);
    
    template <typename iter>
    iter insert_rev(iter pos, const_reference val);

private:
    Node* head;
    Node* tail;
    Node* ahead;
    Node* atail;
};


}

#include "franklist.hpp"

#endif 
