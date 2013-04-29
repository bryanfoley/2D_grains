//------------------------------------------------------------------------------
//
//                                 C++ Header
//
//------------------------------------------------------------------------------
//
//! \details <description>
//! \author  <author>
//! \date    yyyy-mm-dd
//
// History:
// yyyy-mm-dd <WI> <author abbrev> <history comment>
//------------------------------------------------------------------------------
//
//                 Copyright (c) 2013, ASML Netherlands B.V.
//                            All rights reserved
//
//------------------------------------------------------------------------------

#ifndef MYCLASS_HPP
#define MYCLASS_HPP

//------------------------------------------------------------------------------
//                           Own component includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                         Other components includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                         ASML environment includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                              System includes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                            Forward declarations
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                              Type definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                             Class declarations
//------------------------------------------------------------------------------

namespace CCCC
{
class MyClass
{
//------------------------ Special member functions ----------------------------
public:
    MyClass();
    virtual ~MyClass();

protected:

private:
    MyClass(const MyClass& original);
    MyClass& operator=(const MyClass& rhand_value);

//------------------------------------------------------------------------------
public:
    //----------------------------- Functions ----------------------------------
    void foo_bar(int ival, const MyClass& iref, int& ioref) const;

    //----------------------------- Constants ----------------------------------

protected:
    //----------------------------- Functions ----------------------------------

    //----------------------------- Constants ----------------------------------
    static const int MAX_RETRIES = 100;
    enum {RED, GREEN, BLUE};

private:
    //----------------------------- Functions ----------------------------------

    //----------------------------- Variables ----------------------------------
    int m_foobar; //!< Member variables start with "m_"
};
}

//------------------------------------------------------------------------------
//                      Inline functions / template definitions     
//------------------------------------------------------------------------------


#endif // MY_CLASS_HPP
//---------------------------------- End of file -------------------------------