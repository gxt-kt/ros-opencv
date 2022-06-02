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
      this.red = null;
      this.green = null;
      this.blue = null;
      this.point_x = null;
      this.point_y = null;
      this.rec_w = null;
      this.rec_h = null;
      this.col_name = null;
    }
    else {
      if (initObj.hasOwnProperty('red')) {
        this.red = initObj.red
      }
      else {
        this.red = 0;
      }
      if (initObj.hasOwnProperty('green')) {
        this.green = initObj.green
      }
      else {
        this.green = 0;
      }
      if (initObj.hasOwnProperty('blue')) {
        this.blue = initObj.blue
      }
      else {
        this.blue = 0;
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
      if (initObj.hasOwnProperty('col_name')) {
        this.col_name = initObj.col_name
      }
      else {
        this.col_name = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type point
    // Serialize message field [red]
    bufferOffset = _serializer.uint8(obj.red, buffer, bufferOffset);
    // Serialize message field [green]
    bufferOffset = _serializer.uint8(obj.green, buffer, bufferOffset);
    // Serialize message field [blue]
    bufferOffset = _serializer.uint8(obj.blue, buffer, bufferOffset);
    // Serialize message field [point_x]
    bufferOffset = _serializer.int32(obj.point_x, buffer, bufferOffset);
    // Serialize message field [point_y]
    bufferOffset = _serializer.int32(obj.point_y, buffer, bufferOffset);
    // Serialize message field [rec_w]
    bufferOffset = _serializer.int32(obj.rec_w, buffer, bufferOffset);
    // Serialize message field [rec_h]
    bufferOffset = _serializer.int32(obj.rec_h, buffer, bufferOffset);
    // Serialize message field [col_name]
    bufferOffset = _serializer.string(obj.col_name, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type point
    let len;
    let data = new point(null);
    // Deserialize message field [red]
    data.red = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [green]
    data.green = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [blue]
    data.blue = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [point_x]
    data.point_x = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [point_y]
    data.point_y = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [rec_w]
    data.rec_w = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [rec_h]
    data.rec_h = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [col_name]
    data.col_name = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.col_name);
    return length + 23;
  }

  static datatype() {
    // Returns string type for a message object
    return 'mypkg/point';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3b20bcbd4ecfee1b0e2965ef3012f41b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 red
    uint8 green
    uint8 blue
    int32 point_x
    int32 point_y
    int32 rec_w
    int32 rec_h
    string col_name
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new point(null);
    if (msg.red !== undefined) {
      resolved.red = msg.red;
    }
    else {
      resolved.red = 0
    }

    if (msg.green !== undefined) {
      resolved.green = msg.green;
    }
    else {
      resolved.green = 0
    }

    if (msg.blue !== undefined) {
      resolved.blue = msg.blue;
    }
    else {
      resolved.blue = 0
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

    if (msg.col_name !== undefined) {
      resolved.col_name = msg.col_name;
    }
    else {
      resolved.col_name = ''
    }

    return resolved;
    }
};

module.exports = point;
