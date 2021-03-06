// Generated by gencpp from file radar_msgs/RadarDetectionArray.msg
// DO NOT EDIT!


#ifndef RADAR_MSGS_MESSAGE_RADARDETECTIONARRAY_H
#define RADAR_MSGS_MESSAGE_RADARDETECTIONARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <radar_msgs/RadarDetection.h>

namespace radar_msgs
{
template <class ContainerAllocator>
struct RadarDetectionArray_
{
  typedef RadarDetectionArray_<ContainerAllocator> Type;

  RadarDetectionArray_()
    : header()
    , detections()  {
    }
  RadarDetectionArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , detections(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::radar_msgs::RadarDetection_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::radar_msgs::RadarDetection_<ContainerAllocator> >::other >  _detections_type;
  _detections_type detections;





  typedef boost::shared_ptr< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> const> ConstPtr;

}; // struct RadarDetectionArray_

typedef ::radar_msgs::RadarDetectionArray_<std::allocator<void> > RadarDetectionArray;

typedef boost::shared_ptr< ::radar_msgs::RadarDetectionArray > RadarDetectionArrayPtr;
typedef boost::shared_ptr< ::radar_msgs::RadarDetectionArray const> RadarDetectionArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::radar_msgs::RadarDetectionArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::radar_msgs::RadarDetectionArray_<ContainerAllocator1> & lhs, const ::radar_msgs::RadarDetectionArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.detections == rhs.detections;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::radar_msgs::RadarDetectionArray_<ContainerAllocator1> & lhs, const ::radar_msgs::RadarDetectionArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace radar_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "61c7078a9900bd218f71dc0ec77e1358";
  }

  static const char* value(const ::radar_msgs::RadarDetectionArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x61c7078a9900bd21ULL;
  static const uint64_t static_value2 = 0x8f71dc0ec77e1358ULL;
};

template<class ContainerAllocator>
struct DataType< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "radar_msgs/RadarDetectionArray";
  }

  static const char* value(const ::radar_msgs::RadarDetectionArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"\n"
"radar_msgs/RadarDetection[] detections\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: radar_msgs/RadarDetection\n"
"# All variables below are relative to the radar's frame of reference.\n"
"# This message is not meant to be used alone but as part of a stamped or array message.\n"
"\n"
"uint16 detection_id                         # The ID of this detection generated by the radar. If\n"
"                                            # the radar does not generate IDs, this is intended as\n"
"                                            # a sequential identifier for each detection in a scan.\n"
"\n"
"geometry_msgs/Point position                # Only the x and y components are valid.\n"
"geometry_msgs/Vector3 velocity              # range_rate rectangular transformation to x and y components\n"
"float64 amplitude                           # The detection amplitude in dB.\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::radar_msgs::RadarDetectionArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.detections);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarDetectionArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::radar_msgs::RadarDetectionArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::radar_msgs::RadarDetectionArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "detections[]" << std::endl;
    for (size_t i = 0; i < v.detections.size(); ++i)
    {
      s << indent << "  detections[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::radar_msgs::RadarDetection_<ContainerAllocator> >::stream(s, indent + "    ", v.detections[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // RADAR_MSGS_MESSAGE_RADARDETECTIONARRAY_H
