;; Auto-generated. Do not edit!


(when (boundp 'radar_msgs::RadarDetectionStamped)
  (if (not (find-package "RADAR_MSGS"))
    (make-package "RADAR_MSGS"))
  (shadow 'RadarDetectionStamped (find-package "RADAR_MSGS")))
(unless (find-package "RADAR_MSGS::RADARDETECTIONSTAMPED")
  (make-package "RADAR_MSGS::RADARDETECTIONSTAMPED"))

(in-package "ROS")
;;//! \htmlinclude RadarDetectionStamped.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass radar_msgs::RadarDetectionStamped
  :super ros::object
  :slots (_header _detection ))

(defmethod radar_msgs::RadarDetectionStamped
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:detection __detection) (instance radar_msgs::RadarDetection :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _detection __detection)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:detection
   (&rest __detection)
   (if (keywordp (car __detection))
       (send* _detection __detection)
     (progn
       (if __detection (setq _detection (car __detection)))
       _detection)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; radar_msgs/RadarDetection _detection
    (send _detection :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; radar_msgs/RadarDetection _detection
       (send _detection :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; radar_msgs/RadarDetection _detection
     (send _detection :deserialize buf ptr-) (incf ptr- (send _detection :serialization-length))
   ;;
   self)
  )

(setf (get radar_msgs::RadarDetectionStamped :md5sum-) "9475ae8df95353e8dc069034d39b71ba")
(setf (get radar_msgs::RadarDetectionStamped :datatype-) "radar_msgs/RadarDetectionStamped")
(setf (get radar_msgs::RadarDetectionStamped :definition-)
      "std_msgs/Header header

radar_msgs/RadarDetection detection

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: radar_msgs/RadarDetection
# All variables below are relative to the radar's frame of reference.
# This message is not meant to be used alone but as part of a stamped or array message.

uint16 detection_id                         # The ID of this detection generated by the radar. If
                                            # the radar does not generate IDs, this is intended as
                                            # a sequential identifier for each detection in a scan.

geometry_msgs/Point position                # Only the x and y components are valid.
geometry_msgs/Vector3 velocity              # range_rate rectangular transformation to x and y components
float64 amplitude                           # The detection amplitude in dB.

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :radar_msgs/RadarDetectionStamped "9475ae8df95353e8dc069034d39b71ba")


