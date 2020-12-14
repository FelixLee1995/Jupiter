//
// Created by felix lee on 2020/12/14.
//

#ifndef JUPITER_NONCOPYABLE_H
#define JUPITER_NONCOPYABLE_H

/**
*  File: noncopyable.h
*  Desc: 无法复制的类， 用于继承获得该特性
*  Created by felix on 2020/09/01
*/

class Noncopyable {

protected:

    /**
     * @brief 保留默认构造函数
     */
    Noncopyable() = default;

    /**
     * @brief 保留默认析构函数
     */
    virtual ~Noncopyable() = default;

    /**
     * @brief 拷贝构造函数(禁用)
     */
    Noncopyable(const Noncopyable& T) = delete;


    /**
     * @brief 赋值函数(禁用)
     */
    Noncopyable& operator = (const Noncopyable& ) = delete;


};

#endif //JUPITER_NONCOPYABLE_H
