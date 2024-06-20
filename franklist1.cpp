#include <iostream>
#include "franklist.h"

namespace vhuk {

template <typename T>
FrankList<T>::Node::Node()
: next(nullptr)
, prev(nullptr)
, asc(nullptr)
, desc(nullptr)
{}

template <typename T>
FrankList<T>::Node::Node(T val)
: val(val)
, next(nullptr)
, prev(nullptr)
, asc(nullptr)
, desc(nullptr)
{}

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node* ptr)
: ptr(ptr)
{}

template <typename T>
FrankList<T>::base_iterator::~base_iterator() 
{}

template <typename T>
bool FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const {
    return ptr == rhv.ptr;
}

template <typename T>
bool FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const {
    return ptr!= rhv.ptr;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv) 
: base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv.ptr))
{}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference& FrankList<T>::const_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_iterator::operator->() const
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator++()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->next;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator++(value_type)
{
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_iterator& FrankList<T>::const_iterator::operator--()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->prev;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_iterator FrankList<T>::const_iterator::operator--(value_type)
{
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::iterator::iterator(Node* ptr)
: const_iterator(ptr)
{}

template <typename T>
FrankList<T>::iterator::iterator(const base_iterator& rhv)
: const_iterator(rhv)
{}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator&& rhv)
: const_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::iterator& FrankList<T>::iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv)
: base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv))
{}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_reverse_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_reverse_iterator::operator->() const
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator++()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->prev;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator++(value_type)
{
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator& FrankList<T>::const_reverse_iterator::operator--()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->next;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator FrankList<T>::const_reverse_iterator::operator--(value_type)
{
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr)
: const_reverse_iterator(ptr)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv)
: const_reverse_iterator(rhv)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv)
: const_reverse_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::reference FrankList<T>::reverse_iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::reverse_iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::reverse_iterator& FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv)
: base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv))
{}

template <typename T>
const typename FrankList<T>::const_asc_iterator&  FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_asc_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_asc_iterator::operator->() const
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator++()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->asc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator++(value_type)
{
    const_asc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator& FrankList<T>::const_asc_iterator::operator--()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->desc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_asc_iterator FrankList<T>::const_asc_iterator::operator--(value_type)
{
    const_asc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(Node* ptr)
: const_asc_iterator(ptr)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv)
: const_asc_iterator(rhv)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv)
: const_asc_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::reference FrankList<T>::asc_iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::asc_iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::asc_iterator& FrankList<T>::asc_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv)
: base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv))
{}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_desc_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_desc_iterator::operator->() const
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator++()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->desc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator++(value_type)
{
    const_desc_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator& FrankList<T>::const_desc_iterator::operator--()
{
    if(this->ptr)
    {
        this->ptr = this->ptr->asc;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_desc_iterator FrankList<T>::const_desc_iterator::operator--(value_type)
{
    const_desc_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node* ptr)
: const_desc_iterator(ptr)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv)
: const_desc_iterator(rhv)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv)
: const_desc_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::reference FrankList<T>::desc_iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::desc_iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::desc_iterator& FrankList<T>::desc_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& rhv)
: base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv))
{}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_multi_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_multi_iterator::operator->() const
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator++()
{
    if(this->ptr)
    {
        if(mode)
        {
            this->ptr = this->ptr->next;
        }
        else
        {
            this->ptr = this->ptr->asc;
        }
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator++(value_type)
{
    const_multi_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator& FrankList<T>::const_multi_iterator::operator--()
{
    if(this->ptr)
    {
        if(mode)
        {
            this->ptr = this->ptr->prev;
        }
        else
        {
            this->ptr = this->ptr->desc;
        }
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_iterator FrankList<T>::const_multi_iterator::operator--(value_type)
{
    const_multi_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
void FrankList<T>::const_multi_iterator::chmod()
{
    mode = !mode;
}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(Node* ptr)
: const_multi_iterator(ptr)
{}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(const base_iterator& rhv)
: const_multi_iterator(rhv)
{}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(base_iterator&& rhv)
: const_multi_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::reference FrankList<T>::multi_iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::multi_iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::multi_iterator& FrankList<T>::multi_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr)
: base_iterator(ptr)
{}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv)
: base_iterator(rhv)
{}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv)
: base_iterator(std::move(rhv))
{}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::const_multi_reverse_iterator::operator*() const
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::const_pointer FrankList<T>::const_multi_reverse_iterator::operator->() const
{
    if(this->ptr)
    {
        return *(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator++()
{
    if(this->ptr)
    {
        if(mode)
        {
            this->ptr = this->ptr->prev;
        }
        else
        {
            this->ptr = this->ptr->desc;
        }
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator++(value_type)
{
    const_multi_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator& FrankList<T>::const_multi_reverse_iterator::operator--()
{
    if(this->ptr)
    {
        if(mode)
        {
            this->ptr = this->ptr->next;
        }
        else
        {
            this->ptr = this->ptr->asc;
        }
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::const_multi_reverse_iterator::operator--(value_type)
{
    const_multi_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T>
void FrankList<T>::const_multi_reverse_iterator::chmod()
{
    mode = !mode;
}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* ptr)
: const_multi_reverse_iterator(ptr)
{}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv)
: const_multi_reverse_iterator(rhv)
{}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv)
: const_multi_reverse_iterator(std::move(rhv))
{}

template <typename T>
typename FrankList<T>::reference FrankList<T>::multi_reverse_iterator::operator*()
{
    if(this->ptr)
    {
        return this->ptr->val;
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
typename FrankList<T>::pointer FrankList<T>::multi_reverse_iterator::operator->()
{
    if(this->ptr)
    {
        return &(this->ptr->val);
    }
    else
    {
        throw std::out_of_range("ptr is null");
    }
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(const base_iterator& rhv)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator& FrankList<T>::multi_reverse_iterator::operator=(base_iterator&& rhv)
{
    this->ptr = std::move(rhv.ptr);
    return *this;
}

template <typename T>
FrankList<T>::FrankList()
: head(nullptr)
, tail(nullptr)
, ahead(nullptr)
, atail(nullptr)
{}

template <typename T>
FrankList<T>::FrankList(size_type size)
{
    this->head = new Node;
    this->tail = this->head;
    this->atail = this->head;
    this->ahead = this->head;
    for(int i = 0; i < size - 1; ++i)
    {
        Node* newNode = new Node;
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->atail->asc = newNode;
        newNode->desc = this->atail;
        this->atail = newNode;
    }
}

template <typename T>
FrankList<T>::FrankList(size_type size, const_reference init)
{
    this->head = new Node(init);
    this->tail = this->head;
    this->atail = this->head;
    this->ahead = this->head;
    for(int i = 0; i < size - 1; ++i)
    {
        Node* newNode = new Node(init);
        this->tail->next = newNode;
        newNode->prev = this->tail;
        this->tail = newNode;
        this->atail->asc = newNode;
        newNode->desc = this->atail;
        this->atail = newNode;
    }
}

template <typename T>
FrankList<T>::FrankList(const FrankList& rhv)
{
    Node* current = rhv.head;
    while(current)
    {
        push_back(current.val);
        current = current->next;
    }
}

template <typename T>
FrankList<T>::FrankList(FrankList&& rhv)
: head(std::move(rhv.head))
, tail(std::move(rhv.tail))
, ahead(std::move(rhv.ahead))
, atail(std::move(rhv.atail))
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}

template <typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init)
{
    for(auto i = init.begin(); i < init.end(); ++i)
    {
        push_back(*i);
    }
}

template <typename T>
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)
{
    while(f != l)
    {
        push_back(*f);
        ++f;
    }
}

template <typename T>
FrankList<T>::~FrankList()
{
    clear();
}

template <typename T>
void FrankList<T>::swap(FrankList<value_type>& rhv)
{
    std::swap(this->head, rhv.head);
    std::swap(this->tail, rhv.tail);
    std::swap(this->ahead, rhv.ahead);
    std::swap(this->atail, rhv.atail);
}

template <typename T>
void FrankList<T>::resize(size_type s, const_reference init)
{
    size_type sz = size();
    if(s < sz)
    {
        for(size_type i = 0; i < sz - s; ++i)
        {
            pop_back();
        }
    }
    else
    {
        for(size_type i = 0; i < s - sz; ++i)
        {
            push_back(init);
        }
    }
}

template <typename T>
bool FrankList<T>::empty() const
{
    return head==nullptr;
}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::size() const
{
    size_type s = 0;
    Node* node = this->head;
    while(node)
    {
        ++s;
        node = node->next;
    }
    return s;
}

template <typename T>
void FrankList<T>::clear() noexcept
{
    while(!(empty()))
    {
        pop_back();
    }
}

template <typename T>
void FrankList<T>::push_front(const_reference elem)
{
    if(!(this->head))
    {
        push_back(elem);
    }
    else
    {
        Node* node = new Node(elem);
        this->head->prev = node;
        node->next = this->head;
        this->head = node;
        put_in_sorted_order(node);
    }
}

template <typename T>
void FrankList<T>::push_back(const_reference elem)
{
    Node* node = new Node(elem);
    if(!(this->head))
    {
        this->head = node;
        this->tail = node;
        this->atail = node;
        this->ahead = node;
    }
    else
    {
        this->tail->next = node;
        node->prev = this->tail;
        this->tail = node;
        put_in_sorted_order(node);
    }
}

template <typename T>
void FrankList<T>::pop_front()
{
    Node* node = this->head;
    this->head = this->head->next;
    if(this->head)
    {
        this->head->prev = nullptr;
        if(node == ahead)
        {
            node->asc->desc = nullptr;
        }
        else if(node == atail)
        {
            node->desc->asc = nullptr;
        }
        else
        {
            node->asc->desc = node->desc;
            node->desc->asc = node->asc;
        }
    }
    else
    {
        this->tail = nullptr;
    }

    delete node;
}

template <typename T>
void FrankList<T>::pop_back()
{
    Node* node = this->tail;
    this->tail = this->tail->prev;
    if(this->tail)
    {
        this->tail->next = nullptr;
        if(node == ahead)
        {
            node->asc->desc = nullptr;
        }
        else if(node == atail)
        {
            node->desc->asc = nullptr;
        }
        else
        {
            node->asc->desc = node->desc;
            node->desc->asc = node->asc;
        }
    }
    else
    {
        this->head = nullptr;
    }

    delete node;
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::front() const
{
    if(!(empty()))
    {
        return this->head->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::front()
{
    if(!(empty()))
    {
        return this->head->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::back() const
{
    if(!(empty()))
    {
        return this->tail->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::back()
{
    if(!(empty()))
    {
        return this->tail->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::min() const
{
    if(!(empty()))
    {
        return this->atail->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::min()
{
    if(!(empty()))
    {
        return this->ahead->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::const_reference FrankList<T>::max() const
{
    if(!(empty()))
    {
        return this->atail->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
typename FrankList<T>::reference FrankList<T>::max()
{
    if(!(empty()))
    {
        return this->atail->val;
    }
    else
    {
        throw std::out_of_range("list is empty");
    }
}

template <typename T>
const typename FrankList<T>::FrankList<T>& FrankList<T>::operator=(const FrankList<value_type>& rhv)
{
    if(this != &rhv)
    {
        clear();

        for(iterator i = rhv.begin(); i != rhv.end(); ++i)
        {
            push_back(*i);
        }
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::FrankList<T>&  FrankList<T>::operator=(FrankList<value_type>&& rhv)
{
    if(this != &rhv)
    {
        clear();
        
        this->head = rhv.head;
        this->tail = rhv.tail;
        this->ahead = rhv.ahead;
        this->atail = rhv.atail;

        rhv.head = nullptr;
        rhv.tail = nullptr;
        rhv.ahead = nullptr;
        rhv.atail = nullptr;
    }
    return *this;
}

template <typename T>
const typename FrankList<T>::FrankList<T>& FrankList<T>::operator=(std::initializer_list<value_type> init)
{
    clear();
    for(auto i = init.begin(); i < init.end(); ++i)
    {
        push_back(*i);
    }
    return *this;
}

template <typename T>
bool FrankList<T>::operator==(const FrankList<T>& rhv) const
{
    if(size() == rhv.size())
    {
        return false;
    }
    auto it = rhv.begin();
    for(iterator i = begin(); i != end(); ++i)
    {
        if(*i != *it)
        {
            return false;
        }
        ++it;
    }
    return true;
}

template <typename T>
bool FrankList<T>::operator!=(const FrankList<T>& rhv) const
{
    if(size() != rhv.size())
    {
        return true;
    }
    auto it = rhv.begin();
    for(iterator i = begin(); i != end(); ++i)
    {
        if(*i != *it)
        {
            return true;
        }
        ++it;
    }
    return false;
}

template <typename T>
bool FrankList<T>::operator<(const FrankList<T>&rhv) const
{
    auto it1 = begin();
    auto it2 = rhv.begin();
    while(it1 != nullptr && it2 != nullptr)
    {
        if(*it1 < *it2)
        {
            return true;
        }
        else if(*it2 < *it1)
        {
            return false;
        }

        ++it1;
        ++it2;
    }

    if(it1 == end() && it2 != rhv.end())
    {
        return true;
    }
    
    return false;
}

template <typename T>
bool FrankList<T>::operator<=(const FrankList<T>&rhv) const
{
    return (*this < rhv || *this == rhv);
}

template <typename T>
bool FrankList<T>::operator>(const FrankList<T>&rhv) const
{
    return !(*this <= rhv);
}

template <typename T>
bool FrankList<T>::operator>=(const FrankList<T>&rhv) const
{
    return (*this > rhv || *this == rhv);
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const
{
    return const_iterator(this->head);
}

template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const
{
    return const_iterator(this->tail->next);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const
{
    return const_reverse_iterator(this->tail);
}

template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const
{
    return const_reverse_iterator(this->head->prev);
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const
{
    return const_asc_iterator(this->ahead);
}

template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const
{
    return const_asc_iterator(this->atail->asc);
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const
{
    return const_desc_iterator(this->atail);
}

template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const
{
    return const_desc_iterator(this->ahead->desc);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmbegin() const
{
    return const_multi_iterator(this->head);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmend() const
{
    return const_multi_iterator(this->tail->next);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrbegin() const
{
    return const_multi_reverse_iterator(this->tail);
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrend() const
{
    return const_multi_reverse_iterator(this->head->prev);
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmabegin() const
{
    const_multi_iterator it(this->ahead);
    it.chmod();
    return it;
}

template <typename T>
typename FrankList<T>::const_multi_iterator FrankList<T>::cmaend() const
{
    const_multi_iterator it(this->atail->asc);
    it.chmod();
    return it;
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdbegin() const
{
    const_multi_reverse_iterator it(this->atail);
    it.chmod();
    return it;
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator FrankList<T>::cmrdend() const
{
    const_multi_reverse_iterator it(this->ahaed->desc);
    it.chmod();
    return it;
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::begin()
{
    return iterator(this->head);
}

template <typename T>
typename FrankList<T>::iterator FrankList<T>::end()
{
    return iterator(this->tail->next);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rbegin()
{
    return reverse_iterator(this->tail);
}

template <typename T>
typename FrankList<T>::reverse_iterator FrankList<T>::rend()
{
    return reverse_iterator(this->head->prev);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::abegin()
{
    return asc_iterator(this->ahead);
}

template <typename T>
typename FrankList<T>::asc_iterator FrankList<T>::aend()
{
    return asc_iterator(this->atail->asc);
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dbegin()
{
    return desc_iterator(this->atail);
}

template <typename T>
typename FrankList<T>::desc_iterator FrankList<T>::dend()
{
    return desc_iterator(this->ahead->desc);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mbegin()
{
    return multi_iterator(this->head);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mend()
{
    return multi_iterator(this->tail->next);
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::mabegin()
{
    multi_iterator i(this->ahead);
    i.chmod();
    return i;
}

template <typename T>
typename FrankList<T>::multi_iterator FrankList<T>::maend()
{
    multi_iterator i(this->atail->asc);
    i.chmod();
    return i;
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrbegin()
{
    return multi_iterator(this->tail);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrend()
{
    return multi_iterator(this->head->prev);
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdbegin()
{
    multi_iterator i(this->atail);
    i.chmod();
    return i;
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator FrankList<T>::mrdend()
{
    multi_iterator i(this->head->desc);
    i.chmod();
    return i;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_def(iter pos, const_reference val)
{
    Node* node = new Node(val);
    if(!(pos.ptr))
    {
        push_back(val);
    }
    else
    {
        node->next = pos.ptr;
        node->prev = pos.ptr->prev;
        if(pos.ptr->prev)
        {
            pos.ptr->prev->next = node;
        }
        else
        {
            push_front(val);
        }
        pos.ptr->prev = node;
        put_in_sorted_order(node);
    }
    return iter(node);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert_rev(iter pos, const_reference val)
{
    Node* node = new Node(val);
    if(!(pos.ptr))
    {
        push_front(val);
    }
    else
    {
        node->prev = pos.ptr;
        node->next = pos.ptr->next;
        if(pos.ptr->next)
        {
            pos.ptr->next->prev = node;
        }
        else
        {
            push_back(val);
        }
        pos.ptr->next = node;
        put_in_sorted_order(node);
    }
    return iter(node);
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, size_type size, const_reference val)
{
    if(!size)
    {
        return pos;
    }

    iter it = insert(pos, val);
    --size;

    while(size)
    {
        insert(pos, val);
        --size;
    }
    return it;
}

template <typename T>
template <typename iter>
iter FrankList<T>::insert(iter pos, std::initializer_list<value_type> init)
{
    for (auto i = init.begin(); i != init.end(); ++i) 
    {
        pos = insert(pos, *i);
    }

    return pos;
}

template <typename T>
template <typename iter, typename input_iterator>
iter FrankList<T>::insert(iter pos, input_iterator f, input_iterator l)
{
    while(f != l)
    {
        pos = insert(pos, *f);
        ++f;
    }
    return pos;
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter pos)
{
    if(!(pos.ptr))
    {
        return pos;
    }

    Node* rm = pos.ptr;
    Node* nx = rm->next;

    if(rm->prev)
    {
        rm->prev->next = rm->next;
    }
    else
    {
        this->head = rm->next;
    }

    if(rm->desc)
    {
        rm->desc->asc = rm->asc;
    }
    else
    {
        this->ahead = rm->asc;
    }

    if(rm->next)
    {
        rm->next->prev = rm->prev;
    }
    else
    {
        this->tail = rm->prev;
    }

    if(rm->asc)
    {
        rm->asc->desc = rm->desc;
    }
    else
    {
        this->atail = rm->desc;
    }

    delete rm;
    return iter(nx);
}

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter f, iter l)
{
    if(!(f.ptr))
    {
        return f;
    }

    Node* frm = f.ptr;
    Node* lrm = l.ptr;

    if(frm->prev)
    {
        frm->prev->next = frm->next;
    }
    else
    {
        this->head = frm->next;
    }

    if(lrm->next)
    {
        lrm->next->prev = lrm->prev;
    }
    else
    {
        this->tail = lrm->prev;
    }

    Node* current = frm;
    Node* last = lrm->next;
    while (current && current != last) 
    {
        Node* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }

    return iter(last);

}

template <typename T>
typename FrankList<T>::size_type FrankList<T>::remove(const_reference val)
{
    size_type count = 0;
    for(auto i = begin(); i != end(); ++i)
    {
        if(*i == val)
        {
            erase(i);
            --i;
            ++count;
        }
    }
    return count;
}

template <typename T>
template <typename unary_predicate>
typename FrankList<T>::size_type FrankList<T>::remove_if(unary_predicate func)
{
    size_type count = 0;
    for(auto i = begin(); i != end(); ++i)
    {
        if(func(*i))
        {
            erase(i);
            --i;
            ++count;
        }
    }
    return count;
}

template <typename T>
void vhuk::FrankList<T>::reverse()
{
    Node* current = this->head;

    while(current)
    {
        Node* tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    Node* tmp = this->head;
    this->head = this->tail;
    this->tail = tmp;
}

template <typename T>
void FrankList<T>::sort(bool reversed)
{
    if(!(head) || !(head->next))
    {
        return;
    }

    Node* current = !reversed ? this->ahead : this->atail;
    while(current)
    {
        if(!reversed)
        {
            current->next = current->asc;
            current->prev = current->desc;
            current = current->next;
        }
        else
        {
            current->next = current->desc;
            current->prev = current->asc;
            current = current->next;
        }
    }

    this->head = this->ahead;
    this->tail = this->atail;
}

template <typename T>
template <typename UnaryFunction>
void vhuk::FrankList<T>::traverse(UnaryFunction func, bool sorted, bool reversed) {
    Node* current;

    if (sorted) 
    {
        if (reversed) 
        {
            current = this->atail;
        } 
        else 
        {
            current = this->ahead;
        }
    } 
    else 
    {
        if(reversed)
        {
            current = this->tail;
        }
        else
        {
            current = head;
        }
    }

    while (current) {
        func(current->val);

        if (sorted) 
        {
            if (reversed) 
            {
                current = current->desc;
            } 
            else 
            {
                current = current->asc;
            }
        } 
        else 
        {
            if(reversed)
            {
                current = current->prev;
            }
            else
            {
                current = current->next;
            }
        }
    }
}

template <typename T>
void FrankList<T>::print(bool sorted, bool reversed)
{
    traverse([](const value_type& elem)
    {
        std::cout << elem << " ";
    }, sorted, reversed);
    std::cout << std::endl;
}

template <typename T>
void FrankList<T>::put_in_sorted_order(Node* ptr)
{
    if (!ptr) return;
    if (!ahead) 
    {
        ahead = ptr;
        atail = ptr;
        return;
    }
    Node* current = ahead;
    while (current->val < ptr->val && current->asc) 
    {
        current = current->asc;
    }
    if (current->val < ptr->val) 
    {
        ptr->asc = current->asc;
        current->asc = ptr;
        ptr->desc = current;
        if (!ptr->asc) 
        {
            atail = ptr;
        }
    } 
    else 
    {
        ptr->desc = current->desc;
        if (current->desc) 
        {
            current->desc->asc = ptr;
        } 
        else 
        {
            ahead = ptr;
        }
        ptr->asc = current;
        current->desc = ptr;
    }
}

template <typename T>
void FrankList<T>::organize_left(Node* ptr)
{
    if(!ptr || !(ptr->prev))
    {
        return;
    }
    Node* pNode = ptr->prev;
    Node* nNode = ptr->next;

    if (nNode)
    {
        nNode->prev = pNode;
    }

    pNode->next = nNode;

    ptr->next = pNode;
    ptr->prev = pNode->prev;

    if (pNode->prev)
    {
        pNode->prev->next = ptr;
    }
    else
    {
        head = ptr;
    }
}

template <typename T>
void FrankList<T>::organize_right(Node* ptr)
{
    if(!ptr || !(ptr->next))
    {
        return;
    }
    Node* pNode = ptr->prev;
    Node* nNode = ptr->next;

    if (pNode)
    {
        pNode->next = nNode;
    }

    nNode->prev = pNode;

    ptr->prev = nNode;
    ptr->next = nNode->next;

    if (nNode->next)
    {
        nNode->next->prev = ptr;
    }
    else
    {
        tail = ptr;
    }
}

template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::find(const_reference elem) 
{
    Node* current = head;
    while (current) 
    {
        if (current->val == elem) 
        {
            iterator i(current);
            organize_left(current);
            return i;
        }
        current = current->next;
    }
    return end();
}

template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::rfind(const_reference elem) 
{
    Node* current = tail;
    while (current) 
    {
        if (current->val == elem) 
        {
            iterator i(current);
            organize_right(current);
            return i;
        }
        current = current->prev;
    }
    return end();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const FrankList<T>& rhv)
{
    auto i = rhv.cbegin();
    while (i != rhv.cend())
    {
        out << *i << " ";
        ++i;
    }
    return out;
}

}

int main()
{
    vhuk::FrankList<int> list;
    list.push_back(5);
    list.push_front(7);
    std::cout << list << std::endl;

    list.push_back(9);
    std::cout << list << std::endl;

    list.erase(++(list.begin()));

    //list.pop_front();
    std::cout << list << std::endl;

    list.insert(++(list.begin()), 8);
    std::cout << list << std::endl;

    list.push_back(1);
    std::cout << list << std::endl;

    list.sort();
    std::cout << list << std::endl;

    list.push_back(7);
    std::cout << list << std::endl;

    list.remove(7);
    std::cout << list << std::endl;

    list.reverse();
    std::cout << list << std::endl;

    list.find(8);
    std::cout << list << std::endl;

    

    return 0;
}
