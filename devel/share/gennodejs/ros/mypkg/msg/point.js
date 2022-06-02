// Auto-generated. Do not edit!

// (in-package mypkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class point {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.color = null;
      this.point_x = null;
      this.point_y = null;
      this.rec_w = null;
      this.rec_h = null;
    }
    else {
      if (initObj.hasOwnProperty('color')) {
        this.color = initObj.color
      }
      else {
        this.color = 0;
      }
      if (initObj.hasOwnProperty('point_x')) {
        this.point_x = initObj.point_x
      }
      else {
        this.point_x = 0;
      }
      if (initObj.hasOwnProperty('point_y')) {
        this.point_y = initObj.point_y
      }
      else {
        this.point_y = 0;
      }
      if (initObj.hasOwnProperty('rec_w')) {
        this.rec_w = initObj.rec_w
      }
      else {
        this.rec_w = 0;
      }
      if (initObj.hasOwnProperty('rec_h')) {
        this.rec_h = initObj.rec_h
      }
      else {
        this.rec_h = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type point
    // Serialize message field [color]
    bufferOffset = _serializer.int32(obj.color, buffer, bufferOffset);
    // Serialize message field [point_x]
    bufferOffset = _serializer.int32(obj.point_x, buffer, bufferOffset);
    // Serialize message field [point_y]
    bufferOffset = _serializer.int32(obj.point_y, buffer, bufferOffset);
    // Serialize message field [rec_w]
    bufferOffset = _serializer.int32(obj.rec_w, buffer, bufferOffset);
    // Serialize message field [rec_h]
    bufferOffset = _serializer.int32(obj.rec_h, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type point
    let len;
    let data = new point(null);
    // Deserialize message field [color]
    data.color = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [point_x]
    data.point_x = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [point_y]
    data.point_y = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [rec_w]
    data.rec_w = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [rec_h]
    data.rec_h = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mypkg/point';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ced0dd05440ad59425463c1af8c9cc38';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 color
    int32 point_x
    int32 point_y
    int32 rec_w
    int32 rec_h
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new point(null);
    if (msg.color !== undefined) {
      resolved.color = msg.color;
    }
    else {
      resolved.color = 0
    }

    if (msg.point_x !== undefined) {
      resolved.point_x = msg.point_x;
    }
    else {
      resolved.point_x = 0
    }

    if (msg.point_y !== undefined) {
      resolved.point_y = msg.point_y;
    }
    else {
      resolved.point_y = 0
    }

    if (msg.rec_w !== undefined) {
      resolved.rec_w = msg.rec_w;
    }
    else {
      resolved.rec_w = 0
    }

    if (msg.rec_h !== undefined) {
      resolved.rec_h = msg.rec_h;
    }
    else {
      resolved.rec_h = 0
    }

    return resolved;
    }
};

module.exports = point;
