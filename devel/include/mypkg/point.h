// Generated by gencpp from file mypkg/point.msg
// DO NOT EDIT!


#ifndef MYPKG_MESSAGE_POINT_H
#define MYPKG_MESSAGE_POINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mypkg
{
template <class ContainerAllocator>
struct point_
{
  typedef point_<ContainerAllocator> Type;

  point_()
    : red(0)
    , green(0)
    , blue(0)
    , point_x(0)
    , point_y(0)
    , rec_w(0)
    , rec_h(0)
    , col_name()  {
    }
  point_(const ContainerAllocator& _alloc)
    : red(0)
    , green(0)
    , blue(0)
    , point_x(0)
    , point_y(0)
    , rec_w(0)
    , rec_h(0)
    , col_name(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _red_type;
  _red_type red;

   typedef uint8_t _green_type;
  _green_type green;

   typedef uint8_t _blue_type;
  _blue_type blue;

   typedef int32_t _point_x_type;
  _point_x_type point_x;

   typedef int32_t _point_y_type;
  _point_y_type point_y;

   typedef int32_t _rec_w_type;
  _rec_w_type rec_w;

   typedef int32_t _rec_h_type;
  _rec_h_type rec_h;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _col_name_type;
  _col_name_type col_name;





  typedef boost::shared_ptr< ::mypkg::point_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mypkg::point_<ContainerAllocator> const> ConstPtr;

}; // struct point_

typedef ::mypkg::point_<std::allocator<void> > point;

typedef boost::shared_ptr< ::mypkg::point > pointPtr;
typedef boost::shared_ptr< ::mypkg::point const> pointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mypkg::point_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mypkg::point_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mypkg::point_<ContainerAllocator1> & lhs, const ::mypkg::point_<ContainerAllocator2> & rhs)
{
  return lhs.red == rhs.red &&
    lhs.green == rhs.green &&
    lhs.blue == rhs.blue &&
    lhs.point_x == rhs.point_x &&
    lhs.point_y == rhs.point_y &&
    lhs.rec_w == rhs.rec_w &&
    lhs.rec_h == rhs.rec_h &&
    lhs.col_name == rhs.col_name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mypkg::point_<ContainerAllocator1> & lhs, const ::mypkg::point_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mypkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mypkg::point_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mypkg::point_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mypkg::point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mypkg::point_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mypkg::point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mypkg::point_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mypkg::point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3b20bcbd4ecfee1b0e2965ef3012f41b";
  }

  static const char* value(const ::mypkg::point_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3b20bcbd4ecfee1bULL;
  static const uint64_t static_value2 = 0x0e2965ef3012f41bULL;
};

template<class ContainerAllocator>
struct DataType< ::mypkg::point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mypkg/point";
  }

  static const char* value(const ::mypkg::point_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mypkg::point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 red\n"
"uint8 green\n"
"uint8 blue\n"
"int32 point_x\n"
"int32 point_y\n"
"int32 rec_w\n"
"int32 rec_h\n"
"string col_name\n"
;
  }

  static const char* value(const ::mypkg::point_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mypkg::point_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.red);
      stream.next(m.green);
      stream.next(m.blue);
      stream.next(m.point_x);
      stream.next(m.point_y);
      stream.next(m.rec_w);
      stream.next(m.rec_h);
      stream.next(m.col_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct point_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mypkg::point_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mypkg::point_<ContainerAllocator>& v)
  {
    s << indent << "red: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.red);
    s << indent << "green: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.green);
    s << indent << "blue: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.blue);
    s << indent << "point_x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.point_x);
    s << indent << "point_y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.point_y);
    s << indent << "rec_w: ";
    Printer<int32_t>::stream(s, indent + "  ", v.rec_w);
    s << indent << "rec_h: ";
    Printer<int32_t>::stream(s, indent + "  ", v.rec_h);
    s << indent << "col_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.col_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MYPKG_MESSAGE_POINT_H
