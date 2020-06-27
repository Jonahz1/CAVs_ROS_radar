// Generated by gencpp from file radar_msgs/RadarStatus.msg
// DO NOT EDIT!


#ifndef RADAR_MSGS_MESSAGE_RADARSTATUS_H
#define RADAR_MSGS_MESSAGE_RADARSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace radar_msgs
{
template <class ContainerAllocator>
struct RadarStatus_
{
  typedef RadarStatus_<ContainerAllocator> Type;

  RadarStatus_()
    : header()
    , curvature(0)
    , yaw_rate(0.0)
    , vehicle_speed(0.0)
    , max_track_targets(0)
    , raw_data_mode(false)
    , temperature(0)
    , patial_blockage(false)
    , side_lobe_blockage(false)  {
    }
  RadarStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , curvature(0)
    , yaw_rate(0.0)
    , vehicle_speed(0.0)
    , max_track_targets(0)
    , raw_data_mode(false)
    , temperature(0)
    , patial_blockage(false)
    , side_lobe_blockage(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int16_t _curvature_type;
  _curvature_type curvature;

   typedef float _yaw_rate_type;
  _yaw_rate_type yaw_rate;

   typedef float _vehicle_speed_type;
  _vehicle_speed_type vehicle_speed;

   typedef uint8_t _max_track_targets_type;
  _max_track_targets_type max_track_targets;

   typedef uint8_t _raw_data_mode_type;
  _raw_data_mode_type raw_data_mode;

   typedef int8_t _temperature_type;
  _temperature_type temperature;

   typedef uint8_t _patial_blockage_type;
  _patial_blockage_type patial_blockage;

   typedef uint8_t _side_lobe_blockage_type;
  _side_lobe_blockage_type side_lobe_blockage;





  typedef boost::shared_ptr< ::radar_msgs::RadarStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::radar_msgs::RadarStatus_<ContainerAllocator> const> ConstPtr;

}; // struct RadarStatus_

typedef ::radar_msgs::RadarStatus_<std::allocator<void> > RadarStatus;

typedef boost::shared_ptr< ::radar_msgs::RadarStatus > RadarStatusPtr;
typedef boost::shared_ptr< ::radar_msgs::RadarStatus const> RadarStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::radar_msgs::RadarStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::radar_msgs::RadarStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::radar_msgs::RadarStatus_<ContainerAllocator1> & lhs, const ::radar_msgs::RadarStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.curvature == rhs.curvature &&
    lhs.yaw_rate == rhs.yaw_rate &&
    lhs.vehicle_speed == rhs.vehicle_speed &&
    lhs.max_track_targets == rhs.max_track_targets &&
    lhs.raw_data_mode == rhs.raw_data_mode &&
    lhs.temperature == rhs.temperature &&
    lhs.patial_blockage == rhs.patial_blockage &&
    lhs.side_lobe_blockage == rhs.side_lobe_blockage;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::radar_msgs::RadarStatus_<ContainerAllocator1> & lhs, const ::radar_msgs::RadarStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace radar_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::radar_msgs::RadarStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::radar_msgs::RadarStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_msgs::RadarStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::radar_msgs::RadarStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_msgs::RadarStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::radar_msgs::RadarStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::radar_msgs::RadarStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5b982da6e1f20a73f7c8a15070ee5a36";
  }

  static const char* value(const ::radar_msgs::RadarStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5b982da6e1f20a73ULL;
  static const uint64_t static_value2 = 0xf7c8a15070ee5a36ULL;
};

template<class ContainerAllocator>
struct DataType< ::radar_msgs::RadarStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "radar_msgs/RadarStatus";
  }

  static const char* value(const ::radar_msgs::RadarStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::radar_msgs::RadarStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"\n"
"# Status of the radar\n"
"\n"
"int16   curvature\n"
"float32 yaw_rate\n"
"float32 vehicle_speed\n"
"uint8   max_track_targets\n"
"bool    raw_data_mode\n"
"int8    temperature\n"
"bool    patial_blockage\n"
"bool    side_lobe_blockage\n"
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
;
  }

  static const char* value(const ::radar_msgs::RadarStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::radar_msgs::RadarStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.curvature);
      stream.next(m.yaw_rate);
      stream.next(m.vehicle_speed);
      stream.next(m.max_track_targets);
      stream.next(m.raw_data_mode);
      stream.next(m.temperature);
      stream.next(m.patial_blockage);
      stream.next(m.side_lobe_blockage);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::radar_msgs::RadarStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::radar_msgs::RadarStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "curvature: ";
    Printer<int16_t>::stream(s, indent + "  ", v.curvature);
    s << indent << "yaw_rate: ";
    Printer<float>::stream(s, indent + "  ", v.yaw_rate);
    s << indent << "vehicle_speed: ";
    Printer<float>::stream(s, indent + "  ", v.vehicle_speed);
    s << indent << "max_track_targets: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.max_track_targets);
    s << indent << "raw_data_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.raw_data_mode);
    s << indent << "temperature: ";
    Printer<int8_t>::stream(s, indent + "  ", v.temperature);
    s << indent << "patial_blockage: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.patial_blockage);
    s << indent << "side_lobe_blockage: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.side_lobe_blockage);
  }
};

} // namespace message_operations
} // namespace ros

#endif // RADAR_MSGS_MESSAGE_RADARSTATUS_H
